#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "visualisationT.h"

void visualisationT(temp_t temp) {

        FILE* pf=NULL;
        FILE *verrou=NULL;
        temp_t temperature;


        if( access( ".verrouData", F_OK )!= -1){
            temperature=temp;
        }
        else{
            verrou = fopen(".verrouData","w");
            char temoin_chauffe[8];
            float interieure, exterieure;

            // Open the data file
            pf = fopen("data.txt", "r+");
            // Write the temperature data to the file
            strcpy(temoin_chauffe, "true");
            interieure = temp.interieure;
            exterieure = temp.exterieure;
            fprintf(pf, "%s\n%.2f\n%.2f", temoin_chauffe, interieure, exterieure);

            // Close the data file
            fclose(verrou);
            remove(".verrouData");
            fclose(pf); // fermeture du fichier
            
        }
    return;
}
