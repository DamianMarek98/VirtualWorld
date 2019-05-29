#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Antylopa::Antylopa() {

}

Antylopa::Antylopa(Swiat *swiat, const POZYCJA pozycja) {
	this->inicjatywa = 4;
	this->sila = 4;
	this->swiat = swiat;
	this->pozycja = pozycja;
}
void Antylopa::rysowanie() {
	cout << ANTYLOPA;
}
void Antylopa::kolizja(Organizm *nastepny, Organizm *org, KIERUNEK kierunek) {
	int ucieczka = (rand() % 2) + 1;
	if (ucieczka == 1) {
		if (pozycja.x - 1 > -1) {
			if (swiat->pole[nastepny->pozycja.x - 1][nastepny->pozycja.y]->znak() == PUSTKA) {
				swiat->pole[nastepny->pozycja.x - 1][nastepny->pozycja.y] = nastepny;
				swiat->pole[nastepny->pozycja.x][nastepny->pozycja.y] = org;
			}
		}
		if (pozycja.x + 1 < swiat->PobierzX()) {
			if (swiat->pole[nastepny->pozycja.x + 1][nastepny->pozycja.y]->znak() == PUSTKA) {
				swiat->pole[nastepny->pozycja.x + 1][nastepny->pozycja.y] = nastepny;
				swiat->pole[nastepny->pozycja.x][nastepny->pozycja.y] = org;
			}
		}
		if (pozycja.y + 1 < swiat->PobierzY()) {
			if (swiat->pole[nastepny->pozycja.x][nastepny->pozycja.y + 1]->znak() == PUSTKA) {
				swiat->pole[nastepny->pozycja.x][nastepny->pozycja.y + 1] = nastepny;
				swiat->pole[nastepny->pozycja.x][nastepny->pozycja.y] = org;
			}
		}
		if (pozycja.y - 1 > -1) {
			if (swiat->pole[nastepny->pozycja.x][nastepny->pozycja.y - 1]->znak() == PUSTKA) {
				swiat->pole[nastepny->pozycja.x][nastepny->pozycja.y - 1] = nastepny;
				swiat->pole[nastepny->pozycja.x][nastepny->pozycja.y] = org;
			}
		}

		//brak miejsca do ucieczki, podjêcie walki
		else {
			if (nastepny->PobierzSile() > org->PobierzSile()) {
				swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
				swiat->Usun(org);
				cout << "Nieudany atak na antylope: "; org->rysowanie(); cout << endl;
				system("puse");
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
				cout << "antylopa zostala pokonany przez: "; org->rysowanie(); cout << endl;
				system("puse");
			}
		}
	}
	else {
		if (nastepny->PobierzSile() > org->PobierzSile()) {
			swiat->pole[org->pozycja.x][org->pozycja.y] = new PustePole;
			swiat->Usun(org);
			cout << "Nieudany atak na antylope: " << org->znak() << endl;
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
			cout << "Antylopa zostala pokonany przez: " << org->znak() << endl;
		}
	}
}
void Antylopa::akcja(Organizm *org) {
	KIERUNEK k;
	int szansa = (rand() % 4) + 1;
	NowyKierunek(szansa, &k);
	//mo¿liwy ruch o dwa pola
	ruch(k, 1);
	ruch(k, 1);
}
Organizm* Antylopa::urodziny(POZYCJA p) {
	return new Antylopa(swiat, p);
}