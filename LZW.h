#ifndef PROTOTIPE_LZW_H
#define PROTOTIPE_LZW_H

#include "Algorithm.h"

class LZW : public Algorithm {
public:
    LZW();
    ~LZW() = default;
    bool ShouldChoose(string type_file);
    string GetName() override;
private:
    void Encode(IInputStream& original, IOutputStream& compressed);
    void Decode(IInputStream& compressed, IOutputStream& original);
/*PMPL*/
};

#endif //PROTOTIPE_LZW_H
