#include "stdafx.h"
#include "Swiat.h"
#include "Definicje.h"

//pozycja organizmu
int main()
{
	SpecjalnaUmiejetnosc a;
	a.t = false; a.wykonanie = 0;
	srand(time(NULL));
	int Cooldown = 0;
	int x, y;
		cout << "Damian Marek 171952" << endl;
		cout << "Podaj wielkosc swiata NxM" << endl;
		cin >> x >> y;
	Swiat s1(x,y);
	s1.Dodaj(new Czlowiek(&s1, { 1,1 }), { 1,1 });
	s1.Dodaj(new Barszcz_Sosnowskiego(&s1, { 1,0}), { 1,0 });
	s1.Dodaj(new Zolw(&s1, { 6,4 }), { 6,4 });
	s1.Dodaj(new Lis(&s1, { 5,4 }), { 5,4 });
	s1.Dodaj(new Antylopa(&s1, { 9,9 }), { 9,9 });
	s1.Dodaj(new Guarana(&s1, { 10,5 }), { 10,5 });
	s1.Dodaj(new Mlecz(&s1, { 3,2 }), { 3,2 });
	s1.Dodaj(new Wilk(&s1, { 1,9 }), { 1,9 });
	s1.Dodaj(new Owca (&s1, { 5,7 }), { 5,7 });
	s1.Dodaj(new Owca(&s1, { 3,7 }), { 3,7 });
	s1.Dodaj(new Owca(&s1, { 3,8 }), { 3,8 });
	s1.Dodaj(new Owca(&s1, { 4,7 }), { 4,7 });
	s1.Dodaj(new Trawa (&s1, { 4,3 }), { 4,3 });
	s1.Dodaj(new Wilcze_Jagody(&s1, { 2,7 }), { 2,7 });
	s1.rysujSwiat();
	int zmienna = 1;
	do {
		if (Cooldown == 0) {
			switch (_getch())
			{
			//x-zakończ progeam
			case 'x': zmienna = 0; break;
			//s=umiejetnosc specjalna
			case 's': cout << "Aktywowano umiejetnosc specjalna czlowieka!"; a.t = true; a.wykonanie = 5; Cooldown = 10; break;
			case 'z': s1.Zapisz(a.t,a.wykonanie,Cooldown); break;
			case 'w': { s1.NowySwiat(&a.t, &a.wykonanie, &Cooldown);  } break;
			case 72: s1.wykonajTure(gora, a); break;//gora
			case 80: s1.wykonajTure(dol, a); break;//dol
			case 77: s1.wykonajTure(prawo, a); break;//prawo
			case 75: s1.wykonajTure(lewo, a); break;//lewo
			}
		}
		else {//specjalna umiejętność na cooldownie lub w trackcie użycia
			switch (_getch())
			{
				//x-zakończ progeam
			case 'x': zmienna = 0; break;
				//s=umiejetnosc specjalna
			case 's': cout << "Umiejetnosc specjalna na cooldownie!" << endl; break;
			case 'z': s1.Zapisz(a.t, a.wykonanie, Cooldown); break;
			case 'w': { s1.NowySwiat(&a.t, &a.wykonanie, &Cooldown);  } break;
			case 72: s1.wykonajTure(gora, a);  //gora
				if (a.wykonanie > 0) {
					a.wykonanie--;
				}
				Cooldown--;
				break;
			case 80: s1.wykonajTure(dol, a);//dol
				if (a.wykonanie > 0) {
					a.wykonanie--;
				}
				Cooldown--;
				break;
			case 77: s1.wykonajTure(prawo, a);//prawo
				if (a.wykonanie > 0) {
					a.wykonanie--;
				}
				Cooldown--;
				break;
			case 75: s1.wykonajTure(lewo, a); //lewo
				if (a.wykonanie > 0) {
					a.wykonanie--;
				}
				Cooldown--;
				break;
			}
			if (a.wykonanie == 0) {
				a.t = false;
			}
		}
	} while (zmienna != 0);
	
	system("pause");
    return 0;
}

