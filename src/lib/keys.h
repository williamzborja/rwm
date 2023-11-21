//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_KEYS_H
#define DWM_KEYS_H

#include <X11/X.h>
#include "arg.h"

typedef struct {
    unsigned int mod;
    KeySym keysym;
    void (*func)(const Arg *);
    const Arg arg;
} Key;
#endif //DWM_KEYS_H
