#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "visualisationC.h"

void visualisationC(float puissance_f){

   // Déclaration des variables locales
   FILE* fp; // pointeur de fichier
   FILE* verrou; // pointeur de fichier
  float puissance;
   
   if( access( ".verrouData", F_OK )!= -1){
      puissance=puissance_f;
   }else{
      verrou = fopen(".verrouData","w");  
      char temoin_chauffe[8]; // chaîne de caractères pour le témoin de chauffe
      float interieure, exterieure; // températures intérieure et extérieure    
      
      // Lecture des données à partir du fichier
      fp = fopen("data.txt", "r"); // ouverture du fichier en mode lecture
      if (fp == NULL) { // si l'ouverture du fichier a échoué
         perror("in visualisationC, file not found"); // afficher le message d'erreur correspondant
         return; // quitter la fonction
      }
      fscanf(fp, "%s\n%f\n%f", temoin_chauffe, &interieure, &exterieure); // lecture des données à partir du fichier
      fclose(fp); // fermeture du fichier

      // Modification des données
      if (puissance_f > 0.0) { // si la puissance est supérieure à zéro
         strcpy(temoin_chauffe, "true"); // modifier la valeur du témoin de chauffe à "true"
      } else { // sinon
         strcpy(temoin_chauffe, "false"); // modifier la valeur du témoin de chauffe à "false"
      }

      // Écriture des données dans le fichier
      fp = fopen("data.txt", "w"); // ouverture du fichier en mode écriture
      if (fp == NULL) { // si l'ouverture du fichier a échoué
         perror("in visualisationC, file not found"); // afficher le message d'erreur correspondant
         return; // quitter la fonction
      }
      
      fprintf(fp, "%s\n%.2f\n%.2f", temoin_chauffe, interieure, exterieure); // écriture des données dans le fichier
      fclose(verrou);
      remove(".verrouData");
      fclose(fp); // fermeture du fichier
   }
}