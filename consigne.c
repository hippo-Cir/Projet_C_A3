#include "consigne.h"
#include <unistd.h>

// Fonction qui retourne la consigne à atteindre pour le thermostat
float consigne(float thermostatPrec_f)
{
   float thermostat=0;
   FILE* verrou=NULL;
   FILE* cons=NULL;

   // Vérification de l'existence du fichier de verrouillage
   if( access( ".verrouConsigne", F_OK )!= -1){
      // Si le fichier existe, on conserve la dernière consigne utilisée
      thermostat = thermostatPrec_f;
   }
   else{
      // Si le fichier n'existe pas, on crée un fichier de verrouillage pour éviter les conflits d'accès
      verrou=fopen(".verrouConsigne","w");
      // Ouverture du fichier de consigne en mode lecture/écriture
      cons=fopen("consigne.txt","r+");
      // Lecture de la consigne à atteindre dans le fichier de consigne
      fscanf(cons, "%f" , &thermostat);
      // Fermeture des fichiers
      fclose(cons);
      fclose(verrou);
      // Suppression du fichier de verrouillage
      remove(".verrouConsigne");
   }
   // Retourne la consigne à atteindre
   return thermostat;
}
