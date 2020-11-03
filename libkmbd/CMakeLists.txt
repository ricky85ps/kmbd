set(thisTarget kEmbedded)

set(includes
	includes/kmbdQueues.h
)

set(sources
	sources/kmbdQueues.cpp
)

add_library(${thisTarget} ${sources} ${includes})
target_include_directories(${thisTarget} PUBLIC includes)

if(BUILD_TESTING)
	set(thisTargetTest target_test_${thisTarget})
	option(${thisTargetTest} "Signalizes if test cases shall be built." ON)
	if(${thisTargetTest})
		add_subdirectory(test)
	endif()
endif(BUILD_TESTING)

install(TARGETS ${thisTarget})
