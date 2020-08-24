/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: sommar-20

Inlämningsuppgift nr 6b

Namn: Nicole Tran Luu

Personummer: 960728-7225

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja
     Om Nej, beskriv vilka testdata som ger problem:  __________________

Jag har använt kompilator/editor (namn/version): Terminal's (in mac) gcc as complicator

Jag har använt följande dator (t.ex. PC, Mac, Annat): Mac
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : macOs Catelina

Jag har arbetat ungefär 8 dagar med denna uppgift.
================================================================================
*/
// Slut på kommentar


#include <string> //
#include <cctype>
#include <iostream> //
#include <fstream>
#include <cmath>
using namespace std;

// Globala konstanter:
// const int MAX_KOMPISAR = 10;
//const int MAX_TRANSAKTIONER = 30;
//const int MAX_PERSONER = 10;


//--------------------------------------------------------
// H�r kommer klassdeklarationen
// Klass - Transaktion
class Transaktion
{
 private:
  string datum;
  string typ;
  string namn;
  double belopp;
  int ant_kompisar;
  string *kompisar;

 public:
  Transaktion();
  ~Transaktion();
  Transaktion(const Transaktion & t);
  Transaktion& operator=( const Transaktion& t);
  string haemta_namn();
  double haemta_belopp();
  int haemta_ant_kompisar();
  bool finnsKompis( string namnet );
  bool laesEnTrans( istream &is );
  void skrivEnTrans( ostream &os );
  // ...eventuellt div. annat...
};


// Klass - Person
 class Person
 {
 private:
   string namn;
   double betalat_andras;   // ligger ute med totalt
   double skyldig;          // skyldig totalt

 public:
   Person();
   Person( string n, double b, double s );
   double haemta_betalat();
   double haemta_skyldig();
   void skrivUt();
   string haemta_namnFranP();
};


// Klass - PersonLista
class PersonLista
 {
 private:
   int antal_pers;
   Person *pers;

 public:
   PersonLista();
   ~PersonLista();  // Destructor
   void laggTillEn( Person pny );
   void skrivUtOchFixa();
   double summaSkyldig();
   double summaBetalat();
   bool finnsPerson(const string& namn);
 };

 // Klass - Transaktionslista
 class TransaktionsLista
 {
  private:
    Transaktion *trans;
    int antalTrans;

  public:
    TransaktionsLista();
    ~TransaktionsLista();
    void laesin( istream & is );
    void skrivut( ostream & os );
    void laggTill( Transaktion & t );
    double totalkostnad();
    double liggerUteMed( string namnet );
    double aerSkyldig( string namnet );
    PersonLista FixaPersoner();
    int haemta_antalTrans();
  };

// -------------------------------------------------------
// funktionsdeklarationer
void menu(TransaktionsLista nyTLista, int ind);

// -------------------------------------------------------

// Huvudprogram:

int main()
{
  // Objekt Transaktion skapas
  Transaktion nyTrans;
  TransaktionsLista nyTLista;
  PersonLista nyPLista;
  string text;
  int ind;
  string tempNamn;
  double sum;

  cout << "Startar med att läsa från en fil." << endl;
  ifstream fin( "resa.txt" );
  //nyTrans.laesEnTrans(fin);
  //nyTrans.skrivEnTrans(cout);

  nyTLista.laesin(fin);

  string filnamnet = "newFile.txt";
  ofstream utFilen("newFile.txt");

  do {
    cout << endl;
    cout << "Välj i menyn nedan: " << endl;
    cout << "0. Avsluta. Alla transaktioner sparas på fil." << endl;
    cout << "1. Läs in en transaktion från tangentbordet." << endl;
    cout << "2. Skriv ut information om alla transaktioner." << endl;
    cout << "3. Beräkna totala kostnaden." << endl;
    cout << "4. Hur mycket är en viss person skyldig?" << endl;
    cout << "5. Hur mycket ligger en viss person ute med?" << endl;
    cout << "6. Lista alla personer mm och FIXA!!!" << endl;
    cin >> ind;

    switch (ind) {
      case 0:
        nyTLista.skrivut( utFilen);
        break;

      case 1: // Läs in transaktion
        nyTrans.laesEnTrans(cin);
        nyTLista.laggTill(nyTrans);
        break;

      case 2: // Info om transaktionerna
        cout << "Antal trans: " << nyTLista.haemta_antalTrans() << endl;
        nyTLista.skrivut(cout);
        break;

      case 3: // Beräkna totala kostnaden
        cout << "Totala kostnaden är: " << nyTLista.totalkostnad() << "kr." << endl;
        break;

      case 4: // Hur mycket är viss person skyldig?
        cout << "Vad heter personen?/Vem?" << endl;
        cin >> tempNamn;
        sum = nyTLista.aerSkyldig(tempNamn);
        cout << tempNamn << " är skyldig " << sum << "kr." << endl;
        break;

      case 5: // Hur mycket ligger en viss person ute med?
        cout << "Vad heter personen?/Vem?" << endl;
        cin >> tempNamn;
        sum = nyTLista.liggerUteMed(tempNamn);
        cout << tempNamn << " ligger ute med " << sum << "kr." << endl;
        break;

      case 6: // Fixa allt!
        cout << "Nu skapar vi en personarray och reder ut det hela!" << endl;
        nyPLista = nyTLista.FixaPersoner();
        nyPLista.skrivUtOchFixa();
      }
    } while(ind != 0);


  return 0;
}

