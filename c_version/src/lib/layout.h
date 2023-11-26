//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_LAYOUT_H
#define DWM_LAYOUT_H

#include "monitor.h"

typedef struct Monitor Monitor;
typedef struct {
    const char *symbol;

    void (*arrange)(Monitor *);
} Layout;

static void tile(Monitor *m);
static void monocle(Monitor *m);


#endif //DWM_LAYOUT_H
