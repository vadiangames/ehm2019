
#ifndef SERIALIZATION_ENDIANNESS_HPP
#define SERIALIZATION_ENDIANNESS_HPP

#include <cstdlib>

#if __BYTE_ORDER__ == __ORDER_LITTLE_ENDIAN__
  #define LITTLE_ENDIAN
#else
  #define BIG_ENDIAN
#endif

namespace serialization {
  namespace endian {
    
    template<class T>
    T swap_endian(T u) {
      union {
        T u;
        unsigned char u8[sizeof(T)];
      } source,dest;
      source.u = u;
      for(size_t k = 0; k < sizeof(T); k++) {
        dest.u8[k] = source.u8[sizeof(T) - k - 1];
      }
      return dest.u;
    }
    
    template<class T>
    T to_big_endian(T value) {
       #ifdef LITTLE_ENDIAN
        return swap_endian(value);
      #else
        return value;
      #endif   
    }
    
    template<class T>
    T to_little_endian(T value) {
       #ifdef LITTLE_ENDIAN
        return value;
      #else
        return swap_endian(value);;
      #endif      
    }
  }
}

#endif