#include <stdio.h>

int main()
{
	double a, x1, x2, f, fmax;

	int run;

	do {
		printf("Zahl: ");
		scanf("%lf", &a);

		printf("Startwert: ");
		scanf("%lf", &x1);

		printf("Fehlergrenze: ");
		scanf("%lf", &fmax);

		int n = 0;
		printf("\n\n %-2s |      %-8s        |     %-12s\n", "n", "Xn",
		       "delta f");
		printf("------------------------------------------");
		printf("\n %-2d |    %-16.10lf  |  \n", n, x1);
		n++;

		do {
			x2 = (x1 / 2) * (3 - ((x1 * x1)) / a);

			f = x2 - x1;

			printf(" %-2d |    %-16.10lf  |  %-12.10lf\n", n, x2,
			       f);

			x1 = x2;

			n++;

		} while (f >= fmax);

		printf("\nNochmal ( 1 -> ja / 0 -> nein) : ");
		scanf("%d", &run);
                puts("");

	} while (run == 1);

	return 0;
}
