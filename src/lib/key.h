//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_KEY_H
#define DWM_KEY_H

#include <X11/X.h>
#include "Arg.h"

typedef struct {
    unsigned int mod;
    KeySym keysym;

    void (*func)(const Arg *);

    const Arg arg;
} Key;
#endif //DWM_KEY_H
