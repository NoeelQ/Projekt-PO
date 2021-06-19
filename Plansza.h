#pragma once
#include <iostream>
#include <string>
#include <map>
#include "Zolnierz.h"
#include "Pole.h"
#include "Gra.h"
//#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
class Zolnierz;
class Gra;
class Pole;
enum class KierunekRuchu;

class Plansza
{
	int** p1;
	int _wymiary;
	map<Zolnierz*, pair<int, int>> pozycjeZolnierzy;
	Pole*** pola;
	char tablicaPlanszyPrzedmioty[100][100];
	char tablicaPlanszy[100][100];
public:
	Plansza(int wymiary, bool czyTrudne, bool czyLatwe);
	~Plansza();

	/*void ustawienieZolnierza(Zolnierz* z, pair<int,int> pozycja);
	void ruszZolnierza(Zolnierz* z, pair<int,int> pozycja);*/
	//void wybierzTrudnoscTerenu(Plansza& p1);
	//void Wybierzlosowosc();
	Pole* pole(int x, int y);
	int kosztRuchu(int x, int y);
	void WyswietlTrudnoscTerenu();
	TrudnoscTerenu LosujTrudnoscTerenu(bool czyLatwy, bool czyTrudny);
	//IPrzedmiot* LosujPrzedmiot();
	//void przedmiotyResp();
	int wymiary();
	void wymiary(int zmint);
	int wykonajRuch(Zolnierz* zolnierz, KierunekRuchu kierunek);



};