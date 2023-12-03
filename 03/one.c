#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_I  256
#define MAX_J  256

int main(void) {
  char schematic[MAX_I][MAX_J];
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
        if (isdigit(schematic[i][j])) {
          int number = -1;
          sscanf(&schematic[i][j], "%d", &number);
          int len = 0;
          int n = number;
          do {
            n /= 10;
            ++len;
          } while (n != 0);
          
          int is_part_number = 0;
          // check previous line
          // we're good without checking if j > 0 because if i > 0 then negative j are zeroes
          for (int jprime = j-1; jprime < j+len+1; jprime++) {
            is_part_number |= (i > 0) && (schematic[i-1][jprime] != '\0' && schematic[i-1][jprime] != '.');
          }
          // check following line
          for (int jprime = j-1; jprime < j+len+1; jprime++) {
            is_part_number |= (i < (MAX_I-1)) && (schematic[i+1][jprime] != '\0' && schematic[i+1][jprime] != '.');
          }
          // check previous/following chars
          is_part_number |= (j > 0)       && (schematic[i][j-1] != '\0' && schematic[i][j-1] != '.');    
          is_part_number |= (j < MAX_J-1) && (schematic[i][j+len] != '\0' && schematic[i][j+len] != '.');
          
//          printf("%d %d\n", number, is_part_number);
          sum += is_part_number * number;
          j += len-1;
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
