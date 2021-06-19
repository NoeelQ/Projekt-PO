#pragma once
#include "Gra.h"
class Plansza;
Gra::Gra()
{
	//_kierunek = kierunek;//
	plansza = CmdKreator::getPlansza();
	zolnierz1 = CmdKreator::getZolnierz();
	zolnierz2 = CmdKreator::getZolnierz();
}

Gra::~Gra()
{
	CmdWyswietlacz::pokazZwyciezce(Zwyciezca());
}

KierunekRuchu Gra::kierunek()//
{
	return _kierunek;
}

KierunekRuchu Gra::losujKierunek()//
{
	int min = 0, max = 3;
	int random;
	random = (rand() % max + min - 1) + min;
	return (KierunekRuchu)random;

	//if (random == 0)
	//	return KierunekRuchu::gora;
	//else if (random == 1)
	//	return KierunekRuchu::prawo;
	//else if (random == 2)
	//	return KierunekRuchu::dol;
	//else if (random == 3)
	//	return KierunekRuchu::lewo;
}

bool Gra::czyWalka()
{
	const int minOdleglosc = 2;
	return abs(zolnierz1->wspolrzednaX() - zolnierz2->wspolrzednaX()) <= minOdleglosc
		&& abs(zolnierz1->wspolrzednaY() - zolnierz2->wspolrzednaY()) <= minOdleglosc;
}

void Gra::wykonajTure(Zolnierz* zolnierz)
{
	const int kosztWalki = 1;
	KierunekRuchu kierunek = Gra::losujKierunek();//
	int x = zolnierz->wspolrzednaX();
	int y = zolnierz->wspolrzednaY();
	int pktRuchu = zolnierz->szybkosc();


	while (pktRuchu >= plansza->kosztRuchu(x, y)) {
		//wykonanie ruchu
		pktRuchu -= plansza->wykonajRuch(zolnierz, kierunek);

		//walka
		if (pktRuchu >= kosztWalki && czyWalka()) {
			pktRuchu -= kosztWalki;
			walka();
		}

		//podnoszenie przedmiotu
		/*IPrzedmiot* przedmiot = plansza->pole(x, y)->przedmiot();
		if (przedmiot != nullptr) {
			if (przedmiot->czyUzycNatychmiast()) {
				przedmiot->uzyj(zolnierz);
			}
			else {
				zolnierz->ekwipunek().push_back(przedmiot);
			}
		}*/

		//u�ycie przedmiotu z ekwipunku
		/*for (auto p : zolnierz->ekwipunek()) {
			if (p->czyUzyc(zolnierz)) {
				p->uzyj(zolnierz);
			}
		}*/
	}
}
void Gra::WykonajRuch()
{





	CmdWyswietlacz::pokazPlansze(plansza, zolnierz1, zolnierz2);
	CmdWyswietlacz::wyswietlTeren(plansza);
	Gra::wykonajTure(zolnierz1);
	Gra::wykonajTure(zolnierz2);
	//zolnierz1->zdrowie(zolnierz1->zdrowie() - 1);



}

int rzutKostka(int oczka, int rzuty)//
{
	int min = 1, suma = 0;
	int random;
	for (int i = 0; i < rzuty; i++)
	{
		random = (rand() % oczka + min - 1) + min;
		suma = suma + random;
	}
	return suma;
}

void Gra::walka()//
{
	//int pierwszeUderzenie = 1;
	bool czyUcieczka1 = true, czyUcieczka2 = true;
	int dmg;
	//cout << "Rozpoczela sie walka miedzy zolnierzami" << endl;
	cout << "==================================================" << endl;
	cout << "Zolnierz " << zolnierz1->nazwa() << endl;
	cout << "Zdrowie: " << zolnierz1->zdrowie() << endl;
	cout << "Obrazenia: " << zolnierz1->obrazenia() << endl;
	cout << "Szybkosc: " << zolnierz1->szybkosc() << endl;
	cout << "==================================================" << endl;
	cout << "Zolnierz " << zolnierz2->nazwa() << endl;
	cout << "Zdrowie: " << zolnierz2->zdrowie() << endl;
	cout << "Obrazenia: " << zolnierz2->obrazenia() << endl;
	cout << "Szybkosc: " << zolnierz2->szybkosc() << endl;
	cout << "==================================================" << endl;
	while (zolnierz1->zdrowie() > 0 && czyUcieczka1 && czyUcieczka2 || zolnierz2->zdrowie() > 0 && czyUcieczka1 && czyUcieczka2)
	{
		//if (zolnierz1->szybkosc() > zolnierz2->szybkosc())
		//{
		if (zolnierz2->zdrowie() > 0 && zolnierz1->zdrowie() > 0)
		{
			dmg = zolnierz1->obrazenia() + rzutKostka(6, 1);
			zolnierz2->zdrowie(zolnierz2->zdrowie() - dmg);
			cout << "Zolnierz " << zolnierz1->nazwa() << " uderzyl za " << dmg << " obrazen" << endl;
			cout << "Pozostale zdrowie " << zolnierz2->nazwa() << " :" << zolnierz2->zdrowie() << endl;
		}
		//}
		//else
		//{
		if (zolnierz2->zdrowie() > 0 && zolnierz1->zdrowie() > 0)
		{
			dmg = zolnierz2->obrazenia() + rzutKostka(6, 1);
			zolnierz1->zdrowie(zolnierz1->zdrowie() - dmg);
			cout << "Zolnierz " << zolnierz2->nazwa() << " uderzyl za " << dmg << " obrazen" << endl;
			cout << "Pozostale zdrowie " << zolnierz1->nazwa() << " :" << zolnierz1->zdrowie() << endl;
		}
		//}

		if (zolnierz1->zdrowie() <= 30 && zolnierz1->zdrowie() > 0)
		{
			if (rzutKostka(6, 2) == 7)
			{
				czyUcieczka1 = !czyUcieczka1;
				cout << "Zolnierz " << zolnierz1->nazwa() << " uciekl z walki" << endl;
			}
		}
		if (zolnierz2->zdrowie() <= 30 && zolnierz2->zdrowie() > 0 && !czyUcieczka1)
		{
			if (rzutKostka(6, 2) == 7)
			{
				czyUcieczka2 = !czyUcieczka2;
				cout << "Zolnierz " << zolnierz2->nazwa() << " uciekl z walki" << endl;
			}
		}
		if (zolnierz1->zdrowie() <= 0 || zolnierz2->zdrowie() <= 0)
			break;
	}
	if (!czyUcieczka1 && zolnierz1->zdrowie() > 0)
	{
		ucieczka(zolnierz1);
	}
	else if (!czyUcieczka2 && zolnierz2->zdrowie() > 0)
	{
		ucieczka(zolnierz2);
	}

}

void Gra::ucieczka(Zolnierz* zolnierz)//
{
	//Plansza* plansza;
	int max = plansza->wymiary() - 1;
	int x, y;
	int min = 1;
	int random;
	x = (rand() % max + min - 1) + min;
	y = (rand() % max + min - 1) + min;
	zolnierz->wspolrzednaX(x);
	zolnierz->wspolrzednaY(y);
}

bool Gra::CzyKoniec()
{
	return zolnierz1->zdrowie() <= 0
		|| zolnierz2->zdrowie() <= 0;
}

Zolnierz* Gra::Zwyciezca()
{
	if (zolnierz1->zdrowie() <= 0)
		return zolnierz2;
	else if (zolnierz2->zdrowie() <= 0)
		return zolnierz1;
	else
		return nullptr;
}