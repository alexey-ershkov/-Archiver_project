//
// Created by perturabo on 07.12.2019.
//

#include "Archiver.hpp"

int main(int argc, char** argv){
  std::map<std::string, std::string> input_data;
  //input_data.insert(std::pair(std::string("c1.elf"), std::string("c_onefiles")));
  input_data.insert(std::pair(std::string("onefiles"), std::string("c_onefile")));
  input_data.insert(std::pair(std::string("Archiver.bin"), std::string("Archiver.cbp")));
  input_data.insert(std::pair(std::string("Диффуры.pdf"), std::string("iidu.pdf")));
  input_data.insert(std::pair(std::string("Пикча.???"), std::string("4LsNWkt2NLY.jpg")));
  //input_data.insert(std::pair(std::string("OOP.docx"), std::string("OOP_-_Final.docx")));

  Archiver a("newarchive");

  a.Pack(input_data, "", "newarchive");
  auto FS = a.Read();
  a.Unpack (FS);
 // std::printf("\n");
  return 0;
}

//std::invalid_argument