//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_CLIENT_H
#define DWM_CLIENT_H

#include "variables.h"

typedef struct Client Client;
typedef struct Monitor Monitor;
struct Client {
    char name[256];
    float mina, maxa;
    int x, y, w, h;
    int oldx, oldy, oldw, oldh;
    int basew, baseh, incw, inch, maxw, maxh, minw, minh, hintsvalid;
    int bw, oldbw;
    unsigned int tags;
    int isfixed, isfloating, isurgent, neverfocus, oldstate, isfullscreen;
    Client *next;
    Client *snext;
    Monitor *mon;
    Window win;
};

static void applyrules(Client *c);
static int applysizehints(Client *c, int *x, int *y, int *w, int *h, int interact);
static void attach(Client *c);
static void attachstack(Client *c);
static void detach(Client *c);
static void configure(Client *c);
static void detachstack(Client *c);
static void focus(Client *c);
static void grabbuttons(Client *c, int focused);
static Client *nexttiled(Client *c);
static void pop(Client *c);
static void resize(Client *c, int x, int y, int w, int h, int interact);
static void resizeclient(Client *c, int x, int y, int w, int h);
static int sendevent(Client *c, Atom proto);
static void setclientstate(Client *c, long state);
static void setfocus(Client *c);
static void unfocus(Client *c, int setfocus);
static void unmanage(Client *c, int destroyed);
static void updatesizehints(Client *c);
static void updatetitle(Client *c);
static void updatewindowtype(Client *c);
static void updatewmhints(Client *c);
static Client *wintoclient(Window w);
static Atom getatomprop(Client *c, Atom prop);
static void showhide(Client *c);
static void seturgent(Client *c, int urg);
static void setfullscreen(Client *c, int fullscreen);
static void sendmon(Client *c, Monitor *m);
static Atom getatomprop(Client *c, Atom prop);
#endif //DWM_CLIENT_H

