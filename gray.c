#include<stdlib.h>
#include<stdio.h>

typedef struct {
    unsigned char red, green, blue;
} color;

typedef struct {
    int width;
    int height;
    color* pixels;
} picture;


int main(){
    FILE* im = fopen("gris.ppm","r");
    FILE* im_s = fopen("transfo.ppm","w");
    int width, height, max_color;
    color* image_data;
    picture* pic;
    char format[3];

    fscanf(im, "%2s", format);
    fscanf(im, "%d %d", &width, &height);
    fscanf(im, "%d", &max_color);
    fgetc(im);

    image_data = (color*)malloc(height*width*sizeof(color));
    fread(image_data,sizeof(color), height*width,im);
    fclose(im);
    printf("%d,%d,%d\n", width, height, max_color);

    pic = (picture*)malloc(sizeof(int)*2+height*width*sizeof(color));
    pic->width=width;
    pic->height=height;
    pic->pixels=image_data;


    //fonction gris
    fprintf(im_s,"P6 600 400 255 ");
    
    for(int i=1; i<=width*height; i++){
        fputc((pic->pixels[i].red+pic->pixels[i].green+pic->pixels[i].blue)/3,im_s);
        fputc((pic->pixels[i].red+pic->pixels[i].green+pic->pixels[i].blue)/3,im_s);
        fputc((pic->pixels[i].red+pic->pixels[i].green+pic->pixels[i].blue)/3,im_s);
    }
    //


    return 1;
}