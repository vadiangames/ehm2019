
#include <Database/Continent.hpp>

namespace db {
  
  DATABASE_DLL Continent::Continent() {
    
  }
  
  DATABASE_DLL Continent::Continent(const std::string& name) : m_Name(name) {
    
  }
  
  
  DATABASE_DLL Continent::~Continent() {
    
  }

  std::string DATABASE_DLL Continent::getName() const {
    return m_Name;
  }
  
}