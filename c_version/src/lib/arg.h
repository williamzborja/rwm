//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_ARGS_H
#define DWM_ARGS_H
typedef union {
    int i;
    unsigned int ui;
    float f;
    const void *v;
} Arg;

static void focusmon(const Arg *arg);
static void focusstack(const Arg *arg);
static void incnmaster(const Arg *arg);
static void killclient(const Arg *arg);
static void movemouse(const Arg *arg);
static void quit(const Arg *arg);
static void resizemouse(const Arg *arg);
static void setlayout(const Arg *arg);
static void setmfact(const Arg *arg);
static void tag(const Arg *arg);
static void tagmon(const Arg *arg);
static void togglebar(const Arg *arg);
static void togglefloating(const Arg *arg);
static void toggletag(const Arg *arg);
static void toggleview(const Arg *arg);
static void spawn(const Arg *arg);
static void view(const Arg *arg);
static void zoom(const Arg *arg);

#endif //DWM_ARGS_H
