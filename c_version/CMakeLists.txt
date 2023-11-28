cmake_minimum_required(VERSION 3.26)
project(rwm C)

set(CMAKE_C_STANDARD 23)
set(LIBRARY_OUTPUT_PATH  ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

find_package(X11 REQUIRED)
find_package(Freetype REQUIRED)
find_package(Fontconfig REQUIRED)



include_directories(${X11_INCLUDE_DIR}
        ${FREETYPE_INCLUDE_DIRS}
        ${FONTCONFIG_INCLUDE_DIRS}
)

add_executable(rwm src/main.c
        src/lib/enums.h
        src/lib/macros.h
        src/lib/variables.h
        src/lib/arg.h
        src/lib/button.h
        src/lib/monitor.h
        src/lib/client.h
        src/lib/keys.h
        src/lib/layout.h
        src/dwm.c
        src/dwm.h
        src/drw.c
        src/lib/drw.h
        src/lib/rule.h
        src/util/util.c
        src/util/util.h
        src/lib/cursor.h
        src/lib/xft/fnt.h
        src/lib/dwm_lib.h
        src/lib/x11/x_event_error.h
        src/lib/x11/window.h
        src/lib/x11/xevent.h
        config.h
    )

add_executable(transient transient.c)

target_link_libraries(rwm
        ${FREETYPE_LIBRARIES}
        ${X11_LIBRARIES}
        ${X11_Xft_LIB}
        Fontconfig::Fontconfig
)

target_link_libraries(transient
        ${FREETYPE_LIBRARIES}
        ${X11_LIBRARIES}
        ${X11_Xft_LIB}
        Fontconfig::Fontconfig
)
