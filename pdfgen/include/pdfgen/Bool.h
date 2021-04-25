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
        Bool() = default;
        Bool(bool b);
        virtual ~Bool();

        explicit operator bool() const;

        friend bool operator==(const Bool& lvalue, const Bool& rvalue);
        friend std::ostream& operator<<(std::ostream& os, const Bool& b);

      private:
        bool m_bool = false;
    }; // class Bool

    std::ostream& operator<<(std::ostream& os, bool b);
  } // namespace data_type
} // namespace pdf
#endif // define _PDF_BOOL_H
