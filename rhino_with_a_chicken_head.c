#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define two incompatible structs
struct Rhino {
    int weight;
    int horn_length;
    char species[20];
};

struct Chicken {
    int wing_span;
    int egg_count;
    char breed[20];
};

// Dangerous function to "copy" data from Rhino to Chicken with void pointers
void dangerous_copy(void *dest, void *src, size_t n) {
    memcpy(dest, src, n);
}

void chicken_head() {
    struct Rhino *rhino = (struct Rhino *)malloc(sizeof(struct Rhino));
    struct Chicken *chicken = (struct Chicken *)malloc(sizeof(struct Chicken));

    if (rhino == NULL || chicken == NULL) {
        printf("Memory allocation failed\n");
        return;
    }

    // Initialize rhino struct with some data
    rhino->weight = 2000;
    rhino->horn_length = 50;
    strncpy(rhino->species, "White Rhino", sizeof(rhino->species));

    printf("Original Rhino:\n");
    printf("Weight: %d\n", rhino->weight);
    printf("Horn Length: %d\n", rhino->horn_length);
    printf("Species: %s\n\n", rhino->species);

    // Perform a dangerous copy: copying more bytes than Chicken struct can hold
    dangerous_copy(chicken, rhino, sizeof(struct Rhino));

    printf("After dangerous copy - Chicken with Rhino data:\n");
    printf("Wing Span: %d\n", chicken->wing_span);
    printf("Egg Count: %d\n", chicken->egg_count);
    printf("Breed: %s\n", chicken->breed);

    // Free allocated memory
    free(rhino);
    free(chicken);
}