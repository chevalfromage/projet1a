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

    if(input==NULL || output==NULL || fonction==NULL){
        if(input==NULL){
            printf("Erreur: pas d'input\n");
        }
        if(output==NULL){
            printf("Erreur: pas d'output\n");
        }
        if(fonction==NULL){
            printf("Erreur: pas de fonction\n");
        }
        return 1;
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
        printf("Erreur: la fonction %s n'existe pas\n", fonction);
        return 1;
    }

    if(input_mask!=NULL){
        mask("passage.ppm","passage_fonction.ppm",input_mask);
    }

    if(strcmp(fonction,"copy")!=0){
        copy("passage_fonction.ppm",output);
        remove("passage_fonction.ppm");
        remove("passage.ppm");
    }
    
    printf("fonction = %s, input = %s, output = %s\n",fonction, input, output);
    return 0;
}