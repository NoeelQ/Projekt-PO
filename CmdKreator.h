

#pragma once
#include <iostream>
#include "Zolnierz.h"
#include "Plansza.h"
//#include "Pole.h"
class Plansza;
class Zolnierz;
class CmdKreator
{

public:

    static Zolnierz* getZolnierz();
    static string getString();
    static int getInt();
    static bool getBool();
    //static void pokaz(Zolnierz& g1);

    static Plansza* getPlansza();

};