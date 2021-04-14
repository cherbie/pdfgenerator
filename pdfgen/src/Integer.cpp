#include "pdfgen/Integer.h"

namespace pdf
{
  namespace data_type
  {
    template <class T>
    Integer<T>::Integer(T value)
    : m_value(value)
    {
    }

    template <class T>
    Integer<T>::~Integer()
    {
    }

    template class Integer<int>;
    template class Integer<double>;
    template class Integer<float>;
  } // namespace data_type
} // namespace pdf
