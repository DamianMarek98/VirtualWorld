#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Wilk::Wilk() {

}

Wilk::Wilk(Swiat *swiat, const POZYCJA pozycja) {
	this->inicjatywa = 5;
	this->sila = 9;
	this->swiat = swiat;
	this->pozycja = pozycja;
}
void Wilk::kolizja(Organizm *nastepny, Organizm *org,KIERUNEK kierunek) {
	if (nastepny->PobierzSile() > org->PobierzSile()) {
		swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
		swiat->Usun(org);
		cout << "Nieudany atak na wilka przez: " << org->znak() << endl;
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
		cout << "Wilk zostal pokonany przez: " << org->znak() << endl;
	}
}
void Wilk::rysowanie() {
	cout << WILK;
}
Organizm* Wilk::urodziny(POZYCJA p) {
	return new Wilk(swiat, p);
}
char Wilk::znak() {
	return WILK;
}