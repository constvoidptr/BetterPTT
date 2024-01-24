cmake_minimum_required(VERSION 3.26)

set(CMAKE_CXX_STANDARD 20)

project(BetterPTT)

# Collect all cpp sources files
file(GLOB SRC src/*.cpp)
file(GLOB HDR src/*.h)

set(ALL_SRC ${SRC} ${HDR})
list(SORT ALL_SRC)

include_directories(BetterPTT PUBLIC "vendor/include")

add_library(BetterPTT SHARED ${ALL_SRC})

target_link_libraries(BetterPTT PRIVATE "${CMAKE_SOURCE_DIR}/vendor/EuroScopePlugInDll.lib")
