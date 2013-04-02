#include <stdlib.h>
#include <stdio.h>

int main(int m, char const *ma[])
{
  if (m != 3) {
    return EXIT_FAILURE;
  }

  FILE *mal = fopen(ma[1], "r");
  if (mal == NULL) {
    return EXIT_FAILURE;
  }

  FILE *malk = fopen(ma[2], "w");
  if (malk == NULL) {
    return EXIT_FAILURE;
  }

  fprintf(malk, "int main(){char m[30000];char *ma = m;");

  int malko;
  char malkov = 0;
  while ((malko = fgetc(mal)) != EOF) {
    switch ((char)malko) {
      case '.':
        if (malkov == 0) {
          malkov = '.';
        } else {
          switch (malkov) {
            case '?':
              fprintf(malk, "--ma;");
              break;
            case '.':
              fprintf(malk, "++*ma;");
              break;
            case '!':
              fprintf(malk, "putchar(*ma);");
              break;
          }
          malkov = 0;
        }
        break;
      case '?':
        if (malkov == 0) {
          malkov = '?';
        } else {
          switch (malkov) {
            case '.':
              fprintf(malk, "++ma;");
              break;
            case '!':
              fprintf(malk, "while (*ma) {");
              break;
          }
          malkov = 0;
        }
        break;
      case '!':
        if (malkov == 0) {
          malkov = '!';
        } else {
          switch (malkov) {
            case '!':
              fprintf(malk, "--*ma;");
              break;
            case '.':
              fprintf(malk, "*ma=getchar();");
              break;
            case '?':
              fprintf(malk, "}");
              break;
          }
          malkov = 0;
        }
        break;
    }
  }

  fprintf(malk, "return 0;}");

  fclose (malk);
  fclose (mal);

  return EXIT_SUCCESS;
}
