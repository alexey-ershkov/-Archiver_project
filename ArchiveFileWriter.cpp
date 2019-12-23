//
// Created by perturabo on 07.12.2019.
//

#include "ArchiveFileWriter.hpp"

#include <utility>

size_t ArchiveFileWriter::GetInputFileSize (Input *in){
  size_t size_a = 0;
  byte stub;

  while(in->Read(stub))
    size_a++;

  return size_a;
}

void ArchiveFileWriter::WriteString(const std::string& s) {
  for(auto& ch : s){
      Write(ch);
      content_start+=1;
    }
  Write (0x00);
  content_start++;
}

size_t ArchiveFileWriter::GetPointer(const std::string& in){
  size_t x;
  std::stringstream ss;
  ss << std::hex << in;
  ss >> x;
  return x;
}

std::string ArchiveFileWriter::makeString(const std::string& in){
  unsigned int diff  = 16 - in.length();
  std::string out;
  for(int i = 0; i < diff; i++){
      out.push_back('0');
    }
  out.append(in);

  return out;
}

void ArchiveFileWriter::WritePointer(unsigned int input_string){
  std::stringstream field;
  std::string hex_string;
  field << std::hex << input_string;
  field >> hex_string;
  hex_string = makeString(hex_string);
  WriteString(hex_string);
}

void ArchiveFileWriter::WriteSignature () {
  Write (0x74); // TPRK archive file signature (tprk)
  Write (0x70);
  Write (0x72);
  Write (0x6B);
  Write (0x0E);
  content_start+=5;
}

void ArchiveFileWriter::WriteEndOfES(){
  content_start += 17; // there are some trouble in math, fixed with this constant
  WritePointer (content_start);
}

void ArchiveFileWriter::WriteEntrySeparator(){
  Write(0x0F);  // (0F) separates entries from each other in compiled archive
  content_start++;
}

void ArchiveFileWriter::WriteFile(const std::string& path){
  Input bin(path);
  byte b;
  while (bin.Read (b))
    Write (b);
}

unsigned long int ArchiveFileWriter::CreateEntrySystem (const std::map<std::string, std::string>& compressed_data){
  size_t relative_pointer = 0;
  unsigned long int entry_system_length = compressed_data.size();
  WritePointer (entry_system_length);
  /* uncomment all this.
  std::stringstream buff_stream;
  std::vector<std::string> buff_vect;
  std::string iter;
  */
  for (auto &item : compressed_data){
    /*
    buff_stream<<item.first;
    while(std::getline(buff_stream, iter, '/')){ 
    vect_buff.push_back(iter); 
    }
    */
    Entry entry;
    entry.name = item.first; // delete this
    //entry.name = iter;
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

  WriteEndOfES();
  return content_start;
}


ArchiveFileWriter::ArchiveFileWriter
(const std::string& path_to_archive): filepath(path_to_archive), Output (path_to_archive){
    OpenOutput ();
    content_start = 0;
    WriteSignature ();
}


void ArchiveFileWriter::CloseOutput(){
  fout.close();
}


void ArchiveFileWriter::OpenOutput(){
  fout.open (filepath);
  if (!fout.is_open ()){
      std::cout << "can't open or create file" << filepath << std::endl;
      fout.close ();
    }
}

