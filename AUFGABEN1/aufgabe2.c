#include <stdio.h>
#include <math.h>

int main()
{
	// R = p * L / A

	printf("Berechnung des Wiederstand eines Golddrahtes\n\n");
	printf("( R = p * L / A)\n\n");

	double L, A, R, d, I;
	const double p = 2.2e-8;
        
	printf("Laenge ( L in mm): ");
	scanf("%lf", &L);

	printf("\nDurchmesser ( d in mm ): ");
	scanf("%lf", &d);

        printf("\nStromstaerke: ");
        scanf("%lf", &I);

	A = M_PI * ((d * d) / 4);

	R = p * (L / A);

        printf("Ergebnis: \n\n");
        printf("%-20.12lf Ohm \n\n", R );
        printf("%-20.12lf mOhm ( milli Ohm)\n\n", R * pow(10, 3));
        printf("%-20.12lf uOhm ( micro Ohm)\n\n", R * pow(10, 6));
        printf("%-20.12lf nOhm ( nano Ohm)\n\n\n", R * pow(10, 9));

        // R = U / I
        // U = R * I
        double U;

        U = R * I;

        printf("\nSpannung: %.12lf V [ Volt ]\n", U);
        

	return 0;
}
