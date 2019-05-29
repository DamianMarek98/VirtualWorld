#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Wilcze_Jagody::Wilcze_Jagody() {

}

Wilcze_Jagody::Wilcze_Jagody(Swiat *swiat, const POZYCJA pozycja) {
	this->inicjatywa = 0;
	this->sila = 99;
	this->swiat = swiat;
	this->pozycja = pozycja;
}
void Wilcze_Jagody::rysowanie() {
	cout << WILCZE_JAGODY;
}
char Wilcze_Jagody::znak() {
	return WILCZE_JAGODY;
}
void Wilcze_Jagody::kolizja(Organizm *nastepny, Organizm *org, KIERUNEK kierunek) {
	swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
	swiat->pole[nastepny->pozycja.x][nastepny->pozycja.y] = new PustePole;
	swiat->Usun(nastepny);
	swiat->Usun(org);
	cout << "Wilcze jegody zostaly zjedzone przez " << org->znak() << endl;
}
void Wilcze_Jagody::ruch(KIERUNEK kierunek, Organizm *org) {
	if (kierunek == gora) {
		if (pozycja.x - 1 > -1) {
			if (swiat->pole[pozycja.x - 1][pozycja.y]->znak() == PUSTKA) swiat->Dodaj(new Wilcze_Jagody(swiat, { pozycja.x - 1,pozycja.y }), { pozycja.x - 1,pozycja.y });
		}
	}
	else if (kierunek == dol) {
		if (pozycja.x + 1 < swiat->PobierzX()) {
			if (swiat->pole[pozycja.x + 1][pozycja.y]->znak() == PUSTKA) swiat->Dodaj(new Wilcze_Jagody(swiat, { pozycja.x + 1,pozycja.y }), { pozycja.x + 1,pozycja.y });
		}
	}
	else if (kierunek == prawo) {
		if (pozycja.y + 1 < swiat->PobierzY()) {
			if (swiat->pole[pozycja.x][pozycja.y + 1]->znak() == PUSTKA) swiat->Dodaj(new Wilcze_Jagody(swiat, { pozycja.x,pozycja.y + 1 }), { pozycja.x ,pozycja.y + 1 });
		}
	}
	else if (kierunek == lewo) {
		if (pozycja.y - 1 > -1) {
			if (swiat->pole[pozycja.x][pozycja.y - 1]->znak() == PUSTKA) swiat->Dodaj(new Wilcze_Jagody(swiat, { pozycja.x,pozycja.y - 1 }), { pozycja.x,pozycja.y - 1 });
		}
	}
}