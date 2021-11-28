#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <inttypes.h>

#define ARR_SIZE(arr) (sizeof(arr) / sizeof(arr[0]))

int compare(const void *a, const void *b) {
    return ( *(int*)a - *(int*)b);
}

int main()
{
    srand(time(NULL));
    int numbers[6] = {0};
    uint8_t flag = 0;

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

        qsort(numbers, sizeof(numbers) / sizeof(numbers[0]), sizeof(int),
              compare);
        
        printf("Ziehung  %2d:   ", x + 1);
        for (size_t k = 0; k < ARR_SIZE(numbers); k++)
            printf("%2d ", numbers[k]);
        puts("");
    }

    return 0;
}
