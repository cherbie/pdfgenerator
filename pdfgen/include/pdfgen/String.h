#ifndef _PDF_STRING_H
#define _PDF_STRING_H

#include <string>
#include <ostream>

// Base class for pdf String object
namespace pdf
{
  namespace data_type
  {
    class String
    {
	    public:
		    String() = delete;
        String(const char* ptr);
        String(const std::string& str);
		    ~String();

        friend std::ostream& operator<<(std::ostream& os, const String& obj);
        friend bool operator==(const String& s, const std::string& r_str);

      private:
        std::string m_value;
    }; // class String

    std::ostream& operator<<(std::ostream& os, const String& obj)
    {
      os << "(" << obj.m_value << ")";
      return os;
    }

    bool operator==(const String& s, const std::string& r_str)
    {
      return s.m_value == r_str;
    }
  } // namespace data_type
} // namespace pdf
#endif // _PDF_STRING_H
