set(thisTarget test_kmbd)
set(sources
	"test_kmbd.cpp" #entrypoint of tests
	"test_kmbdQueues.cpp"
)

add_executable(${thisTarget} ${sources})
target_include_directories(${thisTarget} PRIVATE .)
target_link_libraries(${thisTarget} PRIVATE kEmbedded)

add_test(NAME testAll
	COMMAND ${thisTarget}
	WORKING_DIRECTORY ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)
