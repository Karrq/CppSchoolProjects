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

int main(){
    
    int x=25;
    int y=200;
    
    int w=250;
    int h=400;
    
    float Vcc, Vce, Ic, hFE, fMIN, Vbe, Vre, Rc, Ib, Re, Ir2, Vbb, R1, R2, Xce;
      
    coords cM;
    
    cM.x=x;
    cM.y=y;
    coords cMQ=cM;
    coords cMC, Cr1, Cr2, Cr3, Cr4, Cc2, CA, CB;
    
    credits();
/**   
    
	printf("Inserisci Vcc:  "); //12
    scanf("%f", &Vcc);    
    printf("\nInserisci Vce: "); //6
    scanf("%f", &Vce); 
    printf("\nInserisci Ic: "); // 0.002
    scanf("%f", &Ic); 
    printf("\nInserisci hFE: "); // 200
    scanf("%f", &hFE);
    printf("\nInserisci fMIN: "); // 10
    scanf("%f", &fMIN);
    printf("\nInserisci Vbe: "); // 0.7
    scanf("%f", &Vbe);
    
    Vre = 0.1*Vcc;
    Rc = (Vcc-Vce-Vre)/Ic;
    Ib = Ic/hFE;
    Re = Vre/Ic;
    Ir2 = Ib*0.2;
    Vbb = Vre+Vbe;
    R1 = (Vcc-Vbb)/Ir2;
    R2 = Vbb/Ir2;
    Xce = 0.1*Re*fMIN;
    
	
    printf("\n Vre = 0.1*Vcc = %f", Vre);
    printf("\n Rc = (Vcc-Vce-Vre)/Ic = %f", Rc);
    printf("\n Ib = Ic/hFE = %f", Ib);
    printf("\n Re = Vre/Ic = %f", Re);
    printf("\n Ir2 = Ib*0.2 = %f", Ir2);
    printf("\n Vbb = Vre+Vbe = %f", Vbb);
    printf("\n R1 = (Vcc-Vbb)/Ir2 = %f", R1);
    printf("\n R2 = Vbb/Ir2 = %f", R2);
    printf("\n Xce = 0.1*Re*fMIN = %f", Xce);

**/  
       
    initwindow(w,h, "gp3Circuit");
    
    // Inserire il codice qui
    moveto(cM);
    
	// C1
	cMC=drawCapacitor(cM, false);	
	
	// R1
	cMC.y-=58;
	Cr1=drawResistor(cMC.x, cMC.y-77, true);
	
	// R2
	cM.x=cMC.x;
	cM.y=cMC.y+58;
	Cr2=drawResistor(cMC,true);		
	
	// Q1
	cM.x+=25;
	moveto(cM);	
	lineto(cM.x-25,cM.y); 
	cMQ=drawTransistor(cM,false,0);
	
	// R3
	cMQ.y-=135;
	moveto(cMQ);
	drawMove(cMC.x,cMQ.y);
	lineto(cMC.x,cMC.y-73);	
	Cr3=drawResistor(cMQ,true);
	cMQ.y+=135;
	
	// C2
	cMQ.x-=3;
	cMQ.y-=10;
	cMQ=drawMove(cMQ.x+3,cMQ.y+5);
	moveto(cMQ.x,cMQ.y+5);
	drawMove(cMQ);
    cMQ.x+=30;	
	Cc2=drawCapacitor(cMQ, false);
	getch();
	cMQ.x-=30;
    cMQ.x+=3;
    cMQ.y+=10;	
	moveto(Cc2.x+10,Cc2.y);		
	
	// R4
    moveto(cM);
	cMQ=drawTransistor(cM,false,2);	// usato solo per otternere le coordinate del collettore, effettivamente disegna sopra l'altro transistor
	cMQ=drawMove(cMQ.x,cMQ.y+5);
	Cr4=drawResistor(cMQ,true);   
    
	// C3
    moveto(cMQ);
	cM=drawMove(cMQ.x+50,cMQ.y);
	drawCapacitor(cM,true);

	// Massa
	drawMove(cM.x,Cr4.y);
	drawMove(Cr2.x,Cr4.y);
	lineto(Cr2.x,Cr2.y-1);	
	drawGround(Cr4); 
	   
    // Non inserire nulla oltre questa linea
	getch();  
    closegraph();
    
    return 0;    
}

