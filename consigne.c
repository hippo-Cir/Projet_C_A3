#include "consigne.h"
#include <unistd.h>

   float consigne(float thermostatPrec_f)
   
   {
      float thermostat=0;
      FILE* verrou=NULL;
      FILE* cons=NULL;

      if( access( ".verrouConsigne", F_OK )!= -1){
         thermostat = thermostatPrec_f;
      }
      else{
         verrou=fopen(".verrouConsigne","w");
         cons=fopen("consigne.txt","r+");
         fscanf(cons, "%f" , &thermostat);
         fclose(cons);
         fclose(verrou);
         remove(".verrouConsigne");
      }
      
      printf("%f", thermostat);
      return thermostat;
      
   }

   