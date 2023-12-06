#include <stdio.h>


int main(void) {
  int time = 71530;
  int distance = 940200;
/*
  size_t time = 60947882;
  size_t distance = 475213810151650;
*/
 
  int ways = 0;
  for (size_t n = 0; n < time; n++) {
    ways += (n*(time-n) > distance);
  }
  
  printf("%d\n", ways);
}
    
      
