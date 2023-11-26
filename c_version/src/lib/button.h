//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_BUTTON_H
#define DWM_BUTTON_H

#include "arg.h"

typedef struct {
    unsigned int click;
    unsigned int mask;
    unsigned int button;

    void (*func)(const Arg *arg);

    const Arg arg;
} Button;
#endif //DWM_BUTTON_H
