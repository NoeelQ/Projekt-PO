//#pragma once
//#include "Zolnierz.h"
//#include <iostream>
//#include <string>
//class Zolnierz;
//
//class IPrzedmiot
//{
//public:
//    virtual ~IPrzedmiot() {}
//    virtual void uzyj(Zolnierz* z) = 0;
//    virtual bool czyUzycNatychmiast() = 0;
//    virtual bool czyUzyc(Zolnierz* zolnierz)
//    {
//        return true;
//    }
//};
//
//class Apteczka :public IPrzedmiot
//{
//    static const int ILOSC_ZDROWIA = 20;
//public:
//    void uzyj(Zolnierz* z)
//    {
//        z->zdrowie(z->zdrowie() + ILOSC_ZDROWIA);
//    }
//    bool czyUzycNatychmiast()
//    {
//        return false;
//    }
//    bool czyUzyc(Zolnierz* zolnierz)
//    {
//        return zolnierz->zdrowie() < zolnierz->zdrowie() - 20;
//    }
//
//};
//
//class Pozywienie :public IPrzedmiot
//{
//    static const int ILOSC_GLODU = 25;
//public:
//    void uzyj(Zolnierz* z)
//    {
//        z->glod(z->glod() + ILOSC_GLODU);
//    }
//    bool czyUzycNatychmiast()
//    {
//        return false;
//    }
//    bool czyUzyc(Zolnierz* zolnierz)
//    {
//        return zolnierz->glod() < 80;
//    }
//};
//
//class Kamizelka :public IPrzedmiot
//{
//    static const int DODATKOWE_ZDROWIE = 40;
//public:
//    void uzyj(Zolnierz* z)
//    {
//        z->maxZdrowie(z->maxZdrowie() + DODATKOWE_ZDROWIE);
//        z->zdrowie(z->zdrowie() + DODATKOWE_ZDROWIE);
//    }
//    bool czyUzycNatychmiast()
//    {
//        return true;
//    }
//};
//
//class Buty :public IPrzedmiot
//{
//    static const int DODATKOWA_SZYBKOSC = 10;
//public:
//    void uzyj(Zolnierz* z)
//    {
//        z->szybkosc(z->szybkosc() + DODATKOWA_SZYBKOSC);
//    }
//    bool czyUzycNatychmiast()
//    {
//        return true;
//    }
//};
//
//class Karabin :public IPrzedmiot
//{
//    static const int DODATKOWE_OBRAZENIA = 5;
//public:
//    void uzyj(Zolnierz* z)
//    {
//        z->obrazenia(z->obrazenia() + DODATKOWE_OBRAZENIA);
//    }
//    bool czyUzycNatychmiast()
//    {
//        return true;
//    }
//};
