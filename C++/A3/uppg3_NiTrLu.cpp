/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: sommar-20

Inlämningsuppgift nr 3

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

#include <iostream>
#include <math.h>       /* pow */

using namespace std;

// Deklarationer av funktionerna
void skrivInfo();
int lasEttTal();
string lasOp();
int ordna(int n1,int n2);
int berakna(int n1,int n2,string Op);
void skrivResultat(int s);

// Globala variabler, dvs att deklarera
// variabler utanför funktionerna är ej tillåtet

int main(){
  // Deklaration av variabler
  int tal1, tal2;
  string op;
  int ordning;
  int svar;

  // Skriv information om vad programmet gör.
  skrivInfo();

  // Definerar första talet
  tal1 = lasEttTal();

  // Definerar andra talet
  tal2 = lasEttTal();

  // Definerar vilket beräkningsmetod
  op = lasOp();

  // Talar om ordningen
  ordning = ordna(tal1, tal2);

  if (ordning == 1) {
    // Om ordning=1 -> tal 1 är mindre
    svar = berakna(tal1,tal2,op);
  }
  else {
    // annars om tal 2 är det lägre talen
    svar = berakna(tal2,tal1,op);
  }

  // Skriv resultat
  skrivResultat(svar);

  return 0;
}


// Definitioner av funktionerna

// Funktionen ska skriva ut en text som kort förklarar vad programmet gör.
// Kräver ingen input eller output, den ska enbart skriva ut texten vid körning.
void skrivInfo() {
  cout << "Detta program läses först in två tal. Därefter får användaren välja om "
  "programmet skall beräkna summan, produkten eller kradratsumman av talen mellan "
  "de två lästa talen. Efter valet beräknar programmet ut svaret och returnerar svaret." << endl;
}

// Funktionen ska skriva ut en ledtext och läsa in och returnera ett (1) heltal.
// Ingen input, returnerar ett int
int lasEttTal() {
  int tal;
  cout << "Vänligen skriv ett tal: " << endl;
  cin >> tal;
  return tal;
}

// Funktionen ska läsa in och returnera ett tecken som representerar den valda
// beräkningen (tecknet a, m eller k). Ledtext skrivs ut så att användaren vet
// vad som ska matas in.
// Input: -, return: a,m,k
string lasOp(){
  string Op;
  cout << "Vänligen välj ett av följande beräkningsmethod: " << endl;
  cout << "a för addition av talen" << endl;
  cout << "m för multiplikation av talen" << endl;
  cout << "k för kvadratsumman av talen" << endl;
  cin >> Op;

  // Vid fel inmatning
  // do-while sats tills användaren matar in rätt variabel.
  bool inmat;
  do{
    inmat = true;
    if ((Op != "a") && (Op != "m") && (Op != "k")) {
      cout << "Fel inmatning! Vänligen välj mellan a,m eller k." << endl;
      cin >> Op;
      inmat = false;
    }
  } while(!inmat);

  return Op;
}

// Funktionen ska sortera de två inlästa talen i storleksordning.
// Funktionen kan antingen ha två eller fyra parametrar, beroende på
// hur man löser problemet.
// Returnerar vilken av talen som är minst.
int ordna(int n1,int n2) {
  int o;
  if (n1 <= n2) {
    o = 1;
  }
  else {
    o = 2;
  }
  return o;
}

// Funktionen ska utföra den beräkning som ges av tecknet i variabeln op.
// Funktionen skall ha två parametrar som innehåller den undre resp. den övre
// gränsen för de tal som ska summeras, multipliceras eller kvadratsummeras.
// Vald beräkning skall vara en tredje parameter. Funktionen returnerar resultatet av beräkningen.
int berakna(int n1, int n2, string Op) {
  int res;
  if (Op == "a") {
    // Adderar talen mellan tal 1 och tal 2
    res = 0;
    for (int i = n1; i <= n2; i++) {
      res += i;
    }
  }
  else if (Op == "m") {
    // Multiplicear talen mellan tal 1 och tal 2
    res = 1;
    for (int i = n1; i <= n2; i++) {
      res *= i;
    }
  }
  else {
    // Kvadratsummerar talen mellan tal 1 och tal 2
    res = 0;
    for (int i = n1; i <= n2; i++) {
      res = res + pow(i,2);
    }
  }
  return res;
}

// Funktionen ska skriva ut resultatet av beräkningen.
// Input: svaret, returnerar inget
void skrivResultat(int s) {
  cout << "Resultatet blir: " << s << endl;
}



/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

