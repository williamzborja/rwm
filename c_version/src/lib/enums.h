//
// Created by william rodriguez on 20/11/23.
//

#ifndef DWM_ENUMS_H
#define DWM_ENUMS_H


/* enums */
enum {
    CurNormal, CurResize, CurMove, CurLast
}; /* cursor */
enum {
    SchemeNorm, SchemeSel
}; /* color schemes */
enum {
    NetSupported, NetWMName, NetWMState, NetWMCheck,
    NetWMFullscreen, NetActiveWindow, NetWMWindowType,
    NetWMWindowTypeDialog, NetClientList, NetLast
}; /* EWMH atoms */
enum {
    WMProtocols, WMDelete, WMState, WMTakeFocus, WMLast
}; /* default atoms */
enum {
    ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle,
    ClkClientWin, ClkRootWin, ClkLast
}; /* clicks */


#endif //DWM_ENUMS_H
