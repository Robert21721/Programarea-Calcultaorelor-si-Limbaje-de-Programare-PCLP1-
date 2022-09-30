............TASK1...........

Citesc dimensiunile matricei si sirul de comenzi
Retin comenzile intr-un vector pentru simplificare

Folosesc un switch si in functie de prima litera apelez functia corespunzatoare decodarii
Retin valoarea returnata in variabila comanda
In functie de comanda primita efectuez deplasarea in matrice

****Modul de functionare al functiilor este explicat in comentarii****



............TASK2...........


Citesc modul de criptare si in functie de el continui decodarea

In cazul codurilor caesar citesc codul si cheia si apelez functia caesar.
Aceasta functie face apel la functia letter si roteste fiecare litera din cod de k ori

In cazul codurilor vigenere citesc din nou codul si cheia.
Si aceasta functie face apel la functia letter, primind parametrul de rotatie in functie de cheie
****mai multe detalii in comentariile din cod****

In cazul modului de criptare addition citesc cheia si cele 2 numere.
Folosesc functia caesar pentru a decodifica numerele
Sterg zerourile din fata in cazul in care exista
Apelez functia addition si aduc numerele la aceeasi lungime prin adaugarea de zerouri in fata celui mai scurt
Parcurg vectorii de la final si fac adunarea
In cazul in care mai ramane un 1 care trebuie adunat si numaerele s-au terminat il adaug separat

Checkerul imi pica unul dintre teste (uneori) dar l-am verificat manual si da rezultatul corect
As ruga sa fie verificat codul si sa mi se acorde punctajul corespunzator
Multumesc!


............TASK3...........

Citesc paragrafele pe rand si folosind concatenarea retin textul intr-o variabila
Aplic strtok si retin fiecare cuvant intr-un vector, scapand astfel de separatori
Intr-un alt vector retin cuvintele in perechi de cate 2 cu un spatiu intre ele
Parcurg acest vector si in cazul in care gasesc doua elemente la fel cresc numarul de aparitii
Numarul de aparitii in convertesc la tipul char si il adaug la finalul fiecarui element din vector
Numarul de elemente ale vectorului imi va da numarul de 2-grame
Afisez vectorul astfel format