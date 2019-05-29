#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Czlowiek::Czlowiek() {
}
Czlowiek::Czlowiek(Swiat *swiat, const POZYCJA pozycja) {
	this->inicjatywa = 4;
	this->sila = 5;
	this->swiat = swiat;
	this->pozycja = pozycja;
}

void Czlowiek::kolizja(Organizm *nastepny, Organizm *org, KIERUNEK kierunek) {
	if (nastepny->PobierzSile() > org->PobierzSile()) {
		swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
		swiat->Usun(org);
		cout << "Nieudany atak na Czlowieka przez: " << org->znak() << endl;
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
		cout << "Czlowiek zostal zostal pokonany przez: " << org->znak() << endl;
	}
}
char Czlowiek::znak() {
	return CZLOWIEK;
}
void Czlowiek::rysowanie() {
	cout << CZLOWIEK;
}

void Czlowiek::akcjaCzlowiek(Organizm *org,KIERUNEK k, SpecjalnaUmiejetnosc s) {
	if (s.t) {
		if (s.wykonanie == 1 || s.wykonanie == 2) {
			int szansa = (rand() % 2) + 1;
			if (szansa == 1) {
				ruch(k, 1);
				ruch(k, 1);
			}
			else {
				ruch(k, 1);
			}
		}
		else {
			ruch(k, 1);
			ruch(k, 1);
		}
	}
	else
	{
		ruch(k, 1);
	}
}