set(GLAD_HEADERS
	include/glad/glad.h
	include/KHR/khrplatform.h
 )
set(GLAD_SOURCES
	src/glad.c
 )

add_library(glad STATIC ${GLAD_SOURCES} ${GLAD_HEADERS})
target_include_directories(glad PRIVATE ${THIRD_PARTY_INCLUDE_DIRECTORIES})
