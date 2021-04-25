#include <gtest/gtest.h>
#include <sstream>

#include "pdfgen/Integer.h"


TEST(DataTypes, IntegerTest)
{
  pdf::data_type::Integer pdf_int(23);
  
  EXPECT_EQ(pdf_int, 23);

  std::ostringstream stream;
  stream << pdf_int;

  std::ostringstream exp_sstream;
  exp_sstream << std::showpos
                          << 23;

  EXPECT_EQ(stream.str(), exp_sstream.str());
}
