#include <gtest/gtest.h>
#include <Huffman.h>
#include <iostream>

bool IsFilesEqual(string input_filepath, string output_filepath) {
    ifstream fin1(input_filepath, ios::binary);
    ifstream fin2(output_filepath, ios::binary);
    /*Сравниваем файлы побайтово*/
    bool result = true;
    if (fin2 && fin2) {
        char ch1, ch2;
        while (fin1.get(ch1) && fin2.get(ch2)) {
            if (ch1 != ch2) {
                result =  false;
                break;
            }
        }
    }
    else{
        cout << "Error opening file!" << endl;
        result = false;
    }
    return result;
}

TEST(HuffmanTest, TestShouldChoose1){
    Huffman alg_huffman;
    vector<string> types_file = {"txt", "rtf", "doc", "docx", "html", "pdf", "odt"};
    for(auto &it : types_file){
        ASSERT_EQ(true, alg_huffman.ShouldChoose(it));
    }

}

TEST(HuffmanTest, TestShouldChoose2){
    Huffman alg_huffman;
    vector<string> types_file = {"txtttttt"};
    for(auto &it : types_file){
        ASSERT_EQ(false, alg_huffman.ShouldChoose(it));
    }

}

TEST(HuffmanTest, TestGetName1){
    Huffman alg_huffman;
    string name = "Huffman";
        ASSERT_EQ(true, alg_huffman.GetName() == name);

}

TEST(HuffmanTest, TestGetName2){
    Huffman alg_huffman;
    string name = "Huffmannnnnn";
    ASSERT_EQ(false, alg_huffman.GetName() == name);

}


TEST(SelectorTest, TestCompressDataTxt1){
    Huffman alg_huffman;
    alg_huffman.Compress("../../files_for_compress/test1.txt", "../../compressed_files/test1.bin");
    ASSERT_EQ(true, alg_huffman.GetCompressionRatio() <= 1);
}
TEST(SelectorTest, TestCompressDataTxt2){
    Huffman alg_huffman;
    alg_huffman.Compress("../../files_for_compress/test2.txt", "../../compressed_files/test2.bin");
    ASSERT_EQ(true, alg_huffman.GetCompressionRatio() <= 1);
}
TEST(SelectorTest, TestCompressDataTxt3){
    Huffman alg_huffman;
    alg_huffman.Compress("../../files_for_compress/test3.txt", "../../compressed_files/test3.bin");
    ASSERT_EQ(true, alg_huffman.GetCompressionRatio() <= 1);
}

TEST(SelectorTest, TestCompressDataTxt4){
    Huffman alg_huffman;
    alg_huffman.Compress("../../files_for_compress/test4.txt", "../../compressed_files/test4.bin");
    ASSERT_EQ(true, alg_huffman.GetCompressionRatio() <= 1);
}

TEST(SelectorTest, TestCompressDataTxt5){
    Huffman alg_huffman;
    alg_huffman.Compress("../../files_for_compress/test5.txt", "../../compressed_files/test5.bin");
    ASSERT_EQ(true, alg_huffman.GetCompressionRatio() <= 1);
}

TEST(SelectorTest, TestCompressDataJpg6){
    Huffman alg_huffman;
    alg_huffman.Compress("../../files_for_compress/test6.jpg", "../../compressed_files/test6.bin");
    ASSERT_EQ(true, alg_huffman.GetCompressionRatio() <= 1);
}



TEST(SelectorTest, TestCompressDataPng9){
    Huffman alg_huffman;
    alg_huffman.Compress("../../files_for_compress/test9.png", "../../compressed_files/test9.bin");
    ASSERT_EQ(true, alg_huffman.GetCompressionRatio() <= 1);
}

TEST(SelectorTest, TestCompressDataZip10){
    Huffman alg_huffman;
    alg_huffman.Compress("../../files_for_compress/test10.zip", "../../compressed_files/test10.bin");
    ASSERT_EQ(true, alg_huffman.GetCompressionRatio() <= 1);
}

TEST(SelectorTest, TestDecompressDataTxt1){
    Huffman alg_huffman;
    alg_huffman.Decompress("../../compressed_files/test1.bin", "../../decompressed_files/test1.txt");
    bool result = IsFilesEqual("../../files_for_compress/test1.txt", "../../decompressed_files/test1.txt");
    ASSERT_EQ(true, result);

}


TEST(SelectorTest, TestDecompressDataTxt2){
    Huffman alg_huffman;
    alg_huffman.Decompress("../../compressed_files/test2.bin", "../../decompressed_files/test2.txt");
    bool result = IsFilesEqual("../../files_for_compress/test2.txt", "../../decompressed_files/test2.txt");
    ASSERT_EQ(true, result);
}
TEST(SelectorTest, TestDecompressDataTxt3) {
    Huffman alg_huffman;
    alg_huffman.Decompress("../../compressed_files/test3.bin", "../../decompressed_files/test3.txt");
    bool result = IsFilesEqual("../../files_for_compress/test3.txt", "../../decompressed_files/test3.txt");
    ASSERT_EQ(true, result);
}

TEST(SelectorTest, TestDecompressDataTxt4){
    Huffman alg_huffman;
    alg_huffman.Decompress("../../compressed_files/test4.bin", "../../decompressed_files/test4.txt");
    bool result = IsFilesEqual("../../files_for_compress/test4.txt", "../../decompressed_files/test4.txt");
    ASSERT_EQ(true, result);

}

TEST(SelectorTest, TestDecompressDataTxt5){
    Huffman alg_huffman;
    alg_huffman.Decompress("../../compressed_files/test5.bin", "../../decompressed_files/test5.txt");
    bool result = IsFilesEqual("../../files_for_compress/test5.txt", "../../decompressed_files/test5.txt");
    ASSERT_EQ(true, result);
}




int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}