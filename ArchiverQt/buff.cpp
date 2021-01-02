//
// Created by perturabo on 15.12.2019.
//

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>

// 8 bytes. AAAA AAAA AAAA AAAA.
// 1111000011110000111100001111000011110000111100001111000011110000
int main(){
  int a = 199;
  std::cout << std::setw(16) << std::hex << a;
  return 0;
}



