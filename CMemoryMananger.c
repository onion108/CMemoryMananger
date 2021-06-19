//
//  CMemoryMananger.c
//  CLibraries
//
//  Created by Harry Potter on 2021/6/19.
//

#include "CMemoryMananger.h"

CMemoryMananger* CMemoryMananger_init() {
    CMemoryMananger* object = (CMemoryMananger*)malloc(sizeof(CMemoryMananger));
    object -> _pool_size = 0;
    object -> _pool = NULL;
    return object;
}

void* CMemoryMananger_alloc(CMemoryMananger* mg, size_t bytes) {
    if(mg -> _pool_size == 0) {
        mg -> _pool = (void**)malloc(sizeof(void*) * 1);
        mg -> _pool_size = 1;
        mg -> _pool[0] = malloc(bytes);
        return NULL;
    }
    void ** tmp = (void**)malloc(sizeof(void*) * mg -> _pool_size + 1);
    if(tmp == NULL) return NULL;
    for(int i = 0; i < mg -> _pool_size; i++) {
        tmp[i] = mg -> _pool[i];
    }
    tmp[mg -> _pool_size] = malloc(bytes);
    if(tmp[mg -> _pool_size] == NULL) return NULL;
    free(mg -> _pool);
    mg -> _pool = tmp;
    mg -> _pool_size++;
    return tmp[mg -> _pool_size - 1];
}

void CMemoryMananger_free(CMemoryMananger* mg, void* ptr) {
    if(mg -> _pool_size == 0) return;
    void ** tmp = (void**)malloc(sizeof(void*) * mg -> _pool_size - 1);
    if(tmp == NULL) return;
    int found = 0, index = 0;
    for(int i = 0; i < mg -> _pool_size; i++) {
        if(mg -> _pool[i] == ptr) {
            free(ptr);
            found = 1;
            index = i;
            mg -> _pool[i] = NULL;
            break;
        }
    }
    if(!found) {
        return;
    }
    for(int i = index; i < (mg -> _pool_size - 1); i++) {
        mg -> _pool[i] = mg -> _pool[i + 1];
    }
    for(int i = 0; i < (mg -> _pool_size - 1); i++) {
        tmp[i] = mg -> _pool[i];
    }
    mg -> _pool = tmp;
    mg -> _pool_size --;
}

void CMemoryMananger_destroy(CMemoryMananger** mg) {
    if((*mg) -> _pool_size == 0) {
        return;
    }
    for(int i = 0; i < (*mg) -> _pool_size; i++) {
        free((*mg) -> _pool[i]);
    }
    free((*mg) -> _pool);
    free((*mg));
    *mg = NULL;
}
