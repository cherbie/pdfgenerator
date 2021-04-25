#ifndef _PDF_NAME_H
#define _PDF_NAME_H

#include <string>
#include <ostream>
#include <memory>

// base class for a pdf "Name" object
// example: /AValidName
namespace pdf
{
  namespace data_type
  {
    class Name
    {
      public:
        Name() = default;
        Name(const Name& name);
        Name(const std::string& title);
        virtual ~Name();

        explicit operator bool() const;
        friend bool operator==(const Name& lvalue, const Name& rvalue);
        friend std::ostream& operator<<(std::ostream& os, const Name& obj);

      private:
        std::unique_ptr<std::string> m_name = nullptr;
    }; // class Name
  } // namespace data_type
} // namespace pdf
#endif // define _PDF_NAME_H
