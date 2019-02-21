#ifndef SERIALIZATION_DLL_HPP
#define SERIALIZATION_DLL_HPP 

#ifdef BUILDING_SERIALIZATION_DLL
  #define SERIALIZATION_DLL __declspec(dllexport)
#else
  #define SERIALIZATION_DLL __declspec(dllimport)
#endif

#endif