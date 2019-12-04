//
// Created by perturabo on 15.11.2019.
//

#ifndef _TYPEIDENTIFIER_HPP_
#define _TYPEIDENTIFIER_HPP_

#include <vector>
#include <map>
#include <string>
#include <boost/algorithm/string.hpp>
#include <magic.h>
#include <string>

#define MIME_DB "/usr/share/file/magic.mgc"

class TypeIdentifier{
 private:
  std::map <std::string, std::string> signature_list;
 public:
  TypeIdentifier();
  ~TypeIdentifier();

  static std::vector<std::string> SignatureDetect(const std::vector<std::string>& list);
  static std::string SignatureDetect (const std::string &path);
};

#endif //_TYPEIDENTIFIER_HPP_


