//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_MONITOR_H
#define DWM_MONITOR_H

#include <X11/X.h>
#include "client.h"
#include "layout.h"

typedef struct Monitor {
    char ltsymbol[16];
    float mfact;
    int nmaster;
    int num;
    int by;               /* bar geometry */
    int mx, my, mw, mh;   /* screen size */
    int wx, wy, ww, wh;   /* window area  */
    unsigned int seltags;
    unsigned int sellt;
    unsigned int tagset[2];
    int showbar;
    int topbar;
    Client *clients;
    Client *sel;
    Client *stack;
    struct Monitor *next;
    Window barwin;
    const Layout *lt[2];
} Monitor;

static void arrange(Monitor *m);
static void arrangemon(Monitor *m);
static void drawbar(Monitor *m);


#endif //DWM_MONITOR_H
