#include <stdio.h>
#define RAND_MAX 1000
unsigned int rand_interval(unsigned int min, unsigned int max);
void printSuit(int value, int suit);
int main(int argc, char const *argv[])
{
	int suit, value;
	for (value = 2; value < 15; value++) {
		for (suit = 0; suit < 4; suit++) {
			printSuit(value, suit);
			if (!(value == 14 && suit == 3))
				printf(",\t");

		}
		printf("\n");
		
	}
	int randValue = rand_interval(2, 14);
	int randSuit = rand_interval(0,3);
	printf("Randomly selected card: ");
	printSuit(randValue, randSuit);
	return 0;
}

unsigned int rand_interval(unsigned int min, unsigned int max)
{
    int r;
    const unsigned int range = 1 + max - min;
    const unsigned int buckets = RAND_MAX / range;
    const unsigned int limit = buckets * range;

    /* Create equal size buckets all in a row, then fire randomly towards
     * the buckets until you land in one of them. All buckets are equally
     * likely. If you land off the end of the line of buckets, try again. */
    do
    {
        r = rand();
    } while (r >= limit);

    return min + (r / buckets);
}

void printSuit(int value, int suit) {
	switch(suit) {
				case 0:
					if (value < 11) {
						printf("%dS", value);

					}
					else if (value == 11) {
						printf("JS");
					}
					else if (value == 12) {
						printf("QS");
					}
					else if (value == 13) {
						printf("KS");
					}
					else if (value == 14) {
						printf("AS");
					}
					break;

				case 1:
					if (value < 11) {
						printf("%dH", value);

					}
					else if (value == 11) {
						printf("JH");
					}
					else if (value == 12) {
						printf("QH");
					}
					else if (value == 13) {
						printf("KH");
					}
					else if (value == 14) {
						printf("AH");
					}
					break;

				case 2:
					if (value < 11) {
						printf("%dC", value);

					}
					else if (value == 11) {
						printf("JC");
					}
					else if (value == 12) {
						printf("QC");
					}
					else if (value == 13) {
						printf("KC");
					}
					else if (value == 14) {
						printf("AC");
					}
					break;

				case 3:
					if (value < 11) {
						printf("%dD", value);

					}
					else if (value == 11) {
						printf("JD");
					}
					else if (value == 12) {
						printf("QD");
					}
					else if (value == 13) {
						printf("KD");
					}
					else if (value == 14) {
						printf("AD");
					}
					break;
			}
}