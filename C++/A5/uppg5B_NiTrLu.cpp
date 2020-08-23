/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: sommar-20

Inlämningsuppgift nr 5B

Namn: Nicole Tran Luu

Personummer: 960728-7225

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja
     Om Nej, beskriv vilka testdata som ger problem:  __________________

Jag har använt kompilator/editor (namn/version): Terminal's (in mac) gcc as complicator

Jag har använt följande dator (t.ex. PC, Mac, Annat): Mac
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : macOs Catelina

Jag har arbetat ungefär 4 timmar med denna uppgift.
================================================================================
*/

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
  double antalBok;
  int absHist[ANTAL_BOKSTAVER];
  double relHist[ANTAL_BOKSTAVER];

public:
  // Konstructorer:
  Text();

  // Övriga metoder:
  void setText(string newText);
  bool beraknaHistogramAbs();
  void skrivHistogramAbs();
  void absTillRel();
  void plottaHistogramRel();
  void beraknaHistogram();
  string tolka();
};

// -------------------------------------------------------
// Funktionsdeklarationer:
// Funktionen namn_pa_fil
string namn_pa_fil();

// Funktionen inlasning
string inlasning(string filNamn);

// -------------------------------------------------------

// Huvudprogram:

int main()
{
 // Deklarera variabler
  string text;
  bool histOK;
  Text minText;  // Ett objekt av typen Text skapas
  string filNamn;

  // Läser in namn på filen
  filNamn = namn_pa_fil();

  // Läser in filen
  text = inlasning(filNamn);

  // Skicka str�ngen text till objektet minText
  minText.setText( text );

  // Ber�kna och skriv ut histogrammet (absoluta värden och relativa värden)
  minText.beraknaHistogram();

  minText.skrivHistogramAbs();

  minText.plottaHistogramRel();

  minText.tolka();

  return 0;
}

// -------------------------------------------------------
// H�r skriver du klassimplementationen

// Standardkonstruktor
Text::Text ()
{
  text = "";
  antalBok = 0.0;
  for (int i = 0 ; i < ANTAL_BOKSTAVER; i++) {
    absHist[i] = 0;
    relHist[i] = 0;
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

void Text::absTillRel() {
  // Beräkna relativa värden
  for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
    relHist[i] = (double) (absHist[i]/antalBok)*100;
  }
}

void Text::plottaHistogramRel(){
  char alp = 'A';
  cout << "\nBokstavsfördelning: \n" << endl;
  // Loopa elementvis i histogrammet och skriv ut tabellen radvis
  for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
    string star = "";
    for (int j = 0; j < round(relHist[i]*2); j++ ) {
      star.append("*");
    }
    cout << alp << " " << star << endl;
    alp++;
  }
}

// Anropa beraknaHistogramAbs och absTillRel
void Text::beraknaHistogram() {
  bool histOK = beraknaHistogramAbs();
  if (histOK) {
    absTillRel();
  }
}

// Tolka språket
string Text::tolka() {
  double kvadS[ANTAL_SPRAK] = {0};
  int sprakInd;
  string sprak;
  double tempMin = 1000000;
  // Loopar genom de fyra språken
  for (int j = 0; j < ANTAL_SPRAK; j++) {
    for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
      kvadS[j] += pow(relHist[i]-TOLK_HJALP[j][i],2);
    }
    if (kvadS[j] < tempMin) {
      tempMin = kvadS[j];
      sprakInd = j;
    }
  }

  switch (sprakInd) {
    case 0:
      sprak = "engelska";
      break;
    case 1:
      sprak = "franska";
      break;
    case 2:
      sprak = "svenska";
      break;
    case 3:
      sprak = "tyska";
      break;
  }

  cout << "Kvadratsumman för engelska: " << kvadS[0] << endl;
  cout << "Kvadratsumman för franska: " << kvadS[1] << endl;
  cout << "Kvadratsumman för svenska: " << kvadS[2] << endl;
  cout << "Kvadratsumman för tyska: " << kvadS[3] << endl;

  cout << "Det lägsta kvadratsumman är: " << tempMin << endl;
  cout << sprak << " är det mest troliga språket" << endl;
  return sprak;
}


//--------------------------------------------------------
// Funktionsdefinitioner:

// Funktionen ska låta användaren läsa in ett filnamn som en sträng och kontrollera om det är korrek.
string namn_pa_fil() {
  string filNamn;
  string filtyp = ".txt";
  cout << "Vänligen läs in ett filnamn: " << endl;
  cin >> filNamn;

  // Kontrollerar om .txt finns med i den inmatade filnamnet,
  // annars lägg till filetypen
  if (filNamn.rfind(filtyp) > 100) {
    filNamn.append(filtyp);
  }
  return filNamn;
}


// Funktionen läser in texten från en fil
string inlasning(string filNamn) {
  string newText;

  // Öppnar filen för att läsa in texten
  ifstream fin( filNamn.c_str() );

  // Felkontroll
  if (!fin) {
    cout << "Filen kunde inte öppnas" << endl;
    exit( EXIT_FAILURE );
  }

  // Om filen har öppnats, påbörjar inläsningen
  char c;
  fin.get(c);

  while(!fin.eof()) {
    newText.append(1u,c);
    fin.get(c);
  }
  return newText;
}

/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================
// Testdata 1-5
Nicoles-Air:A5 entl$ g++ partB.cpp -o test
Nicoles-Air:A5 entl$ ./test
Vänligen läs in ett filnamn:
doyle
Det toala behandlade bokstäver: 12885
A: 1041
B: 171
C: 440
D: 506
E: 1555
F: 280
G: 187
H: 796
I: 980
J: 15
K: 103
L: 486
M: 352
N: 833
O: 991
P: 254
Q: 10
R: 727
S: 835
T: 1188
U: 384
V: 131
W: 267
X: 31
Y: 320
Z: 2

