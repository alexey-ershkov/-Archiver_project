//
// Created by perturabo on 15.11.2019.
//

#include "TypeIdentifier.hpp"

TypeIdentifier::TypeIdentifier () = default;
TypeIdentifier::~TypeIdentifier () = default;

std::string TypeIdentifier::SignatureDetect(const std::string& path){
  auto handle = magic_open(MAGIC_MIME_TYPE);
  magic_load(handle, MIME_DB);

  std::string type = magic_file (handle, path.c_str());
  std::vector<std::string> out;
  boost::split(out, type, [](char c){return c == '/';});

  return out[1];
}


std::vector<std::string> TypeIdentifier::SignatureDetect(const std::vector<std::string>& list){
  std::vector<std::string> out;

  for(const auto & it : list){
      out.push_back(SignatureDetect (it));
    }
  return out;
}
