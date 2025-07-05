#include <stdio.h>
#include <string.h>

unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 2; i <= n; i++)
        result *= i;
    return result;
}

int main() {
    int len, max_len = 15;
    char word[max_len];
    int freq[256] = {0};
    unsigned long long total, denom = 1;

	printf("Введіть слово для анаграми (приклад: SOLO): ");
    if (scanf("%s", word) != 1) {
		printf("\nНекоректні дані\n");
		return 1;
	}
    len = strlen(word);

    for (int i = 0; i < len; i++) {
        freq[(unsigned char)word[i]]++;
    }

    for (int i = 0; i < 256; i++) {
        if (freq[i] > 1) {
            denom *= factorial(freq[i]);
        }
    }

    total = factorial(len);
    printf("\nКількість можливих анаграм: %llu\n", total / denom);

    return 0;
}
