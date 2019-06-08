# ----------------------------------------------------------------------------
#  Root CMake file for BULK Project
#
#    From the off-tree build directory, invoke:
#      $ cmake <PATH_TO_BULK_ROOT>
#
# ----------------------------------------------------------------------------

cmake_minimum_required(VERSION 3.2)

if (DEFINED ENV{TRAVIS_BUILD_NUMBER})
    project(bulk VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})
else ()
    project(bulk VERSION 0.0.1)
endif ()

# find packages ...
find_package(Threads)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/../bin)

# File Path
file(GLOB DIR_ROOT_SRC src/*.cpp)
file(GLOB DIR_UTILS_HDRS src/utils/*.hpp)

file(GLOB DIR_IO_SRCS src/io/*.cpp)
file(GLOB DIR_IO_HDRS src/io/*.hpp)

# make executable file for application
add_executable(${PROJECT_NAME} ${DIR_ROOT_SRC}
                               ${DIR_IO_SRCS}
                               ${DIR_UTILS_HDRS}
                               ${DIR_IO_HDRS})

set_target_properties(${PROJECT_NAME} PROPERTIES
                CXX_STANDARD 14
                CXX_STANDARD_REQUIRED ON
                LINK_LIBRARIES pthread
                COMPILE_OPTIONS "-g;-O0;-Wall;-Wextra;-Werror;-Wpedantic"
                )

# install to bin folder our binaries
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

# generate .deb package
set(CPACK_GENERATOR DEB)

set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")

set(CPACK_PACKAGE_CONTACT john.jasper.doe@gmail.com)
set(CPACK_DEBIAN_PACKAGE_SHLIBDEPS ON)

# include will generate proper code for .deb generation
include(CPack)
