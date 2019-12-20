//
// Created by perturabo on 15.11.2019.
//

#include "Archiver.hpp"

#include <utility>


std::string Archiver::Pack (const std::map<std::string, std::string>& compressed_data, std::string path_to_archive,
    std::string name){
    path_to_archive.append("/");
  path_to_archive.append(name);
  path_to_archive.append(".tprk");
  ArchiveFile archive(path_to_archive, 'w');

  content_start = archive.CreateEntrySystem(compressed_data);

  std::vector<Entry> EntrySystem = archive.ViewArchive ();

  for(auto& entry : EntrySystem){
    archive.WriteFile (entry.bin_name);
  }

  archive.CloseOutput ();
  return path_to_archive;
}


std::vector<Entry> Archiver::Read (const std::string& path_to_archive){
  ArchiveFile archive(path_to_archive, 'r');

  std::vector<Entry> EntrySystem;
  Entry entry_iter;
  unsigned long int entry_system_length = ArchiveFile::GetPointer (archive.GetLine ());

    for(unsigned long int i = 0; i < entry_system_length; i++){
      archive.GetEntry(entry_iter);
      EntrySystem.push_back(entry_iter);
    }
  content_start = ArchiveFile::GetPointer (archive.GetLine ());
  archive.CloseInput();
  return EntrySystem;
}


std::map<std::string, std::string> // name, bin_name
Archiver::Unpack (const std::string& path_to_archive,const std::vector<Entry>& EntrySystem){

  ArchiveFile archive(path_to_archive, 'r');

  return std::map<std::string, std::string> ();
}


std::pair<std::string, std::string> // name, bin_name
Archiver::UnpackSingle (const std::string &path_to_archive, const std::vector<Entry> &EntrySystem, std::string name){
  return std::pair<std::string, std::string> ();
}
