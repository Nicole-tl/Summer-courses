#include <iostream>
#include <math.h>       /* pow */

using namespace std;

// Deklarationer av funktionerna
void skrivInfo();
int lasEttTal();
string lasOp();
void ordna(int &tal1,int &tal2);
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

  // Ordnar talen
  ordna(tal1, tal2);

  // Beräknar algoritm
  svar = berakna(tal1,tal2,op);
  
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
// De två inlästa talen är referensparametrar som
void ordna(int &tal1,int &tal2) {
  int temp;
  // Om tal 1 är större än tal 2 så ska dem byta plats
  if (tal1 > tal2) {
    temp = tal1;
    tal1 = tal2;
    tal2 = temp;
  }
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
