test_commande.exe: test_commande.o commande.o
	gcc commande.o test_commande.o ftd2xx.lib -o commande.exe
test_releve.exe: test_rel.o releve.o
	gcc releve.o test_rel.o ftd2xx.lib -o test_releve.exe
projeta3.exe: autotests.o commande.o consigne.o regulation.o releve.o simulateur.o test_simulateur.o visualisationC.o visualisationT.o
	gcc autotests.o commande.o consigne.o regulation.o releve.o simulateur.o test_simulateur.o visualisationC.o visualisationT.o -o projeta3.exe
test_simulateur.o: test_simulateur.c simulateur.h define.h 
	gcc -c test_simulateur.c 
autotests.o: autotests.c autotests.h define.h consigne.h regulation.h visualisationC.h visualisationT.h
	gcc -c autotests.c
consigne.o: consigne.c consigne.h define.h
	gcc -c consigne.c
regulation.o: regulation.c regulation.h define.h
	gcc -c regulation.c 
simulateur.o: simulateur.c simulateur.h define.h
	gcc -c simulateur.c 
visualisationC.o: visualisationC.c visualisationC.h define.h
	gcc -c visualisationC.c
visualisationT.o: visualisationT.c visualisationT.h define.h
	gcc -c visualisationT.c
test_commande.o: test_commande.c commande.o
	gcc -c test_commande.c
test_rel.o: test_rel.c releve.o
	gcc -c test_rel.c
releve.o: releve.c releve.h define.h
	gcc -c releve.c
commande.o: commande.c commande.h define.h
	gcc -c commande.c
clean :
	rm *.o

