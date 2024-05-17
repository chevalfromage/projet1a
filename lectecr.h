
#ifndef _LECTECR_H_
#define _LECTECR_H_

#include "jpg_io.h"
picture read_pic(char* imageppm);
void save_pic(picture pic, char* fichier);
void copy(char* name_entree, char* name_sortie);

#endif