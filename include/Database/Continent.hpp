#ifndef DATABASE_CONTINENT_HPP
#define DATABASE_CONTINENT_HPP

#include <Database/Object.hpp>
#include <string>

namespace db {
  
  class DATABASE_DLL Continent : public Object {
    
    std::string m_Name;
    
    public:
    Continent();
    explicit Continent(const std::string& name);
    ~Continent();

    std::string getName() const;
    
    void save(const serialization::BinaryWriter& writer) const
    {
      Object::save(writer);
      writer( m_Name ); 
    }

    void load(serialization::BinaryReader& reader)
    {
      Object::load(reader);
      reader( m_Name ); 
    }
    
    
  };
  
}

#endif