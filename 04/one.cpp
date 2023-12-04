#include <iostream>
#include <set>

int main(void) {
  std::string s;
    
  std::cin >> s;
  if (s != "Card") {
    std::cerr << "error reading card" << std::endl;
    return -1;
  }
    
  int total = 0;
  while (std::cin.eof() == false) {
    
    std::cin >> s;
    int card_number = std::stoi(s);
    
    std::set<int> winning_numbers;
    do {
      std::cin >> s;
      if (s != "|") {
        winning_numbers.insert(std::stoi(s));
      }
    } while (s != "|");
    
    
    int worth = 0;
    do {
      int number_you_have = -1;
      
      std::cin >> s;
      if (s != "Card" && std::cin.eof() == false) {
          number_you_have = std::stoi(s);
      
        if (winning_numbers.find(number_you_have) != winning_numbers.end()) {
          if (worth == 0) {
            worth = 1;
          } else {
            worth *= 2;
          }
        }
      }
    } while (s != "Card" && std::cin.eof() == false);
    
    total += worth;
  }
    
  std::cout << total << std::endl;

  
  return 0;
}
