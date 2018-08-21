#include <string>
#include <iostream>
#include <png.h>
#include <fstream>
#include "screenshot.h"
#include "png_handler.h"
#include <tuple>
#include "selection.h"

typedef unsigned short ushort;

int main() {
    Screenshot ss;
    std::tuple<ushort, ushort, ushort, ushort> xywh = select_region(ss.display, ss.win);
    int x = std::get<0>(xywh), y = std::get<1>(xywh), w = std::get<2>(xywh), h = std::get<3>(xywh);
    XImage screenshot = ss(w, h, x, y);
    write_png(std::cout, screenshot.data, ss);
    return 0;
}


