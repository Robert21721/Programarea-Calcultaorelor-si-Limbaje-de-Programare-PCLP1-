Task 1
----------------

Citesc in x un numar de la tastatura dupa care il siftez de 29 de ori spre dreapta
si adun 1 pentru a afla numarul N.

Dupa aceea imi formez o masca pentru a afla pe rand grupurile de 2 biti corespunzatoare
operatorilor. Retin in variabila simbol valoarea in baza 10 a grupului de 2 biti si
fac switch pentru a afisa caracterul corespunzator numarului.

La final creez o noua masca pentru a determina ultimii 4 biti care reprezinta variabila Dim.



Task2
----------------



Am modificat putin primul task si am retinut in vectorul operatori valorile de la 0 la 3
corespunzatoare operatorilor + - * /

Retin in variabila n cate numere vor fi citite de la tastatura.

Citesc numerele pe rand si le separ in grupuri de dimensiune Dim.
Algoritmul functioneaza in felul urmator:
-initializez o variabila nr_executii cu 16 si fac un while in care o decremntez cu Dim de
fiecare data pentru a executa functia de grupare de 16/Dim ori.
-functia grupuri_dim_biti imi formeaza grupurile de dimensiune Dim asa cum este explicat
si in program:
    "functia imi returneaza (la primul apel pt k=1) primii Dim biti din numar.
     Dupa prima utilizare a functiei se sterg primii Dim biti (in main) 
     iar k creste cu o unitate permitand astfel afisarea urmatorilor Dim biti" 
-siftez numarul mai intai la dreapta si apoi la stanga cu Dim*k pentru a sterge bitii deja
retinuti in vectorul numere
-incrementez k, j, iar numarul de executii scade ci Dim


Parcurg in paralel vectorul de operatori si cel de operanti pentru a face calculele,
Retin rezultatul in variabila rezultat.


Task 4
----------------

Retin operatorii si operantii in ordine intr-un vector.
Parcurg vectorul evectuand intai operatiile de * si /, retin rezultatul pe pozitia primului 
operant si sterg urmatoarele 2 numere din vector
Cand toare operatiile de * si / au fost efectuate reincep parcurgerea vectorului si efectuez
adunarea si scaderea (+ si -)

La final rezultatul va fi numarul de pe pozitia 0 in vectorul calcul.









