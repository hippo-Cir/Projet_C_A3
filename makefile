projeta3.exe: autotests.o commande.o consigne.o regulation.o releve.o simulateur.o test_simulateur.o visualisationC.o visualisationT.o
	gcc autotests.o commande.o consigne.o regulation.o releve.o simulateur.o test_simulateur.o visualisationC.o visualisationT.o -o projeta3.exe
autotests.o: autotests.c autotests.h define.h
	gcc -c autotests.c
commande.o: commande.c commande.h define.h
	gcc -c commande.c 
consigne.o: consigne.c consigne.h define.h
	gcc -c consigne.c
regulation.o: regulation.c regulation.h define.h
	gcc -c regulation.c 
releve.o: releve.c releve.h define.h
	gcc -c releve.c 
simulateur.o: simulateur.c simulateur.h define.h
	gcc -c simulateur.c 
test_simulateur.o: test_simulateur.c simulateur.h define.h
	gcc -c test_simulateur.c 
visualisationC.o: visualisationC.c visualisationC.h define.h
	gcc -c visualisationC.c 
visualisationT.o: visualisationT.c visualisationT.h define.h
	gcc -c visualisationT.c 

