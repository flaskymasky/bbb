#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int main()
{
    srand(time(NULL));
    int numbers[6] = {0};
    int tipp[6] = {0};
    int tipp_count = 0;
    long long correct[7] = {0};
    uint8_t flag = 0;
    long long n;

    printf("Anzahl Ziehungen: ");
    scanf("%lld", &n);

    printf("Tipp: ");
    for (size_t x = 0; x < ARR_SIZE(numbers); x++)
        scanf("%d", &tipp[x]);

    for (int x = 0; x < n; x++) {
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
                if (numbers[j] == tipp[i]) 
                    tipp_count++;

        correct[tipp_count]++;

        tipp_count = 0;
    }

    for (int x = 0; x < ARR_SIZE(correct); x++)
        printf("%d. Richtige: %lld\n", x, correct[x]);

    return 0;
}
