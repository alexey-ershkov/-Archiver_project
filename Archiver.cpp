//
// Created by perturabo on 15.11.2019.
//

#include "Archiver.hpp"


std::string Archiver::Pack (const std::map<std::string, std::string>& compressed_data, std::string name)
{
  name.append(".tprk");
  ArchiveFile archive(name, 'w');

  archive.CreateEntrySystem(compressed_data);

  std::vector<Entry> EntrySystem = archive.ViewArchive ();

  for(auto& entry : EntrySystem){
    archive.WriteFile (entry.bin_name);
  }
  archive.CloseOutput ();
  return name;
}


std::map<std::string, std::string> Archiver::Unpack (const std::string& path_to_archive, std::string name)
{
  return std::map<std::string, std::string> ();
}


std::vector<Entry> Archiver::Read (const std::string& path_to_archive, std::string name){
  name.append(".tprk");
  ArchiveFile archive(name, 'r');

  std::vector<Entry> EntrySystem;
  Entry entry_iter;
  unsigned long int entry_system_length = archive.GetPointer (archive.GetLine ());

    for(unsigned long int i = 0; i < entry_system_length; i++){
      archive.GetEntry(entry_iter);
      EntrySystem.push_back(entry_iter);
    }

  return EntrySystem;
}



