#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <assert.h>
#include <string.h>

//Question 1
//La réponse est 8
typedef struct pixel {
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} pixel_t;

//Question 6
typedef struct ppm_image_t {
    size_t height;
    size_t width;
    size_t length;
    char type[3];
    pixel_t *pixel; 
} ppm_image_t;


//Question 2

pixel_t pixel_new(uint8_t blue, uint8_t red, uint8_t green) {
    return (pixel_t){
        .red = red,
        .green = green,
        .blue = blue
    };
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
    return(
        self->red != other->red 
        && self->green != other->green 
        && self->blue != other->blue 
    );
}

//Question 5
pixel_t pixel_invert(const pixel_t *p){
  	return pixel_new(
		~p->red,
		~ p->green,
		~ p->blue
	);
}
//Question 7 
ppm_image_t	* ppm_new(const char *path){
    int numRow, numCol, maxNum;
    char type[3];
    ppm_image_t	*img;
    img = malloc(sizeof(ppm_image_t));
	FILE *file;
	file = fopen(path, "rb");
	if (file == NULL)
	    return NULL; 
    fscanf(file, "%c%c \n", type, type+1);
    type[2] = '\0';
    if(strcmp(type, "P6") != 0) { 
        printf("This file is not of type P6");
        return NULL;
    }else{
        printf("%c%c \n", type[0], type[1]);
    }
    fscanf(file, "%d", &numCol);
    fscanf(file, "%d", &numRow);
    fscanf(file, "%d", &maxNum);
    img->width = numCol;
    img->height = numRow;
    img->length = numCol * numRow;
    printf("Voici le nombre de colonnes: %d \nLe nombre de lignes: %d \nEt le nombre de bits: Max %d.\n", numCol, numRow, maxNum );
	fclose(file);
    free(img);
    return img;
}

//Question 8
size_t	ppm_height(const ppm_image_t *img){
	return img->height;
}

size_t	ppm_width(const ppm_image_t *img){
	return img->width;
}

size_t	ppm_length(const ppm_image_t *img){
	return img->length;
}


//Question 9
pixel_t	*ppm_pixel(const ppm_image_t *img, const size_t x, const size_t y){
	return &(img->pixel[y * (img->width) + x]);
}


//Question 10
void ppm_negatif(ppm_image_t *img)
{
    int length = img->length, i;
    for(i = 0; i < length; i++)
    {
        img->pixel[i] = pixel_invert(&(img->pixel[i]));
    }
}

int main(int argc, char **argv){
    /*
    pixel_t p = pixel_new(10,10,20);
    pixel_t g = pixel_new(10,10,20);
    bool isEqual = pixel_equals(&p,&g);
    printf("%d \n ", isEqual);
    */
    // size_t size;
    assert(argc > 1 && "not enough args");
    ppm_image_t	* img = ppm_new(argv[1]);
    (void) img;
    // size = img->width*3;
    // printf("Voici la largeur du fichier : %ld \n", size);
    return 0;
}
