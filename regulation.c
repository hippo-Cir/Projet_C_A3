#include <stdio.h>
#include <stdlib.h>
#include "regulation.h"

float regulationTest(int regul, float consigne, float* tabT, int nT){
	// Déclaration des variables utilisées pour la régulation PID
	float cmd;
	float P, I, D;
	float error;
	float integral = 0;
	float derivative;
	float Kp = 1.1;
	float Ki = 0.2;
	float Kd = 0.15;

	// Parcours du tableau de températures
	for (int i = 0; i < nT; i++) {
		// Régulation Tout ou Rien
		if (regul == 1) {
			if (tabT[i] < consigne) {
				// Si la température est inférieure à la consigne, on allume le chauffage à 50%
				cmd = 50;
			} else {
				// Sinon, on éteint le chauffage
				cmd = 0;
			}
		}
		// Régulation PID
		if (regul == 2) {
			// Calcul de l'erreur entre la consigne et la température actuelle
			error = consigne - tabT[i];
			// Calcul de la dérivée et de l'intégrale
			if (i > 0) {
				derivative = error - tabT[i-1];
				integral += error;
			}
			// Calcul de la commande de chauffage en fonction des gains Kp, Ki et Kd
			P = Kp * error;
			I = Ki * integral;
			D = Kd * derivative;
			cmd = P + I + D;
			// Limitation de la commande de chauffage entre 0 et 100%
			if (cmd < 0) {
				cmd = 0;
			}
			if (cmd > 100) {
				cmd = 100;
			}
		}
	}
}