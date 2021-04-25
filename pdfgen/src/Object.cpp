#include "pdfgen/Object.h"

namespace pdf
{
namespace data_type
{
    Object::~Object()
    {
    }
    
    Object::Object(const Object& obj)
      : Object()
    {
      if (obj.m_str != nullptr)
        m_str = std::make_unique<String>(*obj.m_str);
      if (obj.m_name != nullptr)
        m_name = std::make_unique<Name>(*obj.m_name);
      if (obj.m_int != nullptr)
        m_int = std::make_unique<Integer>(*obj.m_int);
      if (obj.m_dict != nullptr)
        m_dict = std::make_unique<Dictionary>(*obj.m_dict);
    }
    
    Object::Object(const String& str)
      : Object()
    {
      m_str = std::make_unique<String>(str);
    }
    
    Object::Object(const Integer& n)
      : Object()
    {
      m_int = std::make_unique<Integer>(n);
    }
    
    Object::Object(const Name& name)
      : Object()
    {
      m_name = std::make_unique<Name>(name);
    }
    
    Object::Object(const Dictionary& dict)
      : Object()
    {
      m_dict = std::make_unique<Dictionary>(dict);
    }
    
    Object::operator bool() const
    {
      return m_str != nullptr || m_int != nullptr || m_name != nullptr
        || m_dict != nullptr;
    }
    
    std::ostream& operator<<(std::ostream& os, const Object& obj)
    {
      if (obj.m_str != nullptr)
          os << *obj.m_str;
      else if (obj.m_int != nullptr)
        os << *obj.m_int;
      else if (obj.m_name != nullptr)
        os << *obj.m_name;
      else if (obj.m_dict != nullptr)
        os << *obj.m_dict;
      return os;
    }
    
    bool operator ==(const Object& lvalue, const Object& rvalue)
    {
      return lvalue && rvalue && lvalue.m_str == rvalue.m_str && lvalue.m_int == rvalue.m_int
        && lvalue.m_name == rvalue.m_name && lvalue.m_dict == rvalue.m_dict;
    }
} // namespace data_type
} // namespace data_type
