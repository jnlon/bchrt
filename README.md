# bchrt
`bchrt` is a small program used for viewing binary files.

`bchrt` opens a file specified its first argument and displays the contents in
hexadecimal, octal, ascii, etc. If executed without any arguments, 'bchrt' will
read from stdin.

# Usage

Make sure you have a C compiler and make installed.

Run `make` in the project's directory, and execute the 'bchrt' binary with a
file path as its argument.

# Example

File `test.txt` contains:

```
Hello world!
```

Output of `bchrt test.txt`

```
_offset_  int ascii hex  binary   oct
0  0x0  | 72  'H'   0x48 01001000 110
1  0x1  | 101 'e'   0x65 01100101 145
2  0x2  | 108 'l'   0x6C 01101100 154
3  0x3  | 108 'l'   0x6C 01101100 154
4  0x4  | 111 'o'   0x6F 01101111 157
5  0x5  | 32  ' '   0x20 00100000 40
6  0x6  | 87  'W'   0x57 01010111 127
7  0x7  | 111 'o'   0x6F 01101111 157
8  0x8  | 114 'r'   0x72 01110010 162
9  0x9  | 108 'l'   0x6C 01101100 154
10 0xA  | 100 'd'   0x64 01100100 144
11 0xB  | 33  '!'   0x21 00100001 41
12 0xC  | 10  LF    0xA  00001010 12
```
