
#include <Serialization/BinaryReader.hpp>
#include <Serialization/Endianness.hpp>

namespace serialization {
 
  SERIALIZATION_DLL BinaryReader::BinaryReader(std::istream& stream) : m_Stream(stream) {
    
  }
 
  SERIALIZATION_DLL BinaryReader::~BinaryReader() {
    
  }
    
  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(uint16_t& value) {
    m_Stream.read(reinterpret_cast<char*>(&value), sizeof(uint16_t));
    #ifdef BIG_ENDIAN
      value = serialization::endian::swap_endian(value);
    #endif
  }

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(int16_t& value) {
    m_Stream.read(reinterpret_cast<char*>(&value), sizeof(int16_t));
    #ifdef BIG_ENDIAN
      value = serialization::endian::swap_endian(value);
    #endif
  } 

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(uint32_t& value) {
    m_Stream.read(reinterpret_cast<char*>(&value), sizeof(uint32_t));
    #ifdef BIG_ENDIAN
      value = serialization::endian::swap_endian(value);
    #endif
  }

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(int32_t& value) {
    m_Stream.read(reinterpret_cast<char*>(&value), sizeof(int32_t));
    #ifdef BIG_ENDIAN
      value = serialization::endian::swap_endian(value);
    #endif
  } 

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(uint64_t& value) {
    m_Stream.read(reinterpret_cast<char*>(&value), sizeof(uint64_t));
    #ifdef BIG_ENDIAN
      value = serialization::endian::swap_endian(value);
    #endif
  }

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(int64_t& value) {
    m_Stream.read(reinterpret_cast<char*>(&value), sizeof(int64_t));
    #ifdef BIG_ENDIAN
      value = serialization::endian::swap_endian(value);
    #endif
  }
  
  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(double_t& value) {
    m_Stream.read(reinterpret_cast<char*>(&value), sizeof(double_t));
    #ifdef BIG_ENDIAN
      value = serialization::endian::swap_endian(value);
    #endif
  }

  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(double& value) {
    m_Stream.read(reinterpret_cast<char*>(&value), sizeof(double));
    #ifdef BIG_ENDIAN
      value = serialization::endian::swap_endian(value);
    #endif
  }
  
  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(float& value) {
    m_Stream.read(reinterpret_cast<char*>(&value), sizeof(float));
    #ifdef BIG_ENDIAN
      value = serialization::endian::swap_endian(value);
    #endif
  }
  
  template<>
  void SERIALIZATION_DLL BinaryReader::operator()(std::string& value) {
    size_t len = 0;
    (*this)(len);
    char* tmp = new char[len+1];
    m_Stream.read(tmp, sizeof(char)*len);
    tmp[len] = '\0';
    value = std::string(tmp);
    delete[] tmp;
  }  

}