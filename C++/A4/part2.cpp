// Hanterar fallet med 26 bokst�ver A-Z

#include <string>
#include <cctype>
#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>    // std::min
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
// Funktionsdeklarationer:

// Funktionen berakna_histogram_abs
double berakna_histogram_abs(string newText, int histo[]);

//Funktionen abs_till_rel
void abs_till_rel(int absH[], double relH[], double sum);

// Funktionen plotta_histogram
void plotta_histogram_rel(double relH[]);

// Funktionen tolka
void tolkning(double relH[]);

// Funktionen namn_pa_fil
string namn_pa_fil();

// Funktionen inlasning
string inlasning(string filNamn);

//--------------------------------------------------------
// Huvudprogram:

int main()
{
  // Definerar variabler
  int histoAbs[ANTAL_BOKSTAVER] = {0};
  double histoRel[ANTAL_BOKSTAVER] = {0};
  string newText;
  string filNamn;
  double antalBok;

  // Läser in namn på filen
  filNamn = namn_pa_fil();

  // Läser in filen
  newText = inlasning(filNamn);

  // beräkna histogrammets absoluta värden
  antalBok = berakna_histogram_abs(newText, histoAbs);

  // Beräkna det relativa värden
  abs_till_rel(histoAbs, histoRel, antalBok);

  // Plotta en bokstavshistogram
  plotta_histogram_rel(histoRel);

  // Tolka vilket språk det inskrivna texten är
  tolkning(histoRel);


  return 0;
}

//--------------------------------------------------------
// Funktionsdefinitioner:

// Denna funktion skrevs i deluppgift A
double berakna_histogram_abs(string newText, int histo[]) {
  int tempAl;
  int A = 'A';
  char alp = 'A';

  double bokstaver;
  // Skapar en noll-array för histogrammet
  //  histo = int histo[ANTAL_BOKSTAVER] = {0};

  // Beräkna totala antalet behandlade bokstäver
  for (int i = 0; i<= newText.length(); i++)
    {
      if (isalpha(newText[i])) {
        newText[i] = toupper(newText[i]);
        tempAl = newText[i];
        histo[tempAl-A]++;
        bokstaver++;
      }
    }
  cout << "Det toala behandlade bokstäver: " << bokstaver << endl;
  return bokstaver;
}


// Funktionen ska ta ett histogram med absoluta värden och räkna om dessa till relativa värden.
void abs_till_rel(int absH[], double relH[], double sum){
  // Beräkna relativa värden
  for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
    relH[i] = (double) (absH[i]/ sum)*100;
  }
}

// Funktionen skall rita ut ett bokstavshistogram.
void plotta_histogram_rel(double relH[]) {
  char alp = 'A';
  cout << "Bokstavsfördelning: \n" << endl;
  // Loopa elementvis i histogrammet och skriv ut tabellen radvis
  for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
    string star = "";
    for (int j = 0; j < round(relH[i]*2); j++ ) {
      star.append("*");
    }
    cout << alp << " " << star << endl;
    alp++;
  }
}

// Funktionen skall jämföra ett beräknat histogram med fyra fördefinierade
// språks histogram och sedan bestämma vilket språk den ursprungliga texten troligtvis är skriven på.
void tolkning(double relH[]) {
  double kvadS[ANTAL_SPRAK] = {0};
  int sprakInd;
  string sprak;
  double tempMin = 1000000;
  // Loopar genom de fyra språken
  for (int j = 0; j < ANTAL_SPRAK; j++) {
    for (int i = 0; i < ANTAL_BOKSTAVER; i++) {
      kvadS[j] += pow(relH[i]-TOLK_HJALP[j][i],2);
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

}


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

// -------------------------------------------------------
// Rapport om uppgiften
