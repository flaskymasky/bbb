#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int isInteger(char *);
int read_numerator(void);
int read_denominator(void);

int addition(int *, int *);
int subtraction(int *, int *);
int multiplication(int *, int *);
int division(int *, int *);

int ggt(int, int);
void reduce(int *, int *, int *);
void print_fraction(int *, int *, int *, char);

int isInteger(char *str)
{
	int status = 1;

	for (size_t x = 0; x < strlen(str); x++)
		if (!(48 <= str[x] && str[x] <= 57))
			status = 0;

	return status;
}

int read_numerator()
{
	printf("\nnumerator: ");

	char str[50];
	scanf("%s", str);

	if (isInteger(str))
		return atoi(str);
	else
		return -1;
}

int read_denominator()
{
	printf("\ndenominator ( not 0 ): ");

	char str[50];
	scanf("%s", str);

	if (isInteger(str)) {
		while (atoi(str) == 0) {
			printf("\ndenominator ( not 0 ): ");
			scanf("%s", str);
		}

		return atoi(str);
	}

	return -1;
}

int addition(int *frac1, int *result)
{
	int d1, d2;
	int temp;
	int frac2[2];

	printf("\n2. Bruch: \n");

	frac2[0] = read_numerator();
	frac2[1] = read_denominator();

	if (frac2[0] == -1 || frac2[1] == 1) {
		puts("\nPlease enter a Number!!");
		return -1;
	}

	d1 = frac1[1];
	d2 = frac2[1];

	frac1[1] *= frac2[1];
	frac1[0] *= frac2[1];

	frac2[1] *= d1;
	frac2[0] *= d1;

	result[0] = frac1[0] + frac2[0];
	result[1] = frac1[1];

	frac1[1] = d1;
	frac2[1] = d2;

	frac1[0] /= d2;
	frac2[0] /= d1;

	reduce(frac1, frac2, result);

	print_fraction(frac1, frac2, result, '+');
}

int subtraction(int *frac1, int *result)
{
	int d1, d2;
	int temp;
	int frac2[2];
	frac2[0] = read_numerator();
	frac2[1] = read_denominator();

	if (frac2[0] == -1 || frac2[1] == 1) {
		puts("\nPlease enter a Number!!");
		return -1;
	}

	d1 = frac1[1];
	d2 = frac2[1];

	frac1[1] *= frac2[1];
	frac1[0] *= frac2[1];

	frac2[1] *= d1;
	frac2[0] *= d1;

	result[0] = frac1[0] - frac2[0];
	result[1] = frac1[1];

	frac1[1] = d1;
	frac2[1] = d2;

	frac1[0] /= d2;
	frac2[0] /= d1;

	reduce(frac1, frac2, result);

	print_fraction(frac1, frac2, result, '-');
}

int multiplication(int *frac1, int *result)
{
	int frac2[2];
	frac2[0] = read_numerator();
	frac2[1] = read_denominator();

	if (frac2[0] == -1 || frac2[1] == 1) {
		puts("\nPlease enter a Number!!");
		return -1;
	}

	result[0] = frac1[0] * frac2[0];
	result[1] = frac2[1] * frac2[1];

	reduce(frac1, frac2, result);

	print_fraction(frac1, frac2, result, '*');
}

int division(int *frac1, int *result)
{
	int frac2[2];
	frac2[0] = read_numerator();
	frac2[1] = read_denominator();

	if (frac2[0] == -1 || frac2[1] == 1) {
		puts("\nPlease enter a Number!!");
		return -1;
	}

	result[0] = frac1[0] * frac2[1];
	result[1] = frac1[1] * frac2[0];

	reduce(frac1, frac2, result);

	print_fraction(frac1, frac2, result, '/');
}

int ggt(int x, int y)
{
	if (x == 0)
		return y;

	while (y > 0) {
		if (x > y)
			x -= y;
		else
			y -= x;
	}

	return x;
}

void reduce(int *frac1, int *frac2, int *result)
{
	int gcd = ggt(result[0], result[1]);
	result[0] /= gcd;
	result[1] /= gcd;
}

void print_fraction(int *frac1, int *frac2, int *result, char sign)
{
	printf("\n%d/%d %c %d/%d = %d/%d", frac1[0], frac1[1], sign, frac2[0],
	       frac2[1], result[0], result[1]);
	if (result[1] == 1)
		printf(" = %d\n", result[0]);
}

int main()
{
	int fraction[2]; // fraction[0] is numerator, fraction[1] is denominator
	int result[2]; // result will be saved here
	char run =
		'n'; // either ( a => exit, c => continue with result, n => new calculation )
	char sign; // input operation + - * /

	do {
		if (run == 'n') {
                        printf("\n###########################\n\n");
			printf("\n1. Bruch: \n");
			fraction[0] = read_numerator();
			fraction[1] = read_denominator();

			if (fraction[0] == -1 || fraction[1] == -1) {
				puts("\nPlease enter a Number!!");
				continue;
			}

		} else
			memcpy(fraction, result, 2 * sizeof(int));

		printf("\npress: \n\n+ ( Addition )\n- ( Substraction )\n* ( Multiplication)\n/ ( Division )\n: ");
		scanf(" %c", &sign);

		int s;
		switch (sign) {
		case '+':
			s = addition(fraction, result);
			if (s == -1)
				continue;
			else
				break;

		case '-':
			s = subtraction(fraction, result);
			if (s == -1)
				continue;
			else
				break;
		case '*':
			s = multiplication(fraction, result);
			if (s == -1)
				continue;
			else
				break;
		case '/':
			s = division(fraction, result);
			if (s == -1)
				continue;
			else
				break;
		}

		printf("\n\nContinue ? \npress [ n ] for new\npress [ c ] for continue with result\npress [ a ] for exit\n\n");
		scanf(" %c", &run);

	} while (run != 'a');

	return 0;
}
