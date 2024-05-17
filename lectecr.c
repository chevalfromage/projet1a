#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "lectecr.h"

picture read_pic(char* imageppm){
    FILE* im = fopen(imageppm,"r");
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
    
    return *pic;
}

void save_pic(picture pic, char* fichier){
    FILE* image = fopen(fichier,"w");
    if (image==NULL){
        printf("erreur creation fichier\n");
    }
    else{
        
        fprintf(image,"P6");
        fprintf(image," ");
        fprintf(image,"%d",pic.width);
        fprintf(image," ");
        fprintf(image,"%d",pic.height);
        fprintf(image," ");
        fprintf(image,"255");
        fprintf(image," ");
        fwrite(pic.pixels,sizeof(color),pic.width*pic.height,image);
    }   
}

void copy(char* name_entree, char* name_sortie){
    int n_entree = strlen(name_entree);
    int n_sortie = strlen(name_sortie);
    char format_entree[3];
    char format_sortie[3];
    static char liste_format[2][4] = {"ppm","jpg"};
    //recuperation du format
    for (int i = n_entree-1;i>n_entree-4;i--){
        format_entree[n_entree-1-i] = name_entree[i];
    }
    for (int i = n_sortie-1;i>n_sortie-4;i--){
        format_sortie[n_sortie-1-i] = name_sortie[i];
    }
    /*
    //verification si format valide 
    for (int i=0;i<3;i++){
        if (format_entree[i]!= liste_format[0][i] || format_entree[i]!= liste_format[1][i]){
            printf("L'image rentree n'a pas un bon format\n");
        }
    }*/
    //on change le format
    picture img;
    if (format_entree[0] == 'p' && format_sortie[0] == 'j'){
        img = read_pic(name_entree);
        save_jpeg(name_sortie,img);
    }
    else{
        img = read_jpeg(name_entree);
        save_pic(img,name_sortie);
    }
    
}
