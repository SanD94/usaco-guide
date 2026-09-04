SRC ?= ./cf/1117C.cpp
SUBMISSION ?= sol.cpp
OUT ?= sol
INPUT ?= input
OUTPUT ?= output
JUDGE ?= judge.cpp
JUDGE_OUT ?= judge

PYTHON ?= python3
CXX := g++
CXXFLAGS ?= -std=c++17 -I. -Wall -Wextra -pedantic
SOCAT ?= socat

.PHONY: all bundle build run interact check clean help

all: build

bundle: $(SUBMISSION)

$(SUBMISSION): $(SRC) bundle.py
	$(PYTHON) bundle.py $(SRC) -o $(SUBMISSION)

build: $(OUT)

$(OUT): $(SUBMISSION)
	$(CXX) $(CXXFLAGS) $(SUBMISSION) -o $(OUT)

run: $(OUT)
	./$(OUT) < $(INPUT) > $(OUTPUT)

$(JUDGE_OUT): $(JUDGE)
	$(CXX) $(CXXFLAGS) $(JUDGE) -o $(JUDGE_OUT)

interact: $(OUT) $(JUDGE_OUT)
	$(SOCAT) EXEC:./$(OUT) EXEC:./$(JUDGE_OUT),nofork

check: build
	$(CXX) $(CXXFLAGS) $(SRC) -o /tmp/cp-check

clean:
	rm -f $(SUBMISSION) $(OUT) $(JUDGE_OUT) /tmp/cp-check

help:
	@echo "make SRC=path/to/problem.cpp        # bundle + compile to ./sol"
	@echo "make run SRC=path/to/problem.cpp    # bundle + compile + run with input/output"
	@echo "make interact SRC=problem.cpp JUDGE=judge.cpp  # run solution and judge"
	@echo "make check SRC=path/to/problem.cpp  # compile bundled and original source"
	@echo "make run INPUT=in OUTPUT=out        # override input/output file names"
	@echo "make clean                          # remove generated files"
