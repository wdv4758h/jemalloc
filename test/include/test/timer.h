/* Simple timer, for use in benchmark reporting. */

#include <unistd.h>
#include <sys/time.h>

#define JEMALLOC_CLOCK_GETTIME defined(_POSIX_MONOTONIC_CLOCK) \
    && _POSIX_MONOTONIC_CLOCK >= 0

typedef struct {
#if JEMALLOC_CLOCK_GETTIME
	struct timespec tv0;
	struct timespec tv1;
	int clock_id;
#else
	struct timeval tv0;
	struct timeval tv1;
#endif
} timedelta_t;

void	timer_start(timedelta_t *timer);
void	timer_stop(timedelta_t *timer);
uint64_t	timer_usec(const timedelta_t *timer);
void	timer_ratio(timedelta_t *a, timedelta_t *b, char *buf, size_t buflen);
