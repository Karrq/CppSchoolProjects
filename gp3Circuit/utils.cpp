#include <graphics.h>
#include <iostream.h>
#include "utils.h"

coords moveto(coords C){
	/**
		Overload di moveto,
		in grado di utilizzare il nuovo tipo
	**/
	moveto(C.x, C.y);
	return C;
}

coords lineto(coords C){
	/**
		Overload di lineto,
		in grado di utilizzare il nuovo tipo
	**/
	lineto(C.x, C.y);
	return C;
}

coords circle(coords C, int r){
	/**
		Overload di circle,
		in grado di utilizzare il nuovo tipo
	**/
	
	circle(C.x,C.y,r);
	
	return C;
}

coords drawMove(int x, int y){
    coords C={x,y};
    
	lineto(x,y);
    moveto(x,y);
    
    return C;    
}

coords drawMove(coords C){
	lineto(C);
	C=moveto(C);
	
	return C;
}

void getVars(void){
          
}

