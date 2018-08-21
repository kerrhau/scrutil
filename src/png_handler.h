void png_write(png_structp png_ptr, png_bytep data, png_size_t length); 
void png_flush(png_structp png_ptr);
void write_png(std::ostream& stream, char* data, Screenshot screenshot);
