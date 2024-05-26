#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "lectecr.h"
#include "jpg_io.h"
#include "gray.h"
#include "mask.h"
#include "flou.h"
#include <string.h>

int main (int argc, char **argv){
    char *fonction=NULL;
    char *input = NULL;
    char *output = NULL;
    char *input_mask = NULL;
    char *s=NULL;
    int c;

    while ((c = getopt (argc, argv, "t:i:o:m:s")) != -1)
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
            case 's':
                s = optarg;
                break;
        default:
            abort ();
    }
    if(strcmp(fonction,"copy")==0){
        copy(input,output);
    }
    else if(strcmp(fonction,"gray")==0){
        copy(input,"passage.ppm");
        gray("passage.ppm","passage_fonction.ppm");
    }
    else if(strcmp(fonction,"blur")==0){
        printf("%d\n",s[0]-48);
        //flou(input,output,s[0]-48);
    }   
    else{
        printf("apprend-a-ecrire.com");
    }

    if(input_mask!=NULL){
        mask("passage.ppm","passage_fonction.ppm",input_mask);
    }
    copy("passage_fonction.ppm",output);
    remove("passage_fonction.ppm");
    remove("passage.ppm");

    printf("fonction = %s, input = %s, output = %s\n",fonction, input, output);
    return 0;
}