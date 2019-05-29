#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Guarana::Guarana() {

}
Guarana::Guarana(Swiat *swiat, const POZYCJA pozycja) {
	this->inicjatywa = 0;
	this->sila = 0;
	this->swiat = swiat;
	this->pozycja = pozycja;
}
void Guarana::rysowanie() {
	cout << GUARANA;
}
char Guarana::znak() {
	return GUARANA;
}
void Guarana::kolizja(Organizm *nastepny, Organizm *org, KIERUNEK kierunek) {
	swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
	swiat->Usun(nastepny);
	if (kierunek == gora) {
		org->pozycja.x--;
	}
	else if (kierunek == dol) {
		org->pozycja.x++;
	}
	else if (kierunek == prawo) {
		org->pozycja.y++;
	}
	else if (kierunek == lewo) {
		org->pozycja.y--;
	}
	swiat->pole[org->pozycja.x][org->pozycja.y] = org;
	//zwiêksznie sily
	org->sila += 3;
	cout << "Guarana zostala zjedzona przez " << org->znak() << " ,ktorego sila wzrosla o 3" << endl;
}
void Guarana::ruch(KIERUNEK kierunek, Organizm *org) {
	if (kierunek == gora) {
		if (pozycja.x - 1 > -1) {
			if (swiat->pole[pozycja.x - 1][pozycja.y]->znak() == PUSTKA) swiat->Dodaj(new Guarana(swiat, { pozycja.x - 1,pozycja.y }), { pozycja.x - 1,pozycja.y });
		}
	}
	else if (kierunek == dol) {
		if (pozycja.x + 1 < swiat->PobierzX()) {
			if (swiat->pole[pozycja.x + 1][pozycja.y]->znak() == PUSTKA) swiat->Dodaj(new Guarana(swiat, { pozycja.x + 1,pozycja.y }), { pozycja.x + 1,pozycja.y });
		}
	}
	else if (kierunek == prawo) {
		if (pozycja.y + 1 < swiat->PobierzY()) {
			if (swiat->pole[pozycja.x][pozycja.y + 1]->znak() == PUSTKA) swiat->Dodaj(new Guarana(swiat, { pozycja.x,pozycja.y + 1 }), { pozycja.x ,pozycja.y + 1 });
		}
	}
	else if (kierunek == lewo) {
		if (pozycja.y - 1 > -1) {
			if (swiat->pole[pozycja.x][pozycja.y - 1]->znak() == PUSTKA) swiat->Dodaj(new Guarana(swiat, { pozycja.x,pozycja.y - 1 }), { pozycja.x,pozycja.y - 1 });
		}
	}
}