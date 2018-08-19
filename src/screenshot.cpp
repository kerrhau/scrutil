#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string>
#include "screenshot.h"

Screenshot::Screenshot(unsigned short w, unsigned short h, unsigned short x, unsigned short y): width(w), height(h), x(x), y(y)
{
    this->display = XOpenDisplay(nullptr);
    this->win = DefaultRootWindow(this->display);
    this->finished = false;
}

XImage Screenshot::operator() () {
    if (finished == false)
        finished = true;
    else
        XDestroyImage(this->img);

    return *(this->img = XGetImage(display, this->win, this->x, this->y, this->width, this->height, AllPlanes, ZPixmap));
}
