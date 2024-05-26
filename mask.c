#include <stdio.h>
#include "mask.h"

void mask(char* im_i,char* im_f,char* input_mask){
    
    picture input = read_pic(im_i);
    picture img = read_pic(im_f);
    picture pic_mask = read_pic(input_mask);

    if(pic_mask.width!=img.width || pic_mask.height!=img.height){
        printf("Erreur: dimention du mask non addapté\n");
        exit(1);
    }
    
    for(int i=1; i<=img.width*img.height; i++){
        if(pic_mask.pixels[i].red==0){
            img.pixels[i].red=input.pixels[i].red;
            img.pixels[i].green=input.pixels[i].green;
            img.pixels[i].blue=input.pixels[i].blue;
        }
        
    }

    save_pic(img, im_f);
}