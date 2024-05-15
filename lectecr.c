#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "jpg_io.h"
#include <unistd.h>
#include <jpeglib.h>

//###############################################################################
picture read_jpeg(char *name) {
  FILE *f;
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;
  int bytes_per_pixel;
  picture img;
  JSAMPROW row_pointer[1];
  unsigned int location = 0;
  int i = 0;

  f = fopen(name, "r");
  
  cinfo.err = jpeg_std_error(&jerr);

  jpeg_create_decompress(&cinfo);

  jpeg_stdio_src(&cinfo, f);
  jpeg_read_header(&cinfo, TRUE);

  img.width  = cinfo.image_width;
  img.height = cinfo.image_height ;

  if ( cinfo.num_components !=3) {
    fprintf(stderr,"format non reconnu\n\n");
    exit(1);
  }
    
  jpeg_start_decompress( &cinfo );
  row_pointer[0] = (unsigned char *)malloc( cinfo.output_width*3 );
  img.pixels = malloc(img.height*img.width*3);

  while( cinfo.output_scanline < cinfo.image_height)  {
    jpeg_read_scanlines( &cinfo, row_pointer, 1 );
    for( i=0; i<cinfo.image_width*3;i++)
      img.pixels[location++] = row_pointer[0][i];
  }

  jpeg_finish_decompress( &cinfo );
  jpeg_destroy_decompress( &cinfo );

  free(row_pointer[0]);

  return img;
}



void save_jpeg(char *name, picture img) {

  unsigned char *current_line;
  int i;
  FILE *f;
  struct jpeg_compress_struct cinfo;
  struct jpeg_error_mgr jerr;

  f = fopen(name, "w");
  
  cinfo.err = jpeg_std_error(&jerr);

  jpeg_create_compress(&cinfo);

  jpeg_stdio_dest(&cinfo, f);

  cinfo.image_width = img.width;
  cinfo.image_height = img.height;
  cinfo.input_components = 3;
  cinfo.in_color_space = JCS_RGB;
  jpeg_set_defaults(&cinfo);

  jpeg_start_compress(&cinfo, TRUE);

  for (i = 0; i < img.height; i++) {
    current_line = img.pixels + i * img.width * 3;
    jpeg_write_scanlines(&cinfo, &current_line, 1);
  }

  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);

  fclose(f);
}
//###############################################################################

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
    
    /*
    picture pic;
    FILE* f = fopen(imageppm,"r");
    char* c = "";
    int width,height;
    fscanf(f,"%s\n",c);
    printf("%s\n",c);
    fscanf(f,"%d %d\n",&width,&height);
    pic.width = width-1;
    pic.height = height-1;
    pic.pixels = malloc(width*height*sizeof(color));
    return pic;*/
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

    //verification si format valide 
    for (int i=0;i<3;i++){
        if (format_entree[i]!= liste_format[0][i] || format_entree[i]!= liste_format[1][i]){
            printf("L'image rentree n'a pas un bon format\n");
        }
    }
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





int main (int argc, char **argv){
    char *fonction=NULL;
    char *input = NULL;
    char *output = NULL;
    int c;

    while ((c = getopt (argc, argv, "t:i:o:")) != -1)
        switch (c){
            case 't':
                fonction = optarg;
                break;
            case 'i':
                input = optarg;
                break;
            case 'o':
                output = optarg;
                break;
        default:
            abort ();
    }
    copy(input,output);

    printf ("fonction = %s, input = %s, output = %s\n",
        fonction, input, output);
    return 0;
}
