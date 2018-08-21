#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string>
#include <iostream>
#include "screenshot.h"
#include "selection.h"

Screenshot::Screenshot()
{
    this->display = XOpenDisplay(nullptr);
    this->win = DefaultRootWindow(this->display);
    this->finished = false;
}

Screenshot::~Screenshot() {
    XUngrabPointer(this->display, CurrentTime);
    /*    if (finished)
          XDestroyImage(this->img); */

}
XImage Screenshot::operator() (unsigned short w, unsigned short h, unsigned short xc, unsigned short yc) {
    if (finished == false)
        finished = true;
    else
        XDestroyImage(this->img);

    this->x = xc;
    this->y = yc;
    this->width = w;
    this->height = h;
     
    return *(this->img = XGetImage(display, win, this->x, this->y, this->width, this->height, AllPlanes, ZPixmap));
}
