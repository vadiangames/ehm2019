#ifndef DATABASE_REGION_HPP
#define DATABASE_REGION_HPP

#include <Database/Nation.hpp>
#include <Database/ObjectManager.hpp>

namespace db {
  
  class DATABASE_DLL Region : public Object {
    
    std::string m_Name;
    Nation*  m_Nation;
    
    public:
    Region();
    Region(const std::string& name, Id nationId);
    ~Region();

    std::string getName() const;
    Nation* getNation();
    Continent* getContinent();
    
    void save(const serialization::BinaryWriter& writer) const override
    {
      Object::save(writer);
      writer( m_Name );
      if(m_Nation) {
        writer( m_Nation->getId() );
      } else {
        Id id = 0;
        writer( id );
      }
    }

    void load(serialization::BinaryReader& reader) override;
    
    
  };
  
}

#endif