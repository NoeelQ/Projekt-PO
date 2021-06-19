#pragma once
//#include "Zolnierz.h"
#include "Plansza.h"
#include "CmdWyswietlacz.h"
//#include "Pole.h"
#include "CmdKreator.h"
#include <stdlib.h>
class Plansza;
class CmdKreator;
class CmdWyswietlacz;
class Zolnierz;
enum class KierunekRuchu { gora, prawo, dol, lewo };//

class Gra
{
	Plansza* plansza;
	Zolnierz* zolnierz1;
	Zolnierz* zolnierz2;

	KierunekRuchu _kierunek = KierunekRuchu::gora;//

	Zolnierz* Zwyciezca();
public:
	Gra();
	~Gra();
	static/**/KierunekRuchu losujKierunek();//
	//void przemieszczanieZolnierza(Zolnierz* zolnierz);//

	void ucieczka(Zolnierz* zolnierz);
	void WykonajRuch();
	void walka();
	void wykonajTure(Zolnierz* zolnierz);
	bool CzyKoniec();
	KierunekRuchu kierunek();//
	bool czyWalka();
};