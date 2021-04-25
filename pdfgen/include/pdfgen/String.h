#ifndef _PDF_STRING_H
#define _PDF_STRING_H

#include <string>
#include <ostream>
#include <memory>
#include <cstdlib>

// Base class for pdf String object
namespace pdf
{
  namespace data_type
  {
    class String
    {
	    public:
		    String() = default;
        String(const char* c_ptr);
        String(const char* c_ptr, std::size_t n);
        String(const std::string& str);
        String(const String& str);
        String& operator=(const String& str);
		    virtual ~String();

        explicit operator bool() const;
        friend std::ostream& operator<<(std::ostream& os, const String& obj);
        friend bool operator==(const String& lvalue, const String& rvalue);
        friend bool operator==(const std::string& lvalue, const String& rvalue);
        friend bool operator==(const String& lvalue, const std::string& rvalue);

      private:
        std::unique_ptr<std::string> m_str = nullptr;
    }; // class String
  } // namespace data_type
} // namespace pdf
#endif // _PDF_STRING_H
