#include <stdio.h>

int main()
{
	double number = 1; // End Ergebnis
	double exponent; // Exponent zum Einlesen
	double xn = 1; // Exponent berechnung

	__int128 factorial = 1; // Fakultaet berechnung

	printf("\nExponent ( bis 12 ): ");
	scanf("%lf", &exponent);

	for (int x = 0; x < 30; x++) {
                
		for (int y = 1; y <= 1 + x; y++)
			factorial *= y;
                
		for (int k = 0; k < 1 + x; k++)
			xn *= exponent;

		number += xn / factorial;

                // reset everything
                
		factorial = 1;
		xn = 1;
	}

	printf("\ne hoch %.1lf = %.12lf\n\n", exponent, number);

	return 0;
}
