#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

//Question 1
//La réponse est 8
typedef struct pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel_t;


//Question 2

pixel_t pixel_new(uint8_t blue, uint8_t red, uint8_t green) {
    pixel_t pixel; //il est enregistré dans la stack
    pixel.red = red;
    pixel.green = green;
    pixel.blue = blue;

    return(pixel);
}

//Question 3 
uint8_t pixel_red ( const pixel_t *p) {
    return(p->red);
}

uint8_t pixel_green( const pixel_t *p) {
    return(p->green);
}


uint8_t pixel_blue( const pixel_t *p) {
    return(p->blue);
}
//Question 4

bool pixel_equals( const pixel_t *self, const pixel_t *other) {
    bool isEqual = false; 
	
    return (self->blue == other->blue && self->green == other->green && self->red == other->red)
}




//Question 5
Pixel_t pixel_invert(const pixel_t *p){
  	return pixel_new(
		~p->red,
		~ p->green,
		~ p->blue
	);
}


//question 6
typedef struct ppm_image_t {
    size_t height;
    size_t width;
    size_t length;
    pixel_t array[];
} ppm_image_t;


//question 8
size_t ppm_get_height(const ppm_image_t * image){
  return image -> height;
}

size_t ppm_get_width(const ppm_image_t * image){
  return image -> width;
}
size_t ppm_get_length(const ppm_image_t * image){
  return image -> length;
}


//question 9
pixel_t ppm_pixel(const ppm_image_t *img, const size_t x, const size_t y)
{
    return img->arrayPixel[x * img->width + y];
}


//question 10
void ppm_negatif(ppm_image_t *img)
{
    int length = img->length, i;
    for(i = 0; i < length; i++)
    {
        img->arrayPixel[i] = pixel_invert(&(img->arrayPixel[i]));
    }
}

