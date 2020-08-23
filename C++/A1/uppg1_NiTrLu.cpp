/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: sommar-20

Inlämningsuppgift nr 1

Namn: Nicole Tran Luu

Personummer: 960728-7225

Fyll i (alt. stryk det som INTE är relevant) av nedanstående:

Den fil som jag lämnar in går att kompilera och
programmet fungerar för alla de testdata som finns för uppgiften: Ja
     Om Nej, beskriv vilka testdata som ger problem:  __________________

Jag har använt kompilator/editor (namn/version): Terminal's (in mac) gcc as complicator

Jag har använt följande dator (t.ex. PC, Mac, Annat): Mac
      med operativsystemet (t.ex. WindowsXP, Windows7,...) : macOs Catelina

Jag har arbetat ungefär 1 timmar med denna uppgift.

================================================================================
*/

// annatTest.cpp
#include <iostream>
using namespace std;

int main(){

  int a;
  int b = 12;
  a = 0;

  cout << "a = " << a << endl;
  cout << a+b << '\n' << "a-b = " << a-b << endl;

  return 0;
}

/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================
fungerandeTest.cpp:
Grattis! Du har kompilerat och testk�rt den f�rsta programfilen i
kursen. Nu vet du att du har lyckats med installationen och att
kompilatorn fungerar. G� f�rslagsvis vidare till n�sta punkt p�
OU1, d�r man ska kompilera lite felaktig kod.

annatTest.cpp:
a = 0
12
a-b = -12
================================================================================
Här skriver du en kort rapport om uppgiften:
- ett eller ett par stycken om vad uppgiften gick ut på,
- vilka svårigheter som fanns,
- vad du tyckte var besvärligt
- och hur du löste problemen.

fungerandeTest.cpp
Compiled it with termial by writing "g++ fungerandeTest.cpp -o fTest"
(fTest could be defined differently). Afterwards, to run the code by writing
./fTest, then it will return the output text written in the code.

annatTest.cpp
The error is in line 9, where it missed ; after the sentence.

*/
