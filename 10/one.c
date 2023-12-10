#include <stdio.h>

#define N 140


int main(void) {
  
  char grid[N][N];
  int cw[N][N];
  int ccw[N][N];
  int dst[N][N];
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
      cw[i][j] = 0;
      ccw[i][j] = 0;
      dst[i][j] = 0;
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
//  printf("%d %d\n", i0, j0);

  
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
    
    cw[i][j] = ++distance;
      
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
      cw[i][j] = 0;
      break;
    } else {
      printf("wrong pipe\n");
    }

  } while (i != i0 || j != j0);
  

  
  
  // cointer clockwise
  distance = 0;
  i = i0;
  j = j0;
  dir = left;
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
    
    ccw[i][j] = ++distance;
      
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
      ccw[i][j] = 0;
      break;
    } else {
      printf("wrong pipe\n");
    }
  } while (i != i0 || j != j0);
  
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      dst[i][j] = (ccw[i][j] < cw[i][j]) ? ccw[i][j] : cw[i][j];  
    }
  }
  
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", cw[i][j] % 10);
    }
    printf("\n");
  }
  printf("\n");

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", ccw[i][j] % 10);
    }
    printf("\n");
  }  
  printf("\n");
  
  int farthest = 0;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      printf("%d", dst[i][j] % 10);
      if (dst[i][j] > farthest) {
        farthest = dst[i][j];
      }
    }
    printf("\n");
  }
  
  printf("%d\n", farthest);

  return 0;
}
