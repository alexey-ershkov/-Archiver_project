//
// Created by perturabo on 15.11.2019.
//

#ifndef _TYPEIDENTIFIER_HPP_
#define _TYPEIDENTIFIER_HPP_

#include <vector>
#include <map>

class TypeIdentifier{
 private:
  std::map <std::string> <std::string> signature_list;
 public:
  std::string SignatureDetect(FILE * raw_file);
  std::vector<std::string> SignatureDetect(std::vector<FILE *> raw_files_list);
};

#endif //_TYPEIDENTIFIER_HPP_
