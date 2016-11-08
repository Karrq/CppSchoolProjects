/**
	Dainese Francesco
	7/11/2016
	
	Insieme di funzioni di utilit� per il disegno
**/

#ifndef UTILS_H
#define UTILS_H

struct coordinate{
	/**
		Questo type immagazzina 2 variabili,
		intese come coordinate,
		cos� da poter essere utilizzato come return
	**/
	int x;
	int y;
};
typedef struct coordinate coords;

coords moveto(coords);
coords lineto(coords);
coords circle(coords, int);
coords drawMove(coords);
coords drawMove(int, int);

#endif
