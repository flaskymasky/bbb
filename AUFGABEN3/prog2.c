
#include <stdio.h>

int main(int argc, char **argv)
{
        int number;
        int sum = 0;

        printf("Number: ");
        scanf("%d", &number);

        while (number != 0) {
                sum += number % 10;
                number /= 10;
        }

        printf("Quersumme: %d\n", sum);

	return 0;
}

