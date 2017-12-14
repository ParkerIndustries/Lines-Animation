#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

int main(int ac, char **av)
{
    FILE *fp;
    int c;
    int milisec = 10; // Length of time to sleep, in miliseconds
	struct timespec req = {0};
	req.tv_sec = 0;
	req.tv_nsec = milisec * 1000000L;

    fp = fopen(av[1], "r"); // error check this!

    // This while-statement assigns into c, and then checks against EOF:

    while((c = fgetc(fp)) != EOF) {
        if (c > -1 && c < 127) {
            printf("%c", c);
            nanosleep(&req, (struct timespec *)NULL);
        }
    }

    fclose(fp);

    return 0;
}