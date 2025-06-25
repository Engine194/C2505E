#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *inputStringCallback(void *arg)
{
    char *inputStr = (char *)arg;
    printf("Start timer by press a key: \n");
    fgets(inputStr, 512, stdin);

    return NULL;
}

int main()
{
    // int initiate = 3;
    // while (initiate > 0)
    // {
    //     printf("\r%d", initiate);
    //     fflush(stdout);
    //     if (initiate == 0)
    //     {
    //         break;
    //     }
    //     initiate--;
    //     sleep(1);
    // }
    // printf("\rStart !");
    char inputStr[512];
    pthread_t inputThread;
    pthread_t countdownThread;

    pthread_create(&inputThread, NULL, inputStringCallback, inputStr);

    pthread_join(inputThread, NULL);

    printf("You input: %s", inputStr);

    return 0;
}
