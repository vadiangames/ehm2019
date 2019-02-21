#ifndef SERIALIZATION_BINARYWRITER_HPP
#define SERIALIZATION_BINARYWRITER_HPP

#include <Serialization/DLL.hpp>

#include <fstream>
#include <cmath>

namespace serialization {
  
  class SERIALIZATION_DLL BinaryWriter {
  
    std::ostream& m_Stream;
    
    public:
    BinaryWriter(std::ostream& stream);
    ~BinaryWriter();
    
    template<class T>
    void operator() (const T& value) const {
      value.save((*this));
    }
    
    template<class T>
    void operator() (const char* id, T& value) const {
      (*this)(value);
    }
  
  };
  
  template<>
  void SERIALIZATION_DLL BinaryWriter::operator()(const uint16_t& value) const;

  template<>
  void SERIALIZATION_DLL BinaryWriter::operator()(const int16_t& value) const;

  template<>
  void SERIALIZATION_DLL BinaryWriter::operator()(const uint32_t& value) const;

  template<>
  void SERIALIZATION_DLL BinaryWriter::operator()(const int32_t& value) const;

  template<>
  void SERIALIZATION_DLL BinaryWriter::operator()(const uint64_t& value) const;

  template<>
  void SERIALIZATION_DLL BinaryWriter::operator()(const int64_t& value) const;

  template<>
  void SERIALIZATION_DLL BinaryWriter::operator()(const std::string& value) const;

  template<>
  void SERIALIZATION_DLL BinaryWriter::operator()(const double_t& value) const;

  template<>
  void SERIALIZATION_DLL BinaryWriter::operator()(const double& value) const;

  template<>
  void SERIALIZATION_DLL BinaryWriter::operator()(const float& value) const;
  
}

#endif