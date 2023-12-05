#include <iostream>
#include <algorithm>
#include <vector>
#include <list>

struct threesome {
  size_t dest_range_start;
  size_t source_range_start;
  size_t range_length;
};

int main(void) {
  
  // seeds
  std::vector<size_t> seeds;
  scanf("seeds:");
  int c = 0;
  while ((c = getchar()) != '\n') {
    ungetc(c, stdin);
    size_t seed;
    scanf("%ld", &seed);
    seeds.push_back(seed);
  }

/*  
  for (size_t i = 0; i < seeds.size(); i++) {
    std::cout << seeds[i] << std::endl;
  }
*/

  std::list<std::list<struct threesome>> maps;
  char dummy1[64], dummy2[64];  
  while (scanf("%s %s\n", &dummy1, &dummy2) == 2) {
    std::list<struct threesome> map;
    
    size_t dest_range_start = -1;
    size_t source_range_start = -1;
    size_t range_length = -1;
    
    while (scanf("%ld %ld %ld\n", &dest_range_start, &source_range_start, &range_length) == 3) {
      struct threesome thr;
      thr.dest_range_start = dest_range_start;
      thr.source_range_start = source_range_start;
      thr.range_length = range_length;
//      std::cout << thr.dest_range_start << " " << thr.source_range_start << " " << thr.range_length << std::endl;
      map.push_back(thr);
    }
    maps.push_back(map);
    
  }
  
  std::vector<size_t> locations;
  for (auto &seed : seeds) {
//    std::cout << "seed " << seed << std::endl;
    size_t n = seed;
    for (auto &map : maps) {
      size_t new_n = -1;
//      std::cout << "new map" << std::endl;  
//      std:: cout << n << " -> ";  
      for (auto &thr : map) {
//        std::cout << "new thr " << thr.source_range_start << " " << thr.dest_range_start << " " << thr.range_length  << std::endl;  
        if (n >= thr.source_range_start && n < (thr.source_range_start+thr.range_length)) {
          new_n = thr.dest_range_start + n-thr.source_range_start;
        }
      }
      if (new_n != -1) {
        n = new_n;
      }
//      std::cout << n << std::endl;
    }
//    std::cout << "location = " << n << std::endl;
    locations.push_back(n);
  }

  auto answer = std::min_element(locations.begin(), locations.end());
  std::cout << *answer << std::endl;

  
  return 0;
}
