add_custom_target(CONFIG_FILE)

include_directories(${CMAKE_CURRENT_BINARY_DIR})

configure_file(Config.hpp.in Config.hpp @ONLY)

