#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "pdfgen/String.h"


TEST(DataTypes, StringTest)
{
  pdf::data_type::String pdf_str(std::string("Test string characters"));

  std::ostringstream stream;
  stream << pdf_str;
  EXPECT_EQ(stream.str(), "(Test string characters)");

  stream = std::ostringstream();

  pdf_str = pdf::data_type::String("A_different_set_of_characters");
  stream << pdf_str;
  EXPECT_EQ(stream.str(), "(A_different_set_of_characters)");
  EXPECT_NE(stream.str(), "()");
}

