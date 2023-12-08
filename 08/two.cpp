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

/*  
  for (size_t i = 0; i < instructions.size(); i++) {
    std::cout << instructions[i] << std::endl;
  }
*/
  
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
    
//    std::cout << key << " " << left.substr(1, 3) << " " << right.substr(0, 3) << std::endl;
  }

/*  
  for (auto &node : nodes) {
    std::cout << node.first << " " << node.second.first << " " << node.second.second << std::endl;  
  }
*/
  
  std::list<std::string> current;
  for (auto &node : nodes) {
    if (node.first[2] == 'A') {
      current.push_back(node.first);
    }  
  }
  
  bool done = true;
  size_t i = 0;
  size_t steps = 0;
  do {
  
/*      
    for (auto &c : current) {
      std::cout << c << " ";
    }  
    std::cout << " -> ";
*/
    
    for (auto &c : current) {
      c = (instructions[(steps % instructions.size())] == 0) ? nodes[c].first : nodes[c].second;
    }
    steps++;
    
/*    
    for (auto &c : current) {
      std::cout << c << " ";
    }  
    std::cout << std::endl;
*/
    
    done = true;
    for (auto &c : current) {
      done &= (c[2] == 'Z');
    }  
    
    
  } while (!done);
  
  std::cout << steps << std::endl;
  
  return 0;
}
