#include <stdlib.h>
#include <stdio.h>
#include "flou.h"

void flou(char* imageppm,char* out,int s){
    FILE* f = fopen(imageppm,"r");
    picture pic = read_pic(imageppm);
    static int tab[pic.width][pic.height][3];
    static float new_tab[pic.width][pic.height][3];
    picture new_pic;
    new_pic.height = pic.height;
    new_pic.width = pic.width;
    int nb_pixel_coin = 2*s+2;
    int nb_pixel_bord = (2*s+1)*(2*s+1)-s*(2*s+1);
    int nb_pixel_milieu = (2*s+1)*(2*s+1);
    int moy_red,moy_green,moy_blue;
    for (int i =0;i< pic.height;i++){
        for (int j =0;j<pic.width;j++){
            tab[i][j] = pic.pixels[i*pic.width+j];
        }
    }
    for (int i =0;i< pic.height;i++){
        for (int j =0;j<pic.width;j++){     
            int s_red,s_green,s_blue;
            if (i==0){
                if (j ==0){
                    for (int k=i;k<i+s+1;k++){
                        for (int l = j;l<j+s+1;l++){
                            s_red += tab[k][l][0];
                            s_green += tab[k][l][1];
                            s_blue += tab[k][l][2];
                        }
                    }
                    moy_red = s_red / nb_pixel_coin;
                    moy_green = s_green/nb_pixel_coin;
                    moy_blue = s_blue/nb_pixel_coin;
                    new_tab[i][j][0] = moy_red;
                    new_tab[i][j][1] = moy_green;
                    new_tab[i][j][2] = moy_blue; 

                }
                if (j==pic.width-1){
                    for (int k=i;k<i+s+1;k++){
                        for (int l = j-s;l<j+1;l++){
                            s_red += tab[k][l][0];
                            s_green += tab[k][l][1];
                            s_blue += tab[k][l][2];
                        }
                    }
                    moy_red = s_red / nb_pixel_coin;
                    moy_green = s_green/nb_pixel_coin;
                    moy_blue = s_blue/nb_pixel_coin;
                    new_tab[i][j][0] = moy_red;
                    new_tab[i][j][1] = moy_green;
                    new_tab[i][j][2] = moy_blue;
                }
                else {
                    
                    for (int k=i;k<i+s+1;k++){
                        for (int l = j-s;l<j+s+1;l++){
                            s_red += tab[k][l][0];
                            s_green += tab[k][l][1];
                            s_blue += tab[k][l][2];
                            
                        }
                    }
                    moy_red = s_red / nb_pixel_bord;
                    moy_green = s_green/nb_pixel_bord;
                    moy_blue = s_blue/nb_pixel_bord;
                    new_tab[i][j][0] = moy_red;
                    new_tab[i][j][1] = moy_green;
                    new_tab[i][j][2] = moy_blue;
                }
            }
            if (i==pic.height-1){
                if (j ==0){
                    
                    for (int k=i-s;k<i+1;k++){
                        for (int l = j;l<j+s+1;l++){
                            s_red += tab[k][l][0];
                            s_green += tab[k][l][1];
                            s_blue += tab[k][l][2];
                            
                        }
                    }
                    moy_red = s_red / nb_pixel_coin;
                    moy_green = s_green/nb_pixel_coin;
                    moy_blue = s_blue/nb_pixel_coin;
                    new_tab[i][j][0] = moy_red;
                    new_tab[i][j][1] = moy_green;
                    new_tab[i][j][2] = moy_blue; 

                }
                if (j==pic.width-1){
                    
                    for (int k=i-s;k<i+1;k++){
                        for (int l = j-s;l<j+1;l++){
                            s_red += tab[k][l][0];
                            s_green += tab[k][l][1];
                            s_blue += tab[k][l][2];
                            
                        }
                    }
                    moy_red = s_red / nb_pixel_coin;
                    moy_green = s_green/nb_pixel_coin;
                    moy_blue = s_blue/nb_pixel_coin;
                    new_tab[i][j][0] = moy_red;
                    new_tab[i][j][1] = moy_green;
                    new_tab[i][j][2] = moy_blue;
                }
                else {
                    
                    for (int k=i-s;k<i+1;k++){
                        for (int l = j-s;l<j+s+1;l++){
                            s_red += tab[k][l][0];
                            s_green += tab[k][l][1];
                            s_blue += tab[k][l][2];
                            
                        }
                    }
                    moy_red = s_red / nb_pixel_bord;
                    moy_green = s_green/nb_pixel_bord;
                    moy_blue = s_blue/nb_pixel_bord;
                    new_tab[i][j][0] = moy_red;
                    new_tab[i][j][1] = moy_green;
                    new_tab[i][j][2] = moy_blue;
                }
            }
            if (j==0 && i!=0 && i!=pic.height-1){
                
                    for (int k=i-s;k<i+s+1;k++){
                        for (int l = j;l<j+s+1;l++){
                            s_red += tab[k][l][0];
                            s_green += tab[k][l][1];
                            s_blue += tab[k][l][2];
                            
                        }
                    }
                    moy_red = s_red / nb_pixel_bord;
                    moy_green = s_green/nb_pixel_bord;
                    moy_blue = s_blue/nb_pixel_bord;
                    new_tab[i][j][0] = moy_red;
                    new_tab[i][j][1] = moy_green;
                    new_tab[i][j][2] = moy_blue;
            }
            if (j==pic.width-1 && i!=0 && i != pic.height-1){
                
                    for (int k=i-s;k<i+s+1;k++){
                        for (int l = j-s;l<j+1;l++){
                            s_red += tab[k][l][0];
                            s_green += tab[k][l][1];
                            s_blue += tab[k][l][2];
                            
                        }
                    }
                    moy_red = s_red / nb_pixel_bord;
                    moy_green = s_green/nb_pixel_bord;
                    moy_blue = s_blue/nb_pixel_bord;
                    new_tab[i][j][0] = moy_red;
                    new_tab[i][j][1] = moy_green;
                    new_tab[i][j][2] = moy_blue;
            }            
            else {
                for (int k= i-s;k<i+s+1<k++){
                    for (int l=j-s;l<j+s+1<l++){
                    s_red += tab[k][l][0];
                    s_green += tab[k][l][1];
                    s_blue += tab[k][l][2];

                    }
                }
                moy_red = s_red / nb_pixel_milieu;
                moy_green = s_green/nb_pixel_milieu;
                moy_blue = s_blue/nb_pixel_milieu;
                new_tab[i][j][0] = moy_red;
                new_tab[i][j][1] = moy_green;
                new_tab[i][j][2] = moy_blue; 
            }
            new_pic.pixels[i*new_pic.width+j] = new_tab[i][j];
        }
    }
    save_pic(new_pic,out);
}
