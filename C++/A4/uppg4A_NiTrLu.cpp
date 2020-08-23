/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: sommar-20

Inlämningsuppgift nr 4a

Namn: Nicole Tran Luu

Personummer: 960728-7225

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja
     Om Nej, beskriv vilka testdata som ger problem:  __________________

Jag har använt kompilator/editor (namn/version): Terminal's (in mac) gcc as complicator

Jag har använt följande dator (t.ex. PC, Mac, Annat): Mac
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : macOs Catelina

Jag har arbetat ungefär 5 timmar med denna uppgift.
================================================================================
*/
// Slut på kommentar


// Hanterar fallet med 26 bokstäver A-Z

#include <iostream>
#include <string>
#include <cctype>
#include <cmath>
using namespace std;


// Anv�nd g�rna denna globala konstant i programmet
// i st�llet f�r v�rdet 26
const int ANTAL_BOKSTAVER = 26;  //A-Z
// Globala variabler �r ej till�tna

//--------------------------------------------------------
// Funktionsdeklarationer:
// Anv�nd exakt de funktionsnamn som finns nedan

// Funktionen berakna_histogram_abs
void berakna_histogram_abs(string newText, int histo[]);

// Funktionen skriv_histogram_abs
void skriv_histogram_abs(int histo[]);
//--------------------------------------------------------
// Huvudprogram:

int main()
{
  // Deklarera variabler
  string text;
  int newHist[ANTAL_BOKSTAVER] = {0};

  // L�s in en rad med text fr�n tangentbordet
  cout << "Läs in en textrad: " << endl;
  getline(cin, text); // För att läsa in hela raden

  // Anropa funktionen berakna_histogram_abs som ber�knar histogrammet
  // och antalet bokst�ver.
  berakna_histogram_abs(text, newHist);


  // Anropa funktionen skriv_histogram_abs som skriver ut histogrammet
  skriv_histogram_abs(newHist);

  return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:

// Funktionen skall gå igenom en sträng (d.v.s. en variabel av typen string
// innehållande en text) och beräkna ett histogram med förekomsten av varje bokstav.
// Ingen skillnad görs mellan "stora" (versaler) och "små" (gemener) bokstäver,
// och båda typerna måste naturligtvis ingå vid histogramberäkningen.
// Resultatet skall lagras i en passande datatyp. Funktionen skall beräkna och
// returnera det totala antalet behandlade bokstäver, men du behöver ej hantera å, ä, ö.
void berakna_histogram_abs(string newText, int histo[]) {
  int tempAl;
  int A = 'A';
  // Skapar en noll-array för histogrammet
  //  histo = int histo[ANTAL_BOKSTAVER] = {0};

  // Beräkna totala antalet behandlade bokstäver
  for (int i = 0; i<= newText.length(); i++)
    {
      if (isalpha(newText[i])) {
        newText[i] = toupper(newText[i]);
        tempAl = newText[i];
        histo[tempAl-A]++;
      }
    }
}


// Funktionen skall skriva ut ett förenklat bokstavshistogram som en tabell
// med två kolumner: bokstav och bokstavens förekomst som ett heltal.
void skriv_histogram_abs(int histo[]) {
  char alp = 'A';
  // Loopa elementvis i histogrammet och skriv ut tabellen radvis
  for (int i = 0; i <= ANTAL_BOKSTAVER-1; i++) {
    cout << alp << ": " << histo[i] << endl;
    alp++;
  }
}


/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

Nicoles-Air:A4 entl$ g++ code.cpp -o test
Nicoles-Air:A4 entl$ ./test
Läs in en textrad:
AbCdNNooPPwXyZ
A: 1
B: 1
C: 1
D: 1
E: 0
F: 0
G: 0
H: 0
I: 0
J: 0
K: 0
L: 0
M: 0
N: 2
O: 2
P: 2
Q: 0
R: 0
S: 0
T: 0
U: 0
V: 0
W: 1
X: 1
Y: 1
Z: 1
Nicoles-Air:A4 entl$ ./test
Läs in en textrad:
1234ddddacccbb!?
A: 1
B: 2
C: 3
D: 4
E: 0
F: 0
G: 0
H: 0
I: 0
J: 0
K: 0
L: 0
M: 0
N: 0
O: 0
P: 0
Q: 0
R: 0
S: 0
T: 0
U: 0
V: 0
W: 0
X: 0
Y: 0
Z: 0
Nicoles-Air:A4 entl$ ./test
Läs in en textrad:
Denna rad innehåller ett å!
A: 2
B: 0
C: 0
D: 2
E: 4
F: 0
G: 0
H: 1
I: 1
J: 0
K: 0
L: 2
M: 0
N: 4
O: 0
P: 0
Q: 0
R: 2
S: 0
T: 2
U: 0
V: 0
W: 0
X: 0
Y: 0
Z: 0
Nicoles-Air:A4 entl$
Nicoles-Air:A4 entl$ ./test
Läs in en textrad:
A: 0
B: 0
C: 0
D: 0
E: 0
F: 0
G: 0
H: 0
I: 0
J: 0
K: 0
L: 0
M: 0
N: 0
O: 0
P: 0
Q: 0
R: 0
S: 0
T: 0
U: 0
V: 0
W: 0
X: 0
Y: 0
Z: 0

================================================================================
Här skriver du en kort rapport om uppgiften:
- ett eller ett par stycken om vad uppgiften gick ut på,
- vilka svårigheter som fanns,
- vad du tyckte var besvärligt
- och hur du löste problemen.

Om det finns frågor att besvara i uppgiften ska det göras här.

Uppgiften gick ut på att jag skulle lära mig användning av arrays och stränger.
Programmet beräknar först hur många gånger varje bokstav uppkommer i textraden och
sparar frekvenserna i en histogram. Sedan skriver det ut en tabell med hur många
gånger varje bokstav förekommer i form av ex. A: 3 osv.

Jag tyckte först det var lite klurigt att förstå skillnaden mellan den globala variabeln
och vanliga variabler som är definerade i main funktionen, men efter att jag har läst på lite
har jag nog fått en bättre upppfattning av det.

Uppgiften var ganska klar och fanns inga större besvärligheter med att förstå uppgifterna
och definition av funktionerna.
*/
