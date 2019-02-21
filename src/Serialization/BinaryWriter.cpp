
#include <Serialization/BinaryWriter.hpp>

namespace serialization {
    
    SERIALIZATION_DLL BinaryWriter::BinaryWriter(std::ostream& stream) : m_Stream(stream) {
      
    }
    
    SERIALIZATION_DLL BinaryWriter::~BinaryWriter() {
      
    }
    
    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const uint16_t& value) const {
      m_Stream.write(reinterpret_cast<const char*>(&value), sizeof(uint16_t));
    }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const int16_t& value) const {
      m_Stream.write(reinterpret_cast<const char*>(&value), sizeof(int16_t));
    } 

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const uint32_t& value) const {
      m_Stream.write(reinterpret_cast<const char*>(&value), sizeof(uint32_t));
    }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const int32_t& value) const {
      m_Stream.write(reinterpret_cast<const char*>(&value), sizeof(int32_t));
    } 

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const uint64_t& value) const {
      m_Stream.write(reinterpret_cast<const char*>(&value), sizeof(uint64_t));
    }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const int64_t& value) const {
      m_Stream.write(reinterpret_cast<const char*>(&value), sizeof(int64_t));
    }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const std::string& value) const {
      const size_t len = value.length();
      (*this)(len);
      m_Stream.write(value.c_str(), sizeof(char) * value.length() );
    }    
    
    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const float& value) const {
      m_Stream.write(reinterpret_cast<const char*>(&value), sizeof(float));
    }
    template<>

    void SERIALIZATION_DLL BinaryWriter::operator()(const double& value) const {
      m_Stream.write(reinterpret_cast<const char*>(&value), sizeof(double));
    }

    template<>
    void SERIALIZATION_DLL BinaryWriter::operator()(const double_t& value) const {
      m_Stream.write(reinterpret_cast<const char*>(&value), sizeof(double_t));
    }

    
}