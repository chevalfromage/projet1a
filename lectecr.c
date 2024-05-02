#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "jpg_io.h"


char* copy(char* name_entree, char* name_sortie){
    int n_entree = strlen(name_entree);
    int n_sortie = strlen(name_sortie);
    char* format_entree;
    char* format_sortie;
    char** liste_format = {"ppm","jpg"};

    char* new_output;
    //recuperation du format
    for (int i = n-1,i>n-4,i--){
        format_entree[n-1-i] = name_entree[i];
        format_sortie[n-1-i] = name_sortie[i];
    }
    //verification si format valide 
    for (int i=0;i<3;i++){
        if (format_entree[i]!= liste_format[0][i] || format_entree[i]!= liste_format[1][i]){
            printf("L'image rentree n'a pas un bon format\n");
        }   return {'0'};
    }
    //comparaison des 2 formats
    int rename(name_entree,name_sortie); //on change le nom
    //on change le format
    else if (format_entree[0] == 'p' && format_sortie[0] == 'j'){
        save_jpeg(name_sortie,);//WTF
    }
    else {
        read_jpeg(name_sortie);
    }
}




int main(){
    return 0;
}