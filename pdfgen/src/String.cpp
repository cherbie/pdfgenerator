#include "pdfgen/String.h"

namespace pdf
{
  namespace data_type
  {
    String::String(const std::string& str)
      : m_str(std::make_unique<std::string>(str))
    {
    }

    String::String(const char* c_ptr)
      : m_str(std::make_unique<std::string>(c_ptr))
    {
    }
    
    String::String(const char* c_ptr, std::size_t n)
      : m_str(std::make_unique<std::string>(c_ptr, n))
    {
    }

    String::String(const String& str)
      : String()
    {
      if (str)
        m_str = std::make_unique<std::string>(*str.m_str);
    }
    
    String& String::operator=(const String& str)
    {
      if (str)
        m_str = std::make_unique<std::string>(*str.m_str);
      return *this;
    }

    String::~String()
    {
    }
    
    String::operator bool() const
    {
      return m_str != nullptr;
    }
    
    std::ostream& operator<<(std::ostream& os, const String& obj)
    {
      if (!obj)
        return os;
      os << "(" << *obj.m_str<< ")";
      return os;
    }

    bool operator==(const String& lvalue, const std::string& rvalue)
    {
      return lvalue && *lvalue.m_str == rvalue;
    }
    
    bool operator==(const std::string& lvalue, const String& rvalue)
    {
      return rvalue && lvalue == *rvalue.m_str;
    }
    
    bool operator==(const String& lvalue, const String& rvalue)
    {
      return lvalue && rvalue && *lvalue.m_str == *rvalue.m_str;
    }
  } // namespace data_type
} // namespace pdf
