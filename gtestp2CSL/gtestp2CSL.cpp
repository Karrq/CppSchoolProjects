/**
   Dainese Francesco
   07/11/2016
   
   Appunti
   
**/

#include<graphics.h>
#include<iostream.h>


int main(void){
    
    int x=0;
    int y=0;
    
    int w=1200;
    int h=800;
    
    initwindow(w,h);
    
    
    /**
       Sposta il cursore grafico alle coordinate
       x,y
       
       Questa funziona non traccia niente sullo schermo,
       semplicemente sposta il cursore grafico
    **/
    moveto(x,y);
    
    /**
       Traccia una linea, 
       dalla posizione attuale del cursore grafico
       fino alla posizione x,y
       
       Questa funzione traccia una linea sullo schermo
    **/
    
    lineto(x,y);
    
    /**
       Queste due funzioni, utilizzare insieme,
       possono sostituire la funzione
       line(x0,y0,x1,y1)
    **/
    
    getch();
    
    
    return 0;    
}
