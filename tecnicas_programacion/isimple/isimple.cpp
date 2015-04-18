#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	double capital_f, capital_i, interes;

	cout << "Introduzca el capital inicial:  $";
	cin >> capital_i;
	cout << "Introduzca el interes a manejar: %";
	cin >> interes;
	interes /= 100;
	capital_f = capital_i * (interes + 1);
	cout << endl << "El capital final es: $" << capital_f << endl;

	return 0;
}
