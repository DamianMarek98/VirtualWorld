#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

PustePole::PustePole() {
}
void PustePole::akcja(Organizm *org) {}
void PustePole::ruch(KIERUNEK kieruenk, Organizm *org) {

}
void PustePole::kolizja(Organizm *nastepny, Organizm *org, KIERUNEK kierunek) {
}
char PustePole::znak() {
	return PUSTKA;
}
Organizm* PustePole::urodziny(POZYCJA p) {
	return nullptr;
}
void PustePole::rysowanie() {
	cout << PUSTKA;
}
const void PustePole::wypisz() {
	cout << "PustePole" << endl;
}

void PustePole::akcjaCzlowiek(Organizm *org, KIERUNEK k, SpecjalnaUmiejetnosc s) {}
const POZYCJA PustePole::PobierzPozycje() {
	return pozycja;
}


