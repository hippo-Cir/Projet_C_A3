#include "commande.h"
#include <windows.h>

void commande(float pourcentage){

    // init connexion usb
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus = FT_Open(0, &ftHandle);

    if(ftStatus != FT_OK){
        printf("pas de liaison");
        return;
    } //pas de carte connectée

    // parametres de communication avec la carte
    ftStatus = FT_SetBaudRate(ftHandle, 115200); //ok
    ftStatus = FT_SetDataCharacteristics(ftHandle, FT_BITS_8, FT_STOP_BITS_1, FT_PARITY_NONE); //ok
    ftStatus = FT_SetFlowControl(ftHandle, FT_FLOW_NONE, 0, 0); //ok

    int valeur = (pourcentage /100) * 127.0; // poucentage de puissance en valeur de 0 à 127
    if (valeur == 0) {
        valeur |= (1 << 7);
    }

    // envoyer la valeur
    DWORD octetsEnvoyes;
    BYTE tabByte[1];
    tabByte[0] = valeur;
    ftStatus = FT_Write(ftHandle, tabByte, 1, &octetsEnvoyes);

    // fermer la connexion usb
    ftStatus = FT_Close(ftHandle);
}