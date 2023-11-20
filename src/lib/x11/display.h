//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_DISPLAY_H
#define DWM_DISPLAY_H

#include <X11/Xlib.h>

static int xerror(Display *dpy, XErrorEvent *ee);

static int xerrordummy(Display *dpy, XErrorEvent *ee);

static int xerrorstart(Display *dpy, XErrorEvent *ee);
#endif //DWM_DISPLAY_H
