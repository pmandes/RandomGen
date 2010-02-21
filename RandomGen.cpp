#include <iostream>
#include <vector>
#include <math.h>
#include "source/RandomNumberGenerator.cpp"

using namespace std;

int main(int argc, char* args[]) {

	vector<double> histogram;          // wektor przechowywujący liczebność wylosowanych liczb w danym przedziale klasowym
	RandomNumberGenerator r(1, 1, 1);  // zaininicjowanie generatora liczb losowych

	double min = -3;                   // dolna granica
	double max = 3;                    // górna granica
	double n = 1000;                   // liczba przedziałów klasowych
	double step = (max - min) / n;     // krok o jaki będą zwiększać się kolejne przedziały
	
	// zainicjowanie licznikow
	
	for (int i=0; i < n; i++){
		histogram.push_back(0);
	}
	
	// losowanie i określenie w którym przedziale znajduje się wylosowana liczba
	
	for (int k=0; k<10000000; k++) {
	
		//double X = r.normalDistribution();       // pobranie wartości losowej
		double X = r.cauchyDistribution();       // pobranie wartości losowej
		double lX = X - min;                     // 'odległość' od dolnej granicy
		
		if ((X >= min) && (X <= max)){
			int i = (int) floor(lX / step);  // obliczenie, do którego przedziału zalicza się wylosowana wartość
			histogram[i] = histogram[i] + 1; // zwiększenie licznika danego przedziału
		}
	}

	// wyprowadzenie wartości liczników na standardowe wyjście
	
	for (unsigned int j=0; j < histogram.size(); j++){
		cout << histogram[j] << endl;
	}

	return EXIT_SUCCESS;
}
