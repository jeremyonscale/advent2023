#include <iostream>
#include <sstream>
#include <vector>

int main(void) {

  int result = 0;
  std::string line;
  while (std::getline(std::cin, line)) {
    std::vector<std::vector<int>> data;
    data.push_back({});
    
    // add a placeholder for the extrapolated number
    data[0].push_back(0);
    std::istringstream iss(line);
    int n;
    while (iss >> n) {
      data[0].push_back(n);  
    }
    
    for (int j = 1; j < data[0].size(); j++) {
      std::cout << data[0][j] << " ";
    }
    std::cout << std::endl;
  
    bool done = false;
    int i = 0;
    while (done == false) {
      data.push_back(std::vector<int>());
      // add a placeholder
      data[i++].push_back(0);
      done = true;
      for (int j = 0; j < data[i-1].size()-2; j++) {
//        std::cout << data[i-1][j+1] << "-" << data[i-1][j] << std::endl;  
        int derivative = data[i-1][j+1] - data[i-1][j];
        data[i].push_back(derivative);
        done &= (derivative == 0);
      }
    
      for (int j = 1; j < data[i].size(); j++) {
        std::cout << data[i][j] << " ";
      }   
      std::cout << std::endl;
    }

    std::cout << std::endl;
    
    // go up and extrapolate
    for (i = data.size()-2; i >= 0; i--) {
      data[i][0] = data[i+1][0] + data[i][1];  
    
      for (int j = 0; j < data[i].size(); j++) {
        std::cout << data[i][j] << " ";
      }   
      std::cout << std::endl;
    }
  
    result += data[0][0];
  }

  std::cout << result << std::endl;
  
  return 0;  
    
}
