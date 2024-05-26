#include <stdlib.h>
#include <stdio.h>
#include "med.h"

void insertsort(unsigned char tab[], int len){
    unsigned char e;
    for (int i=1;i<len;i++){
        e= tab[i];
        int j = i;
        while (j>0 && tab[j-1] > e){
            tab[j] = tab[j-1];
            j--;
        }
        tab[j] = e;
    }
}



void med(char* imageppm, char* out, int s) {
    picture pic = read_pic(imageppm);
    
    picture new_pic;
    new_pic.height = pic.height;
    new_pic.width = pic.width;
    new_pic.pixels = (color *)malloc(pic.width*pic.height*sizeof(color));
    
    int nb_pixel_milieu = (2*s+1)*(2*s+1);

    unsigned char* red_tab = (unsigned char*)malloc(nb_pixel_milieu*sizeof(unsigned char));
    unsigned char* green_tab = (unsigned char*)malloc(nb_pixel_milieu*sizeof(unsigned char));
    unsigned char* blue_tab = (unsigned char*)malloc(nb_pixel_milieu*sizeof(unsigned char));

    for (int i = 0; i < pic.height; i++) {
        for (int j = 0; j < pic.width; j++) {
            int compt = 0;
            for (int k = i-s; k <= i+s; k++) {
                if (k<pic.height && k>=0){;
                    for (int l = j-s; l <=j+s; l++) {
                        if( l < pic.width && l >=0){;
                            red_tab[compt] = pic.pixels[k*pic.width+l].red;
                            green_tab[compt] = pic.pixels[k*pic.width+l].green;
                            blue_tab[compt] = pic.pixels[k*pic.width+l].blue;
                            compt++;
                        }
                    }
                }
            }
            insertsort(red_tab, compt);
            insertsort(green_tab, compt);
            insertsort(blue_tab, compt);

            new_pic.pixels[i*pic.width+j].red = red_tab[compt / 2];
            new_pic.pixels[i*pic.width+j].green = green_tab[compt / 2];
            new_pic.pixels[i*pic.width+j].blue = blue_tab[compt / 2];
        }
    }


    free(red_tab);
    free(green_tab);
    free(blue_tab);

    save_pic(new_pic, out);


    free(new_pic.pixels);
}
