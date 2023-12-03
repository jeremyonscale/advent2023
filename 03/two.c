#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_I  256
#define MAX_J  256

char schematic[MAX_I][MAX_J];
int parts[9];
int idx = 0;

int read_number(int i, int j) {
  if ((i >= 0) && (j >= 0) && isdigit(schematic[i][j])) {
    int initial_j = j;
    while (isdigit(schematic[i][initial_j])) {
      initial_j--;
    }
    int number = -1;
    sscanf(&schematic[i][initial_j+1], "%d", &number);
    parts[idx++] = number;
    // printf("found a number %d attached to it at %d, %d\n", number, i, j);
    return 1;
  } 
  return 0;
}

int main(void) {
  
  memset(schematic, 0, sizeof(char)*MAX_I*MAX_J);
  
  int i = 0;
  int j = 0;
  int c = 0;
  while ((c = getchar()) != EOF) {
    if (c == '\n') {
      i++;
      j = 0;
    } else {
      schematic[i][j++] = c;
    }
    // printf("%c", c);
  }

  int sum = 0;
  for (i = 0; i < MAX_J; i++) {
    if (schematic[i][0] != '\0') {
      for (j = 0; j < MAX_J; j++) {
        if (schematic[i][j] == '*') {
          // printf("found candidate at %d, %d\n", i, j);
          memset(parts, 0, sizeof(int)*9);
          idx = 0;
          
          if (read_number(i-1, j-1) == 0 || schematic[i-1][j] == '.') {
            if (read_number(i-1, j) == 0) {
              read_number(i-1, j+1);     
            }
          }
          
          read_number(i, j-1);
          read_number(i, j+1);

          if (read_number(i+1, j-1) == 0 || schematic[i+1][j] == '.') {
            if (read_number(i+1, j) == 0) {
              read_number(i+1, j+1);     
            }
          }
          
          if (idx == 2) {
            // printf("found GEAR %d at %d, %d\n", parts[0] * parts[1], i, j);
            sum += parts[0] * parts[1];
          }
        }
      }  
        
              
      // printf("%s\n", schematic[i]);
    }
  }
  
  printf("%d\n", sum);
  
 /*   
  for (i = 0; i < MAX_J; i++) {
    if (schematic[i][0] != '\0') {  
      printf("%s\n", schematic[i]);
    }
  }
 */
  
  return 0;
    
    
}
