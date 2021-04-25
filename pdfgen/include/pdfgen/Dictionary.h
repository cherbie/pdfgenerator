#ifndef _PDF_DICT_H
#define _PDF_DICT_H

#include <ostream>
#include <map>
#include <string>
#include <utility>
#include <functional>
#include "pdfgen/Object.h"

namespace pdf
{
namespace data_type
{
  class Object;

  /** Base class for the pdf "Dictionary" object
    * example:
    * << /Name1 /ValueObjectName
    *     /Name2 3.14
    * >>
    */
  class Dictionary
  {
    using map_type = std::map<std::string, Object>;
    public:
      Dictionary() = default;
      Dictionary(const Dictionary& dict);
      virtual ~Dictionary();

      explicit operator bool() const;
      friend std::ostream& operator<<(std::ostream& os, const Dictionary& dict);
      friend bool operator==(const Dictionary& lvalue, const Dictionary& rvalue);

      std::pair<Object, bool> set(const std::string& key, const Object& value);
      Object& get(const std::string& key);

//       Object& operator[](const std::string key) const;

    private:
      map_type m_map;
  }; // class Dictionary
} // namespace data_type
} // namespace pdf

#endif // define _PDF_DICT_H
