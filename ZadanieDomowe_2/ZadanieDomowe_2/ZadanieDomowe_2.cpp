#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <cmath>

//Michal Mikolajczak.

using namespace std;

void pow();

double cos(double x);

#define PI 3.1416

double sin(double x);
double asin(double x);

double round(double fValue)
{
	fValue *= 100;
	return fValue < 0 ? ceil(fValue - 0.5)
		: floor(fValue + 0.5);
	fValue /= 100;
	return fValue;
}
void dodawanie()
{
	double a, b;
	cin >> a >> b;
	printf("%.2f\n", a + b);
}

void sortowanie_babelkowe(float *tab, int ile)//tablica, ilosc liczb w tablicy
{
	for (int i = 1; i < ile; i++)// Petla zewnetrzna. Pozwala na wykonywanie petli tyle razy ile wynosi zmienna 'ile'
	{
		for (int j = ile - 1; j >= 1; j--)// petla wewnetrzna, pozwala na znalezienie minimum 
		{
			if (tab[j] > tab[j - 1])
			{
				float k;// zmienna potrzebna do zamiany miejsc
				k = tab[j - 1];
				tab[j - 1] = tab[j];//proces zamiany miejsc
				tab[j] = k;
			}
		}
	}
}

int main()
{
	int Nr = 0; // zmienna okreslajaca numer zadania
	/*cout << " -------------------------------" << endl << "|Witam w menu zadania domowego. |" << endl << " -------------------------------" << endl
	<< "Dodawanie dwoch liczb : 1" << endl
	<< "Obliczanie obwodu, pola oraz najwiekszego kata w trojkacie - 2" << endl
	<< "Rownanie kwadratowe - 3" << endl << "Statystyka tablicy - 4" << endl << "Liczby fibonacciego - 5" << endl
	<< "Sortowanie tablicy - 6" << endl << "Zaawansowany kalkulator - 7" << endl;
	cout << "Podaj numer zadania." << endl;*/
	cin >> Nr;
	switch (Nr)
	{
	case 1:
	{
			  dodawanie();
			  break;
	}
	case 2:
	{
			  //trojkat - obwod,pole,kat
			  double obwod, pole, b1, b2, b3, s, R, m, kat, stopnie; //zmienne 
			  /*  cout << ("Wybrales program, obliczanie obwodu, pola oraz najwiekszego kata w trojkacie") << endl;
			  cout << ("Podaj dlugosci bokow trojkata : a, b, c") << endl;*/
			  cin >> b1 >> b2 >> b3;
			  if (b1 + b2 > b3 && b2 + b3 > b1 && b3 + b1 > b2)//warunek, aby trojkat mogl byc skonstruowany 
			  {
				  obwod = b1 + b2 + b3;//obliczam obwod naszego trojkata
				  s = obwod / 2;//s=polowa obwodu trojkata
				  pole = sqrt(s*(s - b1)*(s - b2)*(s - b3));//obliczam pole ze wzoru Herona
				  round(pole); round(obwod);
				  R = (b1*b2*b3) / (4 * pole);//obliczam R potrzebne przy tw. sinusow i cosinusow 
				  m = b1;//obliczam najdluzszy bok
				  if (m < b2) m = b2;
				  if (m < b3) m = b3;
				  kat = m / (2 * R);
				  sin(kat);
				  stopnie = (asin(kat) * 180) / PI;
				  round(stopnie);
				  printf("%.2f %.2f %.2f ", obwod, pole, stopnie);
				  break;
			  }
			  else
			  {
				  printf("%s \n", "blad");
				  break;
			  }
			  break;
	}
	case 3:
	{
			  double Delta, x1, x2, D1;//Rownanie kwadratowe
			  int a, b, c;//parametry funkcji y=ax^2+bx+c
			  cin >> a >> b >> c;
			  D1 = (pow(b, 2)) - (4 * a * c);//wzor na delte
			  if (a <= 0)
			  {
				  printf("%s\n", "brak");
				  break;
			  }
			  if (D1 == 0 || D1 > 0)//aby byly jakies rozwiazania delta musi byc wieksza rowna zero
			  {
				  Delta = sqrt(D1);//delta pod pierwiastkiem
				  if (Delta == 0)
				  {
					  x1 = -b / (2 * a);
					  round(x1);
					  printf("%.2f\n", x1);//gdy delta pod pierwiastkiem =0 mamy jedno rozwiazanie
					  break;
				  }
				  else (Delta > 0);
				  {
					  x1 = (-b - Delta) / (2 * a);//dwa rozwiazania dla delty > od zera
					  x2 = (-b + Delta) / (2 * a);
					  round(x1); round(x2);
					  printf("%.2f %.2f\n", x1, x2);
					  break;
				  }
			  }
			  if (D1 < 0)
			  {
				  printf("%s\n", "brak");
				  break;
			  }
			  break;
	}
	case 4:
	{
			  int ilosc; // statystyka
			  cin >> ilosc;
			  float tablica[15]; float suma = 0, srednia, maks = tablica[0], min = tablica[0];
			  for (int i = 0; i < ilosc; i++)
			  {
				  cin >> tablica[i];
				  suma = suma + tablica[i];
				  sortowanie_babelkowe(tablica, ilosc);
				  /*skorzystalem z sortowania babelkowego.
				  Pierwsza liczba z tablicy jest najwyzsza(maks)
				  a ostatnia liczba z tablic jest najnizsza(minimalna). Zaoszczedzilem linijki i wykorzystalem funkcje.*/
			  }
			  srednia = suma / ilosc;
			  round(tablica[0]); round(tablica[ilosc - 1]); round(srednia);
			  printf("%.2f %.2f %.2f", tablica[0], tablica[ilosc - 1], srednia);
			  break;
	}
	case 5:
	{
			  long double *fi; int a; //Liczby Fibonnaciego
			  cin >> a;
			  fi = new long double[a];
			  fi[0] = 1;
			  fi[1] = 1;//deklaruje pierwsze dwie liczby z ciagu ktore znam
			  for (int i = 2; i <= a; i++)// dlatego tutaj zaznaczam i=2 nie musze wyznaczac dla 0 i 1 bo je znamy.
			  {
				  fi[i] = fi[i - 1] + fi[i - 2];
				  fi[a] = fi[i];
			  }
			  round(fi[a]);
			  printf("%.2f\n", fi[a]);
			  break;
	}
	case 6:
	{
			  int ile;//korzystam z dynamicznej tablica nie potrzeba zalozenia ze wartosc<15 tablica przypisze tyle wartosci ile chcemy
			  cin >> ile;
			  float *tab;
			  tab = new float[ile];
			  for (int i = 0; i < ile; i++)
			  {
				  cin >> tab[i];
			  }
			  sortowanie_babelkowe(tab, ile);//tu zadziala funkcja sortowania babelkowego
			  for (int i = 0; i < ile; i++)
			  {
				  round(tab[i]);
				  printf("%.2f ", tab[i]);
			  }
			  break;
	}
	case 7:
	{
			  int ileliczb;
			  float *liczby; unsigned char *znaki;
			  cin >> ileliczb;
			  float wynik = 0;
			  liczby = new float[ileliczb];//korzystam z tablic dynamicznych
			  znaki = new unsigned char[ileliczb - 1];//znakow jest o jeden mniej
			  // Znakow musi byc mniej niz liczb. wiec wypisze w petli o jedna liczbe mniej niz chcemy, 
			  //wtedy bedziemy mieli tyle samo znakow i liczb, ALE przypisana tutaj liczba do tablicy zwieksza tablice liczb. czyli LICZBY > ZNAKI (o jedna liczbe wiecej od znakow)
			  cin >> liczby[ileliczb];
			  for (int i = ileliczb - 1; i > 0; i--)
			  {
				  cin >> znaki[i];
				  cin >> liczby[i];
			  }
			  for (int i = ileliczb; i > 0; i--)
			  if (liczby[i] == 0 / liczby[i + 1] == 0)
			  {
				  printf("%s", "blad");
				  break;
			  }
			  int i = ileliczb;
			  while (i > 0)
			  {
				  if (znaki[i] == '/')
				  {
					  liczby[i + 1] = 1 / liczby[i + 1];
					  znaki[i] = '*';
				  }
				  if (znaki[i] == '*')
				  {
					  liczby[i] = liczby[i + 1] * liczby[i];
					  liczby[i + 1] = 0;
				  }
				  if (znaki[i] == '-')
				  {
					  liczby[i + 1] = -liczby[i + 1];
					  znaki[i] = '+';
				  }
				  if (znaki[i] == '+')
				  {
					  liczby[i] = liczby[i] + liczby[i + 1];
					  liczby[i + 1] = 0;
				  }
				  i--;
			  }
			  wynik = liczby[1];
			  printf("%.2f ", wynik);
			  break;
	}
	default:
		cout << ("Zadanie o podanym numerze nie istnieje") << endl;
		return 0;
	}
}