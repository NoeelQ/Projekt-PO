#pragma once
#include "IPrzedmiot.h"
class IPrzedmiot;


enum class TrudnoscTerenu { latwy, neutralny, trudny };
class Pole
{

	//IPrzedmiot* _przedmiot = nullptr;

	TrudnoscTerenu _trudnosc = TrudnoscTerenu::latwy;

public:
	Pole(TrudnoscTerenu trudnosc/*, IPrzedmiot* przedmiot*/);
	//IPrzedmiot* przedmiot();
	//void przedmiot(IPrzedmiot* przedmiot);
	TrudnoscTerenu trudnosc();
};