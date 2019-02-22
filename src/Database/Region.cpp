
#include <Database/Region.hpp>


namespace db {
  
  DATABASE_DLL Region::Region() : m_Nation(nullptr) {
    
  }
  
  DATABASE_DLL Region::Region(const std::string& name, Id NationId) : m_Name(name) {
    m_Nation = ObjectManager<Nation>::getInstance().get( NationId );
  }
  
  
  DATABASE_DLL Region::~Region() {
    
  }

  std::string DATABASE_DLL Region::getName() const {
    return m_Name;
  }
  
  Nation* DATABASE_DLL Region::getNation() {
    return m_Nation;
  }
  
  Continent* DATABASE_DLL Region::getContinent() {
    return m_Nation ? m_Nation->getContinent() : nullptr;
  }
  
  void DATABASE_DLL Region::load(serialization::BinaryReader& reader){
    Object::load(reader);
    reader( m_Name ); 
    Id id;
    reader( id );
    m_Nation = ObjectManager<Nation>::getInstance().get(id);
  }
  
  
}