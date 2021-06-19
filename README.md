# CMemoryMananger
To manage your memory in C (I'm sorry that I misspelled "manage" to "manange")

I provide a code to test it.

```C
//
//  main.c
//  CLibraries
//
//  Created by Harry Potter on 2021/6/19.
//

#include <stdio.h>
#include "CMemoryMananger.h"

int main(int argc, char *argv[]) {
    CMemoryMananger* mananger = CMemoryMananger_init();
    int* a = CMemoryMananger_alloc(mananger, sizeof(int));
    int* b = CMemoryMananger_alloc(mananger, sizeof(int));
    int* c = CMemoryMananger_alloc(mananger, sizeof(int));
    *a = 0;
    *b = 3;
    *c = 125;
    printf("%d %d %d %p %p %p", *a, *b, *c, a, b, c);
    printf("\nmananger = %p\n", mananger);
    printf("Pool Size: %d\n", mananger -> _pool_size);
    CMemoryMananger_free(mananger, a);
    printf("Pool Size: %d\n", mananger -> _pool_size);
    CMemoryMananger_destroy(&mananger);
    printf("\nmananger = %p\n", mananger);
    return 0;
}
```
