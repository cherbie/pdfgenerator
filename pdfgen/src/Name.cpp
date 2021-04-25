#include "pdfgen/Name.h"

namespace pdf
{
  namespace data_type
  {
    Name::Name(const std::string& title)
      : m_name(std::make_unique<std::string>(title))
    {
    }
    
    Name::Name(const Name& name)
      : Name()
    {
      if (name)
          m_name = std::make_unique<std::string>(*name.m_name);
    }

    Name::~Name()
    {
    }
    
    Name::operator bool() const
    {
      return m_name != nullptr;
    }
    
    bool operator==(const Name& lvalue, const Name& rvalue)
    {
      return lvalue && rvalue && *lvalue.m_name == *rvalue.m_name;
    }

    std::ostream& operator<<(std::ostream& os, const Name& obj)
    {
      os << "/" << *obj.m_name;
      return os;
    }
  } // namespace data_type
} // namespace pdf
