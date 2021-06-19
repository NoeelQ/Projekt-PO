
#pragma once

#include <iostream>
#include <list>
#include "IPrzedmiot.h"
using namespace std;
class IPrzedmiot;



class Zolnierz
{
private:
	static const int _MAX_GLOD = 100;
	string _nazwa;
	int _nrZolnierza;
	int _zdrowie;
	int _maxZdrowie;
	int _obrazenia;
	int _szybkosc;
	int _pozostalaSzybkosc;//
	int _glod = _MAX_GLOD;
	int _wspolrzednaX;
	int _wspolrzednaY;

	//list<IPrzedmiot*> _ekwipunek = {};

public:
	~Zolnierz();
	//void pokaz();
	//void wprowadzZolnierze1(Zolnierz &g1, Zolnierz& g2);
	//void wprowadzZolnierze2(Zolnierz &g1, Zolnierz& g2);
	//void startZolnierz(Zolnierz& g1, Zolnierz& g2);
	string nazwa();
	void nazwa(string zmstring);
	int nrZolnierza();
	void nrZolnierza(int zmint);
	int zdrowie();
	void zdrowie(int zmint);
	int maxZdrowie();
	void maxZdrowie(int zmint);
	int obrazenia();
	void obrazenia(int zmint);
	int szybkosc();
	void szybkosc(int zmint);
	int pozostalaSzybkosc();//
	void pozostalaSzybkosc(int zmint);//
	int glod();
	void glod(int zmint);
	int wspolrzednaX();
	int wspolrzednaY();
	void wspolrzednaX(int zmint);//
	void wspolrzednaY(int zmint);//
	void wspolrzedne(int zmint, int zmint2);
	//list<IPrzedmiot*> ekwipunek();

};