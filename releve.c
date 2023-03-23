#include "releve.h"
#include <windows.h>
#include "ftd2xx.h"
#include "define.h"
void releve(){
    FT_HANDLE ftHandle;
    FT_STATUS ftStatus;
    DWORD RxBytes = 8;
    DWORD BytesReceived;
    ftStatus = FT_Open(0, &ftHandle);
    char RxBuffer[6];
    // Déclaration des variables
    int tempExtSOT =  0.0;
    int tempIntSOT = 0.0;
    float tempExtDec = 0.0;
    float tempIntDec = 0.0;
    ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
    
    for(int i =0;i<6;i++){
        if((r))
    }
// Conversion en décimal des valeurs SOT récupérées  
    tempExtDec = -39.64 + (0.04 * tempExtSOT);   // Conversion de la température extérieure en décimal  
    tempIntDec = -39.64 + (0.04 * tempIntSOT);   // Conversion de la température intérieure en décimal
    printf("%g\n", tempExtSOT);
    printf("%g\n", tempIntSOT);
    printf("%g\n", tempExtDec);
    printf("%g", tempIntDec);
    // ftStatus = FT_Open(0, &ftHandle);
    // if(ftStatus != FT_OK) {
    // // FT_Open failed
    // return;
    // }
    // FT_SetTimeouts(ftHandle,10000,0);
    // ftStatus = FT_Read(ftHandle,RxBuffer,RxBytes,&BytesReceived);
    // if (ftStatus == FT_OK) {
    // if (BytesReceived == RxBytes) {
    // // FT_Read OK
    //     tempExtSOT |= (RxBuffer[0] & 0xF0) << 4; // Récupère les bits 11 à 8 de la température extérieure 
    //     tempExtSOT |= (RxBuffer[1] & 0xF0) >> 4; // Récupère les bits 7 à 4 de la température extérieure 
    //     tempExtSOT |= (RxBuffer[2] & 0xF0);      // Récupère les bits 3 à 0 de la température extérieure 
    //     tempIntSOT |= (RxBuffer[3] & 0xF0) << 4; // Récupère les bits 11 à 8 de la température intérieure 
    //     tempIntSOT |= (RxBuffer[4] & 0xF0) >> 4; // Récupère les bits 7 à 4 de la température intérieure 
    //     tempIntSOT |= (RxBuffer[5] & 0xF0);      // Récupère les bits 3 à 0 de la température intérieure 

    //     // Conversion en décimal des valeurs SOT récupérées  
    //     tempExtDec = -39.64 + (0.04 * tempExtSOT);   // Conversion de la température extérieure en décimal  
    //     tempIntDec = -39.64 + (0.04 * tempIntSOT);   // Conversion de la température intérieure en décimal
    // }
    // else {
    // // FT_Read Timeout
    // }
    // }
    // else {
    // // FT_Read Failed
    // }
    // FT_Close(ftHandle);

}

 

        