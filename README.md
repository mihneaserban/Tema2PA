
    clasament - Tema 2

    Programul are ca scop principal organizarea unui clasament pentru diverse competitii / turnee . 
    
    Acesta foloseste ca structura principala un graf orientat al echipelor participante pentru prima cerinta .
    Pentru cerinta a doua programul are ca scop atribuirea unui prestigiu fiecarei echipe . Prestiugiu ce reprezinta
    gradul de importanta al meciurilor jucate de fiecare echipe intr-un turneu . 

    Acest proiect contine urmatoarele fisiere :

    1) main.c 

    Acesta este fisierul principal in care se lucreaza si se apeleaza toate functiile ce vin o data cu header- urile atasate . Toate datele sunt citite din fisierul input si procesate intr-o structura de tip coada numita " games " . Coada " games " pentru fiecare etapa a turneului va reprezenta jocurile de la momentul acela .
    La fiecare etapa , echipa castigatoare trece intr-o coada " winners " , iar cea pierzatoare intr-o coada " losers " . Dupa fiecare etapa in matricea de adiacenta a grafului turneului pe linia data de pozitia celui invins si coloana data de pozitia celui castigator se va pune 1 . Si apoi se va calcula Prestigiul echipei si se vor scoate elementele din coada " losers " , iar elementele din coada " winners " se introduc in " games " pentru etapa urmatoare . 

    2) Graph_functions.c

    Acest fisier contine toate functiile ce folosesc grafuri necesare rezolvarii problemei .

    
    3) Queue_functions.c

    Acest fisier contine toate functiile ce folosesc cozi necesare rezolvarii problemei .

    4) Queue_header.h 

    Acesta este header-ul ce cuprinde toate functiile de cozi si se introduce in main.c pentru a putea fi apelate functiile respective .
    
    5) Graph_header.h 

    Acesta este header-ul ce cuprinde toate functiile de grafuri si se introduce in main.c pentru a putea fi apelate functiile respective .