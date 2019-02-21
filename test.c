#include <stdio.h>

void show_bits(int a) {
    int i;

    i = 31;
    printf("%-10d => ", a);
    while (i >= 0) {
        printf("%d", (a >> i) & 1);
        i--;
    }
    printf("\n");
}

int main(void)
{
	int a;


	a = 12313123;
	show_bits(a);
	show_bits(a ^ 16);
	show_bits((a + 16) ^ 16);
	show_bits(8);
	show_bits(16);
//	printf("Xor: %d", a ^ 16);
//	show_bits((a + 8) ^ 16);
	return 0;
}

