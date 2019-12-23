//
// Created by perturabo on 15.11.2019.
//

#ifndef _ARCHIVER_HPP_
#define _ARCHIVER_HPP_

#include <utility>

#include "TypeIdentifier.hpp"
#include "Output.h"
#include "Input.h"
#include "ArchiveFileWriter.hpp"

class Archiver{
 private:
  unsigned long int content_start;
  std::string path_to_archive;

 public:
  explicit Archiver(std::string b): path_to_archive(std::move(b)){};
  ~Archiver() = default;
  std::vector<Entry> Read();
  std::string Pack(const std::map<std::string, std::string>& compressed_data, std::string path,  const std::string& name);
  std::map<std::string, std::string> Unpack (const std::vector<Entry>& EntrySystem);
  static std::pair<std::string, std::string> UnpackSingle(const std::vector<Entry>& EntrySystem, std::string name);
  std::string CutABinary(Entry &entry, unsigned long int name_binary);
};

#endif //_ARCHIVER_HPP_
