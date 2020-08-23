/*
================================================================================
Datorer och programmering, DoP, 10 hsp, termin/år: sommar-20

Inlämningsuppgift nr 2

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


#include <iostream>
#include <math.h>       /* floor */

using namespace std;

int main(){
  // definerar variabler
  // start - startnummret
  // h_s, min_s s_s - starttiden (h min s)
  // h_m, min_m, s_m - måltid (h min s)
  // preLed - startnummer som prel. leder
  // h, m, s - tiden för preLed.
  // sTot - sluttid i sekund.
  // count - antal tävlande
  int start, h_s, min_s, s_s, h_m, min_m, s_m;
  int preLed, h, min, s, sTot_m, sTot_s, sTot, preSTot = pow(10,6);
  int count = 0;
  // Frågar om startnummret
  cout << "Startnummer? ";
  cin >> start; // sparar startnummret som start

  // Om det första startnummer är <=0, annars kolla vilken som är vinnaren
  if (start <= 0){
    // Om ingen deltagande, printa ut "ingen tävlande".
    cout << "Inga tävlande" << endl;
  }
  else {
    // Frågar om tävlande tills slutvillkoret (startnummer <=0)
    do{
      ++count;
      // Frågar om starttiden
      cout << "Starttid? ";
      cin >> h_s >> min_s >> s_s;

      // Frågar om Måltiden
      cout << "Måltid? ";
      cin >> h_m >> min_m >> s_m;

      // Beräkna sluttiden genom att beräkna differansen mellan start- och måltid
      // (i sekunder).
      sTot_s = h_s*(3600) + min_s*(60) + s_s;
      sTot_m = h_m*(3600) + min_m*(60) + s_m;

      // Om det har passerat mittnatt
      if (sTot_m < sTot_s) {
        // Beräkna tiden från startiden till midnatt och adderas med sluttiden
        sTot = ((24*3600)-sTot_s) + sTot_m;
      }
      else {
        // Annars beräknar differansen som vanligt.
        sTot = sTot_m-sTot_s;
      }

      // Om sluttiden är mindre än förra sluttid -> sätts till prel. ledare
      // Annars kolla på andra tävlande
      if (sTot < preSTot) {
        // Beräknar sluttiden i h, minuter, sekunder
        h = sTot/3600;
        min = (sTot%3600)/60;
        s = ((sTot%3600)%60);
        preSTot = sTot;
        preLed = start;
      }

      // Frågar om startnummret
      cout << "Startnummer? ";
      cin >> start; // sparar startnummret som start
    } while(start >0);

    // Printa ut vinnaren och dens information
    cout << "Vinnare är startnr: " << preLed << endl;
    cout << "Tim: " << h << " " << "Min: " << min << " " << "Sek: " << s << endl;
    cout << "Antal tävlande: " << count << endl;
  }

  cout << "Programmet avslutas" << endl;

  return 0;
}


