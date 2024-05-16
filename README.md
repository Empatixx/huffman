# Huffman Compression and Decompression

This project is an implementation of Huffman coding, a popular algorithm used for lossless data compression. The project is written in C++ and uses the Huffman coding algorithm to compress and decompress files.

## How it works

The Huffman coding algorithm works by creating a binary tree of nodes. These nodes represent frequencies of different characters in the file. The most frequent character gets the smallest code, and the least frequent character gets the largest code.

The compressed file consists of a header that holds the frequency of each character, the padding needed, and the compressed data.

## How to run

The project is run from the command line with the following syntax:

```bash
./program [c/d] [input file] [output file]
```
- `c` is used to compress the input file and save it to the output file.
- `d` is used to decompress the input file and save it to the output file.
- `input file` is the path to the file you want to compress or decompress.
- `output file` is the path where you want to save the compressed or decompressed file.

For example, to compress a file named `input.txt`, you would use:

```bash
./program c input.txt output.bin
```
And to decompress it again:

```bash
./program d output.bin decompressed.txt
```

## Theory
Theory
The theory behind this project is based on the Huffman coding algorithm, as described in the book "Introduction to the Design and Analysis of Algorithms". Huffman coding is a type of optimal prefix code that is commonly used for lossless data compression. The process behind the algorithm is simple: characters that appear more frequently in a file are assigned shorter codes, while less frequent characters are assigned longer codes. This results in a compressed file that can be decompressed to its original state.
