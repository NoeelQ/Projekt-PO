
//#pragma once

#include "Zolnierz.h"


using namespace std;
int zmint, zmint2;
int zmstat1, zmstat2;
string zmstring;

Zolnierz::~Zolnierz()
{
	//	for (auto&& p : ekwipunek)
	//		delete p;
}

string Zolnierz::nazwa()
{
	return _nazwa;
}

void Zolnierz::nazwa(string zmstring)
{
	_nazwa = zmstring;
}
int Zolnierz::nrZolnierza()
{
	return _nrZolnierza;
}
void Zolnierz::nrZolnierza(int zmint)
{
	_nrZolnierza = zmint;
}
int Zolnierz::zdrowie()
{
	return _zdrowie;
}
void Zolnierz::zdrowie(int zmint)
{
	if (zmint > _maxZdrowie) _zdrowie = _maxZdrowie;
	else _zdrowie = zmint;
}
int Zolnierz::maxZdrowie()
{
	return _maxZdrowie;
}
void Zolnierz::maxZdrowie(int zmint)
{
	_maxZdrowie = zmint;
}
int Zolnierz::obrazenia()
{
	return _obrazenia;
}
void Zolnierz::obrazenia(int zmint)
{
	_obrazenia = zmint;
}
int Zolnierz::szybkosc()
{
	return _szybkosc;
}
void Zolnierz::szybkosc(int zmint)
{
	_szybkosc = zmint;
}
int Zolnierz::pozostalaSzybkosc()//
{
	return _szybkosc;
}
void Zolnierz::pozostalaSzybkosc(int zmint)//
{
	_pozostalaSzybkosc = _szybkosc;
}
int Zolnierz::glod()
{
	return _glod;
}
void Zolnierz::glod(int zmint)
{
	if (zmint > _MAX_GLOD) _glod = _MAX_GLOD;
	else _glod = zmint;
}
int Zolnierz::wspolrzednaX()
{
	return _wspolrzednaX;
}
int Zolnierz::wspolrzednaY()
{
	return _wspolrzednaY;
}
void Zolnierz::wspolrzednaX(int zmint)//
{
	_wspolrzednaX = zmint;
}
void Zolnierz::wspolrzednaY(int zmint)//
{
	_wspolrzednaY = zmint;
}
void Zolnierz::wspolrzedne(int x, int y)
{
	_wspolrzednaX = x;
	_wspolrzednaY = y;
}





//void Zolnierz::startZolnierz(Zolnierz& g1,Zolnierz &g2)
//{
//
//    cout << "Czy chcesz zmienic dane Zolnierza ?" << endl << "1 - Tak" << endl << "0 - Nie" << endl;
//    cin >> zmint;
//    switch (zmint)
//    {
//    case 1:
//    zmianaStat:
//        cout << "Ktory zolnierz" << endl << "1 - " << g1.nazwa << endl << "2 - " << g2.nazwa << endl << "0 - Zakoncz" << endl;
//        cin >> zmstat1;
//        switch (zmstat1)
//        {
//        case 1:
//            wprowadzZolnierze1(g1,g2);
//            break;
//        case 2:
//            wprowadzZolnierze2(g1,g2);
//            break;
//        }
//    case 0:
//        break;
//    }
//
//
//}
//
//
//
//
//
//
//void Zolnierz::wprowadzZolnierze1(Zolnierz& g1,Zolnierz &g2)
//{
//
//            cout << "Ktore Statystyki chcesz zmienic?" << endl;
//        gAStaty:
//            cout << "1 - nazwa = " << g1.nazwa << endl;
//            cout << "2 - nrZolnierza = " << g1.nrZolnierza << endl;
//            cout << "3 - zdrowie = " << g1.zdrowie << endl;
//            cout << "4 - obrazenia = " << g1.obrazenia << endl;
//            cout << "5 - szybkosc = " << g1.szybkosc << endl;
//            cout << "6 - glod = " << g1.glod << endl;
//            cout << "7 - Wspolrzedne = [" <<g1.wspolrzednaX<<", "<<g1.wspolrzednaY<<"]"  << endl;
//            cout << "0 - Cofnij" << endl;
//            cin >> zmstat2;
//            switch (zmstat2)
//            {
//            case 1:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmstring;
//                g1.nazwa(zmstring);
//                goto gAStaty;
//                break;
//            case 2:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmint;
//                g1._nrZolnierza(zmint);
//                goto gAStaty;
//                break;
//            case 3:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmint;
//                g1._zdrowie(zmint);
//                goto gAStaty;
//                break;
//            case 4:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmint;
//                g1._obrazenia(zmint);
//                goto gAStaty;
//                break;
//            case 5:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmint;
//                g1._szybkosc(zmint);
//                goto gAStaty;
//                break;
//            case 6:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmint;
//                g1._glod(zmint);
//                goto gAStaty;
//                break;
//            case 7:
//                cout << "Wprowadz [x,y]: " << endl;
//                cout << "x = ";
//                cin >> zmint;
//                cout << "y = ";
//                cin >> zmint2;
//                g1._wspolrzedne(zmint,zmint2);
//                goto gAStaty;
//            break;
//            case 0:
//                startZolnierz(g1, g2);
//                break;
//            }
//
//}
//
//
//
//void Zolnierz::wprowadzZolnierze2(Zolnierz &g1, Zolnierz &g2)
//{
//            cout << "Ktore Statystyki chcesz zmienic?" << endl;
//        gAStaty:
//            cout << "1 - Nazwa = " << g2.nazwa << endl;
//            cout << "2 - nrZolnierza = " << g2.nrZolnierza << endl;
//            cout << "3 - Zdrowie = " << g2.zdrowie << endl;
//            cout << "4 - Obrazenia = " << g2.obrazenia << endl;
//            cout << "5 - Szybkosc = " << g2.szybkosc << endl;
//            cout << "6 - Glod = " << g2.glod << endl;
//            cout << "7 - Wspolrzedne = [" << g2.wspolrzednaX << ", " << g2.wspolrzednaY << "]" << endl;
//            cout << "0 - Cofnij" << endl;
//            cin >> zmstat2;
//            switch (zmstat2)
//            {
//            case 1:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmstring;
//                g2.nazwa(zmstring);
//                goto gAStaty;
//                break;
//            case 2:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmint;
//                g2._nrZolnierza(zmint);
//                goto gAStaty;
//                break;
//            case 3:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmint;
//                g2._zdrowie(zmint);
//                goto gAStaty;
//                break;
//            case 4:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmint;
//                g2._obrazenia(zmint);
//                goto gAStaty;
//                break;
//            case 5:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmint;
//                g2._szybkosc(zmint);
//                goto gAStaty;
//                break;
//            case 6:
//                cout << "Wprowadz dane: " << endl;
//                cin >> zmint;
//                g2._glod(zmint);
//                goto gAStaty;
//                break;
//            case 7:
//                cout << "Wprowadz [x,y]: " << endl;
//                cout << "x = ";
//                cin >> zmint;
//                cout << "y = ";
//                cin >> zmint2;
//                g2._wspolrzedne(zmint, zmint2);
//                goto gAStaty;
//                break;
//            case 0:
//                startZolnierz(g1, g2);
//                break;
//            }
//
//}
//
//