// -------------------------------------------------------
// H�r skriver du klassimplementationen

// Klassimplementation för Transaktion -------------------
// Konstructor
Transaktion:: Transaktion()
//  : datum(""), typ(""), namn(""), belopp(0.0), ant_kompisar(0)
{
  // Sätt nollpekare och nollantal:
  datum = "";
  typ = "";
  namn = "";
  belopp = 0.0;
  ant_kompisar = 0;
  kompisar = 0;
}

// Delete Konstructor
Transaktion:: ~Transaktion()
{
  //cout << "Nu körs destructor för Transaktion" << endl;
  delete[] kompisar;
  kompisar = 0;
}

// Copy constructor
Transaktion::Transaktion(const Transaktion & t) {
  //cout << "Nu körs copy constructor för Transaktion" << endl;
  delete[] kompisar;
  datum = t.datum;
  typ = t.typ;
  namn = t.namn;
  belopp = t.belopp;
  ant_kompisar = t.ant_kompisar;
  kompisar = new string[ant_kompisar];
  for (int i=0; i < ant_kompisar; i++) {
    kompisar[i] = t.kompisar[i];
  }
}

// Tilldelningsoperatorn
Transaktion& Transaktion::operator=( const Transaktion& t)
{
  //cout << "Nu körs copy assign operator för Transaktion" << endl;
  if (this != &t)
    {
      delete[] kompisar;
      datum = t.datum;
      typ = t.typ;
      namn = t.namn;
      belopp = t.belopp;
      ant_kompisar = t.ant_kompisar;
      kompisar = new string[ant_kompisar];
      for (int i=0; i < ant_kompisar; i++) {
        kompisar[i] = t.kompisar[i];
      }
    }
  return *this;
}

// Selektorer för klassen Transaktion
string Transaktion::haemta_namn() {
  return namn;
}

int Transaktion::haemta_ant_kompisar() {
  return ant_kompisar;
}

double Transaktion::haemta_belopp() {
  return belopp;
}

// Funktionen letr igenom arrayen kopmisar och retunerar true om namnet finns
bool Transaktion::finnsKompis(string namnet) {
  bool finns = false;
  for (int i = 0; i < ant_kompisar; i++) {
    if(namnet == kompisar[i]) {
      finns = true;
    }
  }
  return finns;
}


// Läser en transaktion
bool Transaktion::laesEnTrans(istream &is)
{
  is >> datum;
  is >> typ;
  is >> namn;
  is >> belopp;
  is >> ant_kompisar;

  kompisar = new string[ant_kompisar];

  for ( int i = 0; i < ant_kompisar; i++ ) {
    is >> kompisar[i];
  }

  return !is.eof();
}

// Skriver info om ett transaktionsobjekt
void Transaktion::skrivEnTrans(ostream &os) {
  os << datum << "  " << typ << "  " << namn;
  os << "  " << belopp << "  " << ant_kompisar;
  os << "    ";
  for (int i = 0; i < ant_kompisar; i++) {
    os << kompisar[i] << "  ";
  }
  os << endl;
}

// -----------------------
// Klassimplementation för TransaktionsLista

TransaktionsLista::TransaktionsLista() {
  antalTrans = 0;
  trans = 0;
}

TransaktionsLista:: ~TransaktionsLista() {
  cout << "Körning av ~TransaktionsLista" << endl;
  delete[] trans;
  trans = 0;
}

void TransaktionsLista:: laesin(istream & is) {
  bool y;
  Transaktion t;

  do{
    y = t.laesEnTrans(is);
    if (y) {
      laggTill(t);
    }
  } while(y);

}

void TransaktionsLista:: skrivut(ostream & os) {
  for (int i = 0; i < antalTrans; i++) {
    trans[i].skrivEnTrans(os);
  }
}

