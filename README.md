# CEGARBoxCPP

## Versions
I will be working on CEGARBoxCPP continuously throughout the year, so the master branch will change. Because of this I will create branches for each version of the tool.
For the submission to TABLEAUX2023, check the TABLEAUX2023 branch.
For the submission to CSL2024, check the CSL2024 branch.

## Authorship
Robert McArthur and Cormac Kikkert, for contact email cormac.kikkert@anu.edu.au

## Programs
There are two programs in this repo.

`kaleidoscope`: CEGARBox++(K), handles K extended with single axioms OR global assumptions OR converse modalities (tense logic).

`lumen`: CEGARBox++(LTL), handles LTL and LTL-f

## Compilation
Statically compiled files `kaleidoscope` and `lumen` are already available on this repo - compiled on Ubuntu 20.04.3.

However, if you want to recreate our results, you will need to compile CEGARBoxCPP for your machine. To do this, follow the instructions but note that the following will be installed:
1. [Minisat](https://github.com/agurfinkel/minisat), a SAT-solver. This is a fork, as the original is outdated and no longer works.
2. [antlr4](https://www.antlr.org/download.html) for LTL parsing. This is the C++ target
3. [ltl2snf](https://nalon.org/#software) for converting LTL formula to SNF.

## Prerequisites
```
sudo apt-get update && sudo apt-get install -y build-essential wget unzip tar cmake sudo libz-dev libgoogle-glog-dev
```

## Installing ANTLR4
```
export ANTLR_DIR=/antlr4 && wget https://www.antlr.org/download/antlr4-cpp-runtime-4.13.0-source.zip && \
mkdir -p $ANTLR_DIR && unzip -q antlr4-cpp-runtime-4.13.0-source.zip -d $ANTLR_DIR && \
mkdir -p $ANTLR_DIR/build $ANTLR_DIR/run && cd $ANTLR_DIR/build && cmake .. && make install
```

## Installing Minisat
```
git clone https://github.com/agurfinkel/minisat.git && cd minisat && \
make config prefix=/usr && sudo make install
```

## Installing ltl2snf
```
wget https://nalon.org/software/ltl2snf-0.1.0.tar.gz && \
tar xzf ltl2snf-0.1.0.tar.gz && cd ltl2snf-0.1.0 && make && mv ./ltl2snf ../ && cd .. && rm -rf ltl2snf-0.1.0*
```

## Installing CEGARBoxCPP
Run ``make`` to compile CEGARBox
Then test with `cd Examples && ./tests.sh`

## Input Formula
CEGARBox(K) accepts file input. Input is terminated by a newline and valid input formula are defined by the following grammar:
```
Index ::= Nat || -Nat
Atom ::= Alphanumeric String
Formula ::=
 Atom || $true || $false || ~Formula ||
 [Index] Formula || <Index> Formula || []Formula || <>Formula || 
 Formula | Formula || Formula & Formula || Formula => Formula || 
 Formula <=> Formula || (Formula) 
```

Here, negative numbers are used to define converse for tense logic. For example ``[-1]`` is the converse of ``[1]``.

CEGARBox(K) does not handle intohylo files! So files with BEGIN and END won't work. Please refer to the examples in `Examples`.

CEGARBox(LTL) uses the same input as ltl2snf:
```
PROPOSITIONAL SYMBOLS: an alfanumeric sequence starting with a letter: p, p1, p_1 (underscore should not be used at the beginning of a name)
CONSTANTS: true, false
NOT: -, ~, not
AND: &, and
OR: |, or
IMPLICATION: ->, =>, imp, imply, implies
ONLY IF: <-, <=
DOUBLE IMPLICATION: <->, <=>, iff
ALWAYS: [], always
EVENTUALLY: <>, sometime
UNTIL: U, until
UNLESS: W, unless
```

## Running CEGARBox 

``./main -f <input_file> [options]``

Options:

* Reflexivity: ``--reflexive`` or ``-t``
* Symmetry: ``--symmetric`` or ``-b``
* Transitivity: ``--transitive`` or ``-4``
* Seriality: ``--serial`` or ``-d``
* Euclidean: ``--euclidean`` or ``-e``
* Valid (whether input formula is valid): ``--valid`` or ``-a``
* Tense: ``--tense`` or `-n`
* Verbose: ``--verbose`` or `-v`

To use the local prover add `-l`
To use the global prover add `-g`
(Default is bespoke)

## Benchmarks

MQBF, 3CNF and LWB_K benchmarks can be downloaded from [here](http://www.cril.univ-artois.fr/~montmirail/mosaic/#)
ALC benchmarks can be downloaded from [here](https://web.archive.org/web/20190305011522/http://users.cecs.anu.edu.au/~rpg/BDDTab/)

## Examples
Some examples to see how to use the tool are in `Examples`.

Note: logics besides K, KD, KT, KB, K4, K5, and tense are untested, and may not work.
