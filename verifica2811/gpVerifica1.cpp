/**
   Dainese Francesco
   28/11/16
   
   Consegna: Dividi lo schermo in n colonne verticali
**/

#include<iostream.h>
#include<graphics.h>

void disegnaColonne(int n);
void credits(void);

int main(void){
    
    credits();
    
    int w=1200;
    int h=800;
    int n=0;
    
    // Input numero colonne verticai
    while(n<10){
        printf("Inserire numero colonne verticali, minimo 10\n");
        scanf("%d", &n);
    }
    
    //Disegna finestra   
    initwindow(w,h);
    
    //Richiama funzione di disegno colonne verticali
    disegnaColonne(n);
    
    //Attendi input utente
    getch();
    
    //Chiudi finestra
    closegraph();
    
    return 0;    
}

void credits(){
    
    printf("Creato da Francesco Dainese\n");
    printf("In data: 28/11/2016\n");
    printf("Terminato il: 28/11/2016\n");
    printf("Descrizione del programma:\n");
    printf("Dato il numero di colonne verticali n (minimo 10), \nil programma disegna n colonne verticali a schermo\n");    
    printf("Premere un tasto per continuare\n");
    
    std::cin.get(); //getch();
     
    return;     
}

void disegnaColonne(int n){
     
     //Ottieni grandezza finestra
     int x = getmaxx();
     int y = getmaxy();
     
     //Calcola spazio tra ogni colonna
     int a = x/(n-1);
     
     //Salta prima colonna, visto che coincide con il bordo della finestra
     int i = 1;
     
     //Disegna colonne fino a quando il numero delle colonne coincide con il numero richiesto
     //L'ultima colonna non viene disegnata in quanto coincide con il bordo della finestra
     while(i<(n-1)){
         //Disegna colonna numero i
         line(a*i, 0, a*i, y);
         //Aumenta contatore colonne               
         i++;          
     }
          
     
     return;     
}
