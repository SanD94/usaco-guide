#!/usr/bin/env python3
"""Bundle a competitive-programming source file into sol.cpp.

Local quoted includes are expanded recursively; system includes are left alone.
Example:
    python3 bundle.py usaco/bronze/feb.cpp
"""

from __future__ import annotations

import argparse
import re
from pathlib import Path


LOCAL_INCLUDE = re.compile(r'^(\s*)#\s*include\s+"([^"]+)"\s*(?://.*)?$')


def display(path: Path) -> str:
    try:
        return str(path.relative_to(Path.cwd()))
    except ValueError:
        return str(path)


def bundle(path: Path, seen: set[Path], stack: list[Path]) -> list[str]:
    path = path.resolve()
    if path in stack:
        cycle = stack[stack.index(path):] + [path]
        chain = " -> ".join(display(p) for p in cycle)
        raise SystemExit(f"include cycle detected: {chain}")

    if path in seen:
        return []

    seen.add(path)
    stack.append(path)

    out: list[str] = []
    for line in path.read_text().splitlines():
        if line.strip() == "#pragma once":
            continue

        match = LOCAL_INCLUDE.match(line)
        if match:
            header = (path.parent / match.group(2)).resolve()
            out.append(f"// begin {display(header)}")
            out.extend(bundle(header, seen, stack))
            out.append(f"// end {display(header)}")
            continue

        out.append(line)
    stack.pop()
    return out


def main() -> None:
    parser = argparse.ArgumentParser(
        description="Expand local quoted includes into one submission file."
    )
    parser.add_argument("source", type=Path, help="main .cpp file")
    parser.add_argument("-o", "--output", type=Path, default=Path("sol.cpp"))
    args = parser.parse_args()

    contents = bundle(args.source, set(), [])
    args.output.write_text("\n".join(contents) + "\n")


if __name__ == "__main__":
    main()
