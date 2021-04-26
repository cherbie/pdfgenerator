#include "pdfgen/Integer.h"

namespace pdf
{
    Integer::Integer()
      : Value(0)
    {
    }

    Integer::Integer(int n)
      : Value(n)
    {
    }
    
    Integer::Integer(double n)
     : Value(static_cast<int>(n))
    {
    }
    
    Integer::Integer(float n)
     : Value(static_cast<int>(n))
    {
    }
    
    Integer::Integer(const Integer& obj)
      : Integer()
    {
      int n = obj.getInt();
      setInt(n);
    }
    
    Integer::~Integer()
    {
    }
    
    Integer::operator bool() const
    {
      return getInt() == 0;
    }
    
    bool operator==(const Integer& lvalue, int rvalue)
    {
      return lvalue.getInt() == rvalue;
    }

    bool operator==(int lvalue, const Integer& rvalue)
    {
      return lvalue == rvalue.getInt();
    }
    
    bool operator==(const Integer& lvalue, const Integer& rvalue)
    {
      return lvalue.getInt() == rvalue.getInt();
    }

    std::ostream& operator<<(std::ostream& os, const Integer& obj)
    {
      const int  n = obj.getInt();
      os << std::showpos
           << n
           << std::noshowpos;
      return os;
    }
} // namespace pdf
