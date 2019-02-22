#ifndef DATABASE_NATION_HPP
#define DATABASE_NATION_HPP

#include <Database/Continent.hpp>
#include <Database/ObjectManager.hpp>

namespace db {
  
  class DATABASE_DLL Nation : public Object {
    
    std::string m_Name;
    Continent*  m_Continent;
    
    public:
    Nation();
    Nation(const std::string& name, Id continentId);
    ~Nation();

    std::string getName() const;
    Continent* getContinent();
    
    void save(const serialization::BinaryWriter& writer) const override
    {
      Object::save(writer);
      writer( m_Name );
      if(m_Continent) {
        writer( m_Continent->getId() );
      } else {
        Id id = 0;
        writer( id );
      }
    }

    void load(serialization::BinaryReader& reader) override;    
    
  };
  
}

#endif