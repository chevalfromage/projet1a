#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>



FILE* copy(char* name_entree, char* name_sortie){
    int n_entree = strlen(name_entree);
    int n_sortie = strlen(name_sortie);
    char* format_entree;
    char* format_sortie;
    char** liste_format = {"ppm","jpg"};
    //recuperation du format
    for (int i = n-1,i>n-4,i--){
        format_entree[n-1-i] = name_entree[i];
        format_sortie[n-1-i] = name_sortie[i];
    }
    //verification si format valide 
    for (int i=0;i<3;i++){
        if (format_entree[i]!= liste_format[0][i] || format_entree[i]!= liste_format[1][i]){
            printf("L'image rentree n'a pas un bon format\n");
        }   re
    }
    //comparaison des 2 formats
    for (int i=0;i<3;i++){
        if (format_entree[0]== liste_format_sortie[0]){
            name_sortie
        }
    
}




int main(){
    return 0;
}