//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_FNT_H
#define DWM_FNT_H

#include <X11/Xlib.h>
#include <X11/Xft/Xft.h>

typedef struct Fnt {
    Display *dpy;
    unsigned int h;
    XftFont *xfont;
    FcPattern *pattern;
    struct Fnt *next;
} Fnt;
#endif //DWM_FNT_H
