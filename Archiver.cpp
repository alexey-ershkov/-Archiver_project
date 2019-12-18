//
// Created by perturabo on 15.11.2019.
//

#include "Archiver.hpp"


std::string Archiver::Pack (const std::map<std::string, std::string>& compressed_data)
{
  ArchiveFile archive("Archive.tprk");

  archive.CreateEntrySystem(compressed_data);

  std::vector<Entry> EntrySystem = archive.ViewArchive ();

  for(auto& entry : EntrySystem){
    //archive.WriteFile (entry.bin_name);
  }
  archive.Close();
  return "Archive.tprk";
}


std::map<std::string, std::string> Archiver::Unpack (const std::string& path_to_archive)
{
  return std::map<std::string, std::string> ();
}


std::map<std::string, std::string> Archiver::Read (const std::string& path_to_archive)
{
  return std::map<std::string, std::string> ();
}



