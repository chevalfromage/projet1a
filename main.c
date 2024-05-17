#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <unistd.h>
#include "lectecr.h"
#include "jpg_io.h"

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

    printf("fonction = %s, input = %s, output = %s\n",fonction, input, output);
    return 0;
}