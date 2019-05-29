#include "stdafx.h"
#include "Swiat.h"
void printToCoordinates(int x, int y, const std::string& text)
{
	printf("\033[%d;%dH%s\n", x, y, text.c_str());
}


//konstruktor œwiata
void Swiat::NowySwiat(bool *t,int *wykonanie, int *cooldown) {
	bool l; int wyk, cd;
	lista.clear();
	for (int i = 0; i<PobierzX(); i++)
		delete pole[i];
	delete[] pole;
	fstream plik("Zapis.txt", std::ios::in);
	if (plik.good()) {
		plik >> l;
		*t = l;
		plik >> wyk;
		*wykonanie = wyk;
		plik >> cd;
		*cooldown = cd;
		int tur;
		plik >> tur;
		tura = tur;
		char k;
		int b, c, d, i, s;
		plik >> c;
		plik >> d;
		this->x = c;
		this->y = d;
		pole = new Organizm **[x];
		for (int i = 0; i < x; i++) {
			pole[i] = new Organizm*[y];
		}
		for (int i = 0; i < x; i++) {
			for (int j = 0; j < y; j++) {
				pole[i][j] = new PustePole();
			}
		}
		system("cls");
		while (true)
		{
			plik >> k;
			if (plik.good()) {
				if (k == 'C') {
					plik >> c >> d >> i >> s;
					Czlowiek *q = new Czlowiek(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
				else if (k == 'W') {
					plik >> c >> d >> i >> s;
					Wilk *q = new Wilk(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
				else if (k == 'O') {
					plik >> c >> d >> i >> s;
					Owca *q = new Owca(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
				else if (k == 'L') {
					plik >> c >> d >> i >> s;
					Lis *q = new Lis(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
				else if (k == 'Z') {
					plik >> c >> d >> i >> s;
					Zolw *q = new Zolw(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
				else if (k == 'A') {
					plik >> c >> d >> i >> s;
					Antylopa *q = new Antylopa(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
				else if (k == '.') {
					plik >> c >> d >> i >> s;
					Trawa *q = new Trawa(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
				else if (k == '|') {
					plik >> c >> d >> i >> s;
					Mlecz *q = new Mlecz(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
				else if (k == '"') {
					plik >> c >> d >> i >> s;
					Guarana *q = new Guarana(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
				else if (k == ',') {
					plik >> c >> d >> i >> s;
					Wilcze_Jagody *q = new Wilcze_Jagody(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
				else if (k == 'x') {
					plik >> c >> d >> i >> s;
					Barszcz_Sosnowskiego *q = new Barszcz_Sosnowskiego(this, { c,d });
					q->inicjatywa = i;
					q->sila = s;
					Dodaj(q, { c,d });
				}
			}

			else
				break;

		} //while
		cout << "Wczytana plansza: " << endl;
		rysujSwiat();
	}
	else {
		system("cls");
		cout << "Niepoprawny plik!" << endl;
	}
}
Swiat::Swiat(int wys,int szer)
{
	x = wys;
	y = szer;
	//alokacja pamiêci dla pola gry

	pole = new Organizm **[x];
	for (int i = 0; i < x; i++) {
		pole[i] = new Organizm*[y];
	}
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			pole[i][j] = new PustePole();
		}
	}
}
//roswoanie pola
void Swiat::rysujSwiat() {
	//testowy wypis pola
	for (int i = 0; i < x; i++) {
		for (int j = 0; j < y; j++) {
			pole[i][j]->rysowanie();
		}
		cout << endl;
	}
}
void Swiat::Dodaj(Organizm *org, POZYCJA p) {
	this->pole[p.x][p.y] = org;
	//cout << "Dodaje nowy obiekt: " << org->znak() << " na pozycji: " << org->pozycja.x << "," << org->pozycja.y << endl;
	for (auto temp : lista) {
		if (org->PobierzInicjatywe() > temp->PobierzInicjatywe()) {
			auto it = find(lista.begin(), lista.end(), temp);
			lista.insert(it, org);
			return;
		}
		else continue;
	}
	lista.push_back(org);
	//lista.push_front(org);
	//sortowanie oragnizmów po dodaniu do lity (po inicjatywie)
	//lista.sort([](const Organizm* a, const Organizm* b) { return a->inicjatywa > b->inicjatywa ; });
}
void Swiat::Usun(Organizm *org) {
	usun.push_back(org);
}
void Swiat::wykonajTure(KIERUNEK k, SpecjalnaUmiejetnosc s) {
	int i = 3;
	system("cls");
	usun.clear();
	auto iter = lista.begin();
	cout << "Najwa¿niejsze wydarzenia:" << endl;
	//kolejkowanie obiektów
	while (iter != lista.end()) {
		if (pole[iter._Ptr->_Myval->pozycja.x][iter._Ptr->_Myval->pozycja.y]->znak() == iter._Ptr->_Myval->znak()) {
			if (pole[iter._Ptr->_Myval->pozycja.x][iter._Ptr->_Myval->pozycja.y]->znak() == CZLOWIEK)
			{
				iter._Ptr->_Myval->akcjaCzlowiek(iter._Ptr->_Myval,k,s);
			}
			else
			{
				iter._Ptr->_Myval->akcja(iter._Ptr->_Myval);
			}
		}
			iter++;
	}
	//usuwnaie obiektów
	for (auto u : usun) {
		cout << "Zginol organizm: " << u->znak() << endl;
		delete u;
		lista.remove(u);
	}
	cout << "Nacisnij dowolny przycisk aby wyswietlic plansze!" << endl;
	_getch();
	system("cls");
	tura++;
	cout << "Tura: " << tura << endl;
	rysujSwiat();
	cout << "Strzalki pozwalaja kierowac czlowiekiem oraz wywolywac nowa ture, x-zakoncz gre, s-umiejetnosc specjalna czlowieka!" << endl;
	printToCoordinates(i, 35, "_-Puste pole;"); i++;
	printToCoordinates(i, 35, "C-Czlowiek;"); i++;
	printToCoordinates(i, 35, "W-Wilk"); i++;
	printToCoordinates(i, 35, "O-Owca;"); i++;
	printToCoordinates(i, 35, "L-Lis;"); i++;
	printToCoordinates(i, 35, "Z-Zolw"); i++;
	printToCoordinates(i, 35, "A-Antylopa;"); i++;
	printToCoordinates(i, 35, ".-Trawa;"); i++;
	printToCoordinates(i, 35, "|-Mlecz;"); i++;
	printToCoordinates(i, 35, "G-Guarana;"); i++;
	printToCoordinates(i, 35, ",-Wilcze jagody;"); i++;
	printToCoordinates(i, 35, "x-Barszcz sosnowskiego"); i++;
}
int Swiat::PobierzX() {
	return x;
}
int Swiat::PobierzY() {
	return y;
}
void Swiat::Zapisz(bool t,int wykonanie, int cooldown) {
	//zapis gry do pliku
	fstream plik("Zapis.txt", std::ios::out); //zak³adamy, ¿e nie wyst¹pi³ b³¹d (plik otwarto/utworzono)
	string napis;
	//sytuacja cz³owieka
	plik << t << endl;//zapis stanu umiejêtnoœci specjalnej
	plik << wykonanie << endl;//zapis ile tur umiejêtnoœci mia³o miejsce
	plik << cooldown << endl;//d³ugosc przerwy przed mo¿liwoœci¹ aktywowana umiejêtnoœci specjalnej
	plik << tura << endl;
	plik << PobierzX() <<endl<< PobierzY() << endl;//rozmiary planszy
	auto iter = lista.begin();
	//kolejkowanie obiektów
	//kolejno zapisujê: pozycjax,pozycjay,sila,inicjatywa
	while (iter != lista.end()) {
		plik << iter._Ptr->_Myval->znak() << endl << iter._Ptr->_Myval->pozycja.x << endl << iter._Ptr->_Myval->pozycja.y << endl << iter._Ptr->_Myval->inicjatywa << endl<< iter._Ptr->_Myval->sila << endl;
		iter++;
	}
}

Swiat::~Swiat()
{
	lista.clear();
	usun.clear();
	for (int i = 0; i<x; i++)
		delete pole[i];

	delete[] pole;
}
char Antylopa::znak() {
	return ANTYLOPA;
}

