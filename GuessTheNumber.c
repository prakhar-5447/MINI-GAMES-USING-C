#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int game(int);
int retry();

int main()
{
    int number;
    srand(time(0));
    number=rand()%100+1;
    game(number);
    return 0;
}

int game(int number)
{
    int guess,count=1;
    // printf("THE RANDOM NUMBER IS %d\n",number);
    printf("GUESS THE CORRECT NUMBER\n");
    do {
        scanf("%d",&guess);
        if(guess>number)
            printf("THINK LOW VALUE\n");
        else if(guess<number)
            printf("THINK HIGH VALUE\n");
        else
            printf("YOU GUESS THE CORRECT NUMBER IN %d TURNS\n",count);
        count++;
    } while(guess!=number);
    retry(number);
}

int retry()
{   char play;
    printf("WANT TO PLAY AGAIN ");
    printf("(y/n)\n");
    scanf("%s",&play);
    if(play=='y' | play=='Y')
    {
        printf("LETS BEGIN\n");
        main();
    }
    else
        printf("THANKYOU FOR PLAYING\n");
}