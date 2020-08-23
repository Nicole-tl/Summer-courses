/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: sommar-20

Inlämningsuppgift nr 6

Namn: Nicole Tran Luu

Personummer: 960728-7225

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja
     Om Nej, beskriv vilka testdata som ger problem:  __________________

Jag har använt kompilator/editor (namn/version): Terminal's (in mac) gcc as complicator

Jag har använt följande dator (t.ex. PC, Mac, Annat): Mac
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : macOs Catelina

Jag har arbetat ungefär 2 timmar med denna uppgift.
================================================================================
*/
// Slut på kommentar


 Här skall din egen kommenterade/indendenterade programkod finnas...



/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

Nicoles-Air:A6 entl$ g++ partA.cpp -o test
Nicoles-Air:A6 entl$ ./test
Startar med att läsa från en fil.

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
2
Antal trans: 10
050615  transp  Eva  6000       5          Bosse  Kristin  Paul  Torsten  Stina
050721  mat  Eva  300       2          Bosse  Kristin
050721  mat  Paul  400       2          Torsten  Stina
050721  transp  Bosse  5000       3          Eva  Kristin  Paul
050721  transp  Stina  5000       1          Torsten
050722  boende  Kristin  200       1          Eva
050722  mat  Eva  300       2          Kristin  Bosse
050723  mat  Torsten  300       2          Paul  Stina
050724  mat  Paul  200       1          Stina
050725  transp  Eva  600       3          Bosse  Kristin  Paul

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
6
Nu skapar vi en personarray och reder ut det hela!
Eva ligger ute med: 5850 och är skyldig: 1350. Skall lägga 4500 till potten.
Paul ligger ute med: 366.667 och är skyldig: 2500. Skall ha 2133.33 från potten.
Bosse ligger ute med: 3750 och är skyldig: 1350. Skall lägga 2400 till potten.
Stina ligger ute med: 2500 och är skyldig: 1333.33. Skall lägga 1166.67 till potten.
Kristin ligger ute med: 100 och är skyldig: 2600. Skall ha 2500 från potten.
Torsten ligger ute med: 200 och är skyldig: 3633.33. Skall ha 3433.33 från potten.

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
1
010201 transp Paul 400 1 Eva

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
2
Antal trans: 11
050615  transp  Eva  6000       5          Bosse  Kristin  Paul  Torsten  Stina
050721  mat  Eva  300       2          Bosse  Kristin
050721  mat  Paul  400       2          Torsten  Stina
050721  transp  Bosse  5000       3          Eva  Kristin  Paul
050721  transp  Stina  5000       1          Torsten
050722  boende  Kristin  200       1          Eva
050722  mat  Eva  300       2          Kristin  Bosse
050723  mat  Torsten  300       2          Paul  Stina
050724  mat  Paul  200       1          Stina
050725  transp  Eva  600       3          Bosse  Kristin  Paul
010201  transp  Paul  400       1          Eva

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
3
Totala kostnaden är: 18700kr.

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
4
Vad heter personen?/Vem?
Eva
Eva är skyldig 1550kr.

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
5
Vad heter personen?/Vem?
Paul
Paul ligger ute med 566.667kr.

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
0
Nicoles-Air:A6 entl$


// Körning nr 2
Nicoles-Air:A6 entl$ ./test
Startar med att läsa från en fil.

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
6
Nu skapar vi en personarray och reder ut det hela!
Eva ligger ute med: 600 och är skyldig: 100. Skall lägga 500 till potten.
Bosse ligger ute med: 100 och är skyldig: 600. Skall ha 500 från potten.

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
0
Nicoles-Air:A6 entl$ 

================================================================================
Här skriver du en kort rapport om uppgiften:
- ett eller ett par stycken om vad uppgiften gick ut på,
- vilka svårigheter som fanns,
- vad du tyckte var besvärligt
- och hur du löste problemen.

Om det finns frågor att besvara i uppgiften ska det göras här.


*/
