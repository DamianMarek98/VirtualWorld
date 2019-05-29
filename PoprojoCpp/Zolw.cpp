#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Zolw::Zolw() {

}

Zolw::Zolw(Swiat *swiat, const POZYCJA pozycja) {
	this->inicjatywa = 1;
	this->sila = 2;
	this->swiat = swiat;
	this->pozycja = pozycja;
}
void Zolw::rysowanie() {
	cout << ZOLW;
}
char Zolw::znak() {
	return ZOLW;
}
void Zolw::akcja(Organizm *org) {
	KIERUNEK k;
	int prawodpodobienstwo= (rand() % 4) + 1;
	if (prawodpodobienstwo == 1) {
		int szansa = (rand() % 4) + 1;
		NowyKierunek(szansa, &k);
		ruch(k, 1);
	}
}
void Zolw::kolizja(Organizm *nastepny, Organizm *org,KIERUNEK kierunek) {
	if (org->sila >= 5) {
		if (nastepny->PobierzSile() > org->PobierzSile()) {
			swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
			swiat->Usun(org);
			cout << "Nieudany atak na Zolwia: "<<org->znak() << endl;
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
			cout << "Zolw zostal pokonany przez: "<<org->znak() << endl;
		}
	}
	else {
		cout << "Zolw odepchnal przeciwnika: " << org->znak() << endl;
	}
}
Organizm* Zolw::urodziny(POZYCJA p) {
	return new Zolw(swiat, p);
}