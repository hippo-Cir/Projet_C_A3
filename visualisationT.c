#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "visualisationT.h"

void visualisationT(temp_t temp) {
    FILE* pf = NULL; // Pointeur vers le fichier de données
    FILE* verrou = NULL; // Pointeur vers le fichier de verrouillage
    temp_t temperature; // Variable pour stocker les températures lues depuis le fichier

    // Vérification de la présence du fichier de verrouillage
    if (access(".verrouData", F_OK) != -1) { // Si le fichier existe
        temperature = temp; // Utilisation de la température passée en argument de la fonction
    }
    else { // Si le fichier de verrouillage n'existe pas
        verrou = fopen(".verrouData", "w"); // Création du fichier de verrouillage

        // Variables pour stocker les températures lues depuis le fichier
        char temoin_chauffe[8];
        float interieure, exterieure;

        // Lecture des données à partir du fichier
        pf = fopen("data.txt", "r"); // ouverture du fichier en mode lecture
        if (pf == NULL) { // si l'ouverture du fichier a échoué
            perror("in visualisationC, file not found"); // afficher le message d'erreur correspondant
            return; // quitter la fonction
        }
        fscanf(pf, "%s\n%f\n%f", temoin_chauffe, &interieure, &exterieure); // lecture des données à partir du fichier
        fclose(pf); // fermeture du fichier

        // Ouverture du fichier de données en mode écriture
        pf = fopen("data.txt", "w");
        // Écriture des températures dans le fichier de données
        interieure = temp.interieure;
        exterieure = temp.exterieure;
        fprintf(pf, "%s\n%.2f\n%.2f", temoin_chauffe, interieure, exterieure);

        // Fermeture des fichiers
        fclose(verrou);
        fclose(pf);
        // Suppression du fichier de verrouillage
        remove(".verrouData");
    }
}
