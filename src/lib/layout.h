//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_LAYOUT_H
#define DWM_LAYOUT_H

#include "monitor.h"

typedef struct {
    const char *symbol;

    void (*arrange)(Monitor *);
} Layout;
#endif //DWM_LAYOUT_H
