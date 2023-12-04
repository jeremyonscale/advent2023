#include <iostream>
#include <vector>
#include <set>

int main(void) {
  
  std::vector<std::set<int>> winning_numbers;
  std::vector<std::vector<int>> cards;
  std::vector<int> copies;
  
  std::string s;
  std::cin >> s;
  if (s != "Card") {
    std::cerr << "error reading card" << std::endl;
    return -1;
  }
    
  while (std::cin.eof() == false) {
    
    std::cin >> s;
    std::set<int> card;
    do {
      std::cin >> s;
      if (s != "|") {
        card.insert(std::stoi(s));
      }
    } while (s != "|");
    winning_numbers.push_back(card);
    
    
    std::vector<int> number;
    do {
      std::cin >> s;
      if (s != "Card" && std::cin.eof() == false) {
        number.push_back(std::stoi(s));
      }
    } while (s != "Card" && std::cin.eof() == false);
    cards.push_back(number);
    copies.push_back(1);
  }
    
   for (size_t i = 0; i < cards.size(); i++) {
//    std::cout << "card " << i+1 << " has " << winning_numbers[i].size() << " numbers " << std::endl;
    int number_of_matching_numbers = 0;
    for (size_t j = 0; j < cards[i].size(); j++) {
      number_of_matching_numbers += (winning_numbers[i].find(cards[i][j]) != winning_numbers[i].end());
    }
//    std::cout << "card " << i+1 << " has " << number_of_matching_numbers << " matching numbers " << std::endl;
    for (size_t k = i+1; k < i+number_of_matching_numbers+1; k++) {
//      std::cout << "win " << k+1 << std::endl;
      copies[k] += copies[i];
    }
  }

  int total = 0;
  for (size_t i = 0; i < cards.size(); i++) {
//    std::cout << "card " << i+1 << " has " << copies[i] << " copies " << std::endl;
    total += copies[i];
  }
  
  std::cout << total << std::endl;

  
  return 0;
}
