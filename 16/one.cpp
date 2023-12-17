#include <iostream>
#include <vector>
#include <list>
#include <set>

enum Dir {right, left, down, up};
struct init {
  int i;
  int j;
  Dir direction; 
};

std::set<int> inits_set;

#define set_hash(i,j,direction) (direction + 1000*j + 1000*1000*i)

#define GREEN  "\033[31;42m"
#define BLUE   "\033[30;41m"
#define BOLDOFF "\033[0m"


bool is_init(int i, int j, Dir direction) {
  return (inits_set.find(set_hash(i,j,direction)) != inits_set.end());
}


int main(void) {
  
  std::vector<std::vector<char>> grid;
  
  std::string s;
  while (std::cin >> s) {
    std::vector<char> row;
    
    for (size_t i = 0; i < s.length(); i++) {
      row.push_back(s[i]);
    }
    grid.push_back(row);
  }
  
  for (size_t i = 0; i < grid.size(); i++) {
    for (size_t j = 0; j < grid[i].size(); j++) {
      printf("%c", grid[i][j]);
    }
    printf("\n");
  }
  
  std::list<struct init> inits_list;
  inits_list.push_back({0,0,right});
  inits_set.insert(set_hash(0,0,right));
  
  std::set<std::pair<int,int>> energized;
  size_t breaker_limit = 10 * grid.size() * grid[0].size();
  
  for (auto &init : inits_list) {
    int i = init.i;
    int j = init.j;
    Dir direction = init.direction;
    bool first = true;
    size_t breaker = 0;
    while (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && (first || is_init(i, j, direction) == false) && breaker++ < breaker_limit) {
      first = false;
      energized.insert({i,j});
      if (grid[i][j] == '\\') {
        switch (direction) {
          case right: direction = down; break;
          case left:  direction = up; break;
          case down:  direction = right; break;
          case up:    direction = left; break;
        }
      } else if (grid[i][j] == '/') {
        switch (direction) {
          case right: direction = up; break;
          case left:  direction = down; break;
          case down:  direction = left; break;
          case up:    direction = right; break;
        }
      } else if (grid[i][j] == '-' && (direction == up || direction == down)) {
        direction = left;
        if (is_init(i, j, right) == false) {
          inits_list.push_back({i,j,right});
          inits_set.insert(set_hash(i,j,right));
          std::cout << "splitting "<< i << " " << j << " " << right << std::endl;
        }
      } else if (grid[i][j] == '|' && (direction == left || direction == right)) {
        direction = up;
        if (is_init(i, j, down) == false) {
          inits_list.push_back({i,j,down});
          inits_set.insert(set_hash(i,j,down));
          std::cout << "splitting "<< i << " " << j << " " << down << std::endl;
        }
      }
        
      j += (direction == right) - (direction == left);
      i += (direction == down) - (direction == up);

    }
  }

  printf("\n");
  for (int i = 0; i < grid.size(); i++) {
    for (int j = 0; j < grid[i].size(); j++) {
      if (is_init(i,j,left) || is_init(i,j,right) || is_init(i,j,up) || is_init(i,j,down)) {
        printf("%s%c%s", BLUE, grid[i][j], BOLDOFF);
      } else if (energized.find({i,j}) != energized.end()) {
        printf("%s%c%s", GREEN, grid[i][j], BOLDOFF);
      } else {
        printf("%c", grid[i][j]);
      } 
    }
    printf("\n");
  }
  
  std::cout << energized.size() << std::endl;     
  return 0;
}
