

#include <Serialization/BinaryWriter.hpp>
#include <Serialization/Endianness.hpp>

namespace serialization {
    
    SERIALIZATION_DLL BinaryWriter::BinaryWriter(std::ostream& stream) : m_Stream(stream) {
      
    }
    
    SERIALIZATION_DLL BinaryWriter::~BinaryWriter() {
      
    }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const uint16_t& value) const {
      uint16_t tmp = endian::to_little_endian(value);
      m_Stream.write( reinterpret_cast<const char*>(&tmp), sizeof(uint16_t));
    }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const int16_t& value) const {
      int16_t tmp = endian::to_little_endian(value);
      m_Stream.write( reinterpret_cast<const char*>(&tmp), sizeof(int16_t));
    } 

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const uint32_t& value) const {
      uint32_t tmp = endian::to_little_endian(value);
      m_Stream.write( reinterpret_cast<const char*>(&tmp), sizeof(uint32_t));
    }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const int32_t& value) const {
      int32_t tmp = endian::to_little_endian(value);
      m_Stream.write( reinterpret_cast<const char*>(&tmp), sizeof(uint32_t));
    } 

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const uint64_t& value) const {
      uint64_t tmp = endian::to_little_endian(value);
      m_Stream.write( reinterpret_cast<const char*>(&tmp), sizeof(uint64_t));
   }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const int64_t& value) const {
      int64_t tmp = endian::to_little_endian(value);
      m_Stream.write( reinterpret_cast<const char*>(&tmp), sizeof(int64_t));
   }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const std::string& value) const {
      const size_t len = value.length();
      (*this)(len);
      m_Stream.write(value.c_str(), sizeof(char) * value.length() );
    }    
    
    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const float& value) const {
      float tmp = endian::to_little_endian(value);
      m_Stream.write( reinterpret_cast<const char*>(&tmp), sizeof(float));
    }
    
    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const double& value) const {
      double tmp = endian::to_little_endian(value);
      m_Stream.write( reinterpret_cast<const char*>(&tmp), sizeof(double));
    }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const long double& value) const {
      long double tmp = endian::to_little_endian(value);
      m_Stream.write( reinterpret_cast<const char*>(&tmp), sizeof(long double));
    }

    
}