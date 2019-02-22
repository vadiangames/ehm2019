
#include <Database/Nation.hpp>

namespace db {
  
  DATABASE_DLL Nation::Nation() : m_Continent(nullptr) {
    
  }
  
  DATABASE_DLL Nation::Nation(const std::string& name, Id continentId) : m_Name(name) {
    m_Continent = ObjectManager<Continent>::getInstance().get( continentId );
  }
  
  
  DATABASE_DLL Nation::~Nation() {
    
  }

  std::string DATABASE_DLL Nation::getName() const {
    return m_Name;
  }
  
  Continent* DATABASE_DLL Nation::getContinent() {
    return m_Continent;
  }
  
  void DATABASE_DLL Nation::load(serialization::BinaryReader& reader){
    Object::load(reader);
    reader( m_Name ); 
    Id id;
    reader( id );
    m_Continent = ObjectManager<Continent>::getInstance().get(id);
  }

  
  
}