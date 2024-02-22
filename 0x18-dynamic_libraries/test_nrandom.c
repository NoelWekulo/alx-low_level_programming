/* test_nrandom.c */

#include <stdio.h>
#include <dlfcn.h>

int main(void) {
    void *handle;
    int (*get_random_number)(void);

    // Open the dynamic library
    handle = dlopen("./nrandom.so", RTLD_LAZY);
    if (!handle) {
        fprintf(stderr, "Error opening dynamic library: %s\n", dlerror());
        return 1;
    }

    // Load the function from the library
    get_random_number = (int (*)(void))dlsym(handle, "get_random_number");
    if (!get_random_number) {
        fprintf(stderr, "Error loading function: %s\n", dlerror());
        dlclose(handle);
        return 1;
    }

    // Call the function and print the result
    printf("Random Number: %d\n", get_random_number());

    // Close the dynamic library
    dlclose(handle);

    return 0;
}

