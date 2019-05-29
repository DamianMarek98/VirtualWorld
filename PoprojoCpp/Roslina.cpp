#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Roslina::Roslina() {

}

void Roslina::NowyKierunek(int &zmienna, KIERUNEK *kierunek) {
	if (zmienna == 1) {
		*kierunek = gora;
	}
	else if (zmienna == 2) {
		*kierunek = dol;
	}
	else if (zmienna == 3) {
		*kierunek = prawo;
	}
	else if (zmienna == 4) {
		*kierunek = lewo;
	}
}
Organizm* Roslina::nastepny(const KIERUNEK kierunek, const int dystans) {
	if (kierunek == gora) {
		if (pozycja.x - dystans > -1) return swiat->pole[pozycja.x - dystans][pozycja.y];
		else return NULL;
	}
	if (kierunek == dol) {
		if (pozycja.x + dystans < swiat->PobierzX()) return swiat->pole[pozycja.x + dystans][pozycja.y];
		else return NULL;
	}
	if (kierunek == prawo) {
		if (pozycja.y + dystans < swiat->PobierzY()) return swiat->pole[pozycja.x][pozycja.y + dystans];
		else return NULL;
	}
	if (kierunek == lewo) {
		if (pozycja.y - dystans > -1) return swiat->pole[pozycja.x][pozycja.y - dystans];
		else return NULL;
	}
}


void Roslina::ruch(KIERUNEK kierunek, Organizm *org) {
	
}

char Roslina::znak() {
	return 'x';
}

Roslina::Roslina(Swiat *swiat, const POZYCJA pozycja) {
	this->swiat = swiat;
	this->pozycja = pozycja;
}
void Roslina::nowa(Organizm *org,int x,int y) {
	swiat->Dodaj(new Roslina(swiat, { x,y }), { x,y });
}
void Roslina::rysowanie() {

}
void Roslina::akcja(Organizm *org) {
	KIERUNEK k;
	int szansa= (rand() % 20) + 1;
	int kierunek = (rand() % 4) + 1;
	NowyKierunek(kierunek, &k);
	if(szansa==1) ruch(k,org);
}
void Roslina::kolizja(Organizm *nastepny, Organizm *org, KIERUNEK kierunek) {
	
}
Roslina::~Roslina() {}