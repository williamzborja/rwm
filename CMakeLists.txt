cmake_minimum_required(VERSION 3.26)
project(dwm C)

set(CMAKE_C_STANDARD 23)

find_package(X11 REQUIRED)
find_package(Freetype REQUIRED)
find_package(Fontconfig REQUIRED)

include_directories(${X11_INCLUDE_DIR}
        ${FREETYPE_INCLUDE_DIRS}
        ${FONTCONFIG_INCLUDE_DIRS}
)

add_executable(dwm src/main.c
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
        src/lib/x11/display.h
        src/lib/x11/window.h
        src/lib/x11/xevent.h
        config.h
    )

target_link_libraries(dwm
        ${FREETYPE_LIBRARIES}
        ${X11_LIBRARIES}
        ${X11_Xft_LIB}
        Fontconfig::Fontconfig
)
