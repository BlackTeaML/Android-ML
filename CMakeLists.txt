cmake_minimum_required(VERSION 3.21.3)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/out)
set(CMAKE_SYSTEM_NAME Android)
set(CMAKE_SYSTEM_VERSION 21)
set(CMAKE_ANDROID_ARCH_ABI arm64-v8a) # arm64-v8a / armeabi-v7a
set(CMAKE_ANDROID_STL_TYPE c++_static)
set(MODNAME gdmod)

project(${MODNAME} VERSION 1.0.0)

add_library(${MODNAME} SHARED
  src/main.cpp
)

target_include_directories(${MODNAME} PRIVATE
  ${CMAKE_CURRENT_SOURCE_DIR}/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/gd
  ${CMAKE_CURRENT_SOURCE_DIR}/include/cocos2dx
  ${CMAKE_CURRENT_SOURCE_DIR}/include/cocos2dx/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/cocos2dx/kazmath/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/cocos2dx/platform/android
  ${CMAKE_CURRENT_SOURCE_DIR}/include/cocos2dx/platform/third_party/android/prebuit/libcurl/include
  ${CMAKE_CURRENT_SOURCE_DIR}/include/extensions
)

target_link_libraries(${MODNAME} ${CMAKE_CURRENT_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI}/libcocos2dcpp.so)
target_link_libraries(${MODNAME} ${CMAKE_CURRENT_SOURCE_DIR}/libs/${CMAKE_ANDROID_ARCH_ABI}/libdobby.a)
target_link_libraries(${MODNAME} log)

install(TARGETS ${MODNAME} LIBRARY)
