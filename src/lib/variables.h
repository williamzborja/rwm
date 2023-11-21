//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_VARIABLES_H
#define DWM_VARIABLES_H

#include "x11/xevent.h"
#include "enums.h"
#include "cursor.h"
#include "monitor.h"
#include "drw.h"

typedef struct Monitor Monitor;
static const char broken[] = "broken";
static char stext[256];
static int screen;
static int sw, sh;           /* X display screen geometry width, height */
static int bh;               /* bar height */
static int lrpad;            /* sum of left and right padding for text */
static int (*xerrorxlib)(Display *, XErrorEvent *);

static unsigned int numlockmask = 0;

static void (*handler[LASTEvent])(XEvent *) = {
        [ButtonPress] = buttonpress,
        [ClientMessage] = clientmessage,
        [ConfigureRequest] = configurerequest,
        [ConfigureNotify] = configurenotify,
        [DestroyNotify] = destroynotify,
        [EnterNotify] = enternotify,
        [Expose] = expose,
        [FocusIn] = focusin,
        [KeyPress] = keypress,
        [MappingNotify] = mappingnotify,
        [MapRequest] = maprequest,
        [MotionNotify] = motionnotify,
        [PropertyNotify] = propertynotify,
        [UnmapNotify] = unmapnotify
};

static Atom wmatom[WMLast], netatom[NetLast];
static int running = 1;
static Cur *cursor[CurLast];
static Clr **scheme;
static Display *dpy;
static Drw *drw;
static Monitor *mons, *selmon;
static Window root, wmcheckwin;
#endif //DWM_VARIABLES_H
