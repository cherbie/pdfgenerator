#ifndef _INTEGER_H
#define _INTEGER_H

#include <ostream>

// PDF "number" representation handler
namespace pdf
{
  namespace data_type
  {
    template <class T>
    class Integer
    {
	    public:
		    Integer() = delete;
        Integer(T value);
		    ~Integer();

        template <typename U>
        friend bool operator==(const Integer<U>& lvalue, const U& rvalue);

        template <typename U>
        friend std::ostream& operator<<(std::ostream& os, const Integer<U>& i);

     private:
        T m_value;
    }; // class Integer

    template <typename T>
    bool operator==(const Integer<T>& lvalue, const T& rvalue)
    {
      return lvalue.m_value == rvalue;
    }

    template <typename T>
    std::ostream& operator<<(std::ostream& os, const Integer<T>& i)
    {
      os << std::showpos
         << i.m_value;
      return os;
    }
  } // namespace data_type
} // namespace pdf

#endif // define _INTEGER_H
