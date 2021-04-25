#include <gtest/gtest.h>
#include <sstream>
#include <string>

#include "pdfgen/Dictionary.h"
#include "pdfgen/Object.h"

TEST(DataTypes, DictionaryTest)
{
  pdf::data_type::Name pdf_name("TEST_NAME_OBJECT");
  pdf::data_type::Object pdf_obj(pdf_name);
  pdf::data_type::Dictionary pdf_dict;
  
  pdf_dict.set("TEST_KEY",  pdf_obj);

  std::ostringstream stream;
  stream << pdf_dict;
  
  EXPECT_TRUE(stream.str().find("<<") != std::string::npos);
  EXPECT_TRUE(stream.str().find(">>") != std::string::npos);
  EXPECT_TRUE(stream.str().find("/TEST_KEY") != std::string::npos);
  EXPECT_TRUE(stream.str().find("/TEST_NAME_OBJECT") != std::string::npos);
}
