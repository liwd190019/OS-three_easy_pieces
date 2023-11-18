// a single read write lock
#include<semaphore.h>
#include<pthread.h>
#include<stdio.h>

// sem_wait: decrement the value of semaphore s by one, wait if
// value of semaphore s is negative

// sem_post: increment the value of semaphore s by one, 
// if there are one or more threads waiting, wake one

typedef struct _rwlock_t{
  sem_t lock; // binary semaphore (basic lock)
  sem_t writelock; // used to allow ONE writer or MANY readers
  int readers; // count of readers reading in critical sections
} rwlock_t;

void rwlock_init(rwlock_t *rw){
  rw->readers = 0;
  sem_init(&rw->lock, 0, 1); // initial value of rw->lock is 1
  sem_init(&rw->writelock, 0, 1); // initial value of rw->writelock is 1
}

void rwlock_acquire_readlock(rwlock_t *rw){
  // first acquire the lock and then increment readers variable to track
  // how many readers are currently inside the data structure
  sem_wait(&rw->lock);
  rw->readers++;
  if (rw->readers == 1){
    // when the first reader acquires the lock
    // the reader also acquires the write lock
    sem_wait(&rw->writelock);
  }
  // finally release the lock
  sem_post(&rw->lock);
}

void rwlock_release_readlock(rwlock_t *rw){
  sem_wait(&rw->lock);
  rw->readers--;
  if(rw->readers == 0){
    sem_post(&rw->writelock);
  }
  sem_post(&rw->lock);
}

void rwlock_acquire_writelock(rwlock_t *rw){
  sem_wait(&rw->writelock);
}

void rwlock_release_writelock(rwlock_t *rw){
  sem_post(&rw->writelock);
}

// readers can easily get more locks
// however writer should wait until all readers have finished read
// this is because the first reader holds a writelock, so writer
// can't access the contents until that reader returns the writelock