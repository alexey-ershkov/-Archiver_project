#ifndef PROTOTIPE_LZW_H
#define PROTOTIPE_LZW_H

#include "Algorithm.h"

class LZW : public Algorithm {
public:
    LZW();
    ~LZW() = default;
    bool ShouldChoose(std::string type_file);
    std::string GetName() override;
private:
    void CopyStream(IInputStream& input, IOutputStream& output);
    void Encode(IInputStream& original, IOutputStream& compressed) override;
    void Decode(IInputStream& compressed, IOutputStream& original) override;
/*PMPL*/
};

#endif //PROTOTIPE_LZW_H
