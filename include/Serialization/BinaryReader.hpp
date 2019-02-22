#ifndef SERIALIZATION_BINARYREADER_HPP
#define SERIALIZATION_BINARYREADER_HPP

#include <Serialization/DLL.hpp>
#include <fstream>
#include <cmath>
#include <list>

namespace serialization {
  class SERIALIZATION_DLL BinaryReader {
    
    std::istream& m_Stream;
    
    public:
    BinaryReader(std::istream& stream);
    ~BinaryReader();
    
    template<class T>
    void operator() (T& value) {
      value.load( (*this) );
    }

  };

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(uint16_t& value);

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(int16_t& value);

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(uint32_t& value);

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(int32_t& value);

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(uint64_t& value);

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(int64_t& value);

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(double_t& value);

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(double& value);

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(float& value);


  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(std::string& value);

}

#endif