#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Barszcz_Sosnowskiego::Barszcz_Sosnowskiego() {

}

Barszcz_Sosnowskiego::Barszcz_Sosnowskiego(Swiat *swiat, const POZYCJA pozycja) {
	this->inicjatywa = 0;
	this->sila = 10;
	this->swiat = swiat;
	this->pozycja = pozycja;
}
void Barszcz_Sosnowskiego::rysowanie() {
	cout << BARSZCZ_SOSNOWSKIEGO;
}
char Barszcz_Sosnowskiego::znak() {
	return BARSZCZ_SOSNOWSKIEGO;
}
void Barszcz_Sosnowskiego::akcja(Organizm *org) {
	//cout << "Barszcz_Sosnowskiego zabija zwierzeta w swoim sasiedztwie!"<<endl;
	if (pozycja.x + 1 < swiat->PobierzX() && dynamic_cast<Zwierze*>(swiat->pole[org->pozycja.x + 1][org->pozycja.y])) {
		swiat->Usun(swiat->pole[org->pozycja.x + 1][org->pozycja.y]);
		swiat->pole[org->pozycja.x + 1][org->pozycja.y] = new PustePole;
		}
	if (pozycja.x - 1 > -1 && dynamic_cast<Zwierze*>(swiat->pole[org->pozycja.x - 1][org->pozycja.y])) {
		swiat->Usun(swiat->pole[org->pozycja.x - 1][org->pozycja.y]);
		swiat->pole[org->pozycja.x - 1][org->pozycja.y] = new PustePole;
	}
	if (pozycja.y + 1 < swiat->PobierzY() && dynamic_cast<Zwierze*>(swiat->pole[org->pozycja.x][org->pozycja.y+1])) {
		swiat->Usun(swiat->pole[org->pozycja.x][org->pozycja.y + 1]);
		swiat->pole[org->pozycja.x ][org->pozycja.y + 1] = new PustePole;
	}
	if (pozycja.y - 1 > -1 && dynamic_cast<Zwierze*>(swiat->pole[org->pozycja.x][org->pozycja.y-1])) {
		swiat->Usun(swiat->pole[org->pozycja.x][org->pozycja.y-1]);
		swiat->pole[org->pozycja.x][org->pozycja.y-1] = new PustePole;
	}
		KIERUNEK k;
		int szansa = (rand() % 20) + 1;
		int kierunek = (rand() % 4) + 1;
		NowyKierunek(kierunek, &k);
		if (szansa == 1) ruch(k, org);
}
void Barszcz_Sosnowskiego::kolizja(Organizm *nastepny, Organizm *org, KIERUNEK kierunek) {
	swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
	swiat->pole[nastepny->pozycja.x][nastepny->pozycja.y] = new PustePole;
	swiat->Usun(nastepny);
	swiat->Usun(org);
	cout << "Barszcz sosnowskiego zostal zjedzony przez " << org->znak() << endl;
}
void Barszcz_Sosnowskiego::ruch(KIERUNEK kierunek, Organizm *org) {
	if (kierunek == gora) {
		if (pozycja.x - 1 > -1) {
			if (swiat->pole[pozycja.x - 1][pozycja.y]->znak() == PUSTKA) swiat->Dodaj(new Barszcz_Sosnowskiego(swiat, { pozycja.x - 1,pozycja.y }), { pozycja.x - 1,pozycja.y });
		}
	}
	else if (kierunek == dol) {
		if (pozycja.x + 1 < swiat->PobierzX()) {
			if (swiat->pole[pozycja.x + 1][pozycja.y]->znak() == PUSTKA) swiat->Dodaj(new Barszcz_Sosnowskiego(swiat, { pozycja.x + 1,pozycja.y }), { pozycja.x + 1,pozycja.y });
		}
	}
	else if (kierunek == prawo) {
		if (pozycja.y + 1 < swiat->PobierzY()) {
			if (swiat->pole[pozycja.x][pozycja.y + 1]->znak() == PUSTKA) swiat->Dodaj(new Barszcz_Sosnowskiego(swiat, { pozycja.x,pozycja.y + 1 }), { pozycja.x ,pozycja.y + 1 });
		}
	}
	else if (kierunek == lewo) {
		if (pozycja.y - 1 > -1) {
			if (swiat->pole[pozycja.x][pozycja.y - 1]->znak() == PUSTKA) swiat->Dodaj(new Barszcz_Sosnowskiego(swiat, { pozycja.x,pozycja.y - 1 }), { pozycja.x,pozycja.y - 1 });
		}
	}
}