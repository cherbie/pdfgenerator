#ifndef _PDF_INTEGER_H
#define _PDF_INTEGER_H

#include <ostream>
#include <memory>

#include "pdfgen/Value.h"

namespace pdf
{
    /**
     * PDF "number" representation handler
     */
    class Integer: public Value<int, 8>
    {
	    public:
		    Integer();
        Integer(int n);
        Integer(double n);
        Integer(float n);
        Integer(const Integer& n);
        virtual ~Integer();

        explicit operator bool() const;
        friend bool operator==(const Integer& lvalue, int rvalue);
        friend bool operator==(int lvalue, const Integer& rvalue);
        friend bool operator==(const Integer& lvalue, const Integer& rvalue);
        friend std::ostream& operator<<(std::ostream& os, const Integer& obj);
    }; // class Integer
} // namespace pdf

#endif // define _PDF_INTEGER_H
