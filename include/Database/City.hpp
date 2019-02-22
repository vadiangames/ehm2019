#ifndef DATABASE_CITY_HPP
#define DATABASE_CITY_HPP

#include <Database/Region.hpp>
#include <Database/ObjectManager.hpp>

namespace db {
  
  class DATABASE_DLL City : public Object {
    
    std::string m_Name;
    Region*  m_Region;
    
    public:
    City();
    City(const std::string& name, Id regionId);
    ~City();

    std::string getName() const;
    
    Continent* getContinent();
    Nation* getNation();
    Region* getRegion();
    
    template<class Archive>
    void save(const serialization::BinaryWriter& writer) const
    {
      Object::save(writer);
      writer( m_Name );
      if(m_Region) {
        writer( m_Region->getId() );
      } else {
        Id id = 0;
        writer( id );
      }
    }

    template<class Archive>
    void load(serialization::BinaryReader& reader)
    {
      Object::load(reader);
      reader( m_Name ); 
      Id id;
      reader( id );
      m_Region = ObjectManager<Region>::getInstance().get(id);
    }
    
    
  };
  
}

#endif