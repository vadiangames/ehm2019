#ifndef DATABASE_OBJECT_HPP
#define DATABASE_OBJECT_HPP


#include <Database/DLL.hpp>
#include <Serialization/Serializable.hpp>
#include <cstdint>


namespace db {
  
  typedef uint64_t Id;
  
  class DATABASE_DLL Object : public serialization::Serializable {
    
    Id m_Id;
    
    public:
    Object();
    virtual ~Object();

    Id getId() const;
    void setId(Id id);
    
    bool operator == (const Object& obj) const;
    
    virtual void save(const serialization::BinaryWriter& writer) const override
    {
      writer( m_Id ); 
    }

    virtual void load(serialization::BinaryReader& reader) override
    {
      reader( m_Id ); 
    }
    
    
  };
  
}

#endif