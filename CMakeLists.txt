cmake_minimum_required(VERSION 3.29)
project(PolyPSR1)

set(CMAKE_CXX_STANDARD 26)

#SDL paths
set(SDL_INCLUDE_DIR C:/Downloads/SDL/SDL2-devel-2.30.9-mingw/SDL2-2.30.9/x86_64-w64-mingw32/include/SDL2)
set(SDL_LIB_DIR C:/Downloads/SDL/SDL2-devel-2.30.9-mingw/SDL2-2.30.9/x86_64-w64-mingw32/lib)
set(SDL_STATIC_LIB ${SDL_LIB_DIR}/libSDL2.a)
set(SDL_MAIN_LIB ${SDL_LIB_DIR}/libSDL2main.a)

set(SDL_IMAGE_INCLUDE_DIR C:/Downloads/SDL/SDL2_image-2.8.2/x86_64-w64-mingw32/include/SDL2)
set(SDL_IMAGE_LIB_DIR C:/Downloads/SDL/SDL2_image-2.8.2/x86_64-w64-mingw32/lib)
set(SDL_IMAGE_STATIC_LIB ${SDL_IMAGE_LIB_DIR}/libSDL2_image.a)

set(WINDOWS_SDK_PATH C:/Program Files(x86)/Windows Kits/10)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -static-libgcc -static-libstdc++ -static")

include_directories(${WINDOWS_SDK_PATH}/Include/10.0.22621.0/ucrt ${WINDOWS_SDK_PATH}/Include/10.0.22621.0/um)

include_directories(${SDL_INCLUDE_DIR} ${SDL_IMAGE_INCLUDE_DIR})

link_directories(${WINDOWS_SDK_PATH}/Lib/10.0.22621.0/um/x64)
link_directories(C:/msys64/mingw64/lib)


#Compiler and linker flags for static linking
if(MSVC)
    set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
endif()

#console deactivation
#if(WIN32 AND NOT MSVC)
#set(CMAKE_EXE_LINKER_FLAGS "${CMAKE_EXE_LINKER_FLAGS} -mwindows")
#endif()

add_definitions(-DSDL_MAIN_HANDLED)

add_executable(PolyPSR1 main.cpp
        border.cpp border.h
        Player.cpp Player.h
)

target_link_libraries(PolyPSR1 ${SDL_IMAGE_STATIC_LIB} ${SDL_STATIC_LIB} ${SDL_MAIN_LIB} winmm Cfgmgr32 imm32 Version setupapi C:/msys64/mingw64/x86_64-w64-mingw32/lib/libwinpthread.a)