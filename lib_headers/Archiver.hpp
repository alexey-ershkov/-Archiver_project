//
// Created by perturabo on 15.11.2019.
//

#ifndef _ARCHIVER_HPP_
#define _ARCHIVER_HPP_

#include "TypeIdentifier.hpp"
#include "Output.h"
#include "Input.h"
#include "ArchiveFile.hpp"

class Archiver{
 public:
  static std::vector<Entry> Read(const std::string& path_to_archive, std::string name);
  static std::map<std::string, std::string> Unpack(const std::string& path_to_archive, std::string name);
  static std::string Pack(const std::map<std::string, std::string>& compressed_data, std::string name);
};

#endif //_ARCHIVER_HPP_
