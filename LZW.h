#ifndef PROTOTIPE_LZW_H
#define PROTOTIPE_LZW_H

#include "Algorithm.h"

class LZW : public Algorithm {
public:
    LZW(std::vector<std::string> should_choose_formats = {""});
    ~LZW() = default;
    bool ShouldChoose(std::string type_file);
    std::string GetName() override;
private:
    std::vector<std::string> Formats;
    int calculate_bit_resolution(const int data_size);
    void CopyStream(IInputStream& input, IOutputStream& output);
    void Encode(IInputStream& original, IOutputStream& compressed) override;
    void Decode(IInputStream& compressed, IOutputStream& original) override;
/*PMPL*/
};

#endif //PROTOTIPE_LZW_H
