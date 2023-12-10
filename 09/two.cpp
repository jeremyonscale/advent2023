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

    bool done = false;
    int i = 0;
    while (done == false) {
      data.push_back(std::vector<int>());
      // add a placeholder
      i++;
      data[i].push_back(0);
      done = true;
      for (int j = 1; j < data[i-1].size()-1; j++) {
        int derivative = data[i-1][j+1] - data[i-1][j];
        data[i].push_back(derivative);
        done &= (derivative == 0);
      }
    }

    // go up and extrapolate
    for (i = data.size()-2; i >= 0; i--) {
      data[i][0] = -data[i+1][0] + data[i][1];  
    }
  
    result += data[0][0];
  }

  std::cout << result << std::endl;
  
  return 0;  
    
}
