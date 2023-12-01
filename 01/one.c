#include <stdio.h>
#include <ctype.h>

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
    } else if (c == '\n') {
      int value = 10*first + last;
      sum += value;
      first = -1;
      last = -1;
    }
  }    

  printf("%d\n", sum);
  
  return 0;
}
