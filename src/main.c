#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "FileIO.h"

int main()
{
    int L;
    printf("Enter minimum lengths of names: ");
    scanf("%d", &L);

    touch("s.stl");
    char* cmd;
    char* name;
    char nameArray[2048];
    double R;
    cmd = malloc(4096);
    while (1)
    {

        sprintf(cmd, "./StringCreate s.stl --stopX -l %d > name.txt", L);
        system(cmd);

        name = fileContents("name.txt"); //Will include newline
        printf("Rate the following name: %sRating [-1 to 1 or Ctrl-C to quit]: ", name);
        name[strlen(name)-1] = 'X';
        scanf("%f", &R);

        sprintf(cmd, "./StringLearn %s -r %f -s s.stl", name, R);
        system(cmd);
    }
}
