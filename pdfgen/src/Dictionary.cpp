#include "pdfgen/Dictionary.h"
#include "pdfgen/Name.h"

namespace pdf
{
namespace data_type
{
    Dictionary::~Dictionary()
    {
    }

    Dictionary::Dictionary(const Dictionary& dict)
      : m_map(dict.m_map)
    {
    }
    
    std::pair<Object, bool> Dictionary::set(const std::string& key, const Object& obj)
    {
      auto element = m_map.try_emplace(key, obj);
      return std::make_pair((*element.first).second, element.second);
    }
    
    Object& Dictionary::get(const std::string& key)
    {
      return m_map.at(key);
    }
    
    Dictionary::operator bool() const
    {
      return !m_map.empty();
    }
    
    std::ostream& operator<<(std::ostream& os, const Dictionary& dict)
    {
      if (!dict)
        return os;
      os << "<< ";
      for (const auto& [key, obj] : dict.m_map)
      {
        Name key_name(key);
        os << key_name << " " << obj << " \n";
      }
      os << ">>";
      return os;
    }

    bool operator==(const Dictionary& lvalue, const Dictionary& rvalue)
    {
      return lvalue.m_map == rvalue.m_map;
    }
} // namespace data_type
} // namespace pdf
