#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "lectecr.h"
#include "jpg_io.h"
#include "gray.h"
#include "mask.h"
#include <string.h>

int main (int argc, char **argv){
    char *fonction=NULL;
    char *input = NULL;
    char *output = NULL;
    char *input_mask = NULL;
    int c;

    while ((c = getopt (argc, argv, "t:i:o:m:")) != -1)
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
            case 'm':
                input_mask = optarg;
                break;
        default:
            abort ();
    }
    if(strcmp(fonction,"copy")==0){
        copy(input,output);
    }
    else if(strcmp(fonction,"gray")==0){
        gray(input,output);
    }
    else{
        printf("apprend-a-ecrire.com");
    }

    if(input_mask!=NULL){
        mask();
    }
  

    printf("fonction = %s, input = %s, output = %s\n",fonction, input, output);
    return 0;
}