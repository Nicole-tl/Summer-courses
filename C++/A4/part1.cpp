
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
int berakna_histogram_abs(string newText, int histo[]);

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
  int bok = berakna_histogram_abs(text, newHist);

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
// Denna funktion skrevs i deluppgift A
int berakna_histogram_abs(string newText, int histo[]) {
  int tempAl;
  int A = 'A';
  int bokstaver;
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


// Redovisning av uppgiften i ord.
/*
Uppgiften beräknar först hur många gånger varje bokstav uppkommer i textraden och
sparar frekvenserna i en histogram. Sedan skriver det ut en tabell med hur många
gånger varje bokstav förekommer i form av ex. A: 3.
*/
