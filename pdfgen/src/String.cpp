#include "pdfgen/String.h"

namespace pdf
{
  namespace data_type
  {
    String::String(const std::string& str)
    : m_value(str)
    {
    }

    String::String(const char* c_ptr)
    : m_value(c_ptr)
    {
    }

    String::~String()
    {
    }
  } // namespace data_type
} // namespace pdf
