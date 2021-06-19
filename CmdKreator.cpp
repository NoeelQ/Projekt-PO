#pragma once
#include "CmdKreator.h"

using namespace std;

string CmdKreator::getString()
{
	string s;
	cin >> s;
	return s;
}

int CmdKreator::getInt()
{
	int i;
	cin >> i;
	return i;
}

bool CmdKreator::getBool()
{
	string i;
	cin >> i;
	return i == "Y" || i == "Yes" || i == "Tak" || i == "T"
		|| i == "tak" || i == "t" || i == "y" || i == "yes";
}

Zolnierz* CmdKreator::getZolnierz()
{
	Zolnierz* zolnierz = new Zolnierz();
	cout << "Wprowadz dane zolnierza: "<<endl;
	cout << "Nazwa: ";
	zolnierz->nazwa(getString());
	cout << "nrZolnierza: ";
	zolnierz->nrZolnierza(getInt());
	cout << "Max zdrowie: ";
	zolnierz->maxZdrowie(getInt());
	cout << "Zdrowie: ";
	zolnierz->zdrowie(getInt());
	cout << "Obrazenia: ";
	zolnierz->obrazenia(getInt());
	cout << "Szybkosc: ";
	zolnierz->szybkosc(getInt());
	cout << "Glod: ";
	zolnierz->glod(getInt());
	cout << "Wspolrzedne: ";
	cout << "Wprowadz x i y: ";
	int x = getInt();
	int y = getInt();
	zolnierz->wspolrzedne(x, y);
	//cout << "Wprowadz y: ";
	//zolnierz->wspolrzednaY(getInt());

	return zolnierz;
}





Plansza* CmdKreator::getPlansza()
{
	cout << "Wprowadz wymiary(AxA): ";
	int wymiar = getInt();
	cout << "Wprowadz trudnosc terenu: " << endl;
	cout << "Latwe (150% ruchu) Y/N ";
	bool czyLatwy = getBool();
	cout << "Ciezkie (50% ruchu) Y/N ";
	bool czyTrudny = getBool();
	return new Plansza(wymiar, czyLatwy, czyTrudny);
}