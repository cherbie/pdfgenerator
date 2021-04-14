#include <stdio>

namespace pdf
{
  class PdfWriter
  {
	  protected:
		  PdfWriter();
		  ~PdfWriter();
	  private:
		  std::cout m_stream;
  }; // class PdfWriter
} // namespace pdf
