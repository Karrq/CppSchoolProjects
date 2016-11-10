/**
   Dainese Francesco
   7/11/2016
   
   Disegna il circuito dato
**/

#include<graphics.h>
#include<iostream.h>
#include "utils.h"
#include "components.h"

void credits(void);

int main(void){
    int a;
    
    int x=100;
    int y=150;
    
    int w=800;
    int h=400;
    
    coords cM;
    
    cM.x=x;
    cM.y=y;
    coords cMQ=cM;
    coords cMC, Cr2, Cr3, Cr4, Cc2, CA, CB;
    
    credits();
       
    initwindow(w,h);
    
    // Inserire il codice qui
    moveto(cM);
 
    // A 
    cM.x-=10;
    CA=lineto(cM);
    cM.x+=10;
    circle(CA,4);
    
	// C1
	cMC=drawCapacitor(cM, false);	
	
	// R1
	cMC.y-=58;
	drawResistor(cMC,true);
	
	// R2
	cM.x=cMC.x;
	cM.y=cMC.y+57;
	Cr2=drawResistor(cM,true);		
	
	// Q1
	cM.x+=10;
	cM=moveto(cM);
	lineto(cM.x-10,cM.y); 
	cMQ=drawTransistor(cM,false,0);
	
	// R3
	cMQ.y-=58;
	moveto(cMQ);
	drawMove(cMC.x,cMQ.y);
	lineto(cMC.x,cMC.y);	
	Cr3=drawResistor(cMQ,true);
	cMQ.y+=58;
	
	
	// C2
	cMQ=drawMove(cMQ.x+3,cMQ.y);
	Cc2=drawCapacitor(cMQ, false);	
	CB=drawMove(Cc2.x+10,Cc2.y);
	
	// B
	circle(CB,4);	
	
	// R4
	cMQ=drawTransistor(cM,false,2);	// usato solo per otternere le coordinate del collettore, effettivamente disegna sopra l'altro transistor
	Cr4=drawResistor(cMQ,true);   
  
  	// C3
  	moveto(cMQ);
	cM=drawMove(cMQ.x+30,cMQ.y);
	drawCapacitor(cM,true);
	
	//Massa
	drawMove(cM.x,Cr4.y);
	drawMove(Cr2.x,Cr4.y);
	lineto(Cr2.x,Cr2.y-1);	
	drawGround(Cr4);
	   
    // Non inserire nulla oltre questa linea
    getch();
    closegraph();
    
    return 0;    
}

