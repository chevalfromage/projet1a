#ifndef JPEGIO_H
#define JPEGIO_H

typedef struct{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
}color;

typedef struct{
    int width;
    int height;
    color* pixels;
}picture;

picture read_jpeg(char *name);
void    save_jpeg(char *name, picture img);

#endif
