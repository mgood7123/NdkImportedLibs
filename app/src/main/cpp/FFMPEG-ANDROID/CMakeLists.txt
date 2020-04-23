cmake_minimum_required(VERSION 3.4.1)

project(FFMPEG_ANDROID)

# empty.cpp is an empty C++ file in order to get libraries to compile

add_library (FFMPEG-ANDROID-BASE SHARED empty.cpp)

if(CMAKE_ANDROID_ARCH_ABI STREQUAL "arm-v7a")
    set(FFMPEG_ARCH_PREFIX "arm")
elseif(CMAKE_ANDROID_ARCH_ABI STREQUAL "arm64-v8a")
    set(FFMPEG_ARCH_PREFIX "arm64")
else()
    #     for x86 and x86_64 the CMAKE_ANDROID_ARCH_ABI variable is set to the same string
    set(FFMPEG_ARCH_PREFIX ${CMAKE_ANDROID_ARCH_ABI})
endif()

set(FFMPEG_DIR ${CMAKE_CURRENT_SOURCE_DIR}/../../../../../mobile-ffmpeg)
set(LIBSDIR ${FFMPEG_DIR}/prebuilt/android-${FFMPEG_ARCH_PREFIX})
set(LIBSDIRESSENTIAL ${FFMPEG_DIR}/android/libs/${CMAKE_ANDROID_ARCH_ABI})

#symlink
#set(LIBSDIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/android-${CMAKE_ANDROID_ARCH_ABI})

add_library(avcodec SHARED IMPORTED)
add_library(avdevice SHARED IMPORTED)
add_library(avfilter SHARED IMPORTED)
add_library(avformat SHARED IMPORTED)
add_library(avutil SHARED IMPORTED)
add_library(swresample SHARED IMPORTED)
add_library(swscale SHARED IMPORTED)
add_library(cpufeatures SHARED IMPORTED)
add_library(c++_shared SHARED IMPORTED)

set_target_properties(avcodec PROPERTIES IMPORTED_LOCATION ${LIBSDIR}/ffmpeg/lib/libavcodec.so)
set_target_properties(avdevice PROPERTIES IMPORTED_LOCATION ${LIBSDIR}/ffmpeg/lib/libavdevice.so)
set_target_properties(avfilter PROPERTIES IMPORTED_LOCATION ${LIBSDIR}/ffmpeg/lib/libavfilter.so)
set_target_properties(avformat PROPERTIES IMPORTED_LOCATION ${LIBSDIR}/ffmpeg/lib/libavformat.so)
set_target_properties(avutil PROPERTIES IMPORTED_LOCATION ${LIBSDIR}/ffmpeg/lib/libavutil.so)
set_target_properties(swresample PROPERTIES IMPORTED_LOCATION ${LIBSDIR}/ffmpeg/lib/libswresample.so)
set_target_properties(swscale PROPERTIES IMPORTED_LOCATION ${LIBSDIR}/ffmpeg/lib/libswscale.so)
set_target_properties(cpufeatures PROPERTIES IMPORTED_LOCATION ${LIBSDIRESSENTIAL}/libcpufeatures.so)
set_target_properties(c++_shared PROPERTIES IMPORTED_LOCATION ${LIBSDIRESSENTIAL}/libc++_shared.so)

target_link_libraries(
        FFMPEG-ANDROID-BASE
        avcodec
        avdevice
        avfilter
        avformat
        avutil
        swresample
        swscale
        cpufeatures
        c++_shared
)

#add_library (FFMPEG-ANDROID-LIBS SHARED empty.cpp)

#add_library(chromaprint-arm64 STATIC IMPORTED)
#set_target_properties(
#        chromaprint-arm64 PROPERTIES IMPORTED_LOCATION
#        android-arm64/chromaprint/lib/libchromaprint.a
#)
#
#add_library(expat-arm64 STATIC IMPORTED)
#set_target_properties(
#        expat-arm64 PROPERTIES IMPORTED_LOCATION
#        android-arm64/expat/lib/libexpat.a
#)
#
#add_library(fontconfig-arm64 STATIC IMPORTED)
#set_target_properties(
#        fontconfig-arm64 PROPERTIES IMPORTED_LOCATION
#        android-arm64/fontconfig/lib/libfontconfig.a
#)
#
#add_library(freetype-arm64 STATIC IMPORTED)
#set_target_properties(
#        freetype-arm64 PROPERTIES IMPORTED_LOCATION
#        android-arm64/freetype/lib/libfreetype.a
#)
#
#add_library(fribidi-arm64 STATIC IMPORTED)
#set_target_properties(
#        fribidi-arm64 PROPERTIES IMPORTED_LOCATION
#        android-arm64/fribidi/lib/libfribidi.a
#)
#
#add_library(giflib-arm64 STATIC IMPORTED)
#set_target_properties(
#        giflib-arm64 PROPERTIES IMPORTED_LOCATION
#        android-arm64/giflib/lib/libgif.a
#)

add_library (FFMPEG-ANDROID SHARED empty.cpp)
target_link_libraries (FFMPEG-ANDROID FFMPEG-ANDROID-BASE #[[FFMPEG-ANDROID-LIBS]])