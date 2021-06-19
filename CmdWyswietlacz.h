
#pragma once
#include "Zolnierz.h"
#include "Plansza.h"
#include <iostream>
using namespace std;
class Zolnierz;
class Plansza;
class CmdWyswietlacz
{
public:
	static void pokazZwyciezce(Zolnierz* zolnierz);
	static void wyswietlTeren(Plansza* plansza);
	static void pokazPlansze(Plansza* plansza, Zolnierz* zolnierz1, Zolnierz* zolnierz2);
};