void png_write(png_structp png_ptr, png_bytep data, png_size_t length); 
void png_flush(png_structp png_ptr);
void writePng(std::ostream& stream, int width, int height, char* data);
