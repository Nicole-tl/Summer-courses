#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// matserie2.cpp
// Statisk allokering av flera m�tserier
// i samma klass.
//
// H�r kommer "d" att fungera som
// en 2-dim matris med element d[s][i],
// d�r 1:a dimensionen �r fix=MAXANTAL
// och 2:a dimensionen �r dynamisk.


const int MAXANTAL = 100;

class SMatserier
{
private:
  double *d[MAXANTAL]; // 100 st pekare till double.
  int antal[MAXANTAL]; // h�r ihop med "d"
  int antalserier;

 public:
  SMatserier();
  ~SMatserier();
  void laes( istream &is );
  void skriv( ostream &os );
  double medel( int serienummer );
  int antalSerier();
};

SMatserier:: SMatserier()
  : antalserier(0)
{
  // S�tt nollpekare och nollantal:

  for ( int s = 0; s < MAXANTAL; s++ )
    {
      d[s] = 0; // NULL-pekare. Tom dynamisk array.
      antal[s] = 0;
    }
}

SMatserier:: ~SMatserier()
{
  for ( int s = 0; s < antalserier; s++ )
    {
      delete[] d[s]; // d[s] �r dynamisk array!
    }
}

void SMatserier:: laes( istream &is )
{
  is >> antalserier;

  // N�r vi vet antalet m�tserier, s� kan vi ju
  // l�sa med for-loop.

  for ( int s = 0; s < antalserier; s++ )
    {
      is >> antal[s];

      d[s] = new double[antal[s]];

      for ( int i = 0; i < antal[s]; i++ )
	{
	  is >> d[s][i];
	}
    }
}

void SMatserier:: skriv( ostream &os )
{
  os << antalserier << endl;

  for ( int s = 0; s < antalserier; s++ )
    {
      os << antal[s];

      for (int i=0; i < antal[s]; i++)
	os << " " << d[s][i];

      os << endl;
    }
}

double SMatserier:: medel( int serienummer )
{
  double sum = 0;

  for ( int i = 0; i < antal[serienummer]; i++ )
    sum += d[serienummer][i];

  return sum / double(antal[serienummer]);
}

int SMatserier:: antalSerier()
{
  return antalserier;
}
//------------------------

int main()
{
  ifstream fin("matserier.txt");
  SMatserier vaerden;

  vaerden.laes( fin );
  vaerden.skriv( cout );

  for ( int i = 0; i < vaerden.antalSerier(); i++ )
    cout << "medelv�rdet f�r serie "
	 << i << " �r " << vaerden.medel(i) <<endl;

  return 0;
}

/*
3
8 3.4 5.6 1.2 3.5 1.8 6.7 3.4 3.9
3 1.2 1.5 1.3
5 5.6 7.8 3.4 5.6 4.5
medelv�rdet f�r serie 0 �r 3.6875
medelv�rdet f�r serie 1 �r 1.33333
medelv�rdet f�r serie 2 �r 5.38
*/
