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
