#include <stdio.h>

const int Zahl0 = 4;
const int Zahl1 = 7;
const int Zahl2 = 1;
const int Zahl3 = 1;

int main()
{
	int KorrekteStellen = 0;
	int Eingabe;

	printf("Das Schloss ist fest verschlossen! Du kommst hier net rrrrein...\n");
	printf("Um aufzumachen gib bitte die richtige Kombination aus vier Zahlen ein!\n");
	do {
		printf("Deine Zahl bitte: ");
		scanf("%d", &Eingabe);

		switch (KorrekteStellen) {
                        
		case 0:
			if (Eingabe == Zahl0)
				KorrekteStellen++;
			else
				KorrekteStellen = 0;
                        break;

		case 1:
			if (Eingabe == Zahl1)
				KorrekteStellen++;
			else
				KorrekteStellen = 0;
			break;
		case 2:
			if (Eingabe == Zahl2)
				KorrekteStellen++;
			else
				KorrekteStellen = 0;
			break;

		case 3:
			if (Eingabe == Zahl3)
				KorrekteStellen++;
			else
				KorrekteStellen = 0;
                        break;

		}

	} while (KorrekteStellen < 4);

	printf("Ok - das Schloss ist jetzt offen!\n");

	return 0;
}
