#pragma once
#include <tuple>
#include <X11/Xlib.h>
#include <X11/cursorfont.h>

typedef unsigned short ushort;

std::tuple<ushort, ushort, ushort, ushort> select_region(Display *display, Window window);
