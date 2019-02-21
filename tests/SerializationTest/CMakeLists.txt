add_executable(SerializationTest main.cpp)
target_link_libraries(SerializationTest Serialization)
install(
	TARGETS SerializationTest EXPORT FM2019Targets
	RUNTIME DESTINATION "${PROJECT_SOURCE_DIR}/bin" COMPONENT bin
)