Fiecare task are cate un fisier separat in care se afla functiile specifice

Din main se apeleaza functia parser care citeste o comanda si in functie de aceasta
decide ce va face in continuare

##### TASK1 #####

In cazul comenzii edit <path> se deschide fisierul de la calea path, se apeleaza 
functia edit pentru a citi caracteristicile imaginii (infoheader si fileheader)
si apoi se scrie matricea de biti ignorand paddingul

In cazul comenzii save <path> se creaza fisierul la calea path si se deschide
dupa care se apeleaza functia save care scrie imaginea in fisier incepand cu
fileheader, infoheader si apoi matricea de biti, punand explicit valoarea 0
pe bitii de padding

In cazul comenzii quit se dezaloca memoria pentru matricea de biti, fileheader
si infoheader

##### TASK2 #####

In cazul comenzii insert <path> y x aloc memorie si citesc informatiile si matricea de biti
pentru noua imagine.
Apelez functia insert care imi inlocuieste bitii din imaginea initiala cu bitii din a 2a 
imagine, dupa care dezaloc memoria pentru a 2a imagine

##### TASK3 #####

In cazul comenzii set draw_color R G B schimb atributele vriabilei color cu valorile R G B
In cazul comenzii set line_width x atribui variabilei line_width valoarea x
In cazul comenzii draw line y1 x1 y2 x2 se apeleaza functia draw_line. Aceasta functie verifica
intervalul mai mare si ordinea in care sunt punctele dupa care apeleaza functia line_fill care 
coloreaza pixelii din jurul liniei principale pentru a o face de grosimea line_width.
In cazul comenzii draw rectangle y1 x1 width height aceasta va desena un dreptunghi folosind
functia draw_line
In cazul comenzii draw triangle y1 x1 y2 x2 y3 x3 aceasta va desena un triunghi folosind functia
draw_line

##### TASK4 #####

In cazul comenzii fill y x se apeleaza functia fill care seteaza culoarea initiala cu cea gasita
in matrice la coordonatele (y, x) dupa care coloreaza punctul de coordonate (y, x) cu noua culoare
si apeleaza functia complete.
Functia complete este o functie recursiva care se autoapeleaza pentru a colora toti pixelii vecini
pana cand acestia au toti culoarea dorita.

##### TASK 5 #####

Am verificat toate inputurile si primesc "0 errors from 0 contexts"
