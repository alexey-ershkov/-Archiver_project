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



class Algorithm {
public:
    Algorithm();
    ~Algorithm() = default;
    double compressionRatio;
    virtual double Compress(Input input, Output output);
    virtual void Decompress(Input input, Output output);
    virtual bool ShouldChoose(std::string type_file) = 0;
    virtual double GetCompressionRatio();
    virtual std::string GetName() = 0;
private:
    bool IsOrigLessCompr(double size_compressed_f, double size_origin_f);
    virtual void Encode(IInputStream& original, IOutputStream& compressed) = 0;
    virtual void Decode(IInputStream& compressed, IOutputStream& original) = 0;
};


#endif //PROTOTIPE_ALGORITHM_H
