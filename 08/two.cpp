#include <iostream>
#include <vector>
#include <list>
#include <map>

int main(void) {
  
  std::string s;
  std::cin >> s;
  
  std::vector<int> instructions;
  for (size_t i = 0; i < s.length(); i++) {
    instructions.push_back(s[i] == 'R');
  }
  
  std::map<std::string, std::pair<std::string, std::string>> nodes;
  
  while (std::cin.eof() == false) {
    std::string key, equal, left, right;
    std::cin >> key;
    std::cin >> equal;
    std::cin >> left;
    std::cin >> right;
    if (key.length() != 3) {
      continue;
    }
    
    nodes.insert({key, {left.substr(1, 3), right.substr(0, 3)}});
  }

  std::list<std::string> current;
  for (auto &node : nodes) {
    if (node.first[2] == 'A') {
      current.push_back(node.first);
    }  
  }
  
  // make a loop with each guy and see what happens
  for (auto &c : current) {
    size_t step = 0;  
    auto first = c;
    do {
      c = (instructions[(step++ % instructions.size())] == 0) ? nodes[c].first : nodes[c].second;
      if (c[2] == 'Z') {
        std::cout << first << " " << step << std::endl;
        break;
      }
    } while (c != first);
  }
  
  return 0;
}
