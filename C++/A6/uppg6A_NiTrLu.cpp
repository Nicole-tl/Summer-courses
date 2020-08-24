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

Jag har arbetat ungefär 5 timmar med denna uppgift.
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
const int MAX_KOMPISAR = 10;
const int MAX_TRANSAKTIONER = 30;
const int MAX_PERSONER = 10;



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
  string kompisar[MAX_KOMPISAR];

 public:
  Transaktion();
  ~Transaktion();
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
  //  ...eventuellt div. annat...
};


// Klass - PersonLista
class PersonLista
 {
 private:
   int antal_pers;
   Person pers[MAX_PERSONER];

 public:
   PersonLista();
   ~PersonLista();
   void laggTillEn( Person pny );
   void skrivUtOchFixa();
   double summaSkyldig();
   double summaBetalat();
   bool finnsPerson(const string& namn);
  //  ...eventuellt div. annat...
 };

 // Klass - Transaktionslista
 class TransaktionsLista
 {
  private:
    Transaktion trans[MAX_TRANSAKTIONER];
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
   //...eventuellt div. annat...
  };

  // -------------------------------------------------------
  // funktionsdeklarationer
  void menu(TransaktionsLista nyTLista, int ind);

// -------------------------------------------------------

// Huvudprogram:

int main()
{
  // Objekt Transaktion skapas
  TransaktionsLista nyTLista;
  int ind;

  cout << "Startar med att läsa från en fil." << endl;
  ifstream fin( "resa.txt" );
  nyTLista.laesin(fin);

  menu(nyTLista, ind);


  return 0;
}


//----------------------------------------------------
// H�r skriver du klassimplementationen

// Klassimplementation för Transaktion -------------------
// Konstructor
Transaktion:: Transaktion() {
  datum = " ";
  typ = " ";
  namn = " ";
  belopp = 0.0;
  ant_kompisar = 0;
  for (int i = 0 ; i < MAX_KOMPISAR; i++) {
    kompisar[i] = " ";
  }
}

// Delete Konstructor - HAR INGEN POINTERS??
Transaktion:: ~Transaktion()
{}

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


// skriver ut information om ett objekt
void Transaktion::skrivEnTrans(ostream &os) {
  os << datum << "  " << typ << "  " << namn;
  os << "  " << belopp << "       " << ant_kompisar;
  os << "          ";
  for (int i = 0; i < ant_kompisar; i++) {
    os << kompisar[i] << "  ";
  }
  os << endl;
}

// läser data om en transaktion från tangentbordet eller en fil
bool Transaktion::laesEnTrans(istream &is) {
  bool laest = true;
  int c = is.peek();
  if (c == EOF) {
    laest = false;
  }
  else {
    is >> datum;
    is >> typ;
    is >> namn;
    is >> belopp;
    is >> ant_kompisar;
    for ( int i = 0; i < ant_kompisar; i++ ) {
      is >> kompisar[i];
    }
  }
  return laest;
}

// -----------------------
// Klassimplementation för TransaktionsLista

TransaktionsLista:: TransaktionsLista()
  : antalTrans(0)
  {}

TransaktionsLista:: ~TransaktionsLista() {}

void TransaktionsLista:: laesin(istream & is) {
  bool y;
  for (int i = 0; i < MAX_TRANSAKTIONER; i++) {
    y = trans[i].laesEnTrans(is);
    if (y) {
      laggTill(trans[i]);
    }
  }
  antalTrans -= 1;
}

void TransaktionsLista:: skrivut(ostream & os) {
  for (int i = 0; i < antalTrans; i++) {
    trans[i].skrivEnTrans(os);
  }
}

void TransaktionsLista::laggTill(Transaktion & t) {
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

PersonLista:: ~PersonLista() {}

void PersonLista:: laggTillEn(Person pny) {
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


// -------------------------------------------------------
// Funktionsdefinition
void menu(TransaktionsLista nyTLista, int ind) {
  do {
    Transaktion nyTrans;
    PersonLista nyPLista;
    string tempNamn;
    double sum;

    string filnamnet = "newFile.txt";
    ofstream utFilen("newFile.txt");

    cout << endl;
    cout << "Välj i menyn nedan: " << endl;
    cout << "0. Avsluta. Alla transaktioner sparas på fil." << endl;
    cout << "1. Läs in en transaktion från tangentbordet." << endl;
    cout << "2. Skriv ut information om alla transaktioner." << endl;
    cout << "3. Beräkna totala kostnaden." << endl;
    cout << "4. Hur mycket är en viss person skyldig?" << endl;
    cout << "5. Hur mycket ligger en viss person ute med?" << endl;
    cout << "6. Lista alla personer mm och FIXA!!!" << endl;
    cout << "Alternativ: ";
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
}


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

Denna uppgift har fyra klasser Transaktion, TransaktionLista, Person och PersonLista.
Med hjälp av dessa fyra klasser och dess metoder skapar den ett program som
liknar apparna "Splitwise" eller "tricount" där den ta in flera kvitto och ställer upp
tabeller om vad alla har lagt ut, hur mycket alla är skyldiga etc. I denna uppgiften användes
statiska array, därför behövdes inga destruktorer.

Svårigheter med denna uppgiften var att hålla koll på att allt uppdateras när något läggs till,
samt att ex. laesEnTrans läser bara in något som sedan behövs läggas till i listorna för att
dem ska sparas ner. Annars har jag tyckt att uppgiften har varit givandet och roligt för
en bättre förståelse på klasser.

Jag har haft lite problem för inläsning av filen då den inte lästes in rätt. Då kommenterade jag
bort en del kod för att kunna enklare felsöka. Senare fick jag till inläsningen som jag ville och då fortsatte jag med
switch-casen.
*/
