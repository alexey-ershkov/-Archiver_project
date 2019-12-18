//
// Created by perturabo on 07.12.2019.
//

#include "ArchiveFile.hpp"

#include <utility>

size_t ArchiveFile::GetInputFileSize (Input *in){
  size_t size_a = 0;
  byte stub;

  while(in->Read(stub))
    size_a++;

  return size_a;
}

void ArchiveFile::WriteString(const std::string& s) {
  for(auto& ch : s){
      Write(ch);
    }
  Write (0x00);
}

size_t ArchiveFile::GetPointer(const std::string& in){
  size_t x;
  std::stringstream ss;
  ss << std::hex << in;
  ss >> x;
  return x;
}

std::string ArchiveFile::makeString(const std::string& in){
  int diff  = 16 - in.length();
  std::string out;
  for(int i = 0; i < diff; i++){
      out.push_back('0');
    }
  out.append(in);

  return out;
}

void ArchiveFile::WritePointer(unsigned int input_string){
  std::stringstream field;
  std::string hex_string;
  field << std::hex << input_string;
  field >> hex_string;
  hex_string = makeString(hex_string);
  WriteString(hex_string);
}

void ArchiveFile::WriteSignature () {
  Write (0x74); // TPRK archive file signature (tprk)
  Write (0x70);
  Write (0x72);
  Write (0x6B);
  Write (0x0E);
}

void ArchiveFile::WriteEndOfES(){
  Write (0x10);
}

void ArchiveFile::WriteEntrySeparator(){
  Write(0x0F);  // (0F) separates entries from each other in compiled archive
}

void ArchiveFile::WriteFile(const std::string& path){
  Input bin(path);
  byte b;
  while (bin.Read (b))
    Write (b);
}

void ArchiveFile::CreateEntrySystem (const std::map<std::string, std::string>& compressed_data){
  size_t relative_pointer = 0;
  unsigned long int entry_system_length = compressed_data.size();
  WritePointer (entry_system_length);

  for (auto &item : compressed_data){


    Entry entry;
    entry.name = item.first;
    entry.bin_name = item.second;
    {
      Input bin(item.second);
      entry.start = relative_pointer;
      relative_pointer += GetInputFileSize(&bin);
      entry.end = relative_pointer++;
    }
    entry.type = TypeIdentifier::SignatureDetect (item.second);

    WritePointer(entry.start);
    WritePointer(entry.end );
    WriteString (entry.name);
    WriteString (entry.type);

    internal_system.push_back(entry);
    WriteEntrySeparator();
    }
    //WriteEndOfES();
}


ArchiveFile::ArchiveFile (std::string path, char mode) :Output (path), filepath (std::move(path)), Input(path){
  if(mode=='w'){
    OpenOutput();
    WriteSignature();
    content_start = 0;
  }
  if(mode=='r'){
      OpenInput ();
      SkipSignature();
    }
}

void ArchiveFile::CloseOutput(){
  fout.close();
}

void ArchiveFile::CloseInput (){
  fin.close();
}

void ArchiveFile::OpenOutput(){
  fout.open (filepath);
  if (!fout.is_open ()){
      std::cout << "can't open or create file" << filepath << std::endl;
      fout.close ();
    }
}

void ArchiveFile::OpenInput(){
  fin.open(filepath,std::ios::binary);
  if (!fin.is_open()) {
      std::cout << "file " << filepath << " cant be open" << std::endl;
      fin.close();
    }
}
std::string ArchiveFile::GetLine (){
  std::string out;
  unsigned char ch;

  while(Read(ch)&&(ch!='\0')){
    out.push_back(ch);
  }

  return out;
}

bool ArchiveFile::GetEntry(Entry &entry) {
  entry.start = GetPointer (GetLine ());
  entry.end = GetPointer (GetLine ());
  entry.name = GetLine ();
  entry.type = GetLine ();
  unsigned char test;

  return Read (test) && test == 0x0F;
}

void ArchiveFile::SkipSignature (){
  byte stub;
  for(byte i = 0; i < 5; i++){ // 5 is length of tprk signature
    Read(stub);
  }
}
