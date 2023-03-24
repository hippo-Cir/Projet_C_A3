#include "consigne.h"
#include "define.h"
#include "regulation.h"
#include "simulateur.h"
#include "visualisationC.h"
#include "visualisationT.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main()
{
	// INITIALISATION
	temp_t temperature;			   // Création d'une structure de température pour stocker la température intérieure et extérieure
	temperature.exterieure = 14.0; // Initialisation de la température extérieure à 14°C
	temperature.interieure = 15.0; // Initialisation de la température intérieure à 15°C

	int nT = 1;														 // Nombre de températures précédentes à prendre en compte pour le calcul de l'erreur dérivée
	float i_erreur = 0;												 // Initialisation de l'erreur intégrale
	struct simParam_s *monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisée à 0%
	float puissance = 0.0;											 // Puissance de chauffage.
	float consi = 15;												 // Consigne de température.
	float temp_past = 14.2;											 // Température avant la chauffe c'est pas réaliste.
	while (consi > 5)
	{ // boucle tant que la consigne est supérieure à 5
		// Affichage de la puissance et de la consigne actuelles
		// Calcul de la puissance à appliquer avec une régulation PID
		puissance = PID(2, consi, &temperature, temp_past, nT, &i_erreur);
		// Affichage de la puissance et de la consigne actuelles
		// Mise à jour de la consigne à atteindre
		consi = consigne(consi);
		// Affichage de la puissance sur un écran de visualisation
		visualisationC(puissance);
		// Stockage de la température actuelle pour le calcul de la dérivée
		temp_past = temperature.interieure;
		// Simulation du comportement de l'environnement en fonction de la puissance appliquée
		temperature = simCalc(puissance, monSimulateur_ps);
		// Affichage de la température sur un écran de visualisation
		visualisationT(temperature);
		// Pause de 100 millisecondes pour éviter une boucle trop rapide
		usleep(100000);
	}
	// Si la consigne est inférieure à 5, on détruit la simulation
	if (consi < 5)
	{
		simDestruct(monSimulateur_ps);
	}

	// Retourne 0 pour indiquer une fin de programme réussie
	return EXIT_SUCCESS;
}
