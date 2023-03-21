#include "visualisationT.h"

void visualisationT(temp_t temp) {
    FILE* pf;
    char temoin_chauffe[8];
    float interieure, exterieure;

    // Open the data file
    pf = fopen("data.txt", "w");
    if (pf == NULL) {
        perror("Error opening data file in visualisationT()");
        return;
    }

    // Write the temperature data to the file
    strcpy(temoin_chauffe, "true");
    interieure = temp.interieure;
    exterieure = temp.exterieure;
    fprintf(pf, "%s\n%.2f\n%.2f", temoin_chauffe, interieure, exterieure);

    // Close the data file
    fclose(pf);
}
