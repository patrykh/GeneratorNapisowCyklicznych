// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct listEl
{
	char v; // wartoœæ - litera
	listEl * next; // wskaznik na nasteony element listy

	//listEl();
};

/*listEl::listEl(): v(0), next(nullptr)
{
}*/

void wyswietl(listEl * head)
{
	listEl * p;
	cout << " [";
	p = head;
	if (p)
		do
		{
			cout << p->v;
			p = p->next;
		} while (p != head);
		cout << "] \n\n";

}

void push(listEl * & head, char _v)
{
	listEl * e = new listEl;

	e->v = _v;    // inicjujemy element
	e->next = head;
	head = e;
}

void pop(listEl * & head)
{
	listEl * e = head;     // zaeamiêtujemy pocz¹tek

	if (e)
	{
		head = e->next; // nowy pocz¹tek
		delete e;    // usuñ element z pamiêci
	}
}

int size(listEl * & head)
{
	int i = 0;
	listEl * e = head;

	while(e)
	{
		i++;
		e = e->next;
	}
	return i;
}



int main()
{
	
	listEl ** R; // rejestry - tablica list
	listEl * e = NULL; // lista
	char znak; // oznaczenie rejestru
	char r;
	int _r;

	char bufor [10]; // bufor wejœcia
	//char napis[10];
	int numOfReg = 26;
	int x=0;
	R = new listEl *[numOfReg];

	for (int i = 0; i < numOfReg; i++)
		R[i] = NULL;
	
	cin >> bufor;
	
	cin >> r; // oznaczenie rejestru
	_r = ((int)r - 65); // obliczenie elementu tablicy

	int i = 0;
	
		if (bufor[0] == 'U' && bufor[2] == 'T') //USTAW
		{

			cout << "USTAW" << endl;
			znak = getchar();

			while (1)
			{
				znak = getchar();
				cout << r;
				if ((znak == EOF) || (znak == '\r') || (znak == '\n')) break;
				cout << ++i;
				push(R[_r], znak);
			}
		}
		
	
		//size(R[_r]);
	//cout << _r << endl;
	
	//wyswietl(R[_r]);
	////cout << e->v;

	return 0;
}

