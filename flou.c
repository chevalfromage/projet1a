#include <stdlib.h>
#include <stdio.h>
#include "flou.h"

void flou(char* imageppm,char* out,int s){
    picture pic = read_pic(imageppm);
    printf("oui\n");
    
    picture new_pic;
    new_pic.height = pic.height;
    new_pic.width = pic.width;
    new_pic.pixels =(color*)malloc(pic.width * pic.height * sizeof(color));
    //int nb_pixel_coin = 2*s+2;
    //int nb_pixel_bord = (2*s+1)*(2*s+1)-s*(2*s+1);
    int nb_pixel_milieu = (2*s+1)*(2*s+1);
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
    int compt = 0;
    for (int i =0;i< pic.height;i++){
        for (int j =0;j<pic.width;j++){
            int s_red =0;
            int s_green = 0;
            int s_blue=0;
            compt+=1;
            printf("%d,%d,%d\n",pic.pixels[i*pic.width+j].red,pic.pixels[i*pic.width+j].green,pic.pixels[i*pic.width+j].blue);
            for (int k= i-s;k<i+s+1;k++){
                if (k<pic.height && k>=0){
                    
                    for (int l=j-s;l<j+s+1;l++){
                        if( l < pic.width && l >=0){
                            
                            s_red += tab[k][l].red;
                            s_green += tab[k][l].green;
                            s_blue += tab[k][l].blue;
                        }
                    }      
                        
                }
            }
            
            moy_red = s_red / nb_pixel_milieu;
            moy_green = s_green/nb_pixel_milieu;
            moy_blue = s_blue/nb_pixel_milieu;
            new_tab[i][j].red = moy_red;
            new_tab[i][j].green = moy_green;
            new_tab[i][j].blue = moy_blue;
            //printf("%d,%d,%d\n",new_tab[i][j].red,new_tab[i][j].green,new_tab[i][j].blue);
            printf("%d,%d\n",compt,pic.height*pic.width);
            new_pic.pixels[i*new_pic.width+j].red = new_tab[i][j].red;
            new_pic.pixels[i*new_pic.width+j].green = new_tab[i][j].green;
            new_pic.pixels[i*new_pic.width+j].blue = new_tab[i][j].blue;
            //printf("%d,%d,%d\n",new_pic.pixels[i*new_pic.width+j].red,new_pic.pixels[i*new_pic.width+j].green,new_pic.pixels[i*new_pic.width+j].blue);
        }
                
    }
    for (int i = 0; i < pic.height; i++) {
        free(tab[i]);
        free(new_tab[i]);
    }
    
    free(tab);
    free(new_tab);
    
    
    printf("000i\n");
    save_pic(new_pic,out);
    free(new_pic.pixels);
    printf("000i\n");
    
}
