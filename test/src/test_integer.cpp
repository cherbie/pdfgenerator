#include <gtest/gtest.h>
#include <sstream>

#include "pdfgen/Integer.h"


TEST(DataTypes, IntegerTest)
{
  const int testInt = 23;
  pdf::Integer pdf_int(testInt);
  
  EXPECT_EQ(pdf_int, testInt);

  std::ostringstream stream;
  stream << pdf_int;

  std::ostringstream exp_sstream;
  exp_sstream << std::showpos
                          << testInt;

  EXPECT_EQ(stream.str(), exp_sstream.str());
}
