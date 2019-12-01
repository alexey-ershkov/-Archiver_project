//
// Created by alexandr on 11/25/19.
//

#ifndef PROTOTIPE_ALGORITHM_H
#define PROTOTIPE_ALGORITHM_H

#include <vector>
#include <iostream>
#include <vector>
#include <map>
#include <math.h>
#include <algorithm>
#include <list>
#include <stack>
#include "Input.h"
#include "Output.h"
#include "IInputStream.h"
#include "IOutputStream.h"

using namespace std;

/*Абстрактный класс*/

class Algorithm {
public:
    Algorithm();
    ~Algorithm() = default;
    double CompressionRatio;
    virtual void Compress(string input_filepath, string output_filepath); /* Compress никаким образом не зависит от Decompress*/
    virtual void Decompress(string input_filepath, string output_filepath);
    virtual bool ShouldChoose(string type_file) = 0;
    virtual void CopyStream(IInputStream& input, IOutputStream& output);
    virtual double GetCompressionRatio();
    virtual string GetName() = 0;
private:
    bool FlagCompare;
    bool IsOrigLessCompr(double size_compressed_f, double size_origin_f);
    virtual void Encode(IInputStream& original, IOutputStream& compressed) = 0;
    virtual void Decode(IInputStream& compressed, IOutputStream& original) = 0;
};


#endif //PROTOTIPE_ALGORITHM_H
