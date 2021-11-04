#include <stdio.h>
#include <math.h>

int main()
{
        
	printf("Berechnung des Wiederstand eines Golddrahtes\n\n");
	printf("( R = p * L / A)\n\n");

	double L, A, R, d;
	const double p = 2.2e-8;
        
	printf("Laenge [ L in mm ]: ");
	scanf("%lf", &L);

	printf("\nDurchmesser [ d in mm ]: ");
	scanf("%lf", &d);

        // Querschnittflaeche berechnen
	A = M_PI * ((d * d) / 4);

        // Wiederstand berechnen
	R = p * (L / A); 

        printf("\nErgebnis: \n\n");
        printf("%-20.12lf Ohm  \n\n", R );
        printf("%-20.12lf uOhm ( milli Ohm)\n\n", R * pow(10, 3));
        printf("%-20.12lf nOhm ( micro Ohm)\n\n", R * pow(10, 6));
        printf("%-20.12lf pOhm ( nano Ohm)\n\n\n", R * pow(10, 9));

	return 0;
}
