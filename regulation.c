#include <stdio.h>
#include <stdlib.h>
#include "define.h"
#include "regulation.h"

// Fonction qui simule la régulation de température en utilisant des données de température passées
float regulationTest(int regul, float consigne, float *tabT, int nT)
{
	float cmd = 0.0;			  // Initialisation de la commande de régulation
	float temperature = 0.0;	  // Initialisation de la température courante
	float temperature_past = 0.0; // Initialisation de la température passée
	float i_erreur = 0;
	for (int i = 0; i < nT; i++) // Boucle sur toutes les données de température passées
	{
		if (i == 0) // Si c'est la première température passée
		{
			temperature_past = 15.0; // On considère une température passée de 15 degrés Celsius
		}
		else
		{
			temperature_past = tabT[i - 1]; // Sinon, on récupère la température passée précédente
		}

		temperature = tabT[i];															// On récupère la température courante
		cmd = regulation(regul, consigne, temperature, temperature_past, i, &i_erreur); // On calcule la commande de régulation pour cette température
	}
	return cmd; // On retourne la dernière commande de régulation calculée
}

float regulation(int regul, float consigne, float temperature, float temp_past, int i, float *i_erreur)
{
	// Déclaration des variables utilisées pour la régulation PID
	float cmd = 0;
	float P, I, D;
	float error = 0;
	float error_past = 0;
	float integral = 0;
	float derivative = 0;
	float Kp = 1.1;
	float Ki = 0.2;
	float Kd = 0.15;

	// Initialisation de la variable de sortie à une valeur invalide pour détecter les erreurs
	cmd = -1;

	// Parcours du tableau de températures

	// Régulation Tout ou Rien
	if (regul == 1)
	{
		if (temperature < consigne)
		{
			// Si la température est inférieure à la consigne, on allume le chauffage à 50%
			cmd = 50;
		}
		else
		{
			// Sinon, on éteint le chauffage
			cmd = 0;
		}
	}
	// Régulation PID
	if (regul == 2)
	{
		// Calcul de l'erreur entre la consigne et la température actuelle*
		error = consigne - temperature;
		// Calcul de la dérivée et de l'intégrale
		if (i > 0)
		{
			error_past = consigne - temp_past;
			derivative = (error - error_past) / 10;
			*i_erreur += ((error + error_past) / 2) * 10;
		}
		// Calcul de la commande de chauffage en fonction des gains Kp, Ki et Kd
		P = Kp * error;
		I = Ki * (*i_erreur);
		D = Kd * derivative;
		cmd = P + I + D;
		// Limitation de la commande de chauffage entre 0 et 100%
		if (error < 0)
		{
			return 0;
		}

		if (cmd < 0)
		{
			cmd = 0;
		}
		if (cmd > 100)
		{
			cmd = 100;
		}
	}
	return cmd;
}

float PID(int regul, float consigne, temp_t *temperature, float temp_past, int i, float *i_erreur)
{
	float cmd = 0;
	float P, I, D;
	float error = 0;
	float error_past = 0;
	float integral = 0;
	float derivative = 0;
	// Définition des constantes de régulation PID
	float Kp = 1.1;	 // Constante proportionnelle
	float Ki = 0.2;	 // Constante intégrale
	float Kd = 0.15; // Constante dérivée

	if (regul == 2)
	{
		// Calcul de l'erreur entre la consigne et la température actuelle*
		error = consigne - temperature->interieure;
		// Calcul de la dérivée et de l'intégrale
		if (i > 0)
		{
			error_past = consigne - temp_past;
			derivative = (error - error_past) / 10;
			*i_erreur += ((error + error_past) / 2) * 10;
		}
		// Calcul de la commande de chauffage en fonction des gains Kp, Ki et Kd
		P = Kp * error;
		I = Ki * (*i_erreur);
		D = Kd * derivative;
		cmd = P + I + D;
		// Limitation de la commande de chauffage entre 0 et 100%
		if (error < 0)
		{
			return 0;
		}

		if (cmd <= 0)
		{
			cmd = 0;
		}
		if (cmd >= 100)
		{
			cmd = 100;
		}
	}
	return cmd;
}