Nicoles-MacBook-Air:A3 entl$ g++ funktion.cpp -o test
Nicoles-MacBook-Air:A3 entl$ ./test
Detta program läses först in två tal. Därefter får användaren välja om programmet skall beräkna summan, produkten eller kradratsumman av talen mellan de två lästa talen. Efter valet beräknar programmet ut svaret och returnerar svaret.
Vänligen skriv ett tal:
3
Vänligen skriv ett tal:
5
Vänligen välj ett av följande beräkningsmethod:
a för addition av talen
m för multiplikation av talen
k för kvadratsumman av talen
a
Resultatet blir: 12
Nicoles-MacBook-Air:A3 entl$ ./test
Detta program läses först in två tal. Därefter får användaren välja om programmet skall beräkna summan, produkten eller kradratsumman av talen mellan de två lästa talen. Efter valet beräknar programmet ut svaret och returnerar svaret.
Vänligen skriv ett tal:
3
Vänligen skriv ett tal:
5
Vänligen välj ett av följande beräkningsmethod:
a för addition av talen
m för multiplikation av talen
k för kvadratsumman av talen
m
Resultatet blir: 60
Nicoles-MacBook-Air:A3 entl$ ./test
Detta program läses först in två tal. Därefter får användaren välja om programmet skall beräkna summan, produkten eller kradratsumman av talen mellan de två lästa talen. Efter valet beräknar programmet ut svaret och returnerar svaret.
Vänligen skriv ett tal:
3
Vänligen skriv ett tal:
5
Vänligen välj ett av följande beräkningsmethod:
a för addition av talen
m för multiplikation av talen
k för kvadratsumman av talen
k
Resultatet blir: 50
Nicoles-MacBook-Air:A3 entl$ ./test
Detta program läses först in två tal. Därefter får användaren välja om programmet skall beräkna summan, produkten eller kradratsumman av talen mellan de två lästa talen. Efter valet beräknar programmet ut svaret och returnerar svaret.
Vänligen skriv ett tal:
-3
Vänligen skriv ett tal:
5
Vänligen välj ett av följande beräkningsmethod:
a för addition av talen
m för multiplikation av talen
k för kvadratsumman av talen
m
Resultatet blir: 0
Nicoles-MacBook-Air:A3 entl$ ./test
Detta program läses först in två tal. Därefter får användaren välja om programmet skall beräkna summan, produkten eller kradratsumman av talen mellan de två lästa talen. Efter valet beräknar programmet ut svaret och returnerar svaret.
Vänligen skriv ett tal:
5
Vänligen skriv ett tal:
3
Vänligen välj ett av följande beräkningsmethod:
a för addition av talen
m för multiplikation av talen
k för kvadratsumman av talen
a
Resultatet blir: 12
Nicoles-MacBook-Air:A3 entl$ ./test
Detta program läses först in två tal. Därefter får användaren välja om programmet skall beräkna summan, produkten eller kradratsumman av talen mellan de två lästa talen. Efter valet beräknar programmet ut svaret och returnerar svaret.
Vänligen skriv ett tal:
-3
Vänligen skriv ett tal:
-5
Vänligen välj ett av följande beräkningsmethod:
a för addition av talen
m för multiplikation av talen
k för kvadratsumman av talen
a
Resultatet blir: -12
Nicoles-MacBook-Air:A3 entl$ ./test
Detta program läses först in två tal. Därefter får användaren välja om programmet skall beräkna summan, produkten eller kradratsumman av talen mellan de två lästa talen. Efter valet beräknar programmet ut svaret och returnerar svaret.
Vänligen skriv ett tal:
1
Vänligen skriv ett tal:
100
Vänligen välj ett av följande beräkningsmethod:
a för addition av talen
m för multiplikation av talen
k för kvadratsumman av talen
k
Resultatet blir: 338350
Nicoles-MacBook-Air:A3 entl$ ./test
Detta program läses först in två tal. Därefter får användaren välja om programmet skall beräkna summan, produkten eller kradratsumman av talen mellan de två lästa talen. Efter valet beräknar programmet ut svaret och returnerar svaret.
Vänligen skriv ett tal:
1
Vänligen skriv ett tal:
1000
Vänligen välj ett av följande beräkningsmethod:
a för addition av talen
m för multiplikation av talen
k för kvadratsumman av talen
m
Resultatet blir: 0

================================================================================
Här skriver du en kort rapport om uppgiften:
- ett eller ett par stycken om vad uppgiften gick ut på,
- vilka svårigheter som fanns,
- vad du tyckte var besvärligt
- och hur du löste problemen.


Programmet läses först in två tal. Därefter får användaren välja vilken beräkningsmetod;
summering, multiplikation eller kvadratsummering av talen mellan de två lästa talen.
Efter valet beräknar programmet ut svaret och returnerar svaret.

Svårigheter/besvärligheter var att jag inte riktigt visste vilka exakta kriterier det krävde för ex. funktionen ordna().
Jag vet inte om min method uppnå kriterierna då jag inte förstod "Funktionen kan antingen ha två eller fyra parametrar".
Jag löste problemet genom att skapa en metod som läser in de två talen och sedan jämföra dem med varandra.
Metoden returnerar sedan en etta om det andra talet är större och en tvåa om det första talet är större.
Sedan kommer huvudprogrammet att läsa in de två talen i respektive ordning för följande beräkningar.

Fördelen med funktioner är det blir mer simpelt att förstå och följa koden, speciellt
när man har delat upp problemen i dellösningar/delsteg. Det blir dessutom enklare
att återropa funktionerna ifall man ska använda dem flera gånger i funktionen.


I någon av dina skrivna funktioner använder du dig troligen av referensparametrar. Varför gör man inte det jämt?
Ibland skall metoden enbart använda referensparametern till beräkningar etc. men inte påverkar dem till senare användningar,
då vill man bara mata in ett värdeparameter istället.

Det sista testdata 8 blir noll eftersom multiplikationen av 1 till 1000 blir för stort.
En integer kan enbart spara värden mellan -2147483648 to 2147483647, men multiplicationen
blir mycket större än det.
*/
