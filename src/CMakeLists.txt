# make executable file for application
add_executable(${PROJECT_NAME} ./main.cpp)

set_target_properties(${PROJECT_NAME} PROPERTIES
                CXX_STANDARD 14
                CXX_STANDARD_REQUIRED ON
                LINK_LIBRARIES pthread
                COMPILE_OPTIONS "-g;-O0;-Wall;-Wextra;-Werror;-Wpedantic"
                )


# install to bin folder our binaries
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)