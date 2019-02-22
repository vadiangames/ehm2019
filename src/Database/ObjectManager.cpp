
#include <Database/ObjectManager.hpp>
#include <Database/Continent.hpp>
#include <Database/Nation.hpp>
#include <Database/Region.hpp>

namespace db {
  
  template<>
  ObjectManager<Continent>& DATABASE_DLL ObjectManager<Continent>::getInstance() {
    static ObjectManager<Continent> instance;
    return instance;
  }
  
  template<>
  ObjectManager<Nation>& DATABASE_DLL ObjectManager<Nation>::getInstance() {
    static ObjectManager<Nation> instance;
    return instance;
  }

  template<>
  ObjectManager<Region>& DATABASE_DLL ObjectManager<Region>::getInstance() {
    static ObjectManager<Region> instance;
    return instance;
  }  
}