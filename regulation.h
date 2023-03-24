    #include <stdio.h>
	#include <stdlib.h>
	#include "define.h" 
    
   // Pensez à bien proteger vos .h avec des ifndef
    float regulationTest(int regul,float consigne,float* tabT, int nT);
    float regulation(int regul, float consigne, float temperature, float temperature_past, int i,float *i_erreur);
    float PID(int regul, float consigne, temp_t *temperature,float temp_past, int i,float *i_erreur);
