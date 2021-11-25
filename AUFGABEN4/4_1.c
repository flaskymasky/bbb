#include <stdio.h>
#include <stdlib.h>

int main()
{
        unsigned int count; // UNSIGNED -> SIGNED

    printf("Please enter a positive start value for countdown: ");
    scanf("%u", &count);

    // countdown from n to 0:
    while (count>=0) 		
    {
        printf("\n %i", count);	// Ausgabe des aktuellen Schleifenzaehlers
        count--;		// Ende der Schleife, wenn bis 0 heruntergezaehlt wurde
    }
    printf("Finished.");	// dann Programmende!

    return 0;
}
