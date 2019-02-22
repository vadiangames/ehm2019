#include <Database/Person.hpp>

namespace db {
  DATABASE_DLL Person::Person() {
    
  }
  
  DATABASE_DLL Person::Person(const std::string& firstName, const std::string& lastName, const Date& birthDate, Id nationality, Id secondNationality = 0) {
    
  }
  
  DATABASE_DLL Person::~Person() {
    
  }
    
  std::string DATABASE_DLL Person::getFirstName() const {
    return m_FirstName;
  }
  
  std::string DATABASE_DLL Person::getLastName() const {
    return m_LastName;
  }
  
  std::string DATABASE_DLL Person::getFullName() const {
    return m_FirstName + " " + m_LastName;
  }
  
  Date DATABASE_DLL Person::getBirthdate() const {
    return m_Birthdate;
  }
  
  uint16_t DATABASE_DLL Person::getAge(Date today) const {
    return m_Birthdate.getFullYearDifference( today );
  }
  
  Nation* DATABASE_DLL Person::getNationality() {
    return m_FirstNationality;
  }
  
  Nation* DATABASE_DLL Person::getSecondNationality() {
    return m_SecondNationality;
  }
}