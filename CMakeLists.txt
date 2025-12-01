cmake_minimum_required(VERSION 3.15)
project(klibc)

if(NOT LIBC_ARCHITECTURE)
    set(LIBC_ARCHITECTURE "x86_64")
endif()

if(LIBC_ARCHITECTURE STREQUAL "x86_64")
    set(LIBC_DIR "x86_64-unknown-none-elf")
endif()

set(LIB_NAME "c") 
set(COMPILER_RT_NAME "libclang_rt.builtins")

add_library(llvm-libc STATIC IMPORTED GLOBAL)
add_library(compiler_rt-builtins STATIC IMPORTED GLOBAL)

set_property(
    TARGET llvm_libc PROPERTY 
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/${LIBC_DIR}/lib${LIB_NAME}.a"
)

set_property(
    TARGET compiler_rt-builtins PROPERTY
    IMPORTED_LOCATION "${CMAKE_CURRENT_SOURCE_DIR}/lib/${LIBC_DIR}/lib${COMPILER_RT_NAME}.a"
)

set(CRTBEGIN_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/${LIBC_DIR}/crtbegin.o" CACHE INTERNAL "")
set(CRTEND_PATH "${CMAKE_CURRENT_SOURCE_DIR}/lib/${LIBC_DIR}/crtend.o" CACHE INTERNAL "")

target_include_directories(llvm_libc INTERFACE
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
)