#include <stdlib.h>
#include <stdio.h>
#include "flou.h"

void flou(char* imageppm,char* out,int s){
    picture pic = read_pic(imageppm); 
    picture new_pic;
    new_pic.height = pic.height;
    new_pic.width = pic.width;
    new_pic.pixels =(color*)malloc(pic.width * pic.height * sizeof(color));
    int moy_red,moy_green,moy_blue;
    
    color **tab = (color**)malloc(pic.height * sizeof(color*));
    color **new_tab = (color**)malloc(pic.height * sizeof(color*));
    for (int i = 0; i < pic.height; i++) {
        tab[i] = (color*)malloc(pic.width * sizeof(color));
        new_tab[i] = (color*)malloc(pic.width * sizeof(color));
        for (int j =0;j<pic.width;j++){
            tab[i][j] = pic.pixels[i*pic.width+j];
        }
    }
    
    for (int i =0;i< pic.height;i++){
        for (int j =0;j<pic.width;j++){
            int s_red =0;
            int s_green = 0;
            int s_blue=0;
            int compt = 0;
            for (int k= i-s;k<i+s+1;k++){
                if (k<pic.height && k>=0){
                    
                    for (int l=j-s;l<j+s+1;l++){
                        if( l < pic.width && l >=0){
                            
                            s_red += tab[k][l].red;
                            s_green += tab[k][l].green;
                            s_blue += tab[k][l].blue;
                            compt+=1;
                        }
                    }      
                        
                }
            }
            
            moy_red = s_red / compt;
            moy_green = s_green/compt;
            moy_blue = s_blue/compt;
            new_tab[i][j].red = moy_red;
            new_tab[i][j].green = moy_green;
            new_tab[i][j].blue = moy_blue;
            
            new_pic.pixels[i*new_pic.width+j] = new_tab[i][j];
        }    
                  
    }
    for (int i = 0; i < pic.height; i++) {
        free(tab[i]);
        free(new_tab[i]);
    }
    
    free(tab);
    free(new_tab);
    save_pic(new_pic,out);
    free(new_pic.pixels);
    
    
}
