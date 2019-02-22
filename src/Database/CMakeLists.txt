add_definitions(-DBUILDING_DATABASE_DLL)

add_library(Database SHARED Object.cpp ObjectManager.cpp Date.cpp Continent.cpp Nation.cpp Region.cpp City.cpp Person.cpp)
target_link_libraries(Database Serialization)

install(
	TARGETS Database EXPORT FM2019Targets
	RUNTIME DESTINATION "${PROJECT_SOURCE_DIR}/bin" COMPONENT bin
	LIBRARY DESTINATION "${PROJECT_SOURCE_DIR}/lib" COMPONENT bin
	ARCHIVE DESTINATION "${PROJECT_SOURCE_DIR}/lib" COMPONENT dev
)