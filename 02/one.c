#include <stdio.h>
#include <string.h>

int main(void) {

  int sum = 0;
  int game_id = 0;
  while (scanf("Game %d:", &game_id) == 1) {
//    printf("%d\n", game_id);
    
    int possible = 1;
    char color[64];
    int n = 0;
    while (scanf("%d %s", &n, &color) == 2) { 
      char *sep = strchr(color, ',') != NULL ? strchr(color, ',') : strchr(color, ';');
      if (sep != NULL) {
        *sep = '\0';
      }
      possible &= (strcmp(color, "red") == 0 && n <= 12) ||
                  (strcmp(color, "green") == 0 && n <= 13) ||
                  (strcmp(color, "blue") == 0 && n <= 14);
//      printf("%d %s %d\n", n, color, possible);
    }
//    printf("%d %d\n", game_id, possible);
    sum += possible * game_id;
  }
  printf("%d\n", sum);

  return 0;
}
