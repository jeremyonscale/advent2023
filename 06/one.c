#include <stdio.h>


int main(void) {

// example
#define N 3
  int time[N] = {7, 15, 30};
  int distance[N] = {9, 40, 200};

// input
/*  
#define N 4
  int time[N] = {60, 94, 78, 82};
  int distance[N] = {475, 2138, 1015, 1650};
*/
  

  int product = 1;
  for (int i = 0; i < N; i++) {
    int ways = 0;
    for (int n = 0; n < time[i]; n++) {
      ways += (n*(time[i]-n) > distance[i]);
    }
    product *= ways;
  }
  
  printf("%d\n", product);
}
    
      
