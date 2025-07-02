# Huffman Encoding and Decoding

Welcome to the Huffman Encoding repo!
This project provides a Python implementation of Huffman coding,
a widely used algorithm for data compression.
The code consists of two main files:
```Graph.py``` and ```Huffman.py```

## Overview
Huffman coding is a method of data compression that assigns variable-length
codes to input characters, with shorter codes assigned to more frequent characters.
This code implements the algorithm using a choice between a linear priority queue and a heap priority queue for building the Huffman tree.

## Files
- **Graph.py**: Contains the core logic for building the Huffman tree and generating
  binary codes for each character.
- **Huffman.py**: Handles user input, manages the processes,
  and intracts with the ```Graph.py``` functions.

## Features
- **Encoding**: Compress text files by converting characters into binary codes based on their frequency.
- **Priority Queue Options**: Choose between a linear priority queue and a heap priority queue for tree construction.

## Requirements
- Python 3.x
- Basic understanding of command-line operations

## Usage
Run the ```Huffman.py``` script with the following command:
```bash
python Huffman.py InputFile.txt OutputFile.txt
```
- Replace ```InputFile.txt``` with the path to your text file that you want to encode.
- Replace ```OutputFile.txt``` with the path where you want to save the encoded output.

## User Interaction
Upon running the script, you will be prompted to choose the type of priority queue to use:

1. Linear priority queue
2. Heap priority queue

### Thank you for using the Huffman Encoding and Decoding repository! Happy coding!
