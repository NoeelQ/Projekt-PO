#pragma once
#include <iostream>
#include "Zolnierz.h"
#include "Plansza.h"
#include "IPrzedmiot.h"
#include "CmdKreator.h"
#include "Gra.h"
#include<windows.h>
#include <cstdlib>
#include<ctime>
using namespace std;
const unsigned int refreshTime = 1000;
int main()
{
	srand(time(NULL));
	//    /*
	//    Plansza p1;
	//    p1.wybierzWymiary(p1);
	//    p1.wybierzTrudnoscTerenu(p1);
	//    Zolnierze g1;
	//    Zolnierze g2("Bot", 2, 100, 10, 2, 100, 10/*to do zmiany bedzie (max wymiary), 10);
	//    
	//    Przedmioty prz1;
	//
	//    
	//
	//    g1.startZolnierz(g1, g2);
	//
	//    p1.getWymiary();
	//
	//
	//    g1.pokaz();
	//    g2.pokaz();
	//    prz1.jakiPrzedmiot();
	//    */
	//    
	//    CmdKreator m;
	//    Zolnierz* z1 = m.getZolnierz();
	//    //Zolnierz* z2 = m.getZolnierz();
	//    //z1->nazwa = "Alfa";
	//    m.pokaz(*z1);
	//    //m.pokaz(*z2);
	//    Plansza* p = m.getPlansza();
	//}
	Gra* gra = new Gra();
	while (!gra->CzyKoniec())
	{
		gra->WykonajRuch();
		Sleep(refreshTime);
	}
	delete gra;
}