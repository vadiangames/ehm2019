#include <Database/City.hpp>

namespace db {

  DATABASE_DLL City::City() : m_Region(nullptr) {
    
  }
  
  DATABASE_DLL City::City(const std::string& name, Id regionId) : m_Name(name) {
    m_Region = ObjectManager<Region>::getInstance().get(regionId);
  }
  
  DATABASE_DLL City::~City() {
    
  }

  std::string DATABASE_DLL City::getName() const {
    return m_Name;
  }
    
  Continent* DATABASE_DLL City::getContinent() {
    Nation* tmp = getNation();
    return (tmp) ? tmp->getContinent() : nullptr;
  }
  
  Nation* DATABASE_DLL City::getNation() {
    return (m_Region) ? m_Region->getNation() : nullptr;
  }
  
  Region* DATABASE_DLL City::getRegion() {
    return m_Region;
  }
}

