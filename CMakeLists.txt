cmake_minimum_required(VERSION 3.5)
project(utillib VERSION 0.1.0 LANGUAGES C CXX)

# Kaynak dosyaların bulunduğu dizin
set(SOURCES
    src/time.cpp
    src/varray.cpp
    src/complex.cpp
    src/matrix.cpp
    src/string.cpp
)

# Başlık dosyalarının bulunduğu dizin
set(HEADERS
    src/time.hpp
    src/varray.hpp
    src/complex.hpp
    src/matrix.hpp
    src/string.hpp
)

# Testleri dahil et
include(CTest)
enable_testing()

# Kütüphane oluştur
add_library(utillib utillib.cpp)

# Testler için alt klasörü ekle
#add_subdirectory(test)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
