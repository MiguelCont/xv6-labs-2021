#include "defs.h"
#include "spinlock.h"
#include "semaphore.h"
#include "param.h"

struct {
    struct spinlock lock;
    struct semaphore sem[NSEM] //NSEM declared in param.h
} semtable;

void seminit(void){
    initlock(&semtable->lock, "semtable");
    for (int i = 0; i < NSEM; i++){
        initlock(&semtable->sem[i]->lock, "sem");
    }
}
//Returns index of empty index

int semalloc(semtable *semTable){
    int i = 0;
    for (i<NSEM; i++){
        if (semTable->sem[i] == NULL){
            return i;
        }
    }

    return -1;
}