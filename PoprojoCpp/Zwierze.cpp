#include "stdafx.h"
#include "Definicje.h"
#include "Swiat.h"

Zwierze::Zwierze() {

}

void Zwierze::NowyKierunek(int &zmienna, KIERUNEK *kierunek) {
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

Organizm* Zwierze::nastepny(const KIERUNEK kierunek, const int dystans) {
	if (kierunek == gora) {
		if (pozycja.x - dystans > -1) return swiat->pole[pozycja.x - dystans][pozycja.y];
		else return NULL;
	}
	if (kierunek == dol) {
		if (pozycja.x + dystans < swiat->PobierzX()) return swiat->pole[pozycja.x + dystans][pozycja.y];
		else return NULL;
	}
	if (kierunek == prawo) {
		if (pozycja.y + dystans < swiat->PobierzY()) return swiat->pole[pozycja.x][pozycja.y+dystans];
		else return NULL;
	}
	if (kierunek == lewo) {
		if (pozycja.y - dystans > -1) return swiat->pole[pozycja.x][pozycja.y - dystans];
		else return NULL;
	}
}
//Ruch-pierwszy if sprawdza czy pole w danym kierunku jest puste, drugi czy zwierze jest takie same ¿eby siê rozmno¹y³y, trzerci if wywo³uje kolizje w danym kierunku z innymi organizmami
void Zwierze::ruch(KIERUNEK kierunek,int dystans) {
	if (kierunek == gora) {
		if (pozycja.x -1 > -1) {
			//wejscie na puste pole
			if (swiat->pole[pozycja.x - 1][pozycja.y]->znak() == PUSTKA) {
				swiat->pole[pozycja.x - 1][pozycja.y] = swiat->pole[pozycja.x][pozycja.y];
				swiat->pole[pozycja.x][pozycja.y] = new PustePole;
				pozycja.x--;
			}
			//wejscie na organizm tego samego gatunku-rozmna¿anie
			else if (swiat->pole[pozycja.x - 1][pozycja.y]->znak() == swiat->pole[pozycja.x][pozycja.y]->znak()) {
				if (pozycja.x - 2 > -1) {
					if (swiat->pole[pozycja.x - 2][pozycja.y]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x - 2, pozycja.y };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.x +1 < swiat->PobierzX()) {
					if (swiat->pole[pozycja.x + 1][pozycja.y]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x + 1,pozycja.y };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.y + 1 < swiat->PobierzY()) {
					if (swiat->pole[pozycja.x][pozycja.y + 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x,pozycja.y + 1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.y -1 > -1) {
					if (swiat->pole[pozycja.x][pozycja.y - 1]->znak() == PUSTKA) {
						POZYCJA p = {  pozycja.x ,pozycja.y - 1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.y + 1 < swiat->PobierzY()) {
					if (swiat->pole[pozycja.x - 1][pozycja.y + 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x - 1,pozycja.y+1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.y - 1 > -1) {
					if (swiat->pole[pozycja.x - 1][pozycja.y - 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x -1,pozycja.y-1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
			}
			//kolizja z innym organizmem
			else {
				swiat->pole[pozycja.x - 1][pozycja.y]->kolizja(swiat->pole[pozycja.x - 1][pozycja.y], swiat->pole[pozycja.x][pozycja.y],kierunek);
			}
		}
	}
	else if (kierunek == dol) {
		if (pozycja.x + dystans < swiat->PobierzX()) {
			if (swiat->pole[pozycja.x + 1][pozycja.y]->znak() == PUSTKA) {
				swiat->pole[pozycja.x + 1][pozycja.y] = swiat->pole[pozycja.x][pozycja.y];
				swiat->pole[pozycja.x][pozycja.y] = new PustePole;
				pozycja.x++;
			}
			else if (swiat->pole[pozycja.x + 1][pozycja.y]->znak() == swiat->pole[pozycja.x][pozycja.y]->znak()) {
				if (pozycja.x + 2 < swiat->PobierzX() ) {
					if (swiat->pole[pozycja.x + 2][pozycja.y]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x + 1,pozycja.y };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.x - 1 <-1) {
					if (swiat->pole[pozycja.x - 1][pozycja.y]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x - 1,pozycja.y };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.y + 1 <swiat->PobierzY()) {
					if (swiat->pole[pozycja.x][pozycja.y + 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x,pozycja.y+1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.y - 1 > -1) {
					if (swiat->pole[pozycja.x][pozycja.y - 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x ,pozycja.y-1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.y + 1 < swiat->PobierzY()) {
					if (swiat->pole[pozycja.x + 1][pozycja.y + 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x + 1,pozycja.y+1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.y - 1 > -1) {
					if (swiat->pole[pozycja.x + 1][pozycja.y - 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x + 1,pozycja.y-1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
			}
			else {
				swiat->pole[pozycja.x + 1][pozycja.y]->kolizja(swiat->pole[pozycja.x + 1][pozycja.y], swiat->pole[pozycja.x][pozycja.y],kierunek);
			}
		}
	}
	else if (kierunek == prawo) {
		if (pozycja.y + dystans < swiat->PobierzY()) {
			if (swiat->pole[pozycja.x][pozycja.y+1]->znak() == PUSTKA) {
				swiat->pole[pozycja.x][pozycja.y+1] = swiat->pole[pozycja.x][pozycja.y];
				swiat->pole[pozycja.x][pozycja.y] = new PustePole;
				pozycja.y++;
			}
			else if (swiat->pole[pozycja.x][pozycja.y+1]->znak() == swiat->pole[pozycja.x][pozycja.y]->znak()) {
				if (pozycja.y + 2 < swiat->PobierzY()) {
					if (swiat->pole[pozycja.x][pozycja.y+2]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x ,pozycja.y +2};
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.x + 1 < swiat->PobierzX()) {
					if (swiat->pole[pozycja.x + 1][pozycja.y]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x + 1,pozycja.y };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.y - 1 >-1) {
					if (swiat->pole[pozycja.x][pozycja.y - 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x,pozycja.y-1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.x +1<swiat->PobierzX() ) {
					if (swiat->pole[pozycja.x + 1][pozycja.y + 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x + 1,pozycja.y+1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.x -1 >-1) {
					if (swiat->pole[pozycja.x - 1][pozycja.y + 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x -1,pozycja.y +1};
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.x- 1 > -1) {
					if (swiat->pole[pozycja.x - 1][pozycja.y]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x - 1,pozycja.y };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
			}
			else {
				swiat->pole[pozycja.x][pozycja.y+1]->kolizja(swiat->pole[pozycja.x][pozycja.y+1], swiat->pole[pozycja.x][pozycja.y],kierunek);
			}
		}
	}
	else if (kierunek == lewo) {
		if (pozycja.y - dystans > -1) {
			if (swiat->pole[pozycja.x][pozycja.y - 1]->znak() == PUSTKA) {
				swiat->pole[pozycja.x][pozycja.y - 1] = swiat->pole[pozycja.x][pozycja.y];
				swiat->pole[pozycja.x][pozycja.y] = new PustePole;
				pozycja.y--;
			}
			else if (swiat->pole[pozycja.x][pozycja.y-1]->znak() == swiat->pole[pozycja.x][pozycja.y]->znak()) {
				if (pozycja.y - 2 >-1) {
					if (swiat->pole[pozycja.x][pozycja.y - 2]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x ,pozycja.y-2 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.x + 1 < swiat->PobierzX()) {
					if (swiat->pole[pozycja.x + 1][pozycja.y]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x + 1,pozycja.y };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.y +1<swiat->PobierzY()) {
					if (swiat->pole[pozycja.x][pozycja.y + 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x ,pozycja.y+1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}

				else if (pozycja.x + 1<swiat->PobierzX()) {
					if (swiat->pole[pozycja.x + 1][pozycja.y + 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x + 1,pozycja.y+1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
				else if (pozycja.x - 1 >-1) {
					if (swiat->pole[pozycja.x - 1][pozycja.y - 1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x - 1,pozycja.y-1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}

				else if (pozycja.x + 1 <swiat->PobierzX()) {
					if (swiat->pole[pozycja.x + 1][pozycja.y-1]->znak() == PUSTKA) {
						POZYCJA p = { pozycja.x + 1,pozycja.y-1 };
						swiat->Dodaj(swiat->pole[pozycja.x][pozycja.y]->urodziny(p), p);
					}
				}
			}
			else {
				swiat->pole[pozycja.x][pozycja.y-1]->kolizja(swiat->pole[pozycja.x][pozycja.y-1], swiat->pole[pozycja.x][pozycja.y],kierunek);
			}
		}
	}
}

Zwierze::Zwierze(Swiat *swiat, const POZYCJA pozycja) {
	this->swiat = swiat;
	this->pozycja = pozycja;
}

void Zwierze::rysowanie() {

}

void Zwierze::akcja(Organizm *org) {
	KIERUNEK k;
	int szansa = (rand() % 4) + 1;
	NowyKierunek(szansa, &k);
	ruch(k,1);
}

Organizm* Zwierze::urodziny( POZYCJA p) {
	return nullptr;
}
void Zwierze::kolizja(Organizm *napotkany,Organizm *org,KIERUNEK kierunek) {	
		
}
void Zwierze::akcjaCzlowiek(Organizm *org, KIERUNEK k, SpecjalnaUmiejetnosc s){}
Zwierze::~Zwierze(){}
