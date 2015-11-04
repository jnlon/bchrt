# bchrt
Small program for viewing binary files

Opens file specified by argument and displays the contents in
hexadecimal, unsigned integer form, character, etc.

# Usage

Run make, execute binary with a file path as an argument.

# Example

File ```test.txt``` contains:

```
Hello world!
```

Output of ```ochrt test.txt```

```
indx int binary   hex  char
0    72  01001000 0x48 H
1    101 01100101 0x65 e
2    108 01101100 0x6C l
3    108 01101100 0x6C l
4    111 01101111 0x6F o
5    32  00100000 0x20  
6    87  01010111 0x57 W
7    111 01101111 0x6F o
8    114 01110010 0x72 r
9    108 01101100 0x6C l
10   100 01100100 0x64 d
11   33  00100001 0x21 !
12   10  00001010 0x0A \n
```

