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
 private:
  unsigned long int content_start;
 public:
  std::vector<Entry> Read(const std::string& path_to_archive);
  std::string Pack(const std::map<std::string, std::string>& compressed_data, std::string path_to_archive,  std::string name);
  static std::map<std::string, std::string> Unpack (const std::string &path_to_archive, const std::vector<Entry>& EntrySystem);
  static std::pair<std::string, std::string> UnpackSingle(const std::string &path_to_archive,
                                                          const std::vector<Entry>& EntrySystem, std::string name);
};

#endif //_ARCHIVER_HPP_
