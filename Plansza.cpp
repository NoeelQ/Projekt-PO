#pragma once
#include "Plansza.h"


using namespace std;

Plansza::Plansza(int _wymiary, bool czyTrudne, bool czyLatwe)
{
	this->_wymiary = _wymiary;
	pola = new Pole * *[_wymiary];
	for (auto x = 0; x < _wymiary; x++)
	{
		pola[x] = new Pole * [_wymiary];
		for (auto y = 0; y < _wymiary; y++)
		{
			TrudnoscTerenu trudnosc = LosujTrudnoscTerenu(czyLatwe, czyTrudne);
			//IPrzedmiot* przedmiot = LosujPrzedmiot();
			pola[x][y] = new Pole(trudnosc /*przedmiot*/);
		}
	}
}

Plansza::~Plansza()
{
	for (auto x = 0; x < _wymiary; x++)
	{
		for (auto y = 0; y < _wymiary; y++)
		{
			delete pola[x][y]; //Usuniecie obiektu
		}
		delete[] pola[x]; //usuniecie wiersza
	}
	delete pola; //usuniecie tablicy z wierszami
}






int Plansza::wymiary()
{
	return _wymiary;
}

int Plansza::wykonajRuch(Zolnierz* zolnierz, KierunekRuchu kierunek)
{
	//Plansza* plansza;
	int rezultat = kosztRuchu(zolnierz->wspolrzednaX(), zolnierz->wspolrzednaY());

	if (kierunek == KierunekRuchu::gora && zolnierz->wspolrzednaY() > 0)
		zolnierz->wspolrzednaY(zolnierz->wspolrzednaY() - 1);// 'y' zmniejsza o 1
	if (kierunek == KierunekRuchu::dol && zolnierz->wspolrzednaY() < this->wymiary())
		zolnierz->wspolrzednaY(zolnierz->wspolrzednaY() + 1);// 'y' zwieksza o 1
	if (kierunek == KierunekRuchu::prawo && zolnierz->wspolrzednaX() > 0)
		zolnierz->wspolrzednaX(zolnierz->wspolrzednaX() - 1);// 'x' zmniejsza o 1
	if (kierunek == KierunekRuchu::lewo && zolnierz->wspolrzednaX() < this->wymiary())
		zolnierz->wspolrzednaX(zolnierz->wspolrzednaX() + 1);// 'x' zwieksza o 1

	return rezultat;
}
void Plansza::wymiary(int zmint)
{
	_wymiary = zmint;
}


//void Plansza::wybierzWymiary(Plansza &p1)
//{
//    int zmint2;
//	cout << "Chcesz zmienic wymiary planszy? (podstawowo 10x10)"<< endl<<"1 - Tak"<<endl<<"0 - Nie"<<endl;
//	cin >> zmint2;
//	if (zmint2 == 1)
//	{
//		cout << "Wprowadz wymiary planszy (AxA)";
//		cin >> zmint2;
//        p1._wymiary(zmint2);
//	}
//}


Pole* Plansza::pole(int x, int y)
{
	return pola[x][y];
}

int Plansza::kosztRuchu(int x, int y)
{
	Pole* pole = pola[x][y];
	return (int)pole->trudnosc() + 1;

	//if (pole->trudnosc() == TrudnoscTerenu::latwy)
	//	return 1;
	//else if (pole->trudnosc() == TrudnoscTerenu::trudny)
	//	return 3;
	//else if (pole->trudnosc() == TrudnoscTerenu::neutralny)
	//	return 2;
}

void Plansza::WyswietlTrudnoscTerenu()
{
	for (auto x = 0; x < _wymiary; x++)
	{
		for (auto y = 0; y < _wymiary; y++)
		{
			Pole* pole = pola[x][y];
			if (pole->trudnosc() == TrudnoscTerenu::latwy)
				cout << "L";
			else if (pole->trudnosc() == TrudnoscTerenu::trudny)
				cout << "T";
			else if (pole->trudnosc() == TrudnoscTerenu::neutralny)
				cout << "N";
		}
		cout << endl;
	}
	cout << endl;
}

