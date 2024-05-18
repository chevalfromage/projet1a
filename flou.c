#include<stdlib.h>
#include<stdio.h>
#include "flou.h"

void flou(char* imageppm){
    FILE* f = fopen(imageppm,"r");
    picture pic =  read_pic(imageppm);
    static int tab[pic.wight][pic.height][3];
    color pixel_calc;
    for (int i =0;i< pic.height;i++){
        for (int j =0;j<pic.width;j++){
            tab[i][j] = pic.pixels[i*pic.width+j];
            
        }
    }



}