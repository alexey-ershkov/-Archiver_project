#include <gtest/gtest.h>
#include "OutBitStream.h"
#include <iostream>

TEST(TestOutBitStream, TestWriteBit){
    OutBitStream obj;
    unsigned char bit = 1;
    ASSERT_EQ(void, obj.WriteBit(bit));
}

TEST(TestOutBitStream, TestWriteByte){
    OutBitStream obj;
    unsigned char byte = 1;
    ASSERT_EQ(void, obj.WriteBit(byte));
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}