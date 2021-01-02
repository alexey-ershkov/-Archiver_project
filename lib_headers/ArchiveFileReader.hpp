//
// Created by perturabo on 21.12.2019.
//

#ifndef _ARCHIVEFILEREADER_HPP_
#define _ARCHIVEFILEREADER_HPP_

#include "ArchiveFileWriter.hpp"
#include "Input.h"

class ArchiveFileReader: public Input {
 private:
  std::string filepath;
  std::ofstream fin;
  size_t content_start;
  std::vector<Entry> internal_system;

 public:
  explicit ArchiveFileReader (std::string path_to_archive);
  void CloseInput ();
  void OpenInput ();
  void CheckSignature (); //todo replace with CheckSignature
  static size_t GetPointer (const std::string &in);
  bool GetEntry (Entry &entry);
  std::string GetLine ();
  void SkipTo(size_t start_pointer);
};

#endif //_ARCHIVEFILEREADER_HPP_
