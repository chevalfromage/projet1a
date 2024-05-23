#include<stdlib.h>
#include<stdio.h>
#include "gray.h"

void gray(char* im_e,char* im_s){
    
    picture img = read_pic(im_e);
    
    for(int i=1; i<=img.width*img.height; i++){
        img.pixels[i].red=(img.pixels[i].red+img.pixels[i].green+img.pixels[i].blue)/3;
        img.pixels[i].green=(img.pixels[i].red+img.pixels[i].green+img.pixels[i].blue)/3;
        img.pixels[i].blue=(img.pixels[i].red+img.pixels[i].green+img.pixels[i].blue)/3;
    }

    save_pic(img, im_s);
}