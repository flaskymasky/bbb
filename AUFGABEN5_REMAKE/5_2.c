#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <limits.h>

int compare(const void *a, const void *b)
{
    return ( *(int*)a - *(int*)b);
}

int main()
{
    srand((unsigned)time(0));

    
    int n;
    int zahlen[6] = { 0 };
    int tipp[6];
    int tipp_count = 0;
    int max_tipp = -1 * INT_MAX;

    // zaehle falls es doppelte zahlen gibt und geneiere dann neu

    // wenn eine zahl doppel ist dann flag = 1
    int flag = 0;

    for (int x = 0; x < 6; x++)
        scanf("%d", &tipp[x]);

    for (int x = 0; x < 20; x++) {
        
	for (int y = 0; y < n; y++) {
            // resete flag
            flag = 0;

	    int rnd = rand() % 49 + 1;
	    // schaue ob eine zahl doppelt vorkommt
	    for (int z = 0; z < n; z++)
                // falls ja gehe schleife zuruck und wiederhole sie
		if (zahlen[z] == rnd) {
		    flag = 1;
		    y--;
                    break;
		}

	    // wenn flag == 0 ist ( nicht doppelt )
	    if (!flag)
		zahlen[y] = rnd;
	}

        for (int i = 0; i < n; i++) 
            for (int j = 0; j < n; j++) 
                if (tipp[i] == zahlen[j])
                    tipp_count++;

        if (tipp_count > max_tipp)
            max_tipp = tipp_count;


        // sort array
        qsort(zahlen, sizeof(zahlen) / sizeof(zahlen[0]), sizeof(int), compare);

	printf("Ziehung %2d: ", x + 1);
	for (int k = 1; k < n; k++)
	    printf("%2d ", zahlen[k]);

	printf(" Richtige: %d\n", tipp_count);

        tipp_count = 0;

    }

    printf("\nmax tipp: %d\n", max_tipp);

    return 0;
}
