//
// Created by perturabo on 21.12.2019.
//

#include "ArchiveFileReader.hpp"

#include <utility>

void ArchiveFileReader::OpenInput(){
  fin.open(filepath,std::ios::binary);
  if (!fin.is_open()) {
      std::cout << "file " << filepath << " cant be open" << std::endl;
      fin.close();
    }
}

void ArchiveFileReader::CloseInput (){
  fin.close();
}

std::string ArchiveFileReader::GetLine (){
  std::string out;
  unsigned char ch;

  while(Read(ch)&&(ch!='\0'))
      out.push_back(ch);

  return out;
}

bool ArchiveFileReader::GetEntry(Entry &entry) {
  entry.start = GetPointer (GetLine ());
  entry.end = GetPointer (GetLine ());
  entry.name = GetLine ();
  entry.type = GetLine ();
  unsigned char test;

  return Read (test) && test == 0x0F;
}

void ArchiveFileReader::SkipSignature (){
  byte stub;
  for(byte i = 0; i < 5; i++){ // 5 is length of tprk signature
      Read(stub);
    }
}

size_t ArchiveFileReader::GetPointer(const std::string& in){
  size_t x;
  std::stringstream ss;
  ss << std::hex << in;
  ss >> x;
  return x;
}
ArchiveFileReader::ArchiveFileReader (std::string path_to_archive)
    : Input (path_to_archive), filepath (std::move(path_to_archive)){
  SkipSignature ();
}

