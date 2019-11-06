#include <gtest/gtest.h>
#include "../Selection.cpp"
#include "../Selection.h"
#include <iostream>

 
TEST(OutPutTestAboutSize, TestIsCompressionDataLessOriginal){
	Selection selector;
	DataIn data1;
	DataOut data2;
	ASSERT_EQ(true, selector.IsCompressionDataLessOriginal(data1, data2));
  }

 
int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}