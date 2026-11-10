#include <stdio.h>
#include <stdlib.h>

void process_data() {
    // 1. Checked return value for memory allocation
    int *ptr = (int *)malloc(100 * sizeof(int));
    if (ptr == NULL) {
        fprintf(stderr, "Memory allocation failed!\n");
        return;
    }

    ptr[0] = 42;
    printf("Successfully processed value: %d\n", ptr[0]);
    
    // 2. Proper single deallocation and setting pointer to NULL
    free(ptr);
    ptr = NULL; // Prevents dangling pointer and double-free vulnerabilities

    if (ptr == NULL) {
        printf("Memory safely freed and pointer reset to NULL.\n");
    }
}

int main() {
    process_data();
    return 0;
}
