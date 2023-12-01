#include <stdio.h>
#include <ctype.h>
#include <string.h>

int ungetchars(char *s) {
  for (int i = strlen(s)-1; i >= 0; i--) {
    ungetc(s[i], stdin);
  }
  return 0;
}

int check(char *s) {
  
  char read_string[255];
  
  int i = 0;
  for (i = 0; i < strlen(s); i++) {
    int c = 0;
    if ((c = getchar()) == EOF) {
      ungetchars(read_string);
      return 0;
    }
    read_string[i] = c;
  }
  read_string[i] = '\0';
  ungetchars(read_string);
  return strcmp(read_string, s) == 0;
}
  

int main(void) {
 
  int sum = 0;
  int c = 0;
  char line[256];
  
  int first = -1;
  int last = -1;
  
  while ((c = getchar()) != EOF) {
    
    if (isdigit(c)) {
      int digit = c - '0';
      if (first == -1) {
        first = digit;
      }
      last = digit;
    } else if (isalpha(c)) {
      ungetc(c, stdin);
      int digit = -1;
      if (check("one")) {
        digit = 1;
      } else if (check("two")) {
        digit = 2;
      } else if (check("three")) {
        digit = 3;
      } else if (check("four")) {
        digit = 4;
      } else if (check("five")) {
        digit = 5;
      } else if (check("six")) {
        digit = 6;
      } else if (check("seven")) {
        digit = 7;
      } else if (check("eight")) {
        digit = 8;
      } else if (check("nine")) {
        digit = 9;
      }
      
      
      if (digit != -1) {
        if (first == -1) {
          first = digit;
        }
        last = digit;
      }
      
      c = getchar();
      
      
    } else if (c == '\n') {
      if (first != -1 && last != -1) {
        int value = 10*first + last;
        sum += value;
      }
      first = -1;
      last = -1;
    }
  }    

  printf("%d\n", sum);
  
  return 0;
}
