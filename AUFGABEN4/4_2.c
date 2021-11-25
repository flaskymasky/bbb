#include <stdio.h>

int main()
{
        int number = 1;
        int min = 100000, max = 0;
        double sum = 0;

        for (int x = 0;; x++) {

                printf("%d. number: ", x+1);
                scanf("%d", &number);

                if (number == 0 && x >= 10)
                        break;

                if (number < min)
                        min = number;
                if (number > max)
                        max = number;

                sum += number;

                printf("\nMin: %d\tMax: %d\tAverage: %lf\n\n",
                       min, max, (double)sum / (double)(x + 1));

        }

        puts("done");
        
        return 0;
}
        
