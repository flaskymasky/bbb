#include <stdio.h>

int main()
{
        double e = 1;
        long long int fact = 1;

        for (int x = 0; x < 50; x++) {
                
                for (int y = 1; y <= 1 + x; y++) {
                        fact *= y;
                        /* printf("fact: %lld\n", fact); */
                }
                e += ((double) 1.0 / (double) fact);
                printf("\n(%d)e: %.12lf\n", x, e);
                fact = 1;
        }

        printf("\ne: %.12lf\n\n", e);
        
        return 0;
}
        
