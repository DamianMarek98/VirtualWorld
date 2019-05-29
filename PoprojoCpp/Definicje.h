#pragma once
#include <cstdlib>
#include "stdafx.h"
#include <iostream>
#include <ctime>
#include <list>
#include <fstream> 
#include <stdio.h> 
#include <conio.h>
#include <string>
using namespace std;

struct SpecjalnaUmiejetnosc {
	bool t;
	int wykonanie;
};
struct POZYCJA {
	int x;//wysokoœæ
	int y;//szerokoœæ
};
//kierunki
enum KIERUNEK
{
	gora = 1,
	dol = 2,
	prawo = 3,
	lewo = 4
};

#define CZLOWIEK 'C'
#define PUSTKA '_'
#define WILK 'W'
#define OWCA 'O'
#define LIS 'L'
#define ZOLW 'Z'
#define ANTYLOPA 'A'
#define TRAWA '.'
#define MLECZ '|'
#define GUARANA 'G'
#define WILCZE_JAGODY ','
#define BARSZCZ_SOSNOWSKIEGO 'x'
