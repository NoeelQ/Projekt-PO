#pragma once
#include "Pole.h"

Pole::Pole(TrudnoscTerenu trudnosc /*IPrzedmiot* przedmiot*/)
{
	_trudnosc = trudnosc;
	//_przedmiot = przedmiot;
}

//IPrzedmiot* Pole::przedmiot()
//{
//	return _przedmiot;
//}

//void Pole::przedmiot(IPrzedmiot* przedmiot)
//{
//	_przedmiot = przedmiot;
//}

TrudnoscTerenu Pole::trudnosc()
{
	return _trudnosc;
}
