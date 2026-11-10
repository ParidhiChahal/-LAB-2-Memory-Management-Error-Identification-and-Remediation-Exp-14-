#include <stdio.h>
#include <stdlib.h>

void process_data() {
    // 1. Unchecked return value (malloc failure risk)
    int *ptr = (int *)malloc(100 * sizeof(int));
    // Missing check: if (ptr == NULL) { ... }

    ptr[0] = 42;
    
    // Free the memory once
    free(ptr);

    // 2. Use-after-free / Dangling pointer dereference
    printf("Value after free: %d\n", ptr[0]);

    // 3. Double-free bug
    free(ptr);
}

int main() {
    process_data();
    return 0;
}
