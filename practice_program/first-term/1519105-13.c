#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

#define winMessage "勝ち"
#define lossMessage "負け"

int promptHand()
{
    int hand;
    printf("(0)ぐー (1)チョキ (2)パー\n");
    scanf("%d", &hand);
    if (hand >= 3)
    {
        printf("Invalid hand:");
        return 3;
    }
    return hand;
}

int genHand(void)
{
    srand((unsigned)time(NULL));
    return rand() % 3;
}
/* 
char judge(int comHand, int userHand)
{
    char *notif;
    // if (comHand == 0)
    // {
    //     return (userHand == 2) ? "勝ち" : "負け";
    // }
    // if (comHand == 1)
    // {
    //     return (userHand == 0) ? "勝ち" : "負け";
    // }
    // if (comHand == 2)
    // {
    //     return (userHand == 1) ? "勝ち" : "負け";
    // }

    if (comHand == 0)
    {
        notif = (userHand == 2) ? winMessage : lossMessage;
    }
    if (comHand == 1)
    {
        notif = (userHand == 0) ? winMessage : lossMessage;
    }
    if (comHand == 2)
    {
        notif = (userHand == 1) ? winMessage : lossMessage;
    }
    return notif;
}
 */
int main(void)
{
    while (1)
    {
        int hand = promptHand();
        printf("あなた:%d\n", hand);
        int comHand = genHand();
        printf("コンピュータ:%d\n", comHand);
        if (hand == 3)
        {
            printf("お手つきです\n");
            return 0;
        }

        if (comHand == hand)
        {
            printf("あいこ\n");
        }
        else
        {
            char *message;
            if (comHand == 0)
            {
                message = (hand == 2) ? winMessage : lossMessage;
            }
            if (comHand == 1)
            {
                message = (hand == 0) ? winMessage : lossMessage;
            }
            if (comHand == 2)
            {
                message = (hand == 1) ? winMessage : lossMessage;
            }
            printf("あなたの%sです\n", message);
            break;
        }
    }
}
