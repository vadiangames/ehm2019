add_library(Serialization SHARED BinaryWriter.cpp BinaryReader.cpp Serializable.cpp)
target_compile_definitions(Serialization PUBLIC BUILDING_SERIALIZATION_DLL) 

include (TestBigEndian)
TEST_BIG_ENDIAN(IS_BIG_ENDIAN)
if(IS_BIG_ENDIAN)
 message(STATUS "BIG_ENDIAN")
else()
 message(STATUS "LITTLE_ENDIAN")
endif()

install(
	TARGETS Serialization EXPORT FM2019Targets
	RUNTIME DESTINATION "${PROJECT_SOURCE_DIR}/bin" COMPONENT bin
	LIBRARY DESTINATION "${PROJECT_SOURCE_DIR}/lib" COMPONENT bin
	ARCHIVE DESTINATION "${PROJECT_SOURCE_DIR}/lib" COMPONENT dev
)