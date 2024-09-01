#include "./lib/hmm.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEAP_SIZE 1024 * 1024  // 1 MB

int main() {

    // 1. Allocate a large block
    void* block1 = my_malloc(128 * 1024);
    if (block1) printf("Allocated 128 KB\n");

    // 2. Allocate multiple small blocks
    void* block2 = my_malloc(64);
    void* block3 = my_malloc(128);
    void* block4 = my_malloc(256);

    // 3. Free one small block
    my_free(block3);

    // 4. Allocate a large block again to test reuse
    void* block5 = my_malloc(64 * 1024);

    // 5. Edge cases
    void* block6 = my_malloc(0);  // Edge case: 0 bytes
    if (block6 == NULL) printf("Handled zero allocation correctly\n");

    // 7. Free everything
    my_free(block1);
    my_free(block2);
    my_free(block4);
    my_free(block5);

    // 8. Stress test loop (optional)
    for (int i = 0; i < 1000000; i++) {
        void* temp = my_malloc(rand() % 1024);
        if (temp) my_free(temp);
    }

    void* temp = my_malloc(1024);

    return 0;
}
