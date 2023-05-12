

#include<iostream>
#include<windows.h>
#include<conio.h>
#include<stdlib.h>
#include<list>
#include<mmsystem.h>

#pragma comment(lib, "winmm.lib")

using namespace std;

#define ARRIBA 72
#define IZQUIERDA 75
#define DERECHA 77
#define ABAJO 80



void gotoxy (int x, int y);
void ocultarcursor();
void pintarlimite();
void disparo();
void lose();
void explosion();


int main() { 
 
   ocultarcursor();
   pintarlimite();
   disparo();
   lose();
   explosion();
   
   return 0;
   
    }   



void gotoxy(int x, int y) {

      HANDLE hcon;
      hcon = GetStdHandle(STD_OUTPUT_HANDLE);
      
      COORD dwpos;
      dwpos.X=x;
      dwpos.Y=y;
      SetConsoleCursorPosition(hcon,dwpos);
      
      
}

void ocultarcursor()
{
	  HANDLE hcon;
	  hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	  CONSOLE_CURSOR_INFO cci;
	  cci.dwSize = 50;
	  cci.bVisible = FALSE;
	  SetConsoleCursorInfo(hcon, &cci);
	  	
}


void pintarlimite()
{
      for ( int i = 2; i < 78; i++)
	{
		 gotoxy(i,3); 
		 printf("%c", 205);
		 gotoxy(i,33);
		  printf("%c", 205);
	}
	
	  for (int i = 4; i< 33; i++)
	{
		gotoxy(2,i);
		 printf("%c", 186);
		gotoxy(77,i); 
		printf("%c", 186);	
	}
	
	gotoxy(2,3);
	 printf("%c", 201);
	gotoxy(2,33);
	 printf("%c", 200);
	gotoxy(77,3); 
	printf("%c", 187);
	gotoxy(77,33);
	 printf("%c", 188);
	
}

void disparo()
{
	
	   PlaySound(TEXT("snd_disparo.wav"),NULL,SND_ASYNC);
}

void lose()
{

       PlaySound(TEXT("snd_lose.wav"),NULL,SND_ASYNC);
       
}      

void explosion ()
{
	
	   PlaySound(TEXT("explosion.wav"),NULL,SND_ASYNC);
	   
	   
}

class NAVE
{ 

    int x,y;
    int corazones;
    int vidas;
    
 public :
    
	 NAVE ();
	 NAVE(int _x, int _y, int _corazones, int _vidas);
	 
	 void pintar();
	 void borrar();
	 void mover();
	 void pintarcorazones();
	 void perdervida();
	 void disminuircorazones(){corazones--;};
	 
	 int obtenerx() const;
	 int obtenery()const;
	 int obtenervidas() const;
	 
		 
};

       


