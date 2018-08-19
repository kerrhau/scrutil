#pragma once
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string>

class Screenshot {
 public:
    Screenshot(unsigned short w, unsigned short h, unsigned short x, unsigned short y);
    XImage operator() ();
 private:
    unsigned short width, height, x, y;
    Window win;
    XImage *img;
    Display *display;
    bool finished;
};
