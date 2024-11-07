#include <stdio.h>
#include <string.h>
#include "rhino_with_a_chicken_head.h"

void partial_copies() {
    int num = 0x12345678;   // A 4-byte integer in hexadecimal format
    int half_num = 0;    // An integer to store the partial copy
    int tiny_num = 0;
    int safe_copy = 0;      // An integer to store the full copy

    printf("Original integer (hex): 0x%X\n", num);

    // Unsafe: Using memcpy to copy only half of the integer
    memcpy(&half_num, &num, sizeof(short)); // Copies only 2 bytes

    // Unsafe: Using memcpy to copy only part of the integer
    memcpy(&tiny_num, &num, sizeof(char)); // Copies only 2 bytes

    // Safe: Using memcpy to copy the full integer
    memcpy(&safe_copy, &num, sizeof(int));       // Copies all 4 bytes

    printf("Partial copy (hex): 0x%X\n", half_num);
    printf("Partial copy (hex): 0x%X\n", tiny_num);
    printf("Safe full copy (hex): 0x%X\n", safe_copy);
}


void dangerzone(){
    char buffer[] = "Hello, world!";
    memcpy(buffer + 6, buffer, 6); // Overlapping regions
    printf("%s\n", buffer); // Undefined behavior, might produce corrupted output
}

int main() {
    partial_copies();
    dangerzone();

    chicken_head();

    return 0;
}
