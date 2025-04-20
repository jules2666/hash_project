#include "Hash.h"

char* hashing(char* input) {
    char salt = 0x5A; // initial salt value (static for now)
    int len = strlen(input);
    char* hashed = malloc(len + 1); // allocate memory for the output string

    if (!hashed) return NULL; // check for allocation failure

    // Repeat transformation multiple times for more diffusion
    for (int round = 0; round < 150; round++) {
        for (int i = 0; i < len; i++) {
            unsigned char c = input[i];

            // Obfuscation steps
            c = (c ^ salt);                      // XOR with salt
            c = ((c << 3) | (c >> 5));           // left circular bit rotation (3 bits)
            c = ((c + 31 + i) * 3) % 95 + 32;    // keep result within printable ASCII range

            hashed[i] = (char)c;
            salt = c; // use output char as new salt to add cascading effect
        }
    }

    hashed[len] = '\0'; // null-terminate the string
    return hashed;
}

unsigned long hash_fichier_unique(const char *chemin_fichier) {
    FILE *fichier = fopen(chemin_fichier, "rb");
    if (!fichier) {
        perror("Erreur ouverture fichier");
        return 0;
    }

    unsigned char octet;
    unsigned long hash = 0xcbf29ce484222325;  // base FNV-1a

    while (fread(&octet, 1, 1, fichier) == 1) {
        hash ^= octet;
        hash *= 0x100000001b3;  // FNV prime
    }

    fclose(fichier);
    return hash;
}
