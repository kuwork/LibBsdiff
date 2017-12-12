# For more information about using CMake with Android Studio, read the
# documentation: https://d.android.com/studio/projects/add-native-code.html

# Sets the minimum version of CMake required to build the native library.

cmake_minimum_required(VERSION 3.4.1)

# Creates and names a library, sets it as either STATIC
# or SHARED, and provides the relative paths to its source code.
# You can define multiple libraries, and CMake builds them for you.
# Gradle automatically packages shared libraries with your APK.

include_directories(
./src/main/cpp
./src/main/cpp/bzip2
)
# 将./src/main/cpp目录（不包含子目录）下所有源文件保存在变量 SRC 中
aux_source_directory(./src/main/cpp SRC)
# 将./src/main/cpp/bzip2目录（不包含子目录）下所有源文件保存在变量 SRC_OTHER 中
aux_source_directory(./src/main/cpp/bzip2 SRC_OTHER)
# 将 SRC_OTHER 添加到 SRC 中
list(APPEND SRC ${SRC_OTHER})

add_library( # Sets the name of the library.
             bsdiff
             # Sets the library as a shared library.
             SHARED
             # Provides a relative path to your source file(s).
             ${SRC}
              )

# Searches for a specified prebuilt library and stores the path as a
# variable. Because CMake includes system libraries in the search path by
# default, you only need to specify the name of the public NDK library
# you want to add. CMake verifies that the library exists before
# completing its build.

find_library( # Sets the name of the path variable.
              log-lib
              # Specifies the name of the NDK library that
              # you want CMake to locate.
              log )

# Specifies libraries CMake should link to your target library. You
# can link multiple libraries, such as libraries you define in this
# build script, prebuilt third-party libraries, or system libraries.

target_link_libraries( # Specifies the target library.
                       bsdiff
                       # Links the target library to the log library
                       # included in the NDK.
                       ${log-lib} )