#include<graphics.h>
#include<iostream.h>

int main(){
    /**
    Inizia sessione grafica
    initwindow(w,h)
    w= width, larghezza
    h= height, altezza
    **/
    initwindow(1200,800);
    
    /**
    line(x1, y1, x2, y2);
    dove x1 e y1 sono il punto di partenza,
    e x2, y2, sono il punto di arrivo
    **/
    line(50,50,500,300);
    
    /**
    Attendi tasto premuto da tastiera
    **/
    getch();
    /**
    Chiudi sessione grafica
    **/
    closegraph();    
}


