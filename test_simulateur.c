#include "consigne.h"
#include "define.h"
#include "regulation.h"
#include "simulateur.h"
#include "visualisationC.h"
#include "visualisationT.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
	//INITIALISATION
	temp_t temperature; // Création d'une structure de température pour stocker la température intérieure et extérieure
	temperature.exterieure = 14.0; // Initialisation de la température extérieure à 14°C
	temperature.interieure = 15.0; // Initialisation de la température intérieure à 15°C
	
	//Définition des constantes de régulation PID
	float Kp=1.1; // Constante proportionnelle
	float Ki=0.2; // Constante intégrale
	float Kd=0.15; // Constante dérivée

	int nT = 1; // Nombre de températures précédentes à prendre en compte pour le calcul de l'erreur dérivée
	float i_erreur=0; // Initialisation de l'erreur intégrale
	struct simParam_s*  monSimulateur_ps = simConstruct(temperature); // creation du simulateur, puissance intialisée à 0%
	printf("pointeur avant:%f\n",i_erreur);
	float puissance = 70.0; // Puissance de chauffage.
	float consi = 20.0; // Consigne de température.
	float temp_past=14.5; // Température avant la chauffe c'est pas réaliste.
	while(consi>5){ // boucle tant que la consigne est supérieure à 5
		// Affichage de la puissance et de la consigne actuelles
		// Calcul de la puissance à appliquer avec une régulation PID
		puissance=regulation_PID(2,consi,&temperature,temp_past,nT,&i_erreur,Kp,Ki,Kd);
		// Affichage de la puissance et de la consigne actuelles
		// Mise à jour de la consigne à atteindre
		consi=consigne(consi);
		// Limitation de la puissance à 100% si elle est supérieure, ou à 0% si elle est inférieure
		if (puissance >= 100) {
      		puissance = 100;
    	} else if (puissance <= 0) {
      		puissance = 0;
    	}
		// Affichage de la puissance sur un écran de visualisation
		visualisationC(puissance);
		// Stockage de la température actuelle pour le calcul de la dérivée
		temp_past=temperature.interieure;
		// Simulation du comportement de l'environnement en fonction de la puissance appliquée
		temperature=simCalc(puissance,monSimulateur_ps);
		// Affichage de la température sur un écran de visualisation
		visualisationT(temperature);
		// Pause de 100 millisecondes pour éviter une boucle trop rapide
		usleep(100000);
	}
	// Si la consigne est inférieure à 5, on détruit la simulation
	if (consi<5)
	{
		simDestruct(monSimulateur_ps);
	}

	// Retourne 0 pour indiquer une fin de programme réussie
	return EXIT_SUCCESS;


}
