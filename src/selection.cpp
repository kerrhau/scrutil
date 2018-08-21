#include <tuple>
#include <iostream>
#include "selection.h"

std::tuple<ushort, ushort, ushort, ushort> select_region(Display *display, Window window) {
    Cursor cursor = XCreateFontCursor(display, XC_plus);
    
    if (XGrabPointer(display, window, true, PointerMotionMask | ButtonPressMask | ButtonReleaseMask | EnterWindowMask, GrabModeAsync, GrabModeAsync, None,
                     cursor, CurrentTime) != GrabSuccess)
        throw new std::runtime_error("[select_region] Failed to grab mouse pointer.");

    if ((XGrabKeyboard (display, window, False, GrabModeAsync, GrabModeAsync, CurrentTime) != GrabSuccess))
        throw new std::runtime_error("[select_region] Failed to grab keyboard.");
    
    bool finished = false;
    XEvent xev;
    short x,y,w,h;
    
    while (!finished) {
        XNextEvent(display, &xev);
        switch(xev.type) {
        case ButtonPress:
            x = xev.xbutton.x;
            y = xev.xbutton.y;
            break;
        case ButtonRelease:
            finished = true;
            break;
        }
    }

    w = xev.xmotion.x - x;
    h = xev.xmotion.y - y;

    /* support for moving the cursor towards the top left */
    if (w < 0) {
        x += w;
        w = -w;
    }

    if (h < 0) {
        y += h;
        h = -h;
    }

    return std::make_tuple(x, y, w, h);
}
