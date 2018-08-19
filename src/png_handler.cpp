#include <png.h>
#include <iostream>

void png_write(png_structp png_ptr, png_bytep data, png_size_t length) {
    std::ostream *stream = (std::ostream*)png_get_io_ptr(png_ptr);
    stream->write((char*)data, length);
}

void png_flush(png_structp png_ptr) {
    std::ostream *stream = (std::ostream*)png_get_io_ptr(png_ptr);
    stream->flush();
}

void writePng(std::ostream& stream, int width, int height, char* data) {
    png_structp png_ptr = nullptr;
    png_infop info_ptr = nullptr;
    png_bytep *rows = new png_bytep[height];
    
    png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, nullptr, nullptr, nullptr);

    if (!png_ptr)
        throw new std::runtime_error("[writePng] png_create_write_struct failed; could not initialize png_ptr");

    info_ptr = png_create_info_struct(png_ptr);

    if (!info_ptr)
        throw new std::runtime_error("[writePng] png_create_info_struct failed; could not initialize info_ptr");

    png_set_write_fn(png_ptr, &stream, png_write, png_flush);
    png_set_compression_level(png_ptr, 9);

    png_set_IHDR(png_ptr, info_ptr, width, height, 8,
                 PNG_COLOR_TYPE_RGBA, PNG_INTERLACE_NONE,
                 PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

    for(int i = 0; i < height; i++) {
        rows[i] = (png_bytep)(data + (i * width * 4));
    }

    png_write_info(png_ptr, info_ptr);
    png_write_image(png_ptr, rows);
    png_write_end(png_ptr, info_ptr);
    png_destroy_write_struct(&png_ptr, &info_ptr);
    
}
