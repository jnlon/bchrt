# bchrt
Small program for viewing binary files

Opens file specified by argument and displays the contents in
hexadecimal, unsigned integer form, character, etc.

# Usage

Run make, execute binary with a file path as an argument.

# Example

File test.txt contains:

```
Hello world!
```

Output of ```ochrt test.txt```

```
int binary hex bytes char
72  01001000 0x48 0 H
101 01100101 0x65 1 e
108 01101100 0x6C 2 l
108 01101100 0x6C 3 l
111 01101111 0x6F 4 o
32  00100000 0x20 5  
87  01010111 0x57 6 W
111 01101111 0x6F 7 o
114 01110010 0x72 8 r
108 01101100 0x6C 9 l
100 01100100 0x64 10 d
33  00100001 0x21 11 !
10  00001010 0x0A 12 \n
```

