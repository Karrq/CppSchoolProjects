int main(void){
	
	cairo_surface_t *surface;
	caito_t *cr;
	
	surface=cairo_image_surface_create(CAIRO_FORMAT_ARGB32, 120, 120);
	cr = cairo_create (surface);
	
	return 0;
}
