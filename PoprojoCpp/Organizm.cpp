#include "stdafx.h"
#include "Swiat.h"


void Organizm::ruch(KIERUNEK kieruenk,Organizm *org) {

}


Organizm* Organizm::urodziny(POZYCJA p) {
	return nullptr;
}

const void Organizm::wypisz() {
	cout << "Organizm" << endl;
}
void Organizm::akcjaCzlowiek(Organizm *org, KIERUNEK k, SpecjalnaUmiejetnosc s) {}

const POZYCJA Organizm::PobierzPozycje() {
	return pozycja;
}
const int Organizm::PobierzWiek() {
	return wiek;
}
const int Organizm::PobierzInicjatywe() {
	return inicjatywa;
}
const int Organizm::PobierzSile() {
	return sila;
}
Organizm::~Organizm() {
	
}

