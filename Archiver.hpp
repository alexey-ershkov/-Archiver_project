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
  unsigned long int content_start = 0;
  std::string path_to_archive;

 public:
  explicit Archiver(std::string b): path_to_archive(std::move(b)){};
  ~Archiver() = default;
  std::vector<Entry> Read();
  std::string Pack(const std::map<std::string, std::string>& compressed_data, std::string path,  const std::string& name);
  std::map<std::string, std::string> Unpack (const std::vector<Entry>& EntrySystem);
  std::string CutABinary(Entry &entry, unsigned long int name_binary);
  std::pair<std::string, std::string> UnpackSingle(Entry entry, const std::string& name);
  static void CleanUp(const std::vector<std::string>& binaries);
  static void CleanUpSingle(const std::string& binary);
};

#endif //_ARCHIVER_HPP_
