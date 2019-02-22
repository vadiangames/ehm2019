#ifndef DATABASE_DLL_HPP
#define DATABASE_DLL_HPP 

#ifdef BUILDING_DATABASE_DLL
  #define DATABASE_DLL __declspec(dllexport)
#else
  #define DATABASE_DLL __declspec(dllimport)
#endif

#endif