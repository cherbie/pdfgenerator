#ifndef _NUMBER_H
#define _NUMBER_H

#include <ostream>

namespace pdf
{
  namespace data_type
  {
    template <class T>
    class Number
    {
      protected:
        Number() = delete;
        virtual Number(T n);
        virtual Number(const T& n);
        virtual ~Number();

        virtual Number& operator =(const T& n);
    }; // class Number
  } // namespace data_type
} // namespace pdf

#endif // define _NUMBER_H
