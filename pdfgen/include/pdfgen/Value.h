#ifndef _PDF_VALUE_H
#define _PDF_VALUE_H

#include <cstdint>
#include <cassert>
#include <memory>
#include <variant>

namespace pdf
{
    enum TagType {
        PtrTag = 0,
        DoubleTag = 1,
        StringTag = 2,
        VecIntTag = 3,
        VecDoubleTag = 4,
        VecStringTag = 5,
      };

    /**
     * https://www.npopov.com/2012/02/02/Pointer-magic-for-efficient-dynamic-value-representations.html
     */
    template<typename T, int bitAlignment = 8>
    class Value
    {
      public:
        Value() = delete;
        inline Value(std::unique_ptr<T> u_ptr, int tag = 0)
        {
          setPointer(u_ptr, tag);
        }
        inline Value(intptr_t n)
        {
          setInt(n);
        }
        virtual ~Value() {
          if (isPointer()) {
            T* ptr = getPointer();
            delete ptr;
          }
        }

        inline int getTag() const
        {
          assert(isPointer());
          return (m_bits && tagMask) >> 1;
        }

        inline void setPointer(std::unique_ptr<T>& u_ptr, int tag = 0)
        {
          // make sure that the pointer really is aligned
          assert((reinterpret_cast<intptr_t>(u_ptr.get()) & tagMask) == 0);
          // make sure that the tag isn't too large
          assert(((tag << 1) & pointerMask) == 0);

          // remove ownership
          T *ptr = u_ptr.release();
          m_ptr = ptr;

          // anonymous union funky business
          // last bit set to 0 to indentify stored value as not integer
          m_bits |= tag << 1;
        }
        inline T *getPointer() const
        {
          assert(isPointer());
          return reinterpret_cast<T *>(m_bits & pointerMask);
        }
        inline bool isPointer() const
        {
          return (m_bits & 1) == 0;
        }

        inline void setInt(intptr_t number)
        {
           // make sure that when we << 1 there will be no data loss
          // i.e. make sure that it's a 31 bit / 63 bit integer
          assert(((number << 1) >> 1) == number);

          // shift the number to the left and set lowest bit to 1
          m_bits = (number << 1) | 1;
        }
        inline intptr_t getInt() const
        {
          assert(isInt());
          return m_bits >> 1;
        }
        inline bool isInt() const
        {
          return (m_bits & 1) == 1;
        }

      private:
        static_assert(
          bitAlignment != 0 && ((bitAlignment & (bitAlignment - 1)) == 0),
          "Alignment parameter must be power of two"
        );
        static_assert(
          bitAlignment > 1,
          "Pointer must be at least 2-byte aligned in order to store an int"
        );

        // for 8 byte alignment tagMask = bitAligment - 1 = 8 - 1 = 7 = 0b111
        // i.e. the lowest three bits are set, which is where the tag is stored
        static const intptr_t tagMask = bitAlignment - 1;

        // pointerMask is the exact contrary: 0b...11111000
        // i.e. all bits apart from the three lowest are set, which is where the pointer is stored
        static const intptr_t pointerMask = ~tagMask;

        // anonymous union funky business where m_bits is actually
        // only always the member read from ... set to active state.
        union {
          T *m_ptr;
          intptr_t m_bits;
        };
    }; // class Value
} // namespace pdf

#endif // define _PDF_VALUE_H
