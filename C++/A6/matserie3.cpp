#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// matserie3.cpp
// Statisk allokering av flera m�tserier
// i samma klass.
//
// H�r kommer "d" att fungera som
// en 2-dim dynsmisk matris med
// element d[s][i], d�r 1:a dimensionen och
// och 2:a dimensionen �r dynamiska.


class DMatserier
{
private:
  double **d;  // pekare till pekare (array av pekare)
  int *antal;  // h�r ihop med "d"
  int antalserier;
  void deallocate(); // hj�lpmetod, privat

 public:
  DMatserier();
  ~DMatserier();
  void laes( istream &is );
  void skriv( ostream &os );
  double medel( int serienummer );
  int antalSerier();
};

DMatserier:: DMatserier()
  : antalserier(0), d(0), antal(0)
{}

DMatserier:: ~DMatserier()
{
  deallocate(); // Anrop av privat metod i samma klass
}

void DMatserier:: deallocate()
{
  // L�mna tillbaka minne, dvs det som pekarna
  // pekar p�.

  for (int i=0; i < antalserier; i++)
    {
      delete[] d[i];
    }

  delete[] d;
  delete[] antal;
}

void DMatserier:: laes( istream &is )
{
  deallocate();
  is >> antalserier;

  d = new double*[antalserier];
  antal = new int[antalserier];

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

void DMatserier:: skriv( ostream &os )
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

double DMatserier:: medel( int serienummer )
{
  double sum = 0;

  for ( int i = 0; i < antal[serienummer]; i++ )
    sum += d[serienummer][i];

  return sum / double(antal[serienummer]);
}

int DMatserier:: antalSerier()
{
  return antalserier;
}
//------------------------

int main()
{
  ifstream fin("matserier.txt");
  DMatserier vaerden;

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
