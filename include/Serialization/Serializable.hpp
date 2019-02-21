#ifndef SERIALIZATION_SERIALIZABLE_HPP
#define SERIALIZATION_SERIALIZABLE_HPP

#include <Serialization/BinaryReader.hpp>
#include <Serialization/BinaryWriter.hpp>

namespace serialization {

  class SERIALIZATION_DLL Serializable {
    
    public:
    Serializable();
    virtual ~Serializable();
    
    virtual void save( const BinaryWriter& writer ) const = 0;    
    virtual void load(BinaryReader& read) = 0;

  };

}

#endif