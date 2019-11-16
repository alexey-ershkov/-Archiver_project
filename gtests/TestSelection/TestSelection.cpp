#include <gtest/gtest.h>
#include "Selection.h"
#include <iostream>

 
TEST(SelectorTest, TestIsCompressionDataLessOriginal){
	Selection selector;
	DataIn data1;
	DataOut data2;
	ASSERT_EQ(true, selector.IsCompressionDataLessOriginal(data1, data2));
  }

TEST(SelectorTest, TestGetAlgorithm){
    DataIn data_for_compression;
    Selection selector;
    std::string str = "Huffman";
    ASSERT_EQ(true, str == selector.GetAlgorithm(data_for_compression));
}

TEST(SelectorTest, TestGetCompressionData){
    std::string str = "Huffman";
    Selection selector;
    DataIn data2;
    ASSERT_EQ(data2, selector.GetCompressedData(data2, str));
}

TEST(SelectorTest, TestGetDecompressedData){
    std::string str = "Huffman";
    Selection selector;
    DataIn data2;
    ASSERT_EQ(data2, selector.GetCompressedData(data2, str));
}
 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}