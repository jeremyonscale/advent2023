#include <iostream>
#include <vector>
#include <map>

int main(void) {
  
  std::string s;
  std::cin >> s;
//  std::cout << s;
  
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
  
  // start in AAA
  std::string current = "AAA";
  size_t i = 0;
  size_t steps = 0;
  do {
    std::cout << current << " -> ";
    current = (instructions[(steps++ % instructions.size())] == 0) ? nodes[current].first : nodes[current].second;
    std::cout << current << std::endl;
  } while (current != "ZZZ");
  
  std::cout << steps << std::endl;
  
  return 0;
}
