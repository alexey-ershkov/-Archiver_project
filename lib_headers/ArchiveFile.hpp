//
// Created by perturabo on 07.12.2019.
//

#ifndef _ARCHIVEFILE_HPP_
#define _ARCHIVEFILE_HPP_

#include <vector>
#include <map>
#include "Output.h"
#include "Input.h"
#include "TypeIdentifier.hpp"

typedef struct _entry{
  std::string name;
  std::string type;

  size_t start;
  size_t end;

  std::string bin_name; // not stored in the archive, needed only to create the archive
} Entry;

class ArchiveFile : private Output, Input{
 private:
  std::string filepath;
  std::ofstream fout;
  std::ifstream fin;
  size_t size = 0;
  size_t content_start;
  std::vector<Entry> internal_system;

  void WriteEntrySeparator ();
  void WriteString (const std::string& s);
  void WriteSignature ();
  void WritePointer (unsigned int input_string);
  void WriteEndOfES ();

  static std::string makeString (const std::string &in);

 public:    //todo This class is suspiciously large. Maybe it should be refactored
  explicit ArchiveFile (std::string path,  char mode);

  unsigned long int CreateEntrySystem(const std::map<std::string, std::string>& compressed_data);
  std::vector<Entry> ViewArchive(){ return internal_system;};

  void WriteFile (const std::string& path);

  void CloseOutput();
  void CloseInput();

  void OpenOutput();
  void OpenInput();

  static size_t GetPointer (const std::string &in);
  static size_t GetInputFileSize(Input *in);
  bool GetEntry(Entry &entry);
  std::string GetLine();
  void SkipSignature();

};


#endif //_ARCHIVEFILE_HPP_
