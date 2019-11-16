//
// Created by perturabo on 15.11.2019.
//

#ifndef _ARCHIVER_HPP_
#define _ARCHIVER_HPP_

#include <TypeIdentifier.hpp>


struct DataIn{
  FILE *file;
  std::string type;
};

struct DataOut{
  FILE *file;
  std::string type;
};

class Archiver{
 public:
  std::vector<DataOut> Read(DataIn archive);
  DataOut Write(std::vector<DataIn> compressed_data);
};

#endif //_ARCHIVER_HPP_
