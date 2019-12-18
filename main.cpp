//
// Created by perturabo on 07.12.2019.
//

#include "Archiver.hpp"

int main(int argc, char** argv){
  std::map<std::string, std::string> input_data;
  input_data.insert(std::pair(std::string("c1.elf"), std::string("c_onefiles")));
  input_data.insert(std::pair(std::string("c2.elf"), std::string("c_onefile")));
  input_data.insert(std::pair(std::string("Makefile"), std::string("Makefile")));
  input_data.insert(std::pair(std::string("Archiver.bin"), std::string("Archiver")));


  Archiver::Pack(input_data);

  return 0;
}