void TransaktionsLista::laggTill(Transaktion & t) {

  Transaktion *tempTrans = 0;
  tempTrans = new Transaktion[antalTrans+1];

  // Kopierar trans-lista
  for (int i = 0; i < antalTrans; i++) {
    tempTrans[i] = trans[i];
  }

  delete [] trans; // avllokera minne.
  trans = tempTrans;
  trans[antalTrans] = t;
  antalTrans++;
}

double TransaktionsLista::totalkostnad() {
  double totalK = 0.0;
  for (int i = 0; i < antalTrans; i++) {
    totalK += trans[i].haemta_belopp();
  }
  return totalK;
}

double TransaktionsLista::liggerUteMed( string namnet ) {
  double totalForNamn = 0.0;
  double m;
  for (int i = 0; i < antalTrans; i++) {
    if( namnet == (trans[i].haemta_namn()) ) {
      m = (double) trans[i].haemta_ant_kompisar();
      totalForNamn += trans[i].haemta_belopp()* (m/(m+1));
    }
  }
  return totalForNamn;
}

double TransaktionsLista::aerSkyldig( string namnet ) {
  double totalForNamn = 0.0;
  for (int i = 0; i < antalTrans; i++) {
    if(trans[i].finnsKompis(namnet)) {
      totalForNamn += trans[i].haemta_belopp()/(trans[i].haemta_ant_kompisar()+1);
    }
  }
  return totalForNamn;
}

PersonLista TransaktionsLista::FixaPersoner() {
  PersonLista nyLista;
  string n1;
  // Loopar igenom alla transaktioner
  for (int i = 0; i < antalTrans; i ++) {
    n1 = trans[i].haemta_namn();
    if (!nyLista.finnsPerson(n1)) {
      Person nyPers(n1, liggerUteMed(n1), aerSkyldig(n1) );
      nyLista.laggTillEn(nyPers);
    }
  }
  return nyLista;
}

int TransaktionsLista::haemta_antalTrans() {
  return antalTrans;
}
// -----------------------
// Klassimplementation för Person
Person:: Person(){
  namn = "";
  betalat_andras = 0.0;
  skyldig = 0.0;
}
Person:: Person(string n, double b, double s){
  namn = n;
  betalat_andras = b;
  skyldig = s;
}

double Person::haemta_betalat() {
  return betalat_andras;
}

double Person:: haemta_skyldig() {
  return skyldig;
}

string Person:: haemta_namnFranP() {
  return namn;
}

void Person:: skrivUt() {
  cout << namn;
  cout << " ligger ute med: " << betalat_andras;
  cout << " och är skyldig: " << skyldig << ". ";
  if (betalat_andras-skyldig < 0) {
    cout << "Skall ha " << abs(betalat_andras-skyldig) << " från potten." << endl;
  }
  else{
    cout << "Skall lägga " << betalat_andras-skyldig << " till potten." << endl;
  }
}

// -----------------------
// Klassimplementation för PersonLista
PersonLista:: PersonLista()
: antal_pers(0)
{}

PersonLista:: ~PersonLista() {
  cout << "Nu körs destructor för PersonLista" << endl;
  delete []pers;
}


void PersonLista:: laggTillEn(Person pny) {
  Person *tempPers = 0;

  tempPers = new Person[antal_pers+1];

  for (int i = 0; i < antal_pers; i++) {
    tempPers[i] = pers[i];
  }

  delete[] pers;

  pers = tempPers;
  pers[antal_pers] = pny;
  antal_pers++;
}

void PersonLista:: skrivUtOchFixa() {
  for (int i = 0; i< antal_pers; i++) {
    pers[i].skrivUt();
  }
  if ((summaSkyldig()-summaBetalat()) > 0.8) {
    cout << "Det belopp som personer lägger till potten är INTE";
    cout << " lika med det belopp som andra personer tar från potten." << endl;
  }
}

double PersonLista:: summaSkyldig(){
  double sum = 0.0;
  for (int i = 0; i < antal_pers; i++) {
    sum += pers[i].haemta_skyldig();
  }
  return sum;
}

double PersonLista:: summaBetalat(){
  double sum = 0.0;
  for (int i = 0; i < antal_pers; i++) {
    sum += pers[i].haemta_betalat();
  }
  return sum;
}

bool PersonLista:: finnsPerson(const string& namn){
  bool finns = false;
  for(int i = 0; i< antal_pers; i++) {
    if(namn.compare(pers[i].haemta_namnFranP()) == 0) {
      finns = true;
      break;
    }
  }
  return finns;
}



