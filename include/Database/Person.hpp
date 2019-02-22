#ifndef DATABASE_PERSON_HPP
#define DATABASE_PERSON_HPP

#include <Database/Date.hpp>
#include <Database/Nation.hpp>

namespace db {
  class DATABASE_DLL Person : public Object {
    
    std::string m_FirstName;
    std::string m_LastName;
    Date        m_Birthdate;
    Nation*     m_FirstNationality;
    Nation*     m_SecondNationality;
    
    public:
    Person();
    Person(const std::string& firstName, const std::string& lastName, const Date& birthDate, Id nationality, Id secondNationality);
    virtual ~Person();
    
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getFullName() const;
    Date getBirthdate() const;
    uint16_t getAge(Date today) const;
    Nation* getNationality();
    Nation* getSecondNationality();
    
    virtual void save(const serialization::BinaryWriter& writer) const override
    {
      Object::save(writer);
      writer( m_FirstName );
      writer( m_LastName );
      writer( m_Birthdate );
      if(m_FirstNationality) {
        writer( m_FirstNationality->getId() );
      } else {
        Id id = 0;
        writer( id );
      }
      if(m_SecondNationality) {
        writer( m_SecondNationality->getId() );
      } else {
        Id id = 0;
        writer( id );
      }
    }

    virtual void load(serialization::BinaryReader& reader) override
    {
      Object::load(reader);
      reader( m_FirstName );
      reader( m_LastName );
      reader( m_Birthdate );
      Id id;
      reader( id );
      m_FirstNationality = ObjectManager<Nation>::getInstance().get(id);
      reader( id );
      m_SecondNationality = ObjectManager<Nation>::getInstance().get(id);
    }
    
  };
}

#endif