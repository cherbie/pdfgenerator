#ifndef _NAME_H
#define _NAME_H

#include <string>
#include <ostream>

// base class for a pdf "Name" object
// example: /AValidName
namespace pdf
{
  namespace data_type
  {
    class Name
    {
      public:
		    Name(const std::string& title);
        Name() = delete;
        ~Name();

        friend std::ostream& operator<<(std::ostream& os, const Name& obj);
      private:
        std::string m_value;
    }; // class Name

    std::ostream& operator<<(std::ostream& os, const Name& obj);
  } // namespace data_type
} // namespace pdf
#endif // define _NAME_H
