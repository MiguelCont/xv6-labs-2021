struct spinlock;

struct semaphore{
    struct spinlock lock;
    int count;
    int valid; 
};

typedef int sem_t;

