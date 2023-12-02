#include <stdio.h>
#include <string.h>

#define RED   0
#define GREEN 1
#define BLUE  2

int main(void) {

  int sum = 0;
  int game_id = 0;
  while (scanf("Game %d:", &game_id) == 1) {
    char color[64];
    int n = 0;
    int min[3] = {0,0,0};
    while (scanf("%d %s", &n, &color) == 2) { 
      char *sep = strchr(color, ',') != NULL ? strchr(color, ',') : strchr(color, ';');
      if (sep != NULL) {
        *sep = '\0';
      }
      
      int index = (strcmp(color, "red") == 0) ? RED : (strcmp(color, "green") == 0) ? GREEN : BLUE;
      if (n > min[index]) {
        min[index] = n;
      }
    }
    sum += min[RED]*min[GREEN]*min[BLUE];
//    printf("%d %d %d %d\n", game_id, min[RED], min[GREEN], min[BLUE]);
    
  }
  printf("%d\n", sum);

  return 0;
}
