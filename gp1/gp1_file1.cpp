/**
Consegna:
         Griglia 10x10
         su finestra grafica
         
         protip: usa cicli
**/

#include<graphics.h>
#include<iostream.h>

int drawVertical(int,int,int);
int drawHorizontal(int,int,int);
int credits();

/**
line(x1,y1,x2,y2)

Disegna linea da x1,y1 a x2,y2
**/

int main(){
    credits();
    
    int w = 1200;
    int h = 800;
    
    initwindow(w,h);
    
    drawVertical(15, w, h);
    drawHorizontal(15, w, h);
    
    getch();
    closegraph();
    
    return 0;
}

int drawVertical(int n, int w, int h){
    /**
    n = numero celle
    w = larghezza schermo
    h = altezza schermo
    Disegna n righe verticali sulla finestra
    **/
       
    int offset = 3;
    int a = n+offset; 
    
    for(int i=1;i<a;i++){
            int x;
            x =(i*w)/a;
            line(x, (h/a), x, (h-(h/a)));
    }
    
    return 0;
}

int drawHorizontal(int n, int w, int h){
    /**
    n = numero celle
    w = larghezza schermo
	h = altezza schermo
    Disegna n righe orizzontali sulla finestra
    **/ 

    int offset = 3;
    int a = n+offset; 
        
    for(int i=1;i<a;i++){
            int x;
            x = (i*h)/a;
            line((w/a),x, (w-(w/a)),x);
    	
    } 
    
    return 0;  
}
