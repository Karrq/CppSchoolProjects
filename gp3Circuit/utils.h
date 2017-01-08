/**
	Dainese Francesco
	7/11/2016
	
	Insieme di funzioni di utilità per il disegno
**/

#ifndef UTILS_H
#define UTILS_H

struct coordinate{
	/**
		Questo type immagazzina 2 variabili,
		intese come coordinate,
		così da poter essere utilizzato come return
	**/
	int x;
	int y;
};
typedef struct coordinate coords;

coords moveto(coords C);
coords lineto(coords C);
coords circle(coords C, int radius);
coords drawMove(coords C);
coords drawMove(int x, int y);

void getVars(void);

#endif
