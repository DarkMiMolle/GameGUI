find_package(SFML REQUIRED)

add_library(core ${BUILD_TYPE}
	Widget.hpp Widget.cpp
	)
target_link_libraries(core
	${SFML_TARGETS})
target_include_directories(core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
