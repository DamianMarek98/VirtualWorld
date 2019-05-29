#pragma once
#include "Definicje.h"
class Swiat
{
	int tura = 0;
	friend class Organizm;
	int x, y; //wielkoœæ planszy(x wysokoœæ, y szerokoœæ)
	list<Organizm*> lista;
	list<Organizm*> usun;
public:
	Organizm ***pole;
	Swiat(int,int);
	void NowySwiat(bool *,int *,int *);
	void Dodaj(Organizm *org, POZYCJA p);
	void Usun(Organizm *org);
	void rysujSwiat();
	void Zapisz(bool,int,int);
	int PobierzX();
	int PobierzY();
	void wykonajTure(KIERUNEK k,SpecjalnaUmiejetnosc s);
	~Swiat();
};


class Organizm
{
	friend Swiat;
	int wiek = 0;
public:
	POZYCJA pozycja;
	Swiat *swiat;
	char nazwa;
	int inicjatywa, sila;
	virtual void akcja(Organizm *org)=0;
	virtual void kolizja(Organizm *nastepny,Organizm *org,KIERUNEK kierunek)=0;
	virtual void rysowanie()=0;
	virtual void ruch(KIERUNEK kierunek, Organizm *org);
	virtual Organizm* urodziny(POZYCJA p);
	virtual char znak()=0;
	virtual const void wypisz();
	virtual void akcjaCzlowiek(Organizm *org, KIERUNEK k, SpecjalnaUmiejetnosc s);
	//gettery
	virtual const POZYCJA PobierzPozycje();
	const int PobierzWiek();
	const int PobierzInicjatywe();
	const int PobierzSile();
	~Organizm();
};
//zwierzêta
class PustePole : public Organizm
{
public:
	PustePole();
	void akcja(Organizm *org);
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK kierunek);
	void rysowanie();
	void ruch(KIERUNEK kierunek, Organizm *org);
	Organizm* urodziny(POZYCJA p);
	char znak();
	const void wypisz();
	void akcjaCzlowiek(Organizm *org, KIERUNEK k, SpecjalnaUmiejetnosc s);
	//gettery
	const POZYCJA PobierzPozycje();

private:
};
class Zwierze : public Organizm
{
protected:
	void NowyKierunek(int &zmienna, KIERUNEK *kierunek);
	Organizm* nastepny(const KIERUNEK kierunek,const int dystans);
	void ruch(KIERUNEK kierunek, int dystans) ;
public:
	void akcjaCzlowiek(Organizm *org, KIERUNEK k, SpecjalnaUmiejetnosc s) override;
	Zwierze();
	Zwierze(Swiat *swiat, const POZYCJA pozycja);
	virtual Organizm* urodziny(POZYCJA pozycja);
	void rysowanie() override;
	//const void wypisz() override;
	void akcja(Organizm *org) override;
	void kolizja(Organizm *nastepny,Organizm *org,KIERUNEK kierunek);
	~Zwierze();
};
class Czlowiek : public Zwierze
{
public:
	Czlowiek();
	Czlowiek(Swiat *swiat, const POZYCJA pozycja);
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	char znak() override;
	void rysowanie() override;
	void akcjaCzlowiek(Organizm *org,KIERUNEK k, SpecjalnaUmiejetnosc s) ;
};
class Wilk : public Zwierze
{
public:
	Wilk();
	Wilk(Swiat *swiat, const POZYCJA pozycja);
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	char znak() override;
	Organizm* urodziny(POZYCJA pozycja) override;
	void rysowanie() override;
};
class Owca : public Zwierze
{
public:
	Owca();
	Owca(Swiat *swiat, const POZYCJA pozycja);
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK kierunek);
	Organizm* urodziny(POZYCJA pozycja) override;
	void rysowanie() override;
	char znak() override;
};
class Lis : public Zwierze
{
public:
	Lis();
	Lis(Swiat *swiat, const POZYCJA pozycja);
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	Organizm* urodziny(POZYCJA pozycja) override;
	void akcja(Organizm *org) override;
	char znak() override;
	void rysowanie() override;
};
class Zolw : public Zwierze
{
public:
	Zolw();
	Zolw(Swiat *swiat, const POZYCJA pozycja);
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	Organizm* urodziny(POZYCJA pozycja) override;
	void akcja(Organizm *org) override;
	char znak() override;
	void rysowanie() override;
};
class Antylopa : public Zwierze
{
public:
	Antylopa();
	Antylopa(Swiat *swiat, const POZYCJA pozycja);
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	Organizm* urodziny(POZYCJA pozycja) override;
	void akcja(Organizm *org) override;
	char znak() override;
	void rysowanie() override;
};
//roœliny
class Roslina : public Organizm 
{
protected:
	void NowyKierunek(int &zmienna, KIERUNEK *kierunek);
	Organizm* nastepny(const KIERUNEK kierunek, const int dystans);
public:
	Roslina();
	char znak() override;
	Roslina(Swiat *swiat, const POZYCJA pozycja);
	void nowa(Organizm *org,int x,int y);
	void rysowanie() override;
	//const void wypisz() override;
	void akcja(Organizm *org) override;
	void ruch(KIERUNEK kierunek, Organizm *org);
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	~Roslina();
};
class Trawa : public Roslina
{
public:
	Trawa();
	void ruch(KIERUNEK kierunek, Organizm *org) override;
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	Trawa(Swiat *swiat, const POZYCJA pozycja);
	char znak() override;
	void rysowanie() override;
};
class Mlecz : public Roslina
{
public:
	Mlecz();
	void akcja(Organizm *org) override;
	void ruch(KIERUNEK kierunek, Organizm *org) override;
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	Mlecz(Swiat *swiat, const POZYCJA pozycja);
	char znak() override;
	void rysowanie() override;
};
class Guarana : public Roslina
{
public:
	char znak() override;
	Guarana();
	void ruch(KIERUNEK kierunek, Organizm *org) override;
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	Guarana(Swiat *swiat, const POZYCJA pozycja);
	void rysowanie() override;
};
class Wilcze_Jagody : public Roslina
{
public:
	Wilcze_Jagody();
	void ruch(KIERUNEK kierunek, Organizm *org) override;
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	Wilcze_Jagody(Swiat *swiat, const POZYCJA pozycja);
	char znak() override;
	void rysowanie() override;
}; 
class Barszcz_Sosnowskiego : public Roslina
{
public:
	Barszcz_Sosnowskiego();
	void ruch(KIERUNEK kierunek, Organizm *org) override;
	void kolizja(Organizm *nastepny, Organizm *org, KIERUNEK k) override;
	void akcja(Organizm *org) override;
	char znak() override;
	Barszcz_Sosnowskiego(Swiat *swiat, const POZYCJA pozycja);
	void rysowanie() override;
};