#include "pdfgen/Bool.h"

namespace pdf
{
  namespace data_type
  {
    Bool::Bool(bool b)
    : m_bool(b)
    {
    }

    Bool::~Bool()
    {
    }
    
    Bool::operator bool() const
    {
      return m_bool;
    }

    bool operator==(const Bool& lvalue, const Bool& rvalue)
    {
      return lvalue.m_bool == rvalue.m_bool;
    }

    std::ostream& operator<<(std::ostream& os, const Bool& obj)
    {
      if (obj.m_bool)
        os << "true";
      else
        os << "false";
      return os;
    }
    
    std::ostream& operator<<(std::ostream& os, bool b)
    {
      if (b)
        os << "true";
      else
        os << "false";
      return os;
    }
  } // namespace data_type
} // namespace pdf

