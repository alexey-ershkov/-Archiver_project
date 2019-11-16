//
// Created by perturabo on 16.11.2019.
//


#include <gtest/gtest.h>
#include "../Archiver.hpp"
#include "../TypeIdentifier.hpp.hpp"
#include <iostream>

TEST(ArchiverGeneral, TestIsCompressionDataLessOriginal)
{
Archiver archiver;

DataIn data1;
DataOut data2;
ASSERT_EQ(true, archiver.Read(data1));
}


int main(int argc, char **argv)
{
  testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}