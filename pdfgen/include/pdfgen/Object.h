#ifndef _PDF_OBJECT_H
#define _PDF_OBJECT_H

#include <ostream>
#include <memory>

#include "pdfgen/String.h"
#include "pdfgen/Name.h"
#include "pdfgen/Integer.h"
#include "pdfgen/Dictionary.h"

namespace pdf
{
namespace data_type
{
    class Dictionary;

    class Object
    {
        public:
            Object() = default;
            virtual ~Object();
            Object(const Object& obj);
            Object(const String& str);
            Object(const Name& name);
            Object(const Integer& n);
            Object(const Dictionary& dict);

            explicit operator bool() const;
            friend std::ostream& operator<<(std::ostream& os, const Object& obj);
            friend bool operator==(const Object& lvalue, const Object& rvalue);

        private:
            std::unique_ptr<String> m_str = nullptr;
            std::unique_ptr<Name> m_name = nullptr;
            std::unique_ptr<Integer> m_int = nullptr;
            std::unique_ptr<Dictionary> m_dict = nullptr;
    }; // class Object
} // namespace data_type
} // namespace pdf

#endif // define _PDF_OBJECT_H
