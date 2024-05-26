#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "lectecr.h"

picture read_pic(char* imageppm){
    FILE* im = fopen(imageppm,"r");
    
    if(im ==NULL){
        printf("Erreur: l'image %s n'existe pas\n",imageppm);
        exit(1);
    }

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
    //printf("%d,%d,%d\n", width, height, max_color);

    pic = (picture*)malloc(sizeof(int)*2+height*width*sizeof(color));
    pic->width=width;
    pic->height=height;
    pic->pixels=image_data;
    
    return *pic;
}

void save_pic(picture pic, char* fichier){
    FILE* image = fopen(fichier,"w");
    if (image==NULL){
        printf("Erreur: creation fichier\n");
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
    char format_entree[4];
    char format_sortie[4];
    //recuperation du format
    for (int i = 0;i<3;i++){
        format_entree[i] = name_entree[n_entree -3+i];
    }
    format_entree[3]='\0';

    for (int i = 0;i<3;i++){
        format_sortie[i] = name_sortie[n_sortie-3+i];
    }
    format_sortie[3]='\0';
    
    if((strcmp(format_entree, "ppm")!=0 && strcmp(format_entree, "jpg")!=0) || (strcmp(format_sortie, "ppm")!=0 && strcmp(format_sortie, "jpg")!=0)){
        if((strcmp(format_entree, "ppm")!=0 && strcmp(format_entree, "jpg")!=0)){
            printf("Erreur: format de l'input non pris en compte\n");
        }
        if(strcmp(format_sortie, "ppm")!=0 && strcmp(format_sortie, "jpg")!=0){
            printf("Erreur: format de l'output non pris en compte\n");
        }
        exit(1);
    }

    //on change le format
    picture img;
    if (format_entree[0] == 'p' && format_sortie[0] == 'j'){
        img = read_pic(name_entree);
        save_jpeg(name_sortie,img);
    }
    else if (format_entree[0] == 'j' && format_sortie[0] == 'p'){
        img = read_jpeg(name_entree);
        save_pic(img,name_sortie);
    }
    else if (format_entree[0] == 'p' && format_sortie[0] == 'p'){
        img = read_pic(name_entree);
        save_pic(img,name_sortie);
    }
    else{
        img = read_jpeg(name_entree);
        save_jpeg(name_sortie,img);
    }
    
}