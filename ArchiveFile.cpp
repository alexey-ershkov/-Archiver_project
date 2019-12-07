//
// Created by perturabo on 07.12.2019.
//

#include "ArchiveFile.hpp"

#include <utility>


void ArchiveFile::WriteString(const std::string& s) {
  for(auto& ch : s){
      Write(ch);
    }
  Write (0x00);
}

void ArchiveFile::WriteSizeT(const size_t s){
  fout.write(reinterpret_cast<const char*>(&s), sizeof(s));
  size += sizeof(s);
}

void ArchiveFile::WriteSignature () {
  Write (0x74); // TPRK archive file signature (tprk)
  Write (0x70);
  Write (0x72);
  Write (0x6B);
  Write (0x00);
  Write (0x00);
  Write (0x00);
  Write (0x00);
}

void ArchiveFile::WriteEntrySeparator(){
  Write(0x00);  // (00AA00AA) separates entries from each other in compiled archive
  Write(0xAA);
  Write(0x00);
  Write(0xAA);
}

void ArchiveFile::WriteFile(const std::string& path){
  Input bin(path);
  byte b;
  while (bin.Read (b))
    Write (b);
}

void ArchiveFile::CreateEntrySystem (const std::map<std::string, std::string>& compressed_data){
  size_t relative_pointer = 0;

  for (auto &item : compressed_data){
    WriteEntrySeparator();

    Entry entry;
    entry.name = item.first;
    entry.bin_name = item.second;
    {
      Input bin(item.second);
      entry.start = relative_pointer;
      relative_pointer += bin.GetFileSize ();
      entry.end = relative_pointer++;
    }
    entry.type = TypeIdentifier::SignatureDetect (item.first);

    WriteSizeT (entry.start);
    WriteSizeT (entry.end);
    WriteString (entry.name);
    WriteString (entry.type);

    internal_system.push_back(entry);
    }
}


ArchiveFile::ArchiveFile (std::string path) :Output (path), filepath (std::move(path)){
  fout.open(filepath, std::ios::binary);
  if (!fout.is_open()) {
    std::cout << "can't open or create file" << filepath << std::endl;
    fout.close();
  }

  WriteSignature();
  content_start = 0;
}
