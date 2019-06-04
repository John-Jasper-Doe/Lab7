# ----------------------------------------------------------------------------
#  CMake file for "src". See root CMakeLists.txt
#
# ----------------------------------------------------------------------------

file(GLOB DIR_ROOT_SRC *.cpp)

file(GLOB DIR_IO_SRCS io/*.cpp)
file(GLOB DIR_IO_HDRS io/*.hpp)


# make executable file for application
add_executable(${PROJECT_NAME} ${DIR_ROOT_SRC}
                               ${DIR_IO_SRCS}
                               ${DIR_IO_HDRS})

set_target_properties(${PROJECT_NAME} PROPERTIES
                CXX_STANDARD 14
                CXX_STANDARD_REQUIRED ON
                LINK_LIBRARIES pthread
                COMPILE_OPTIONS "-g;-O0;-Wall;-Wextra;-Werror;-Wpedantic"
                )

# install to bin folder our binaries
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)