Bokstavsfördelning:

A ****************
B ***
C *******
D ********
E ************************
F ****
G ***
H ************
I ***************
J
K **
L ********
M *****
N *************
O ***************
P ****
Q
R ***********
S *************
T ******************
U ******
V **
W ****
X
Y *****
Z
Kvadratsumman för engelska: 1.75771
Kvadratsumman för franska: 96.1956
Kvadratsumman för svenska: 73.3371
Kvadratsumman för tyska: 116.072
Det lägsta kvadratsumman är: 1.75771
engelska är det mest troliga språket
Nicoles-Air:A5 entl$ ./test
Vänligen läs in ett filnamn:
goethe.txt
Det toala behandlade bokstäver: 14027
A: 745
B: 219
C: 510
D: 662
E: 2340
F: 196
G: 461
H: 799
I: 1254
J: 25
K: 158
L: 489
M: 432
N: 1512
O: 295
P: 59
Q: 2
R: 874
S: 965
T: 795
U: 558
V: 115
W: 277
X: 0
Y: 89
Z: 196

Bokstavsfördelning:

A ***********
B ***
C *******
D *********
E *********************************
F ***
G *******
H ***********
I ******************
J
K **
L *******
M ******
N **********************
O ****
P *
Q
R ************
S **************
T ***********
U ********
V **
W ****
X
Y *
Z ***
Kvadratsumman för engelska: 107.856
Kvadratsumman för franska: 85.205
Kvadratsumman för svenska: 160.318
Kvadratsumman för tyska: 1.04313
Det lägsta kvadratsumman är: 1.04313
tyska är det mest troliga språket
Nicoles-Air:A5 entl$ ./test
Vänligen läs in ett filnamn:
lagerlof
Det toala behandlade bokstäver: 12221
A: 1376
B: 112
C: 176
D: 707
E: 1191
F: 263
G: 513
H: 453
I: 510
J: 164
K: 420
L: 633
M: 431
N: 1105
O: 526
P: 162
Q: 0
R: 911
S: 842
T: 1090
U: 200
V: 372
W: 0
X: 3
Y: 61
Z: 0

Bokstavsfördelning:

A ***********************
B **
C ***
D ************
E *******************
F ****
G ********
H *******
I ********
J ***
K *******
L **********
M *******
N ******************
O *********
P ***
Q
R ***************
S **************
T ******************
U ***
V ******
W
X
Y *
Z
Kvadratsumman för engelska: 86.6804
Kvadratsumman för franska: 145.722
Kvadratsumman för svenska: 8.88258
Kvadratsumman för tyska: 170.223
Det lägsta kvadratsumman är: 8.88258
svenska är det mest troliga språket
Nicoles-Air:A5 entl$ ./test
Vänligen läs in ett filnamn:
verne.txt
Det toala behandlade bokstäver: 11417
A: 931
B: 163
C: 411
D: 467
E: 1981
F: 113
G: 124
H: 75
I: 781
J: 37
K: 4
L: 625
M: 320
N: 869
O: 572
P: 339
Q: 103
R: 779
S: 966
T: 793
U: 679
V: 165
W: 1
X: 60
Y: 37
Z: 22

Bokstavsfördelning:

A ****************
B ***
C *******
D ********
E ***********************************
F **
G **
H *
I **************
J *
K
L ***********
M ******
N ***************
O **********
P ******
Q **
R **************
S *****************
T **************
U ************
V ***
W
X *
Y *
Z
Kvadratsumman för engelska: 112.425
Kvadratsumman för franska: 0.885142
Kvadratsumman för svenska: 149.256
Kvadratsumman för tyska: 90.491
Det lägsta kvadratsumman är: 0.885142
franska är det mest troliga språket
Nicoles-Air:A5 entl$ ./test
Vänligen läs in ett filnamn:
torsten.txt
Filen kunde inte öppnas

================================================================================
Här skriver du en kort rapport om uppgiften:
- ett eller ett par stycken om vad uppgiften gick ut på,
- vilka svårigheter som fanns,
- vad du tyckte var besvärligt
- och hur du löste problemen.

Om det finns frågor att besvara i uppgiften ska det göras här.

Denna uppgiften bygger på uppgift 5b och är väldigt lik uppgift 4b, det som skiljer sig är att
klasser används för text-objekten. Klass-metoderna är väldigt lik i 4b, dock simplare.

Det fanns inte mycket svårigheter eller besvärligheten när jag har fått ou4 rätt. 

BeraknaHistogram anropar både det absoluta och relativa histogrammet, detta är till fördel
i main-funktionen då det räcker att enbart anropar beraknaHistogram för att både
värdena ska beräknas. Detta underlättar till större program då vissa metoder hänger ihopa
och då kan man bara kalla på en method som talar om att beräkna båda funktionerna.
Vid detta fall behövs både det relativa och absoluta värden för att plotta, tolka eller annat,
därför underlättas beraknaHistogram i main för att direkt beräkna både värden.

Man skulle kunna ha en do-while, då kan hela huvudprogrammet/beräkningarna uppdateras
för den nya texten tills ingen ny text implementeras.

Man skulle kunna inkludera funktionerna namn_pa_fil och inlasning i klassen, då
skulle man haft fler attribut som definerar filnamnet och för testen. Då kanske man
skulle kunna kombinera inlasning och setText än att ha två metoder. Dock skulle detta inte
rekommeneras för när man senare ska använda klassen till andra filer så vill man kunna
nå dessa externa funktioner enkelt utan att behöva gå in i klassen och "öppna upp" en ny fil.
Nu när dem är externa så kan man enkelt skapa flera text-objekt från olika filer.

*/
