
#include <Database/Object.hpp>

namespace db {
  
  DATABASE_DLL Object::Object() {
    m_Id = 0;
  }
  
  DATABASE_DLL Object::~Object() {
    
  }

  Id DATABASE_DLL Object::getId() const {
    return m_Id;
  }
  
  void DATABASE_DLL Object::setId(Id id) {
    m_Id = id;
  }
    
  bool DATABASE_DLL Object::operator == (const Object& obj) const {
    return m_Id == obj.m_Id;
  }
}