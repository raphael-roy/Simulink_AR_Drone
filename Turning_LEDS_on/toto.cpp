/**
******************************************************************************
* File Name          : toto.c
* Date               : 26/06/2015 13:15:00
* Description        : Main program body
******************************************************************************
*/

/* Includes ------------------------------------------------------------------*/
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include "led.h"

using namespace std;

int main(void)
{
	string contenu = "Hello World!\n";
	ofstream fichier;
	cout << contenu << endl;

	fichier.open("test.txt", ios::out);

	if (fichier)  // si l'ouverture a réussi
	{
		fichier << contenu;
		fichier.close();
	}
	else cerr << "Erreur à l'ouverture !";

	LED_Initialization();

	int Couleur[4] = {0, 1, 2, 3};
	bool error = true;
	for (int i = 0; i < 4; i++) {
		error = Actuators::Led::set(i, Couleur[i]);
		// LED_Set(Couleur[i], i);
		if (error == false) printf("Erreur!\n");
	}

	return 0 ;
}

