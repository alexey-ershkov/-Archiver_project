//
// Created by perturabo on 15.11.2019.
//

#ifndef _ARCHIVER_HPP_
#define _ARCHIVER_HPP_

#include "TypeIdentifier.hpp"

class Archiver{
 public:
  std::map<std::string, std::string> Read(std::string path_to_archive);
  std::map<std::string, std::string> Unpack(std::string path_to_archive);
  std::string Pack(std::map<std::string, std::string> compressed_data);

};

#endif //_ARCHIVER_HPP_
