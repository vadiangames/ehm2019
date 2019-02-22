
#include <Serialization/BinaryWriter.hpp>
#include <Serialization/BinaryReader.hpp>
#include <Serialization/Serializable.hpp>
#include <fstream>

class TestClass : public serialization::Serializable {
  
  int16_t m_Value;
  
  public:
  TestClass(int16_t val) : m_Value(val) {
  }
  
  ~TestClass() {}
  
  void load(serialization::BinaryReader& reader) override {
    reader( m_Value );
  }
  
  void save(const serialization::BinaryWriter& writer) const override {
    writer( m_Value );
  }
  
  int getValue() const {
    return m_Value;    
  }
  
};



int main(int argc, char** argv) {
 
  std::fstream log("SerializationTest.log", std::ios_base::out);

  int16_t val1 = 1;
  uint16_t val2 = 2;
  int32_t val3 = 3;
  uint32_t val4 = 4;
  int64_t val5 = 5;
  uint64_t val6 = 6;
  std::string val7 = "Hello World";
  float val8 = 1.2345;
  double val9 = 6.7890;
  TestClass val10(99);
  int32_t val11 = -1234;
 
  log << "Write Data... ";
  
  {
    std::ofstream stream;
    stream.open("SerializationTest.data", std::ios_base::binary);
    {
      serialization::BinaryWriter writer(stream);
        writer(val1);
        writer(val2);
        writer(val3);
        writer(val4);
        writer(val5);
        writer(val6);
        writer(val7);
        writer(val8);
        writer(val9);
        writer(val10);
        writer(val11);
    }
    stream.close();
  }
  
  log << "OK" << std::endl;
  
  int16_t ret1 = 0;
  uint16_t ret2 = 0;
  int32_t ret3 = 0;
  uint32_t ret4 = 0;
  int64_t ret5 = 0;
  uint64_t ret6 = 0;
  std::string ret7 = "";
  float ret8 = 0;
  double ret9 = 0;
  TestClass ret10(0);
  int32_t ret11 = 0;
  
  log << "Read data... ";
  
  {
    std::ifstream stream;
    stream.open("SerializationTest.data", std::ios_base::binary);
    {
       serialization::BinaryReader reader(stream);
        reader(ret1);
        reader(ret2);
        reader(ret3);
        reader(ret4);
        reader(ret5);
        reader(ret6);
        reader(ret7);
        reader(ret8);
        reader(ret9);
        reader(ret10);
        reader(ret11);
    }
    stream.close();
  }
  
  log << "OK" << std::endl;
  
  if(val1 != ret1) {
    log << "[ERROR] ret1 has wrong value " << ret1 << " should be " << val1 << std::endl;
    return -1;
  }
  
  if(val2 != ret2) {
    log << "[ERROR] ret2 has wrong value " << ret2 << " should be " << val2 << std::endl;
    return -1;
  }
  
  if(val3 != ret3) {
    log << "[ERROR] ret3 has wrong value " << ret3 << " should be " << val3 << std::endl;
    return -1;
  }
  
  if(val4 != ret4) {
    log << "[ERROR] ret4 has wrong value " << ret4 << " should be " << val4 << std::endl;
    return -1;
  }
  
  if(val5 != ret5) {
    log << "[ERROR] ret5 has wrong value " << ret5 << " should be " << val5 << std::endl;
    return -1;
  }
  
  if(val6 != ret6) {
    log << "[ERROR] ret6 has wrong value " << ret6 << " should be " << val6 << std::endl;
    return -1;
  }
  
  if(val7 != ret7) {
    log << "[ERROR] ret7 has wrong value " << ret7 << " should be " << val7 << std::endl;
    return -1;
  }
  
  if(val8 != ret8) {
    log << "[ERROR] ret8 has wrong value " << ret8 << " should be " << val8 << std::endl;
    return -1;
  }
  
  if(val9 != ret9) {
    log << "[ERROR] ret9 has wrong value " << ret9 << " should be " << val9 << std::endl;
    return -1;
  }
  
  if(val10.getValue() != ret10.getValue()) {
    log << "[ERROR] ret10 has wrong value " << ret10.getValue() << " should be " << val10.getValue() << std::endl;
    return -1;
  }
  
  if(val11 != ret11) {
    log << "[ERROR] ret11 has wrong value " << ret11 << " should be " << val11 << std::endl;
    return -1;
  }
  
  log << "[SUCCESFUL]" << std::endl;
  log.close();
  
  return 0;
}