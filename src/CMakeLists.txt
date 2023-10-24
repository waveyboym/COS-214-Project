cmake_minimum_required(VERSION 3.5)  # version can be different

project(container) #name of your project

# Our project requires at least C++20
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
  include(FetchContent)
  FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
  )
  # For Windows: Prevent overriding the parent project's compiler/linker settings
  set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
  FetchContent_MakeAvailable(googletest)

  enable_testing() #to  discover tests in test explorer 

  add_executable(tests tests.cpp) # add this executable

  target_link_libraries(tests GTest::gtest_main)

  include(GoogleTest)
  gtest_discover_tests(tests)
else()
  find_package(Threads)
  find_package(ZLIB)
  find_package(OpenSSL)

  if(OPENSSL_FOUND)
      include_directories(${OPENSSL_INCLUDE_DIR})
  endif()

  if (NOT CMAKE_BUILD_TYPE)
      message(STATUS "No build type selected, default to Release")
      set(CMAKE_BUILD_TYPE "Release")
  endif()

  if (MSVC)
      set(Boost_USE_STATIC_LIBS "On")
      find_package( Boost 1.70 COMPONENTS system thread regex REQUIRED )
  else()
      find_package( Boost 1.70 COMPONENTS system thread REQUIRED )
  endif()

  include_directories(${Boost_INCLUDE_DIR})

  add_compile_options(-pthread)

  add_executable(main main.cpp) # add this executable
endif()