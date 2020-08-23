/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: sommar-20

Inlämningsuppgift nr 5A

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


//
// Programskal till obluppg5A
//
// Hanterar fallet med 26 bokst�ver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:

// Tips: Anv�nd de globala konstanterna ANTAL_BOKSTAVER och ANTAL_SPRAK
// ist�llet f�r v�rdena 26 och 4 i programmet.
const int ANTAL_BOKSTAVER = 26;  //A-Z
const int ANTAL_SPRAK = 4;

// 2d-arrayen TOLK_HJALP inneh�ller bokstavsfrekvensen i %
// f�r fyra spr�k. TOLK_HJALP[0][0] �r frekvensen av
// bokstaven a f�r engelska.TOLK_HJALP[0][25] �r frekvensen av
// bokstaven z f�r engelska.
// Arrayen �r en GLOBAL KONSTANT och skall allts� ej skickas
// som parameter till den funktion som beh�ver den.
const double TOLK_HJALP[ANTAL_SPRAK][ANTAL_BOKSTAVER]=
       {{8.27,1.48,2.94,4.03,11.78,2.22,1.72,6.77, //engelska
         7.39,0.12,0.81,3.76,2.85,6.71,7.79,1.54,
         0.05,5.95,6.69,9.07,2.66,1.13,2.14,0.19,
         1.89,0.03},
        {7.97,1.40,3.55,3.79,16.89,1.02,1.00,0.75, //franska
         7.08,0.38,0.04,5.51,2.82,8.11,5.19,2.78,
         1.01,6.69,8.35,7.22,6.09,1.35,0.02,0.54,
         0.30,0.15},
        {9.50,1.11,1.53,5.30,8.94,1.74,3.57,3.94,  //svenska
         3.98,0.89,3.26,4.93,3.41,8.46,5.01,1.77,
         0.00,6.73,5.56,9.20,1.94,2.42,0.00,0.05,
         0.45,0.00},
        {5.12,1.95,3.57,5.07,16.87,1.35,3.00,5.79, //tyska
         8.63,0.19,1.14,3.68,3.12,10.64,1.74,0.42,
         0.01,6.30,6.99,5.19,3.92,0.77,1.79,0.01,
         0.69,1.24}};

// Globala variabler �r ej till�tna

//--------------------------------------------------------
// H�r kommer klassdeklarationen
class Text
{
private:
  // Attribut:
  string text;
  int antalBok;
  int absHist[ANTAL_BOKSTAVER];

public:
  // Konstructorer:
  Text();

  // Övriga metoder:
  void setText(string newText);
  bool beraknaHistogramAbs();
  void skrivHistogramAbs();
};

// -------------------------------------------------------

// Huvudprogram:

int main()
{
 // Deklarera variabler
  string text;
  bool histOK;
  Text minText;  // Ett objekt av typen Text skapas

  // L�s in en rad med text fr�n tangentbordet
  cout <<"Ge en rad med text:" << endl;
  getline(cin,text);

  // Skicka str�ngen text till objektet minText
  minText.setText( text );

  // Ber�kna och skriv ut histogrammet
  histOK = minText.beraknaHistogramAbs( );

  minText.skrivHistogramAbs( );

  return 0;
}

// -------------------------------------------------------
// H�r skriver du klassimplementationen

// Standardkonstruktor
Text::Text ()
{
  text = "";
  antalBok = 0;
  for (int i = 0 ; i < ANTAL_BOKSTAVER; i++) {
    absHist[i] = 0;
  }
}

// Selektorer
void Text::setText(string newText)
{
  text = newText;
}

// Funktionen beräknar histogrammets absoluta värden
bool Text::beraknaHistogramAbs() {
  int tempAl;
  int A = 'A';
  bool bokIHist = true;

  // Beräkna totala antalet behandlade bokstäver
  for (int i = 0; i<= text.length(); i++)
    {
      if (isalpha(text[i])) {
        text[i] = toupper(text[i]);
        tempAl = text[i];
        absHist[tempAl-A]++;
        antalBok++;
      }
    }

  cout << "Det toala behandlade bokstäver: " << antalBok << endl;

  if (antalBok == 0) {
    bokIHist = false;
  }

  return bokIHist;
}

void Text::skrivHistogramAbs() {
  char alp = 'A';
  // Loopa elementvis i histogrammet och skriv ut tabellen radvis
  for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
    cout << alp << ": " << absHist[i] << endl;
    alp++;
  }
}



/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

Nicoles-Air:A5 entl$ ./test
Ge en rad med text:
AbCdNNooPPwXyZ
Det toala behandlade bokstäver: 14
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
Nicoles-Air:A5 entl$ ./test
Ge en rad med text:
1234ddddacccbb!?
Det toala behandlade bokstäver: 10
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
Nicoles-Air:A5 entl$ ./test
Ge en rad med text:
Denna rad innehåller ett å!
Det toala behandlade bokstäver: 20
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
Nicoles-Air:A5 entl$ ./test
Ge en rad med text:

Det toala behandlade bokstäver: 0
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
Nicoles-Air:A5 entl$

================================================================================
Här skriver du en kort rapport om uppgiften:
- ett eller ett par stycken om vad uppgiften gick ut på,
- vilka svårigheter som fanns,
- vad du tyckte var besvärligt
- och hur du löste problemen.

Om det finns frågor att besvara i uppgiften ska det göras här.

Uppgiften är väldigt lik uppgift 4A, det som skiljer sig är att allt sker i en klass,
metoderna etc är definerade i klassen. Detta leder till att metoderna behöver inga inputs
för att kunna hantera ex. texten eller histogrammet (tabellen).

I och med metoderna var skapade i uppgift 4A så kunde det återanvändas och ändra på variablerna och
rensa några rader av kod för att det ska fungera som metoden i uppgift 4A, därför var det inte alltför
svår uppgift.

Finns det ett bättre sätt att konstruera en array i konstruktorn eller vilket sätt är
lämpligast? Att skriva en forloop och loopar igenom eller definera om den som en ny noll-array, eller
finns det andra sätt ni rekommendera? Jag har försökt läsa och sökt på det, men hittade inget
konkret svar så jag löste det med en for-loop.

*/