TrudnoscTerenu Plansza::LosujTrudnoscTerenu(bool czyLatwy, bool czyTrudny)
{
	int min = 1, max = 10;
	int random;
	//srand(time(NULL));
	random = (rand() % max + min - 1) + min;
	if (random >= 1 && random <= 3 && czyTrudny)
		return TrudnoscTerenu::trudny;
	else if (random >= 1 && random <= 3 && !czyTrudny)
		return TrudnoscTerenu::neutralny;
	if (random >= 4 && random <= 6 && czyLatwy)
		return TrudnoscTerenu::latwy;
	else if (random >= 4 && random <= 6 && !czyLatwy)
		return TrudnoscTerenu::neutralny;
	if (random >= 7)
		return TrudnoscTerenu::neutralny;

}

//void Plansza::wybierzTrudnoscTerenu(Plansza& p1)
//{
//	int wartosc = 10;
//	int while2 = 1;
//	while (while2 == 1)
//	{
//		cout << "Podaj jakosc pol jakie beda sie znajdowac na planszy: " << endl;
//		cout << "1 - Latwe (150% ruchu)";
//		if (planszaPolaL == 1) cout << "            X" << endl;
//		else cout << endl;
//		cout << "2 - Ciezkie (50% ruchu)";
//		if (planszaPolaC == 1) cout << "           X" << endl;
//		else cout << endl;
//		cout << "9 - Reset" << endl;
//		cout << "0 - Zatwierdz" << endl;
//		cin >> planszaPola;
//		switch (planszaPola)
//		{
//		case 1:
//			planszaPolaL = 1;
//			break;
//		case 2:
//			planszaPolaC = 1;
//			break;
//		case 9:
//			planszaPolaL = 0;
//			planszaPolaC = 0;
//			break;
//		case 0:
//			while2 = 0;
//			break;
//
//		}
//
//	}
//	p1.WyswietlTrudnoscTerenu(planszaPolaL, planszaPolaC);
//	p1.przedmiotyResp();
//}

//void Plansza::przedmiotyResp()
//{
//	int a = 1, b = 100;
//	tablicaPlanszyPrzedmioty[100][100];
//	int random;
//	srand(time(NULL));
//	/*Uzbrojenie:
//	* buty(szybkosc) shoe         S
//	* kamizelka(zdrowie) vest     V
//	* bron(obrazenia) weapon      W
//	*
//	* Po�ywienie Food             F
//	*
//	* Apteczki  heal              H
//	*/
//	for (auto i = 0; i < _wymiary; i++)
//	{
//		for (auto j = 0; j < _wymiary; j++)
//		{
//			random = (rand() % b + a - 1) + a;
//			if (random >= 1 && random < 3)//2% na buty
//			{
//				tablicaPlanszyPrzedmioty[i][j] = 'S';
//				cout << tablicaPlanszyPrzedmioty[i][j] << " ";
//			}
//			if (random >= 3 && random < 5)//2% na kamizelke
//			{
//				tablicaPlanszyPrzedmioty[i][j] = 'V';
//				cout << tablicaPlanszyPrzedmioty[i][j] << " ";
//			}
//			if (random >= 5 && random < 7)//2% na bron
//			{
//				tablicaPlanszyPrzedmioty[i][j] = 'W';
//				cout << tablicaPlanszyPrzedmioty[i][j] << " ";
//			}
//			if (random >= 7 && random < 37)//30% na jedzenie
//			{
//				tablicaPlanszyPrzedmioty[i][j] = 'F';
//				cout << tablicaPlanszyPrzedmioty[i][j] << " ";
//			}
//			if (random >= 37 && random < 52)//15% na heal
//			{
//				tablicaPlanszyPrzedmioty[i][j] = 'H';
//				cout << tablicaPlanszyPrzedmioty[i][j] << " ";
//			}
//			if (random >= 52)//na nic
//			{
//				tablicaPlanszyPrzedmioty[i][j] = '0';
//				cout << tablicaPlanszyPrzedmioty[i][j] << " ";
//			}
//		}
//		cout << endl;
//	}
//
//}

//IPrzedmiot* Plansza::LosujPrzedmiot() //Polimorfizm 
//{
//	int min = 1, max = 100;
//
//	//srand(time(NULL));
//	int random = (rand() % max + min - 1) + min;
//	if (random >= 1 && random < 3)//2% na buty
//		return new Buty();
//	if (random >= 3 && random < 5)//2% na kamizelke
//		return new Kamizelka();
//	if (random >= 5 && random < 7)//2% na bron
//		return new Karabin();
//	if (random >= 7 && random < 37)//30% na jedzenie
//		return new Pozywienie();
//	if (random >= 37 && random < 52)//15% na heal
//		return new Apteczka();
//	else
//		return nullptr;
//
//}