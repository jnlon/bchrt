#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define READBUFSZ 1024
#define CHRBUFSZ 5

void get_ascii_symbol(int code, char* buf) {

  if (code >= 32 && code <= 126) {
    snprintf(buf, CHRBUFSZ, "'%c'", code);
    return;
  }

  switch (code) {
    case 0: strncpy(buf, "NUL", CHRBUFSZ); break;
    case 1: strncpy(buf, "SOH", CHRBUFSZ); break;
    case 2: strncpy(buf, "STX", CHRBUFSZ); break;
    case 3: strncpy(buf, "ETX", CHRBUFSZ); break;
    case 4: strncpy(buf, "EOT", CHRBUFSZ); break;
    case 5: strncpy(buf, "ENQ", CHRBUFSZ); break;
    case 6: strncpy(buf, "ACK", CHRBUFSZ); break;
    case 7: strncpy(buf, "BEL", CHRBUFSZ); break;
    case 8: strncpy(buf, "BS", CHRBUFSZ); break;
    case 9: strncpy(buf, "HT", CHRBUFSZ); break;
    case 10: strncpy(buf, "LF", CHRBUFSZ); break;
    case 11: strncpy(buf, "VT", CHRBUFSZ); break;
    case 12: strncpy(buf, "FF", CHRBUFSZ); break;
    case 13: strncpy(buf, "CR", CHRBUFSZ); break;
    case 14: strncpy(buf, "SO", CHRBUFSZ); break;
    case 15: strncpy(buf, "SI", CHRBUFSZ); break;
    case 16: strncpy(buf, "DLE", CHRBUFSZ); break;
    case 17: strncpy(buf, "DC1", CHRBUFSZ); break;
    case 18: strncpy(buf, "DC2", CHRBUFSZ); break;
    case 19: strncpy(buf, "DC3", CHRBUFSZ); break;
    case 20: strncpy(buf, "DC4", CHRBUFSZ); break;
    case 21: strncpy(buf, "NAK", CHRBUFSZ); break;
    case 22: strncpy(buf, "SYN", CHRBUFSZ); break;
    case 23: strncpy(buf, "ETB", CHRBUFSZ); break;
    case 24: strncpy(buf, "CAN", CHRBUFSZ); break;
    case 25: strncpy(buf, "EM", CHRBUFSZ); break;
    case 26: strncpy(buf, "SUB", CHRBUFSZ); break;
    case 27: strncpy(buf, "ESC", CHRBUFSZ); break;
    case 28: strncpy(buf, "FS", CHRBUFSZ); break;
    case 29: strncpy(buf, "GS", CHRBUFSZ); break;
    case 30: strncpy(buf, "RS", CHRBUFSZ); break;
    case 31: strncpy(buf, "US", CHRBUFSZ); break;
    case 32: strncpy(buf, " ", CHRBUFSZ); break;
    case 127: strncpy(buf, "DEL", CHRBUFSZ); break;
    default: strncpy(buf, "__ ", CHRBUFSZ); break;
  }

  return;
}

void print_help_exit() {
  printf("Usage: bchrt [filepath]");
  exit(1);
}

void get_binary(unsigned char code, char* buf) {
  for (int i=0;i<8;i++) {
    if (((code >> (7-i)) % 2) == 0)
      buf[i] = '0';
    else 
      buf[i] = '1';
  }
  buf[8] = 0;
}

void print_bchrt(char* buf, int sz, long long offset) {
  char char_symbol_buf[CHRBUFSZ];
  bzero(char_symbol_buf, CHRBUFSZ);
  char binary_buf[9];
  bzero(binary_buf, 9);

  for (int i=0;i<sz;i++) {

    unsigned char ch = buf[i];
    long long index = offset + i;
    get_ascii_symbol(ch, char_symbol_buf);
    get_binary(ch, binary_buf);

    printf("%-2lld 0x%-2llX | %-3hhu %-5s 0x%-2hhX %s %hho\n", 
        index, index, ch, char_symbol_buf, ch, binary_buf, ch);
    //puts(binary_buf);
  }
}

int main(int argc, char* argv[]) {

  FILE *f;
  int readbufsize = READBUFSZ;
  if (argc <= 1) {
    f = stdin;
    readbufsize = 1;
  }
  else
    f = fopen(argv[1], "r");
  int ret = -1;
  long long offset = 0;
  char buf[readbufsize];

  puts("_offset_  int ascii hex  binary   oct");
  while (ret != 0) {
    ret = fread(buf, sizeof(buf[0]), readbufsize, f);
    print_bchrt(buf, ret, offset) ;
    offset += ret;
    fflush(f);
  }

  fclose(f);

  return 0;
}
