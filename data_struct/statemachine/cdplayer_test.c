#include "cdplayer.h"
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void TEST1()
{
    printf("this is test one:\n");
    initialize();
    onPlayOrPause();
    onPlayOrPause();
    onPlayOrPause();
}

void TEST2()
{
    printf("this is test two:\n");
    initialize();
    onPlayOrPause();
    onStop();
}

void TEST3()
{
    printf("this is test three:\n");
    initialize();
    onPlayOrPause();
    onPlayOrPause();
    onStop();
}

int main(int argc, char** argv)
{
    TEST1();
    TEST2();
    TEST3();
    return 0;
}
