#include <iostream>
#include <windows.h>
#include <ctime>

void read_bfFile(FILE *cmdlist) {
  char c;
  int i = 0;
  while (!feof(cmdlist)) {
    if (i == 50) {
      printf("\n");
      i = 0;
    }
    fscanf(cmdlist, "%c", &c);
    if (!feof(cmdlist)) {
      printf("%c", c);
      i++;
    }
  }
  printf("\n");
}

void translate_brainfuck_fFile(FILE *cmdlist, char *tier) {
  int loop;
  char cmd_char;

  do {
    fscanf(cmdlist, "%c", &cmd_char);
    switch (cmd_char) {
      case '>':
        tier++;
        break;
      case '<':
        tier--;
        break;
      case '+':
        (*tier)++;
        break;
      case '-':
        (*tier)--;
        break;
      case '.':
        putchar(*tier);
        break;
      case ',':
        *tier = getchar();
        break;
      case '[':
        if (!*tier) {
          loop = 1;
          while (loop) {
            fscanf(cmdlist, "%c", &cmd_char);
            if (cmd_char == '[') {
              loop++;
            }
            if (cmd_char == ']') {
              loop--;
            }
          }
        }
        break;
      case ']':
        if (*tier) {
          loop = 1;
          while (loop) {
            fseek(cmdlist, -2, SEEK_CUR);
            fscanf(cmdlist, "%c", &cmd_char);
            if (cmd_char == '[') {
              loop--;
            }
            if (cmd_char == ']') {
              loop++;
            }
          }
        }
        break;
      default:
        fprintf(stderr, "Error");
        exit(1);
    }
    (*tier)++;
  } while ((!feof(cmdlist)));
  printf("\n");
}

int main() {
  SetConsoleOutputCP(CP_UTF8);
  srand(time(NULL));

  char cpu[30000];
  FILE *read = fopen("exercise.txt", "r");
  read_bfFile(read);
  translate_brainfuck_fFile(read, cpu);
}