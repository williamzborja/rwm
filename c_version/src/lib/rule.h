//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_RULE_H
#define DWM_RULE_H

typedef struct {
    const char *class;
    const char *instance;
    const char *title;
    unsigned int tags;
    int isfloating;
    int monitor;
} Rule;
#endif //DWM_RULE_H
