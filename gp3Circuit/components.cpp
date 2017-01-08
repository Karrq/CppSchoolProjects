/**
	Insieme di funzioni per disegnare componenti elettrici
**/

#include <graphics.h>
#include <math.h>
#include "utils.h"
#include "components.h"

coords drawCapacitor(coords cC, bool r){
	/**
		Disegna un condensatore
		
		r=rotate 90deg, F = horizontal
		x=initial x
		y=initial y
		
		x e y finali sono la posizione finale del cursore
		
		Occupa 30x20px	
	**/
	
		int a=15;
		
		circle(cC, 3);
		
		if(!r){
		
			// sbarretta iniziale
			
			cC.x+=a;		
			drawMove(cC.x,cC.y);
		
			// parte metà inferiore 1 + meta superiore 1
			cC.y-=a;		
			moveto(cC.x,cC.y);
			cC.y+=a+a;
			lineto(cC.x,cC.y);
		
			// vuoto		
			cC.x+=a;
			moveto(cC.x,cC.y);
		
			// parte metà inferiore 2 + metà superiore 2	
			cC.y-=a+a;
			lineto(cC.x,cC.y-1);
		
			//sbarretta finale		
			cC.y+=a;
			moveto(cC.x,cC.y);
			cC.x+=a;
			drawMove(cC.x+5,cC.y);
			
			cC.x+=5;
		}else{
			
			// sbarretta iniziale
			cC.y+=a;		
			drawMove(cC.x,cC.y);
		
			// parte metà inferiore 1 + meta superiore 1
			cC.x-=a;		
			moveto(cC.x,cC.y);
			cC.x+=a+a;
			lineto(cC.x,cC.y);
		
			// vuoto		
			cC.y+=a-1;
			moveto(cC.x,cC.y);
		
			// parte metà inferiore 2 + metà superiore 2	
			cC.x-=a+a;
			lineto(cC.x+1,cC.y);
		
			//sbarretta finale		
			cC.x+=a;
			moveto(cC.x,cC.y);
			cC.y+=a;
			drawMove(cC.x,cC.y+5);
			
			cC.y+=5;			
			
		}
		
		circle(cC, 3);
		
	return cC;	

}

coords drawResistor(coords cR, bool r){
    /**
        Disegna un resistore
        
        r=rotated 90deg, F = horizontal
        x=initial x
        y=initial y
        
        x e y finali sono la posizione finale del cursore
        
        Occupa 60x30px
    **/
     
    int a=15;
    int b=15;
    int c=int((cos(45)*b)+0.5);
     
    int y1=0;
    int x1=0;
    
    moveto(cR);
    circle(cR,3);
     
    if(r){
    	
    	//sbarretta finale  
        drawMove(cR);
        
        //mezzo-segmento iniziale 

        cR=drawMove(cR.x,cR.y+a);
        
        for(int i=0; i<=5; i++){
        	//resistenza stessa
            if (i%2==0){
                cR.y+=c;
                x1=cR.x+c;
                drawMove(x1,cR.y);    
            }else{
                cR.y+=c;
                x1=cR.x-c;
                drawMove(x1,cR.y);
            }            
        }
        
        //mezzo-segmento finale
        cR.y+=a;
        drawMove(cR);
        
        //sbarretta finale
        cR.y+=a;
        drawMove(cR);      
        
    }else{
	
		//sbarretta iniziale
        cR.y+=a-5;  
        drawMove(cR);  
        
        //mezzo-segmento iniziale
        drawMove(cR.x+a,cR.y);
        
        for(int i=0;i<=5;i++){
        	//resistenza stessa
            if (i%2==0){
                cR.x+=c;
                y1=cR.y+c;
                drawMove(cR.x,y1);                        
            }else{
                cR.x+=c;
                y1=cR.y-c;
                drawMove(cR.x,y1);                        
            }           
        }
     	
     	//mezzo-segmento finale
        cR.x+=a;  
        drawMove(cR);
     	
     	//sbarretta finale
        cR.x+=a;
        drawMove(cR);
    }
    
    circle(cR, 3);
          
     return cR;     
     
}

coords drawTransistor(coords cQ, bool r, int terminal){
    /**
        Disegna un transistor
        
        r=rotated 90deg, F = horizontal
        x=initial x, queste coordinate sarebbero il punto B
        y=initial y
        t=[0,1,2] 0 = collettore, 1= base, 2=emettitore << serve per decidere dove far arrivare il cursore
        
        x e y finali sono la posizione finale del cursore
        
        Occupa 45x45px
    **/
    coords cQC={15+cQ.x+int((25*cos(45))+0.5),cQ.y-int(((25*cos(45))+15)+0.5)};
	
	coords cQB=cQ;
    
    coords cQE={15+cQ.x+int((25*cos(45))+0.5),cQ.y+int(((25*cos(45))+15)+0.5)}; 
    
    if(r){
    	// transistor ruotato di 90deg
    	
	}else{
		
		//transistor dritto
		
		//terminale base
		moveto(cQB);
		lineto(cQB.x+15,cQB.y);
		
		
		//linea della base
		moveto(cQB.x+15,cQB.y);
		lineto(cQB.x+15,cQB.y+15);
		lineto(cQB.x+15,cQB.y-15);
		
		//Cerchio transistor
		int r=30;
        circle(cQE.x,cQB.y,r);
		
		//mod freccia bassa
		moveto(cQB.x+15,cQB.y);
		lineto(cQE.x,cQE.y-15);
		
		
		//terminale emettitore
		lineto(cQE.x,cQE.y);
		
		//freccia
		lineto(cQE.x,cQE.y-22);
		lineto(cQE.x-7,cQE.y-15);
		lineto(cQE.x,cQE.y-15);
		
		
		//mod freccia alta
		moveto(cQB.x+15,cQB.y);
		lineto(cQC.x,cQC.y+15);
		
		//terminale collettore
		lineto(cQC.x,cQC.y-3);
				
		
	}
    
    /**
    	Se  terminal = 0
    			return cQC
    		terminal = 1
    			return cQB
    		terminal = 2
    			return cQE
    			
    	default : return cQC
    **/
    switch(terminal){
    	case (0):
    		return cQC;
    	case (1):
    		return cQB;
    	case (2):
    		return cQE;
    	default:
    		return cQE;
	}
	
}

coords drawGround(coords cG){
	
	moveto(cG);
	
	// sbarra 1
	drawMove(cG.x,cG.y+7);
	lineto(cG.x-8,cG.y+7);
	lineto(cG.x+8,cG.y+7);
	// sbarra 2
	moveto(cG.x,cG.y+10);
	lineto(cG.x-4,cG.y+10);
	lineto(cG.x+4,cG.y+10);
	// sbarra 3
	moveto(cG.x,cG.y+12);
	lineto(cG.x-2,cG.y+12);
	lineto(cG.x+2,cG.y+12);
	
	return cG;
	
}

coords drawResistor(int x, int y, bool r){
       coords Cr;
       Cr.x=x;
       Cr.y=y;
       Cr=drawResistor(Cr, r);
       return Cr;
}

coords protoResistor(coords Cr, bool r){
       
       if(r){
             
             
       }else{
             
             
       }
       
       
       
       return Cr;       
}

coords protoResistor(int x, int y, bool r){
       coords Cr;
       
       Cr.x = x;
       Cr.y = y;
       
       Cr=protoResistor(Cr, r);
       return Cr;       
}
