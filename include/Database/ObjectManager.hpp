#ifndef DATABASE_OBJECTMANAGER_HPP
#define DATABASE_OBJECTMANAGER_HPP

#include <Database/Object.hpp>
#include <list>

namespace db {
  
  template<class T>
  class DATABASE_DLL ObjectManager : public serialization::Serializable {
    
    std::list<T> m_Data;
    Id m_NextId;
    
    public:
    ObjectManager() {
      m_NextId = 1;
    }
    
    ~ObjectManager() {
      
    }
    
    static ObjectManager<T>& getInstance();
    
    T* create(T object) {
      object.setId( m_NextId );
      m_NextId++;
      m_Data.push_back(object);
      return &m_Data.back();
    }
    
    T* get( Id id ) {
      for(auto& obj : m_Data) {
        if(obj.getId() == id) {
          return &obj;
        }
      }
      return nullptr;
    }
    
    void clear() {
      m_Data.clear();
      m_NextId = 1;
    }
    
    bool remove( Id id ) {
      T* obj = get(id);
      if( obj ) {
        m_Data.remove(*obj);
        return true;
      }
      return false;
    }
    
    void save(const serialization::BinaryWriter& writer) const override
    {
      writer( m_NextId ); 
      writer(m_Data.size());
      for(auto& obj : m_Data) {
        writer(obj);
      }
    }

    void load(serialization::BinaryReader& reader) override
    {
      reader( m_NextId );
      size_t size;
      reader(size);
      for(size_t x = 0; x < size; ++x) {
        T obj;
        reader(obj);
        m_Data.push_back(obj);
      }
    }
    
    
  };
  
}

#endif