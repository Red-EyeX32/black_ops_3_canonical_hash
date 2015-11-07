#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int getCanonicalNameHash(char *input) {
	if ((input[0] - 65) <= 25)
		input[0] += 32;

	unsigned int hash = (input[0] ^ 0x4B9ACE2F) * 0x1000193;

	for (unsigned int i = 1; i <= strlen(input); i++) {
		unsigned int c = input[i];
		if ((c - 65) <= 25)
			c += 32;

		hash = (c ^ hash) * 0x1000193;
	}

	return hash;
}

int main() {
	printf("black_ops_3_canonical_hash 0.1.0 (c) by Red-EyeX32\n\n");

	const char name[1024];

	for (;;) {
		printf("\nEnter string to hash:\n");
		scanf("%s", &name);
		printf("\n");

		printf("Hash: 0x%X\n", getCanonicalNameHash(&name));

		printf("Press any key to continue...\n");
		getch();
	}

	return 0;
}