#include <stdio.h>
#include <math.h>

int main()
{
	// R = p * L / A

	printf("Programm zur Berechnung: Wiederstand eines Golddrahtes\n\n");
	printf("( R = p * L / A)\n\n");

	double L, A, R, d, I;
	/* const double p = 2.2e-8; */
        const double p = 0.022;
        

	printf("Laenge ( L in mm): ");
	scanf("%lf", &L);
        /* L /= 1000; */

	printf("\nDurchmesser ( d in mm ): ");
	scanf("%lf", &d);

        printf("\nStromstaerke: ");
        scanf("%lf", &I);

        // Fläche berechnen
        
	A = M_PI * ((d * d) / 4);

        // Wiederstand Golddraht
	R = p * (L / A);

        printf("Ergebnis: \n\n");
        printf("%-28.12lf Ohm\n\n", R * pow(10, -3));
        printf("%-28.12lf mOhm ( milli Ohm )\n\n", R );
        printf("%-28.12lf uOhm ( micro Ohm)\n\n", R * pow(10, 3));
        printf("%-28.12lf nOhm ( nano Ohm)\n\n", R * pow(10, 6));
        printf("%-28.12lf pOhm ( pico Ohm)\n\n\n", R * pow(10, 9));

        // R = U / I
        // U = R * I
        double U;

        U = (R * pow(10, -3)) * I;

        printf("%-20s%.12lf V\n","\nSpannung: ", U);

        printf("%-20s%-10.12lf W\n","\nLeistung ( P ) : ", U * I);
        printf("%-20s%.12lf J\n","\nStromdichte : ",  I / A);
        

	return 0;
}
