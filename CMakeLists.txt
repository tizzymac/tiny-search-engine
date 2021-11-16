## The top-level CMakeLists.txt

cmake_minimum_required(VERSION 3.18.3)

# Set up project name
project(TinySearchEngine 
    LANGUAGES C CXX
    VERSION 1.0
)

# Setup config files
configure_file(Config.h.in Config.h)

# Build into an object called whatever the project name is
add_executable(TinySearchEngine 
    runner.cpp
)

# The binary dir is where we write Config.h out to
# This will have the version number
target_include_directories(TinySearchEngine PUBLIC ${PROJECT_BINARY_DIR})

set_target_properties(TinySearchEngine 
    PROPERTIES
        CXX_STANDARD 17
        CXX_STANDARD_REQUIRED YES
        CXX_EXTENSIONS NO
)

add_subdirectory(src)
