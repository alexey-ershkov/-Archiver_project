//
// Created by perturabo on 15.11.2019.
//

#include "TypeIdentifier.hpp"

TypeIdentifier::TypeIdentifier () = default;
TypeIdentifier::~TypeIdentifier () = default;

std::string TypeIdentifier::SignatureDetect(const std::string& path){
  auto handle = magic_open(MAGIC_MIME_TYPE);
  magic_load(handle, MIME_DB);

  std::string type = SplitAndClear(magic_file (handle, path.c_str ()));

  return type;
}


std::vector<std::string> TypeIdentifier::SignatureDetect(const std::vector<std::string>& list){
  std::vector<std::string> out;
  out.reserve(list.size());

for(const auto & iter : list){
      out.push_back(SignatureDetect(iter));
    }
  return out;
}


std::string TypeIdentifier::SplitAndClear(const std::string &string){
    std::stringstream string_a(string);
    std::string segment;
    std::vector<std::string> seglist;

    while(std::getline(string_a, segment, '/')){
        seglist.push_back(segment);
    }
    if(seglist[0].length() > 31)
      seglist[0].resize(31);
    seglist[0].append("\0");
    return seglist[0];
}

