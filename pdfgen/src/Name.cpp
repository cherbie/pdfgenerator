#include "pdfgen/Name.h"

namespace pdf
{
  namespace data_type
  {
    Name::Name(const std::string& title)
    : m_value(title)
    {
    }

    Name::~Name()
    {
    }

    std::ostream& operator<<(std::ostream& os, const Name& n)
    {
      os << "/" << n.m_value;
      return os;
    }
  } // namespace data_type
} // namespace pdf
