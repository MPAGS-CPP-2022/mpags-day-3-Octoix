# Build subscript for the MPAGSCipher library

# Declare static build of library
add_library(MPAGSCipher STATIC
    CipherMode.hpp
    CaesarCipher.hpp
    CaesarCipher.cpp
    ProcessCommandLine.hpp
    ProcessCommandLine.cpp
    TransformChar.hpp
    TransformChar.cpp
)

target_include_directories(MPAGSCipher
    PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}
)

target_compile_features(MPAGSCipher
    PUBLIC cxx_auto_type cxx_range_for cxx_uniform_initialization
)