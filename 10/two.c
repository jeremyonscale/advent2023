#include <stdio.h>

#define N 140


int main(void) {
  
  char grid[N][N];
  int loop[N][N];
  int i0 = -1;
  int j0 = -1;
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int c = getchar();
      grid[i][j] = c;
      if (grid[i][j] == 'S') {
        i0 = i;
        j0 = j;
      }
      loop[i][j] = 0;
    }
    if (getchar() != '\n') {
      printf("wrong N");
      return 1;
    }
  }


  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c", grid[i][j]);
  }
    printf("\n");
  }

  
  enum direction {none, right, down, left, up};

  // clockwise
  int distance = 0;
  int i = i0;
  int j = j0;
  enum direction dir = right;
  do {
    if (dir == left) {
      j--;
    } else if (dir == right) {
      j++;
    } else if (dir == up) {
      i--;
    } else if (dir == down) {
      i++;
    }    
    
    loop[i][j] = 1;
      
    if (grid[i][j] == '-') {
      if (dir == right) {
        dir = right;
      } else if (dir == left) {
        dir = left;
      } else {
        printf("wrong pipe\n");
      }
    } else if (grid[i][j] == '|') {
      if (dir == up) {
        dir = up;
      } else if (dir == down) {
        dir = down;
      } else {
        printf("wrong pipe\n");
      }
    } else if (grid[i][j] == '7') {
      if (dir == right) {
        dir = down;
      } else if (dir == up) {
        dir = left;
      } else {
        printf("wrong pipe\n");
      }
    } else if (grid[i][j] == 'J') {
      if (dir == right) {
        dir = up;
      } else if (dir == down) {
        dir = left;
      } else {
        printf("wrong pipe\n");
      }
    } else if (grid[i][j] == 'L') {
      if (dir == left) {
        dir = up;
      } else if (dir == down) {
        dir = right;
      } else {
        printf("wrong pipe\n");
      }
    } else if (grid[i][j] == 'F') {
      if (dir == left) {
        dir = down;
      } else if (dir == up) {
        dir = right;
      } else {
        printf("wrong pipe\n");
      }
    } else if (grid[i][j] == 'S') {
      loop[i][j] = 1;
      break;
    } else {
      printf("wrong pipe\n");
    }

  } while (i != i0 || j != j0);
  

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%c", loop[i][j] ? '*' : ' ');
    }
    printf("\n");
  }
  printf("\n");
  
  
  int inside = 0;
  for (int i = 0; i < N; i++) {
    int crosses = 0;
    for (int j = 0; j < N; j++) {
      if (loop[i][j]) {
        crosses++;
      } else {
        if (crosses % 2 == 1) {
          inside++;
        }
      }
    }
  }
  printf("%d\n", inside);

  return 0;
}
