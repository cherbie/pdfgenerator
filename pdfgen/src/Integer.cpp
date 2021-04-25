#include "pdfgen/Integer.h"

namespace pdf
{
  namespace data_type
  {
    Integer::Integer(int n)
      : m_int(std::make_unique<int>(n))
    {
    }
    
    Integer::Integer(double n)
     : m_int(std::make_unique<int>(static_cast<int>(n)))
    {
    }
    
    Integer::Integer(float n)
     : m_int(std::make_unique<int>(static_cast<int>(n)))
    {
    }
    
    Integer::Integer(const Integer& n)
      : Integer()
    {
      if (n)
        m_int = std::make_unique<int>(*n.m_int);
    }
    
    Integer::~Integer()
    {
    }
    
    Integer::operator bool() const
    {
      return m_int != nullptr;
    }
    
    bool operator==(const Integer& lvalue, int rvalue)
    {
      return lvalue && *lvalue.m_int == rvalue;
    }

    bool operator==(int lvalue, const Integer& rvalue)
    {
      return rvalue && lvalue == *rvalue.m_int;
    }
    
    bool operator==(const Integer& lvalue, const Integer& rvalue)
    {
      return lvalue && rvalue && *lvalue.m_int == *rvalue.m_int;
    }

    std::ostream& operator<<(std::ostream& os, const Integer& obj)
    {
      if (!obj)
        return os;
      os << std::showpos
           << *obj.m_int
           << std::noshowpos;
      return os;
    }
  } // namespace data_type
} // namespace pdf
