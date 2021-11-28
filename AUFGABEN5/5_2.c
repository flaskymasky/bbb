#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>
#include <limits.h>

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int compare(const void *a, const void *b)
{
    return (*(int *)a - *(int *)b);
}

int main()
{
    srand(time(NULL));
    int numbers[6] = { 0 };
    uint8_t flag = 0;

    int tipp[6] = { 0 };
    int tipp_count = 0;
    int max_tipp_count = -1 * INT_MAX;


    printf("\nTipp: ( zb 1 2 3 4 5 6): ");
    for (size_t x = 0; x < ARR_SIZE(tipp); x++)
	scanf("%d", &tipp[x]);
    puts("");

    for (int x = 0; x < 20; x++) {
	for (size_t y = 0; y < ARR_SIZE(numbers); y++) {
	    flag = 0;
	    int rnd = rand() % 49 + 1;
	    for (size_t z = 0; z < ARR_SIZE(numbers); z++) {
		if (numbers[z] == rnd) {
		    y--;
		    flag = 1;
		    break;
		}
	    }
	    if (flag == 1)
		continue;
	    else
		numbers[y] = rnd;
	}

	for (size_t i = 0; i < ARR_SIZE(numbers); i++)
	    for (size_t j = 0; j < ARR_SIZE(numbers); j++)
		if (numbers[j] == tipp[i]) {
		    tipp_count++;
		    break;
		}

	if (tipp_count > max_tipp_count)
	    max_tipp_count = tipp_count;

	qsort(numbers, sizeof(numbers) / sizeof(numbers[0]), sizeof(int),
	      compare);

	printf("Ziehung  %2d:   ", x + 1);
	for (size_t k = 0; k < ARR_SIZE(numbers); k++)
	    printf("%2d ", numbers[k]);

	printf("  richtige: %d\n", tipp_count);

	tipp_count = 0;
    }

    printf("\nMaximale Richtige: %d\n", max_tipp_count);

    return 0;
}
