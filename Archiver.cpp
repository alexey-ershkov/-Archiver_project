//
// Created by perturabo on 15.11.2019.
//

#include "Archiver.hpp"
#include "ArchiveFileReader.hpp"

#include <utility>


std::string Archiver::Pack (const std::map<std::string, std::string>& compressed_data,std::string path,
    const std::string& name){
  path.append("/");
  path.append(name);
  path.append(".tprk");
  path_to_archive = path;
  ArchiveFileWriter archive (path_to_archive);

  content_start = archive.CreateEntrySystem(compressed_data);

  std::vector<Entry> EntrySystem = archive.ViewArchive ();

  for(auto& entry : EntrySystem){
    archive.WriteFile (entry.bin_name);
  }

  archive.CloseOutput ();
  return path_to_archive;
}


std::vector<Entry> Archiver::Read (){
  ArchiveFileReader archive(path_to_archive);

  std::vector<Entry> EntrySystem;
  Entry entry_iter;
  unsigned long int entry_system_length = ArchiveFileWriter::GetPointer (archive.GetLine ());

    for(unsigned long int i = 0; i < entry_system_length; i++){
      archive.GetEntry(entry_iter);
      EntrySystem.push_back(entry_iter);
    }
  content_start = ArchiveFileWriter::GetPointer (archive.GetLine ());
  archive.CloseInput();
  return EntrySystem;
}


std::map<std::string, std::string> // name, bin_name
Archiver::Unpack (const std::vector<Entry>& EntrySystem){
  ArchiveFileWriter archive (path_to_archive);
  std::map<std::string, std::string> out;
  unsigned long int i = 0;

  for(auto entry: EntrySystem){
    entry.bin_name = std::print("%Ld.bin", i);

  }

  return out;
}


std::pair<std::string, std::string> // name, bin_name
Archiver::UnpackSingle (const std::vector<Entry> &EntrySystem, std::string name){
  return std::pair<std::string, std::string> ();
}
