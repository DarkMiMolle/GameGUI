find_package(SFML REQUIRED)

add_library(core ${BUILD_TYPE}
	coreGlobal.hpp
	Widget.hpp Widget.cpp
	GUIObject.hpp GUIObject.cpp
	)
target_link_libraries(core
	${SFML_TARGETS})
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


if (CONFIG_BUILD_TEST)
	add_subdirectory(unit_tests)
endif()
