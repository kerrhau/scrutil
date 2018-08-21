#pragma once
#include <X11/Xlib.h>
#include <X11/Xutil.h>
#include <string>

class Screenshot {
 public:
    Screenshot();
    ~Screenshot();
    XImage operator() (unsigned short w, unsigned short h, unsigned short x, unsigned short y);
    unsigned short width, height;
    Display *display;
    Window win;
 private:
    unsigned short x, y;
    XImage *img;
    bool finished;
};
