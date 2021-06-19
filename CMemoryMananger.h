//
//  CMemoryMananger.h
//  CLibraries
//
//  Created by Harry Potter on 2021/6/19.
//

#ifndef CMemoryMananger_h
#define CMemoryMananger_h

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    void** _pool;
    int _pool_size;
} CMemoryMananger;

CMemoryMananger* CMemoryMananger_init(void);
void* CMemoryMananger_alloc(CMemoryMananger* mg, size_t bytes);
void CMemoryMananger_free(CMemoryMananger* mg, void* ptr);
void CMemoryMananger_destroy(CMemoryMananger** mg);
#endif /* CMemoryMananger_h */
