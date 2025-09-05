cmake_minimum_required(VERSION 3.16)
project(voltos_min_hostname C)

set(CMAKE_C_STANDARD 11)
find_package(PkgConfig REQUIRED)
pkg_check_modules(CLIXON REQUIRED clixon-backend)

include_directories(${CLIXON_INCLUDE_DIRS})
link_directories(${CLIXON_LIBRARY_DIRS})

add_library(clixon_backend_voltos MODULE
  src/backend/be_hostname.c)

target_link_libraries(clixon_backend_voltos
  ${CLIXON_LIBRARIES})

set_target_properties(clixon_backend_voltos
  PROPERTIES OUTPUT_NAME "clixon_backend_voltos")
