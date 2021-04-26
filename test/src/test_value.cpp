#include <gtest/gtest.h>
#include <string>
#include <vector>
#include <map>
#include <memory>
#include "pdfgen/Value.h"

TEST(DataTypes, ValueIntTest)
{
  int pos_test_value = 10;
  pdf::Value<int> pos_value(pos_test_value);
  EXPECT_EQ(pos_value.getInt(), pos_test_value);
  
  int neg_test_value = -1232;
  pdf::Value<int> neg_value(neg_test_value);
  EXPECT_EQ(neg_value.getInt(), neg_test_value);
}

TEST(DataTypes, ValueStringTest)
{
  std::string testStr = "A test string.";
  pdf::Value<std::string> value(std::make_unique<std::string>(testStr), pdf::TagType::StringTag);
  
  EXPECT_EQ(testStr, *value.getPointer());
}

TEST(DataTypes, ValueDoubleTest)
{
  double pTestValue = 2.32;
  pdf::Value<double> value(std::make_unique<double>(pTestValue), pdf::TagType::DoubleTag);
  EXPECT_EQ(pTestValue, *value.getPointer());
  
  double nTestValue = -3234.33;
  pdf::Value<double> neg_value(std::make_unique<double>(nTestValue), pdf::TagType::DoubleTag);
  EXPECT_EQ(nTestValue, *neg_value.getPointer());
}

TEST(DataTypes, ValueVectorIntTest)
{
  using Vector = std::vector<int>;
  Vector testValue = { -2, 4, 2343, -234, 0, 223 }; 
  pdf::Value<Vector> value(std::make_unique<Vector>(testValue), pdf::TagType::VecIntTag);
  EXPECT_EQ(testValue, *value.getPointer());
}

TEST(DataTypes, ValueMapTest)
{
  using Map = std::map<std::string, int>;
  Map testMap;
  testMap.emplace("one", 1);
  testMap.emplace("two", 2);
  testMap.emplace("negative_hundred", -100);

  pdf::Value<Map> value(std::make_unique<Map>(testMap), pdf::TagType::PtrTag);
  EXPECT_EQ(testMap, *value.getPointer());
}
