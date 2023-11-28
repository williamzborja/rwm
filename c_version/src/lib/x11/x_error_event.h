#ifndef X_ERROR_EVENT_H
#define X_ERROR_EVENT_H

#include <X11/Xlib.h>

static int xerror(Display *dpy, XErrorEvent *ee);
static int xerrordummy(Display *dpy, XErrorEvent *ee);
static int xerrorstart(Display *dpy, XErrorEvent *ee);

#endif
