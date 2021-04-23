#ifndef _PDF_BOOL_H
#define _PDF_BOOL_H

#include <ostream>

namespace pdf
{
  namespace data_type
  {
    class Bool
    {
      public:
        Bool() = delete;
        Bool(bool b);
        Bool& operator=(bool b);
        ~Bool();

        explicit operator bool() const
        {
          return m_value;
        }

        friend bool operator==(const Bool& lvalue, const Bool& rvalue)
        {
          return lvalue.m_value == rvalue.m_value;
        }

        friend std::ostream& operator<<(std::ostream& os, const Bool& b)
        {
          if (b)
            os << "true";
          else
            os << "false";
          return os;
        }

      private:
        bool m_value;
    }; // class Bool

    std::ostream& operator<<(std::ostream& os, bool b)
    {
      if (b)
        os << "true";
      else
        os << "false";
      return os;
    }
  } // namespace data_type
} // namespace pdf
#endif // define _PDF_BOOL_H
