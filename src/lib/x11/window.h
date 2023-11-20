//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_WINDOW_H
#define DWM_WINDOW_H

#include <X11/X.h>
#include <X11/Xlib.h>
#include "monitor.h"

static long getstate(Window w);
static int gettextprop(Window w, Atom atom, char *text, unsigned int size);
static void manage(Window w, XWindowAttributes *wa);
static Monitor *wintomon(Window w);
#endif //DWM_WINDOW_H
