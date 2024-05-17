// compiler avec -ljpeg

#include <stdio.h>
#include <jpeglib.h>
#include <stdlib.h>
#include <string.h>
#include "jpg_io.h"


picture read_jpeg(char *name) {
  FILE *f;
  struct jpeg_decompress_struct cinfo;
  struct jpeg_error_mgr jerr;
  picture img;
  JSAMPROW row_pointer[1];
  unsigned int location = 0;
  int i = 0;

  f = fopen(name, "rb");
  
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
  img.pixels = (color*)malloc(img.height*img.width*sizeof(color));

  while( cinfo.output_scanline < cinfo.image_height)  {
    jpeg_read_scanlines( &cinfo, row_pointer, 1 );
    for( i=0; i<cinfo.image_width*3;i+=3){
      img.pixels[location].red = row_pointer[0][i];
      img.pixels[location].green = row_pointer[0][i+1];
      img.pixels[location].blue = row_pointer[0][i+2];
      location++;
    }

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
    current_line = (unsigned char*)(img.pixels + i * img.width);
    jpeg_write_scanlines(&cinfo, &current_line, 1);
  }

  jpeg_finish_compress(&cinfo);
  jpeg_destroy_compress(&cinfo);

  fclose(f);
}

