find_package(gtest REQUIRED)


add_executable(core_test main.cpp
	GUIObjectTest.cpp GUIObjectTest.hpp
	LayoutTest.cpp LayoutTest.hpp)

target_link_libraries(core_test gtest core)
target_include_directories(core_test PUBLIC "${CMAKE_BINARY_DIR}/${CONFIG_DIR}")

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/data" AND IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/data")
add_custom_command(TARGET core_test POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy_directory
	 "${CMAKE_CURRENT_SOURCE_DIR}/data"
	 "${CMAKE_CURRENT_BINARY_DIR}/data"
  COMMENT "Copying test data output directory")
endif()
