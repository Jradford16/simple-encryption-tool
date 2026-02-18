#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void xorTransform(char *data, int len, int key) {
    for (int i = 0; i < len; i++) {
        data[i] ^= key;
    }
}

int main(int argc, char *argv[]) {

    if (argc < 4) {
        printf("Valid inputs:\n");
        printf("  ./simple encrypt <text> <key>\n");
        printf("  ./simple decrypt <text> <key>\n");
        printf("  ./simple verify <encrypted> <password> <key>\n");
        return 1;
    }

    char *mode = argv[1];
    int key;

    if (strcmp(mode, "verify") == 0) {

        if (argc != 5) return 1;

        char encrypted[1024];
        char plain[1024];

        strcpy(encrypted, argv[2]);
        strcpy(plain, argv[3]);
        key = atoi(argv[4]);

        xorTransform(plain, strlen(plain), key);

        if (strcmp(encrypted, plain) == 0) {
            printf("Match\n");
        } else {
            printf("No match\n");
        }
    }

    else {

        if (argc != 4) return 1;

        char buffer[1024];
        strcpy(buffer, argv[2]);
        key = atoi(argv[3]);

        xorTransform(buffer, strlen(buffer), key);
        printf("%s\n", buffer);
    }

    return 0;
}
