#include <stdio.h>
#include <stdlib.h>
#include <time.h>
char computer(int, int, int);
int player(char, int, int, int);
int random();
int row(int, int, int);
int retry();
int main()
{
    int streak, win = 0, loss = 0;
    printf("START THE GAME\n");
    printf("ENTER WINNING STREAK\n");
    scanf("%d", &streak);
    row(win, loss, streak);
    return 0;
}

int row(int win, int loss, int streak)
{
    int num;
    char comp;
    if (win != streak & loss != streak)
    {
        num = random();
        comp = computer(num, win, loss);
        printf("YOU TURN\n");
        player(comp, win, loss, streak);
    }
    if (win == streak)
        printf("STREAK COMPLETED\n");
    else
        printf("BETTER LUCK NEXT TIME\n");
    retry();
}

int random()
{
    int number;
    srand(time(0));
    number = rand() % 10 + 1;
    return number;
}

char computer(int number, int win, int loss)
{
    char comp;
    if (number >= 0 & number < 3)
        comp = 'r';
    if (number >= 3 & number < 6)
        comp = 'p';
    if (number > 6 & number < 10)
        comp = 's';
    // printf("%c\n",comp);
    return comp;
}

int player(char comp, int win, int loss, int streak)
{
    char you;
    printf("TYPE \n");
    printf(" r for rock\n p for paper\n s for scissor\n");
    scanf("%s", &you);
    if (you == comp)
    {
        printf("DRAW\n");
    }
    if (you == 'p' & comp == 'r')
    {
        printf("YOU WIN\n");
        win++;
    }
    else if (you == 'r' & comp == 'p')
    {
        printf("YOU LOSS\n");
        loss++;
    }
    if (you == 'r' & comp == 's')
    {
        printf("YOU WIN\n");
        win++;
    }
    else if (you == 's' & comp == 'r')
    {
        printf("YOU LOSS\n");
        loss++;
    }
    if (you == 's' & comp == 'p')
    {
        printf("YOU WIN\n");
        win++;
    }
    else if (you == 'p' & comp == 's')
    {
        printf("YOU LOSS\n");
        loss++;
    }
    row(win, loss, streak);
}

int retry()
{
    char play;
    printf("WANT TO PLAY AGAIN ");
    printf("(y/n)\n");
    scanf("%s", &play);
    if (play == 'y' | play == 'Y')
    {
        printf("LETS BEGIN\n");
        main();
    }
    else
        printf("THANKYOU FOR PLAYING\n");
}