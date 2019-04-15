list(APPEND MODULES core)
list(APPEND MODULES widgets)

foreach(module ${MODULES})
	add_subdirectory(${module})
	message("Adding '" ${module} "' module to the configuration")
endforeach()
