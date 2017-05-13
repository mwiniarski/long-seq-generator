# long-sequence-generator

Generator for long genome reads

### Prerequisites

To build project you need: `scons`, `boost` and `g++6`

### Installing program and running tests

In main folder run `scons`

### Usage

`./generator SEQUENCE_LENGTH`

options:

`-L LENGTH` - length of single read, **_default 5000_**  
`-C COVERAGE`  - the coverage of sequence, **_default 5_**  
`-E ERROR`  - % of errors in every read, **_default 0_**

### Output

The **correct** genome is saved to `whole_correct_genome` file and generated reads to `out`.

