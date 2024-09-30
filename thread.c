#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
// put the appropriate extentios for pthread to work

void *thread_function(void *arg)
{
    printf("Inside Thread\n");
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", i);
        sleep(1);
    }
    printf("Thread Finished\n");
    pthread_exit(NULL);
}

int main()
{
    pthread_t a_thread;

    // Create the thread
    if (pthread_create(&a_thread, NULL, thread_function, NULL) != 0)
    {
        fprintf(stderr, "Error creating thread\n");
        return 1; // Exit if thread creation fails
    }
    printf("Thread Created\n");

    // Wait for the thread to finish
    if (pthread_join(a_thread, NULL) != 0)
    {
        fprintf(stderr, "Error joining thread\n");
        return 2; // Exit if thread join fails
    }
    printf("Thread Joined\n");

    printf("Inside Main Program\n");
    for (int j = 20; j < 25; j++)
    {
        printf("%d\n", j);
        sleep(1);
    }

    return 0;
}
