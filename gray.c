#include<stdlib.h>
#include<stdio.h>

int main(){
    FILE* im = fopen("gris.ppm","w+");
    
    
        fprintf(im,"P6 600 400 255 ");
        for(int x=0; x<400;x ++){
            for(int y=0; y<600; y++){
                if(((x-200)*(x-200)+(y-300)*(y-300))<=100*100){
                    fputc(0,im);
                    fputc(255,im);
                    fputc(0,im);
                }
                else{
                    fputc(255,im);
                    fputc(255,im);
                    fputc(255,im);
                }
            }
            
        }
        
    

    return 1;
}