#include <iostream>
#include <vector>
#include <list>
#include <set>

std::vector<std::vector<char>> grid;
  
enum Dir {right, left, down, up};
struct init {
  int i;
  int j;
  Dir direction; 
};



#define set_hash(i,j,direction) (direction + 1000*j + 1000*1000*i)

#define GREEN  "\033[31;42m"
#define BLUE   "\033[30;41m"
#define BOLDOFF "\033[0m"


bool is_init(std::set<int> &inits_set, int i, int j, Dir direction) {
  return (inits_set.find(set_hash(i,j,direction)) != inits_set.end());
}


int run(int i0, int j0, Dir direction0) {
    
  std::set<int> inits_set;  
  std::list<struct init> inits_list;
  inits_list.push_back({i0,j0,direction0});
  inits_set.insert(set_hash(i0,j0,direction0));
  
  std::set<std::pair<int,int>> energized;
  size_t breaker_limit = 10 * grid.size() * grid[0].size();
  
  for (auto &init : inits_list) {
    int i = init.i;
    int j = init.j;
    Dir direction = init.direction;
    bool first = true;
    size_t breaker = 0;
    while (i >= 0 && i < grid.size() && j >= 0 && j < grid[0].size() && (first || is_init(inits_set, i, j, direction) == false) && breaker++ < breaker_limit) {
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
        if (is_init(inits_set, i, j, right) == false) {
          inits_list.push_back({i,j,right});
          inits_set.insert(set_hash(i,j,right));
        }
      } else if (grid[i][j] == '|' && (direction == left || direction == right)) {
        direction = up;
        if (is_init(inits_set, i, j, down) == false) {
          inits_list.push_back({i,j,down});
          inits_set.insert(set_hash(i,j,down));
        }
      }
        
      j += (direction == right) - (direction == left);
      i += (direction == down) - (direction == up);

    }
  }
  
  return energized.size();     

}


int main(void) {
  
  std::string s;
  while (std::cin >> s) {
    std::vector<char> row;
    
    for (size_t i = 0; i < s.length(); i++) {
      row.push_back(s[i]);
    }
    grid.push_back(row);
  }
  
  int current = 0;
  int max = 0;
  for (int i = 0; i < grid.size(); i++) {
    current = run(i,0,right);
    if (current > max) {
      max = current;  
    }
    std::cout << i << "right" << std::endl;
    current = run(i,grid[0].size()-1,left);
    if (current > max) {
      max = current;  
    }
    std::cout << i << "left" << std::endl;
  }

  for (int j = 0; j < grid[0].size(); j++) {
    current = run(0,j,down);
    if (current > max) {
      max = current;  
    }
    std::cout << j << "down" << std::endl;
   
    current = run(grid.size()-1,j,up);
    if (current > max) {
      max = current;  
    }
    std::cout << j << "up" << std::endl;
  }
  
  std::cout << max << std::endl;

  return 0;
}
