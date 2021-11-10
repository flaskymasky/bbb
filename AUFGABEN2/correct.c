#include <stdio.h>
#include <string.h>

int correct_code(int *arr, int *correct)
{
	for (int x = 0; x < 4; x++)
		if (arr[x] != correct[x])
			return -1;

	return 1;
}

int main()
{
	int Eingabe;

	int code[4] = { 0, 0, 0, 0 }; // richtige reihenfolge checken

	printf("Das Schloss ist fest verschlossen! Du kommst hier net rrrrein...\n");
	printf("Um aufzumachen gib bitte die richtige Kombination aus vier Zahlen ein!\n\n");

	for (;;) {
		memset(code, 0, sizeof(code) / sizeof(code[0]));

		for (int j = 0; j < 4; j++) {
                        
			printf("%d. Zahl : ", j + 1);
			scanf("%d", &Eingabe);

			switch (Eingabe) {
			case 4:
				code[j] = 4;
				break;
			case 7:
				code[j] = 7;
				break;

			case 1:
				code[j] = 1;
				break;
			}
		}

		if (correct_code(code, (int[4]){ 4, 7, 1, 1 }) == -1) {
			puts("\nWRONG CODE!!!\n");
			memset(code, 0, sizeof(code) / sizeof(code[0]));
		} else
			break;
	}

	printf("\nOk - das Schloss ist jetzt offen!\n");

	return 0;
}
