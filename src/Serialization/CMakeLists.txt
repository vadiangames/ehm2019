add_library(Serialization SHARED BinaryWriter.cpp BinaryReader.cpp Serializable.cpp)
target_compile_definitions(Serialization PUBLIC BUILDING_SERIALIZATION_DLL) 

install(
	TARGETS Serialization EXPORT FM2019Targets
	RUNTIME DESTINATION "${PROJECT_SOURCE_DIR}/bin" COMPONENT bin
	LIBRARY DESTINATION "${PROJECT_SOURCE_DIR}/lib" COMPONENT bin
	ARCHIVE DESTINATION "${PROJECT_SOURCE_DIR}/lib" COMPONENT dev
)