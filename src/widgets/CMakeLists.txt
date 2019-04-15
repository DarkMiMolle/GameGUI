find_package(SFML REQUIRED)

add_library(widgets ${BUILD_TYPE}
	widgetsGlobal.hpp
	Button.hpp Button.cpp
	)
target_link_libraries(widgets
	core
	${SFML_TARGETS})
target_include_directories(widgets PUBLIC "${CMAKE_BINARY_DIR}/${CONFIG_DIR}")
target_include_directories(widgets PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


if (CONFIG_BUILD_TEST)
	add_subdirectory(unit_tests)
endif()
