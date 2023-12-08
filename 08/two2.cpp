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
  size_t step = 0;
  size_t instructions_size  = instructions.size();
  do {
/*  
    for (auto &c : current) {
      std::cout << c << " ";
    }  
    std::cout << " -> ";
*/
    
    done = true;
    if (instructions[i++] == 0) {
      for (auto &c : current) {
        c = nodes[c].first;
        done &= (c[2] == 'Z');
      }
    } else {
      for (auto &c : current) {
        c = nodes[c].second;
        done &= (c[2] == 'Z');
      }
    }
    if (i == instructions_size) {
      i = 0;
    }
    step++;
    if (step % 1000000 == 0) {
      std::cout << step << std::endl;
    }
/*    
    for (auto &c : current) {
      std::cout << c << " ";
    }  
    std::cout << std::endl;
*/
    
  } while (!done);
  
  std::cout << step << std::endl;
  
  return 0;
}
