#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Lis::Lis() {

}

Lis::Lis(Swiat *swiat, const POZYCJA pozycja) {
	this->inicjatywa = 7;
	this->sila = 3;
	this->swiat = swiat;
	this->pozycja = pozycja;
}
void Lis::rysowanie() {
	cout << LIS;
}
char Lis::znak() {
	return LIS;
}
void Lis::kolizja(Organizm *nastepny, Organizm *org,KIERUNEK kierunek) {
	if (nastepny->PobierzSile() > org->PobierzSile()) {
		swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
		swiat->Usun(org);
		cout << "Nieudany atak na lisa: " << org->znak() << endl;
	}
	else
	{
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
		cout << "lis zostal pokonany przez: " << org->znak() << endl;
	}
}
void Lis::akcja(Organizm *org) {
	KIERUNEK k;
	int szansa = (rand() % 4) + 1;
	NowyKierunek(szansa, &k);
	if (k == gora) {
		if (pozycja.x - 1 > -1) {
			if (swiat->pole[org->pozycja.x - 1][org->pozycja.y]->sila > org->sila) {}
			else ruch(k, 1);
		}
	}
	else if (pozycja.x + 1 < swiat->PobierzX()) {
		if (pozycja.x + 1 < swiat->PobierzX()) {
			if (swiat->pole[org->pozycja.x + 1][org->pozycja.y]->sila > org->sila) {}
			else ruch(k, 1);
		}
	}
	else if (k==prawo) {
		if (pozycja.y + 1 < swiat->PobierzY()) {
			if (swiat->pole[org->pozycja.x][org->pozycja.y + 1]->sila > org->sila) {}
			else ruch(k, 1);
		}
	}
	else if (k==lewo) {
		if (pozycja.y - 1 > -1) {
			if (swiat->pole[org->pozycja.x][org->pozycja.y - 1]->sila > org->sila) {}
			else ruch(k, 1);
		}
	}
}
Organizm* Lis::urodziny(POZYCJA p) {
	return new Lis(swiat, p);
}