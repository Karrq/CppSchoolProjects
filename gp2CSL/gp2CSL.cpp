/**
   Dainese Francesco
   31/10/2016
   
   Consegna:
            Disegna carta logaritmica 
            
   TODO:
        Input n decadi e v div verticali
**/

#include<graphics.h>
#include<iostream.h>
#include<math.h>

void credits();

int drawDecades(int, int, int, int);
int drawHorizontal(int, int, int, int);
int drawCSL(int, int, int, int);

int main(){   

    credits();
    /**
        w = larghezza finestra,  default = massima larghezza 
        h = altezza finestra,    default = massima altezza
        v = divisioni verticali, default 4
        d = decadi,              default 6
    **/
    
    printf("getmaxwidth() = %d\n", getmaxwidth());
    printf("getmaxheight() = %d\n\n", getmaxheight());

      
    int w = 1200;   
    int h = 800;
    int v = 4;       
    int d = 11;
    
    while(d<2 || d>10){
        printf("Inserisci numero decadi, min=2 max=10: \n");
        scanf("%d",&d);
    
        printf("Inserisci numero divisori verticali: \n");
        scanf("%d",&v);
        
        if (d>10 || d<2){
           printf("Valore decadi non valido!\n");
           d=11;        
        }
    }   
    
    initwindow(w, h, "gp2CSL");
    
                  
    drawCSL(v,d,w,h);                  
    
    //utilizzato al posto di getch()  
    getch();
    
    closegraph();    
    return 0;    
}

int drawCSL(int v, int n, int w, int h){
    /**
        v = numero divisori verticali
        n = numero decadi
        w = larghezza schermo
        h = altezza schermo 
    **/
    
    drawDecades(v,n,w,h);
    drawHorizontal(v,n,w,h);
    

    return 0;
}


int drawDecades(int v, int n, int w, int h){
    /**      
       v = numero divisori verticali
       n = numero decadi
       w = larghezza schermo
       h = altezza schermo
       
       Disegna n decadi sulla finestra      
    **/
    
    //+2 serve per tenere conto della spaziatura dallo schermo.      
    int a = n+2;
    v+=2; 
    
    // i tiene conto di quanti decadi rimangono
    for(int i=1; i<=n; i++){      
        
        //j tiene conto di quante linee mancano per completare la decade in corso
        for(int j=1; j<=10; j++){
            
            /**
                k = costante di spazio in cui la decade viene costruita. Invesamente proporzionale al numero di decadi e direttamente proporzionale alla larghezza dello schermo 
                x1 = distanza dall'origine della decade, viene aggiornata ad ogni linea, quindi ad ogni ciclo
                x = parte intera di x1
                y0 = costante di spaziatura dalla parte alta dello schermo. E' determinata dal numero totale di divisioni verticali
                y1 = costante di spaziatura dalla parte bassa dello schermo. E' determinata dal numero totale di divisioni verticali         
            **/
            int k = w/a;
            
            /** x1 = k*i > è la distanza di "base" della decade in cosiderazione, rispetto allo schermo. 
                            Modificandosi insieme alla i, si modifica in concomitanza all numero di decadi rimaste,
                            effettivamente "saltando" quelle precedenti, evitando alle decadi di sovrapporsi.
                    
                    (k*log10(j)) > espressione che cambia ad ogni ciclo intero, quindi in base alla linea corrente
                                    della decade. Questo valore, sommandosi a quello di base, determina la posizione
                                    in cui disegnare la linea della decade, effettivamente creando la scala logaritmica.
            **/
            double x1 = (k*i + (k*log10(j)));            
            int x = int(x1+0.5);             
            int y0 = h/v;
            int y1 = (((h*v)-h)/v); 
            
            line(x, y0, x, y1);
                               
        }
    } 
      
    return 0;  
} 

int drawHorizontal(int n, int v, int w, int h){
    /**
       n = numero divisioni verticali
       v = numero divisori orrizontali
       w = larghezza schermo
       h = altezza schermo
       Disegna n divisioni verticali sulla finestra
    **/
    
    //+2 serve per tenere conto della spaziatura dallo schermo.
    n+=2;
    v+=2; 
    
    //i tiene conto delle linee verticali rimanenti    
    for(int i=1;i<n;i++){
            /**
                y = serve per spostare la linea in verticale; cambiando ad ogni iterazione porta la linea in basso, una spaziatura alla volta
                
                x0 = costante per determinare il punto di inizio della linea, rimanendo distaccata dallo schermo (margine sinistro)
                x1 = costante per determinare il punto di fine della linea, rimanendo distaccata dallo schermo (magine destro)
            **/
            
            int y = (i*h)/n;                                 
            int x0=w/v;
            int x1=((w*v)-w)/v;
            
            line(x0,y, x1,y);
    } 
    
    return 0;
}