/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

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
050615  transp  Eva  6000  5    Bosse  Kristin  Paul  Torsten  Stina
050721  mat  Eva  300  2    Bosse  Kristin
050721  mat  Paul  400  2    Torsten  Stina
050721  transp  Bosse  5000  3    Eva  Kristin  Paul
050721  transp  Stina  5000  1    Torsten
050722  boende  Kristin  200  1    Eva
050722  mat  Eva  300  2    Kristin  Bosse
050723  mat  Torsten  300  2    Paul  Stina
050724  mat  Paul  200  1    Stina
050725  transp  Eva  600  3    Bosse  Kristin  Paul

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
3
Totala kostnaden är: 18300kr.

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
Eva är skyldig 1350kr.

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
Paul ligger ute med 366.667kr.

Välj i menyn nedan:
0. Avsluta. Alla transaktioner sparas på fil.
1. Läs in en transaktion från tangentbordet.
2. Skriv ut information om alla transaktioner.
3. Beräkna totala kostnaden.
4. Hur mycket är en viss person skyldig?
5. Hur mycket ligger en viss person ute med?
6. Lista alla personer mm och FIXA!!!
1
010101 mat Eva 10 0

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
050615  transp  Eva  6000  5    Bosse  Kristin  Paul  Torsten  Stina
050721  mat  Eva  300  2    Bosse  Kristin
050721  mat  Paul  400  2    Torsten  Stina
050721  transp  Bosse  5000  3    Eva  Kristin  Paul
050721  transp  Stina  5000  1    Torsten
050722  boende  Kristin  200  1    Eva
050722  mat  Eva  300  2    Kristin  Bosse
050723  mat  Torsten  300  2    Paul  Stina
050724  mat  Paul  200  1    Stina
050725  transp  Eva  600  3    Bosse  Kristin  Paul
010101  mat  Eva  10  0

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
Nu körs destructor för PersonLista
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
0

================================================================================
Här skriver du en kort rapport om uppgiften:
- ett eller ett par stycken om vad uppgiften gick ut på,
- vilka svårigheter som fanns,
- vad du tyckte var besvärligt
- och hur du löste problemen.

Om det finns frågor att besvara i uppgiften ska det göras här.

Uppgiften är snarlik uppgift 6A, det som är annorlunda är att vissa attribut är i form av
pekare och då behövs destruktor, tilldelningsoperator och kopieringskonstruktor. Alla andra
funktioner är orörda. Det krävde en definition av destruktor för klassen Transaktion,
TransaktionsLista och PersonLista då en pekare ingick i dessa tre klasser. Klassen
Transaktion krävde ytterligare en tilldelningsoperator,
då den användes i laggTill-funktionen och behövdes destruktorn och "copy assign. operator" för
att kopiera objekten för att skapandet av den dynamiska arrayn.

Svårigheterna var att jag först hade väldigt svårt att förstå kopieringskonstruktor
och tilldelningsoperator. Efter att ha läst på väldigt länge har jag börjat förstå lite
mer varför man använder dem, dock var det fortfarande svårt att veta hur och var jag ska implementera dem.
Med hjälp av diskutionen och exemplarna så jag har provat mig fram och skapat en kopieringskonstruktor
och tilldelningsoperator för alla tre klasserna. Sedan hade jag en "cout" för att se vilka som användes
och varför just bara dem som användes. Det visade sig att det bara var Transaktion då den i sig använder
en pekare och som används i TransaktionLista, vilket är skillnaden mellan klassen Transaktion(samt TransaktionLista) och Person(samt PersonLista).

Besvärligt var att jag hade en bugg i dator som sa att allt var fel hela tiden trots det hade fungerat köra innan.
Nu har det löst sig utan att jag har gjort några större skillnader, men felsökningen på det tog också väldigt lång tid.
Detta bidrog också till att min kod i 6B kanske skiljer sig till 6A lite då jag har ändrat på strukturen för ex. laggTill etc.
Ett exempel är att jag har min switch-case inne i main code.

När jag läste på Rule of Three så förstod jag det som att tre delar skall användas tillsammans, men varför verkar
det som jag inte behöver kopieringskonstruktor för Transaktion eller överlag inget mer än destruktor för TransaktionLista och PersonLista?
Samt varför ser jag att den alltid att destruktor för PersonLista körs alltid i slutet av programmet? Varför händer detta?


Jag skulle gärna vilja se en exempellösning på uppgiften för att kunna få en bättre förståelse på hur man ska tänka
när man gör en sådan uppgift i framtiden. Jag tyckte att det skulle varit enklare om uppgift 6 kunde
delas upp i mindre delar, då det kändes som de förra uppgifterna var betydligt enklare än denna.
Annars har jag tyckt att kursen har varit väldigt givandet och roligt, tack så mycket!

*/
