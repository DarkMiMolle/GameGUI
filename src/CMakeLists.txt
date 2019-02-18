list(APPEND MODULES core)

foreach(module ${MODULES})
	add_subdirectory(${module})
	message("Adding '" ${module} "' module to the configuration")
endforeach()