/*
================================================================================
Här följer programkörningar för alla testdata:
==============================================

Nicoles-MacBook-Air:A2 entl$ g++ styrandeSats.cpp -o sSats
Nicoles-MacBook-Air:A2 entl$ ./sSats
Startnummer? 33
Starttid? 17 30 15
Måltid? 18 22 35
Startnummer? -1
Vinnare är startnr: 33
Tim: 0 Min: 52 Sek: 20
Antal tävlande: 1
Programmet avslutas
Nicoles-MacBook-Air:A2 entl$ ./sSats
Startnummer? 33
Starttid? 00 30 15
Måltid? 19 22 35
Startnummer? -1
Vinnare är startnr: 33
Tim: 18 Min: 52 Sek: 20
Antal tävlande: 1
Programmet avslutas
Nicoles-MacBook-Air:A2 entl$ ./sSats
Startnummer? 33
Starttid? 17 30 15
Måltid? 18 22 35
Startnummer? 14
Starttid? 23 35 00
Måltid? 0 12 24
Startnummer? 26
Starttid? 10 11 12
Måltid? 20 21 22
Startnummer? -1
Vinnare är startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tävlande: 3
Programmet avslutas
Nicoles-MacBook-Air:A2 entl$ ./sSats
Startnummer? 14
Starttid? 23 35 00
Måltid? 0 12 24
Startnummer? 26
Starttid? 10 11 12
Måltid? 20 21 22
Startnummer? 33
Starttid? 17 30 15
Måltid? 18 22 35
Startnummer? -1
Vinnare är startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tävlande: 3
Programmet avslutas
Nicoles-MacBook-Air:A2 entl$ ./sSats
Startnummer? 26
Starttid? 10 11 12
Måltid? 20 21 22
Startnummer? 33
Starttid? 17 30 15
Måltid? 18 22 35
Startnummer? 14
Starttid? 23 35 00
Måltid? 0 12 24
Startnummer? -1
Vinnare är startnr: 14
Tim: 0 Min: 37 Sek: 24
Antal tävlande: 3
Programmet avslutas
Nicoles-MacBook-Air:A2 entl$ ./sSats
Startnummer? 17
Starttid? 00 00 50
Måltid? 00 00 30
Startnummer? -1
Vinnare är startnr: 17
Tim: 23 Min: 59 Sek: 40
Antal tävlande: 1
Programmet avslutas
Nicoles-MacBook-Air:A2 entl$ ./sSats
Startnummer? -1
Inga tävlande
Programmet avslutas
Nicoles-MacBook-Air:A2 entl$ ./sSats
Startnummer? 15
Starttid? 10 00 00
Måltid? 11 00 00
Startnummer? 12
Starttid? 11 00 00
Måltid? 10 00 10
Startnummer? -1
Vinnare är startnr: 15
Tim: 1 Min: 0 Sek: 0
Antal tävlande: 2
Programmet avslutas
Nicoles-MacBook-Air:A2 entl$ ./sSats
Startnummer? 8
Starttid? 00 00 10
Måltid? 00 00 20
Startnummer? -1
Vinnare är startnr: 8
Tim: 0 Min: 0 Sek: 10
Antal tävlande: 1
Programmet avslutas


================================================================================
Här skriver du en kort rapport om uppgiften:

Uppgiften var kul och fick med en hel del med syrande satser. Uppgiften gick ut på
att man ska beräkna den bästa tiden på en tävlning, där man får tävlandens startnummer,
start- och sluttid. Sedan ska programmet beräkna ut den tävlande som har bäst tid
och printa ut den. Generellt, ska man lära sig att göra en while-loop för att
uppnå kriteriet med antal deltangade och sen även if och for loop, beroende på hur
koden är uppbyggt. I detta program, användes en if sats till bland annat att kolla bästa tiden.

Det som var lite svårare var att veta vilka krav uppgiften hade. Man fick allt eftersom vid testningen
veta vilka kriterier denna uppgiften skulle klara av och printa ut.
Det var dock bra med tipsen för dem var till bra hjälp när man skulle beräkna bästa tiden.

Uppgiften löstes med en do-whileloop för kriteriet med flera tävlande.
Sedan beräknades slutiden för varje deltagande i whileloopen. Om den beräknade
sluttiden är bättre (dvs. kortaren) den preliminära ledarens tid, så ersätts
preliminär ledarens plats med denna tävlande och dens tid. While-loopen är färdig
när det inte finns fler deltagande och då printas vinnarens information ut.
Över hela do-whileloop finns en if-sats som kollar om det finns några deltagande,
om det inte finns så hoppar den över all beräkning och enbart printar ut att det inte
finns några deltagande och sista meningen.

Besvara frågor i gula rutan:

När två tävlande har samma totaltid så kommer den första deltagande vara vinnaren,
detta är för att if satsen i rad 83 är definerat som om nästa deltagaren har mindre (inte lika med)
så ska den placeras som preliminär ledare, annars inte. Det var inte klart definerat
i uppgiften om vem som ska vara först och det skulle bara finnas en vinnare, därför
bestämdes det som den första deltagande med samma tid vinner.

Många testdata är för att man ska se att koden fungera på riktigt och att det täcker
alla senarier, såsom flera deltagande, utan deltagande, samma senario men olika input ordning etc.
Programmet fungerar utmärkt om det klarar av alla senarier.

En fördelen med att ha testdatan färdigt är att lätt kunna kompilera och
felsöka under gången. Uppgifterna delas oftast upp i delproblem när man kodar och
löser dem del för del. Därmed blir det enklare om man kan testköra dellösningarna
för att se om dem är korrekta och sedan gå vidare till nästa delproblem.
Dessutom är det enklare att felsöka speciellt för ett större program.

*/
