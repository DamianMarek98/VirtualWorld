#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Owca::Owca() {

}

Owca::Owca(Swiat *swiat, const POZYCJA pozycja) {
	this->inicjatywa = 4;
	this->sila = 4;
	this->swiat = swiat;
	this->pozycja = pozycja;
}
void Owca::rysowanie() {
	cout << OWCA;
}
char Owca::znak() {
	return OWCA;
}
void Owca::kolizja(Organizm *nastepny, Organizm *org, KIERUNEK kierunek) {
	if (nastepny->PobierzSile() > org->PobierzSile()) {
		swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
		swiat->Usun(org);
		cout << "Nieudany atak na Owce: " << org->znak() << endl;
	}
	else
	{
		swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
		swiat->Usun(nastepny);
		if (kierunek == gora) {
			org->pozycja.x--;
		}
		else if (kierunek== dol) {
			org->pozycja.x++;
		}
		else if (kierunek == prawo) {
			org->pozycja.y++;
		}
		else if (kierunek == lewo) {
			org->pozycja.y--;
		}
		swiat->pole[org->pozycja.x][org->pozycja.y] = org;
		cout << "Owca zostala pokonana przez: " << org->znak() << endl;
	}
}
Organizm* Owca::urodziny(POZYCJA p) {
	return new Owca(swiat, p);
}