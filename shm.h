#ifndef _SYS_SHM_H
#define _SYS_SHM_H

#include <linux/shm.h>
#include <stdint.h>
#include <sys/types.h>

typedef	int	key_t;			/* IPC key type		*/
/*
 * TEMP_FAILURE_RETRY is defined by some, but not all, versions of
 * <unistd.h>. (Alas, it is not as standard as we'd hoped!) So, if it's
 * not already defined, then define it here.
 */
#ifndef TEMP_FAILURE_RETRY
/* Used to retry syscalls that can return EINTR. */
#define TEMP_FAILURE_RETRY(exp) ({         \
    typeof (exp) _rc;                      \
    do {                                   \
        _rc = (exp);                       \
    } while (_rc == -1 && errno == EINTR); \
    _rc; })
#endif

__BEGIN_DECLS

/* Shared memory control operations. */
extern int shmctl(int shmid, int cmd, struct shmid_ds* buf);

/* Get shared memory area identifier. */
extern int shmget(key_t key, size_t size, int shmflg);

/* Attach shared memory segment. */
extern void *shmat(int shmid, void const* shmaddr, int shmflg);

/* Detach shared memory segment. */
extern int shmdt(void const* shmaddr);

__END_DECLS

#endif
