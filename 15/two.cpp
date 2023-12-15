#include <stdio.h>
#include <string.h>
#include <vector>
#include <list>
#include <iostream>

int hash(char *s) {
  
  int h = 0;
  for (int i = 0; i < strlen(s); i++) {
    h += s[i];
    h *= 17;
    h %= 256;
  }
  
  return h;
  
}

void list_set(std::list<std::pair<std::string, int>> &list, std::string key, int value) {

  for (auto &item : list) {
    if (item.first == key) {
      item.second = value;
      return;
    }
  }
  
  list.push_back({key, value});
    
}

void list_remove(std::list<std::pair<std::string, int>> &list, std::string key) {

  for (auto it = list.begin(); it != list.end(); ++it) {
    if (it->first == key) {
      list.erase(it);
      return;
    }
  }
}


int main(void) {

  std::vector<std::list<std::pair<std::string, int>>> boxes(256);
  char instruction[256];
  while (!feof(stdin)) {
    int i = 0;
    int c = 0;
    while ((c = getchar()) != ',' && c != '\n' && c != EOF) {
      instruction[i++] = c;
    }
    instruction[i] = '\0';
    
    
    for (int i = 0; i < strlen(instruction); i++) {
      if (instruction[i] == '=') {
        instruction[i] = '\0';
        int box = hash(instruction);
        int focal_length = atoi(&instruction[i+1]);
        std::cout << "inserted " << instruction << " " << focal_length << " into box " << box << std::endl;
        list_set(boxes[box], instruction, focal_length);
      } else if (instruction[i] == '-') {
        instruction[i] = '\0';
        int box = hash(instruction);
        int focal_length = atoi(&instruction[i+1]);
        std::cout << "removing " << instruction << " from box " << box << std::endl;
        list_remove(boxes[box], instruction);
      }
    }
  }

  int power = 0;
  for (int box = 0; box < boxes.size(); box++) {
    if (boxes[box].size() > 0) {
      std::cout << "box " << box << std::endl;
      int j = 0;
      for (auto &lens : boxes[box]) {
        std::cout << lens.first << " " << lens.second << std::endl;
        power += (box+1)*((++j) * lens.second);
      }
    }
  }
  
  std::cout << power << std::endl;
  
  return 0;
}
