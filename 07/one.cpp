#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

struct hand_t {
  char s[16];
  int cards[5];
  int bid;
  int score;
};

int main(void) {

  std::vector<hand_t> hands;

  struct hand_t hand;
  while (scanf("%s %d\n", &hand.s, &hand.bid) == 2) {
//    std::cout << hand.s << " " << hand.bid << std::endl;
    
    for (int i = 0; i < 5; i++) {
      if (hand.s[i] == 'A') {
        hand.cards[i] = 14;
      } else if (hand.s[i] == 'K') {
        hand.cards[i] = 13;
      } else if (hand.s[i] == 'Q') {
        hand.cards[i] = 12;
      } else if (hand.s[i] == 'J') {
        hand.cards[i] = 11;
      } else if (hand.s[i] == 'T') {
        hand.cards[i] = 10;
      } else {
        hand.cards[i] = hand.s[i] - '0';  
      }
    }
    
    std::map<int, int> counts;
    for (int i = 0; i < 5; i++) {
//      std::cout << hand.cards[i] << " ";  
      counts[hand.cards[i]]++;
    }
//    std::cout << std::endl;
    
    int equal_cards1 = 0;
    int equal_cards2 = 0;
    for (int i = 2; i <= 14; i++) {
      if (counts.find(i) != counts.end()) {
        if (counts[i] >= equal_cards1) {
          equal_cards2 = equal_cards1;
          equal_cards1 = counts[i];
        } else if (counts[i] >= equal_cards2) {
          equal_cards2 = counts[i];
        }
      }
    }
//    std::cout << equal_cards1 << " " << equal_cards2 << std::endl;
    
    if (equal_cards1 == 5) {
      // five of a kind  
      hand.score = 6;
    } else if (equal_cards1 == 4) {
      // four of a kind  
      hand.score = 5;
    } else if (equal_cards1 == 3 && equal_cards2 == 2) {
      // full house
      hand.score = 4;
    } else if (equal_cards1 == 3) {
      // three of a kind
      hand.score = 3;
    } else if (equal_cards1 == 2 && equal_cards2 == 2) {
      // two pairs
      hand.score = 2;
    } else if (equal_cards1 == 2) {
      // one pair
      hand.score = 1;
    } else {
      hand.score = 0;
    }
    
    hands.push_back(hand);
  }

  std::sort(hands.begin(), hands.end(),
    [](hand_t a, hand_t b) {
      if (a.score != b.score) {
        return (a.score < b.score);
        
      } else if (a.cards[0] != b.cards[0]) {
        return (a.cards[0] < b.cards[0]);
        
      } else if (a.cards[1] != b.cards[1]) {
        return (a.cards[1] < b.cards[1]);
        
      } else if (a.cards[2] != b.cards[2]) {
        return (a.cards[2] < b.cards[2]);
        
      } else if (a.cards[3] != b.cards[3]) {
        return (a.cards[3] < b.cards[3]);
        
      } else {
        return (a.cards[4] < b.cards[4]);
      }
    });  

  int winnings = 0;  
  for (int i = 0; i < hands.size(); i++) {
//    std::cout << i+1 << " " << hands[i].s << " " << hands[i].score << " " << hands[i].bid << std::endl;
    winnings += (i+1)*hands[i].bid;  
  }
  std::cout << winnings << std::endl;
    
  
  
  return 0;
}
