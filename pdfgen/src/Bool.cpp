#include "pdfgen/Bool.h"

namespace pdf
{
  namespace data_type
  {
    Bool::Bool(bool b)
    : m_value(b)
    {
    }

    Bool::~Bool()
    {
    }

    Bool& Bool::operator =(bool b)
    {
      m_value = b;
      return *this;
    }
  } // namespace data_type
} // namespace pdf

