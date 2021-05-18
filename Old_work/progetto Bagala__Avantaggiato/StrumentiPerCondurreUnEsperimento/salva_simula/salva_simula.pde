/////////////////////////// PROGETTO DI GUIDA E NAVIGAZIONE ///////////////////
//                       Bagalà Alfredo, Avantaggiato Sabrina               //
//////////////////////////////////////////////////////////////////////////////

// Salva_simula realizza un'interfaccia grafica che permette di visualizzare 
// in tempo reale l'andamento dell'esperimento.
// Questo software inizia a leggere i dati provenienti da seriale non appena viene avviato.
// Quando si conclude l'esperimento, digitando qualsiasi tasto da tastiera, 
// vengono creati due file:
// - un file .txt, contenente tutti i dati letti da seriale
// - una cattura della schermata grafica dell'esperimento.

// NOTA : 
// bisogna inserire manualmente le coordinate delle ancore e scegliere dist e size 
// per ottenere la centratura desiderata.
//////// PARAMETRI MODIFICABILI ////
// dimensioni schermata grafica
int size_x = 3000; 
int size_y = 2000;

float dist_x = 25000;
float dist_y = 25000;

float rap_x = size_x / dist_x;
float rap_y = size_y / dist_y;

int centra_x = 500; // distanze x e y dall'origine (posta in alto a sinistra)
int centra_y = 500;
// coordinate ancore. Bisogna inserirle manualmente
float anchors_x[] = {centra_x, centra_x, centra_x + 1758*rap_x, centra_x +  886*rap_x};               
float anchors_y[] = {centra_y, centra_y +  2829*rap_y, centra_y +  1745*rap_y, centra_y +  1579*rap_y}; 

import processing.serial.*;       

Serial MyPort;              // porta seriale
PrintWriter output;

String dati = "";
String label = "Ancora";

float printed[][];
int rows = 50;
int cols = 2;
int index_printed = 0;
int col = 250; 

// condizioni iniziali
int c = 0;
int i = 0;
int first = 1;
float X0 = 0.0; 
float Y0 = 0.0;
float X1 = 0.0;
float Y1 = 0.0;
float X02 = 0.0; 
float Y02 = 0.0;
float X12 = 0.0;
float Y12 = 0.0;
int misure = 0;
int fallimenti = 0;
int perc_fall = 0;


int dim = 6;

void setup(){

  MyPort = new Serial(this, Serial.list()[0], 115200); // inizializzazione della porta seriale
  MyPort.clear();
  output = createWriter( "outdoor2.txt" );  // Nome file dati (lo scrive dove risiede il programma)
  
  size(3000, 2000);
  background(255);

  for(c=0; c<size_x/10; c++){
    line(c*30 + 10,0,c*30 + 10,size_y);
    line(0,c*30 + 10,size_x,c*30 + 10);
    fill(0,0,0);
    textSize(12);
  }
  
  textSize(30);
  
  fill(0,100,0);
  rect(100, size_y - 60, 30, 3);
  rect(100, size_y - 67, 3, 14);
  rect(127, size_y - 67, 3, 14);
  int scale_x = int(30/rap_x);
  text(scale_x + "[mm]", 65, size_y - 25);

  rect(150, size_y - 100, 3, 30);
  rect(144, size_y - 100, 14, 3);
  rect(144, size_y - 73, 14, 3);
  int scale_y = int(30/rap_y);
  text(scale_y + "[mm]", 160, size_y - 74);
  
  fill(0,0,255);
  rect(centra_x - 3, centra_y - 3, 240, 6);
  triangle(centra_x + 225, centra_y - 20,centra_x + 225,centra_y + 20, centra_x + 250, centra_y);
  text("x", centra_x +  150, centra_y - 20);
  rect(centra_x - 3, centra_y - 3, 6, 240);
  triangle(centra_x - 20, centra_y + 225,centra_x + 20, centra_y + 225, centra_x, centra_y + 250);
  text("y", centra_x - 50, centra_y + 150);
  for (i=0; i < 4; i ++){
    fill(255,0,0);
    rect(anchors_x[i], anchors_y[i], 20, 20);
    fill(22,22,22);
    text(i, anchors_x[i] + 30, anchors_y[i] + 30);
  }
  
  fill(255,255,255);
  rect(size_x-600, size_y-300, 580, 250);
  fill(0,0,0);
  text("misure", size_x - 550, size_y - 100);
  text("%fallimenti", size_x - 275, size_y - 100);
  text("Coordinate dei tag nel piano", size_x - 530, size_y - 250);
}

void draw() {
  
  // fino a quando sono disponibili dati nella porta seriale, essi vengono letti
  while(MyPort.available()>0){
    dati = MyPort.readStringUntil('\n');
  }
  
  if(dati != "" & dati != null){
    fill(255,255,255);
    rect(size_x-600, size_y-300, 580, 250);
    output.print(dati);
    String[] p = split(dati,' '); // p salva tutti i dati
    misure++;
    
    // vengono stampate le coordinate dei due tag
    if(first == 1){
      X0 = centra_x + float(p[0])*rap_x ;
      Y0 = centra_y + float(p[1])*rap_y ;
      X1 = X0;
      Y1 = Y0;
      
      X02 = centra_x + float(p[7])*rap_x ;
      Y02 = centra_y + float(p[8])*rap_y ;
      X12 = X02;
      Y12 = Y02;
      
      first++;
    }else{
       X0 = X1;
       Y0 = Y1;
       X1 = centra_x + float (p[0])*rap_x ;
       Y1 = centra_y + float (p[1])*rap_y ;  
       
       X02 = X12;
       Y02 = Y12;
       X12 = centra_x + float (p[7])*rap_x ;
       Y12 = centra_y + float (p[8])*rap_y ;  
       
       first++;
     
    }  
    println(dati);
    dati ="";
  
    if(first == 2 || first%100 == 0){
      fill(col,128,0);
      rect(X0-dim-10, Y0-dim-10, dim+10, dim+10);
       
      fill(0,col,col);
      rect(X02-dim-10, Y02-dim-10, dim+10, dim+10);
    }else{
      fill(0,col,0);
    rect(X0-dim, Y0-dim, dim, dim);
     
    fill(0,0,col);
    rect(X02-dim, Y02-dim, dim, dim);
    }
     
    fill(0,0,col);
    rect(X02-dim, Y02-dim, dim, dim);
    
    fill(0,0,0);
    text("Coordinate dei tag nel piano", size_x - 530, size_y - 250);
    fill(0,250,0);
    text(int(p[0]), size_x - 450, size_y - 200);
    text(int(p[1]), size_x - 250, size_y - 200);
    fill(0,0,250);
    text(int(p[7]), size_x - 450, size_y - 150);
    text(int(p[8]), size_x - 250, size_y - 150);
    
    // conteggio fallimenti
    if(int(p[0])==0 & int(p[1])==0 & int(p[2])==0 | int(p[7])==0 & int(p[8])==0 & int(p[9])==0){
      fallimenti++;
   }
   perc_fall = 100*fallimenti/(misure);
  }
  
  fill(0,0,0);
  text("misure", size_x - 550, size_y - 100);
  text("%fallimenti", size_x - 275, size_y - 100);
  text(misure, size_x - 415, size_y - 100);
  text(perc_fall, size_x - 100, size_y - 100);
}

// funzione che permette di salvare la schermata quando si digita qualsiasi tasto da tastiera
void keyPressed() {
  saveFrame("otdoor2.png");
  output.flush(); // Scrive i dati rimanenti su file
  output.close(); // Chiude il file
  MyPort.stop();
  exit(); // Esce dal programma
}
