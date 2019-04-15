find_package(gtest REQUIRED)


add_executable(widgets_test main.cpp
	ButtonTest.hpp ButtonTest.cpp)

target_link_libraries(widgets_test gtest widgets)
target_include_directories(widgets_test PUBLIC "${CMAKE_BINARY_DIR}/${CONFIG_DIR}")

if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/data" AND IS_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/data")
add_custom_command(TARGET widgets_test POST_BUILD
  COMMAND "${CMAKE_COMMAND}" -E copy_directory
	 "${CMAKE_CURRENT_SOURCE_DIR}/data"
	 "${CMAKE_CURRENT_BINARY_DIR}/data"
  COMMENT "Copying test data output directory")
endif()
