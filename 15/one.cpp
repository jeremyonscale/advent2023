#include <stdio.h>
#include <string.h>

int hash(char *s) {
  
  int h = 0;
  for (int i = 0; i < strlen(s); i++) {
    h += s[i];
    h *= 17;
    h %= 256;
  }
  
  return h;
  
}

int main(void) {

  int total = 0;
  char instruction[256];
  while (!feof(stdin)) {
    int i = 0;
    int c = 0;
    while ((c = getchar()) != ',' && c != EOF) {
      instruction[i++] = c;
    }
    instruction[i] = '\0';
    
    int h = hash(instruction);
    total += h;
    
    printf("%s %d %d\n", instruction, h, total);
    
  }
  
  return 0;
}
