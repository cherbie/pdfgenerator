#include <gtest/gtest.h>
#include <sstream>

#include "pdfgen/Bool.h"

TEST(DataTypes, BoolTest)
{
  pdf::data_type::Bool b(true);
  std::ostringstream stream;
  stream << b;
  EXPECT_EQ(stream.str(), "true");

  b = false;
  // test false
  stream = std::ostringstream();
  stream << b;
  EXPECT_EQ(stream.str(), "false");
}
