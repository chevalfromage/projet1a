#include<stdlib.h>
#include<stdio.h>
#include "gray.h"

void gray(char* im_e,char* im_s){
    int couleur;
    picture img = read_pic(im_e);
    
    for(int i=1; i<=img.width*img.height; i++){
        couleur = (img.pixels[i].red+img.pixels[i].green+img.pixels[i].blue)/3;
        img.pixels[i].red=couleur;
        img.pixels[i].green=couleur;
        img.pixels[i].blue=couleur;
    }

    save_pic(img, im_s);
}