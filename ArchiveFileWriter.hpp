//
// Created by perturabo on 07.12.2019.
//

#ifndef _ARCHIVEFILEWRITER_HPP_
#define _ARCHIVEFILEWRITER_HPP_

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

class ArchiveFileWriter : private Output{
 private:
  std::string filepath;
  std::ofstream fout;
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
  explicit ArchiveFileWriter (const std::string& filepath);
  unsigned long int CreateEntrySystem(const std::map<std::string, std::string>& compressed_data);
  std::vector<Entry> ViewArchive(){ return internal_system;};

  void WriteFile (const std::string& path);

  void CloseOutput();
  void OpenOutput();

  static size_t GetPointer (const std::string &in);
  static size_t GetInputFileSize(Input *in);
};


#endif //_ARCHIVEFILEWRITER_HPP_
