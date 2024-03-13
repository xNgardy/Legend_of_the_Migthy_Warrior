/*
Please develop a game using the C language. The choices made by the player throughout the game should have an impact on the game's ending.
Additionally, the items obtained as a result of these choices should be stored in a list structure, with each item requiring a separate memory location.
To achieve this, you need to create list nodes within a separate function.
This function should accept the names of the items through a pointer pointer parameter.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

typedef struct itemCheck {
    int item;
    struct itemCheck* next;
} itemNode;

void beginJourney(const char* title);
itemNode* itemNodeCreator(itemNode* node, int **itemNum);
int chapters(int chapterNum, int * itemNum);

int main()
{
    char title[50];
    int choice;

    do{
        printf("!!WELCOME TO THE STORY OF THE MIGHTY WARRIOR!!\n");
        printf("Please name your Warrior: ");
        scanf("%s", title);
        beginJourney(title);
        printf("Please enter 1 if you want to start over, -1 to exit: ");
        scanf("%d", &choice);

    }while(choice != -1);
    
    return 0;
}

void beginJourney(const char* title)
{
    int chapterResult, chapterNum = 1, itemNum = 0;
    printf("***You are beginning your journey %s !***\n\n", title);
    printf("You had always dreamt of becoming a royal knight in the kingdom.\n");
    printf("After years of training, you finally gathered the courage to face the king.\n");
    printf("However, a fearsome dragon named Elden Dragon suddenly appeared, threatening the kingdom.\n");
    printf("To prove your worth and earn the title of a royal knight,\n");
    printf("you embarked on a challenging journey to defeat the dragon and fulfill your destiny.\n");

    do{
        chapterResult = chapters(chapterNum, &itemNum);
        chapterNum = chapterResult;

    } while (chapterResult != -1);

}

itemNode* itemNodeCreator(itemNode* root, int **itemNum)
{
    if (root == NULL)
    {
        root = (itemNode*)malloc(sizeof(itemNode));
        root->next = NULL;
        root->item = **itemNum;
        
        return root;
    }
    else
    {
        root -> next = (itemNode*)malloc(sizeof(itemNode));
        root -> next -> item = **itemNum;
        root -> next -> next = NULL;
        return root -> next;

    }
}

int chapters(int chapNum, int *itemNum)
{
    int choice, questAnswer;
    itemNode* root = NULL;

    srand(time(NULL));

    if (chapNum == 1)
    {
        printf("Armed with your trusted weapons, you start your journey.\n");
        printf("After a week, you come to a crossroads with two paths:\n");
        printf("Now, you must decide which path to take.\n");
        printf("\n1. Swamp road\n");
        printf("\n2. Mountain cliff\n");
        
        printf("\nEnter your choice (1 or 2): ");
    
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nOh no, you sinked to the swamp because of your heavy armour!!! You pathetically died from drowning in mud.\n");
            printf("GAME OVER!!\n");
            return -1;
        }
        else if (choice == 2)
        {
            printf("\nDespite the dangerous appearance of the mountain cliff, you managed to pass the obstacles very quickly!\n");
            return 2;
        }
    }
    else if (chapNum == 2)
    {
        printf("\nAfter days of journeying, you finally arrive at a bridge guarded by a troll.\n");
        printf("The troll looks at you and grins, saying, \"Yu wan to pass! Yu anser ma queston!\"\n");
        printf("Considering that you are the mighty warrior, it seems unlikely that the troll could defeat you.\n");
        printf("Should you take a chance and try to answer the troll's question or simply eliminate the troll instead?\n");
        printf("\n1. Eliminate the troll.\n");
        printf("\n2. Take a chance and answer the troll's question.\n");
        

        printf("\nEnter your choice (1 or 2): ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nYou killed the troll quickly. What a waste of time!\n");
            return 3;
        }
        else if (choice == 2)
        {
            printf("\nTroll asks:\nMe spek without a mout and heer without ears. I have no body, but I come alive wit wind. Wat am I?\n");
            printf("\n 1 - Echo\n 2 - Shadow\n");
            printf("\nEnter your choice (1 or 2): ");
            scanf("%d", &questAnswer);

            if (questAnswer == 1)
            {
                printf("\nYou simply answered the question! You are truly a mighty riddle solver!\n");
                printf("The troll allowed you to pass the bridge, and while crossing, you witnessed a tragic accident.\n");
                printf("The troll accidentally fell from the bridge and perished.\n");
                printf("Seizing the opportunity, you quickly looted the troll's strong skin to fashion a sturdy shield!\n");
                printf("YAYY!! You got an item called Strudy Shield!!.\n");
                (*itemNum)++;
                root = itemNodeCreator(root, &itemNum);
                printf("You have %d item in your inventory now! \n", root -> item);
                return 3;
            }
            else if (questAnswer == 2)
            {
                printf("\nWith your wrong answer, a cunning troll appeared and mercilessly mocked you.\n");
                printf("Feeling disheartened, you made the impulsive choice to abandon your journey\n");
                printf("and instead focused on studying riddle books.\n");
                printf("Tragically, during your absence, the fearsome dragon ravaged the kingdom,\n");
                printf("leaving behind a trail of destruction.\n");
                printf("\n");
                printf("GAME OVER!!\n");
                return -1;
            }
        }
    }
    else if (chapNum == 3)
    {
        printf("\nAs you continue on your journey, you come across a merchant engaged in a heated confrontation.\n");
        printf("The merchant seems to be in trouble and is arguing with another man.\n");
        printf("Now, you must decide whether to intervene and help or simply pass by without interfering.\n");
        printf("What will you do?\n");
        printf("\n1. Pass by without interfering and continue your journey.\n");
        printf("\n2. Intervene and offer assistance to the wounded merchant.\n");
        
        printf("\nEnter your choice (1 or 2): ");

        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nYou decided to leave the merchant and the man alone.\n");
            return 4;
        }
        else if (choice == 2)
        {
            printf("\nUpon closer inspection, you notice that the merchant is wielding an iron cleaver, while the other man has visible bruises on his leg.\n");
            printf("Now faced with this additional information, you must make a decision on whether to help the merchant or the injured man.\n");
            printf("What will you do?\n");
            printf("\n1. Fight against the merchant.\n");
            printf("\n2. Fight against the man.\n");
            printf("\nEnter your choice (1 or 2): ");
            scanf("%d", &questAnswer);

            if (questAnswer == 1)
            {
                printf("\nIt turns out that the merchant is a slave merchant! You defeated the merchant with the help of a man, and as a token of gratitude, the man gave you a life elixir.\n");
                printf("YAYY!! You got an item called Life Elixir!!.\n");
                (*itemNum)++;
                root = itemNodeCreator(root, &itemNum);
                printf("You have %d item in your inventory now! \n", root -> item);
                return 4;
            }
            else if (questAnswer == 2)
            {
                printf("\nAfter defeating the injured man, you learned that the merchant wants to sell him to the faraway kingdoms.\n");
                printf("Upon discovering this, you realized that you cannot transition from evil to good and maintain your principles.\n");
                printf("Consequently, you abandoned your title and instead opened a tavern, patiently awaiting the dragon's arrival.\n");
                printf("GAME OVER!!\n");
                return -1;
            }
        }
    }
    else if (chapNum == 4)
    {
        printf("\nYou came across to an Arena!. Will you join to show your power, or pass it?\n");
        printf("\n1. Fight in the Arena.\n");
        printf("\n2. Pass the Arena.\n");
        printf("\nEnter your choice (1 or 2): ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nYou joined to the Arena!!\n");
            root = itemNodeCreator(root, &itemNum);

            if (root != NULL && root -> item >= 1)
            {
                printf("\nYou succesfully defeated all of your opponents in the Arena! Hurray!\n ");
                printf("YAYY!! You got an item called Arena Sword!!.\n");
                (*itemNum)++;
                root = itemNodeCreator(root, &itemNum);
                printf("You have %d item in their inventory now! \n", root -> item);
                return 5;
            }
            else
            {
                printf("\nYou simply died during the first fight. Poor you!\n");
                printf("GAME OVER!!\n");
                return -1;
            }
        }
        else if (choice == 2)
        {
            printf("\nYou didn't join the Arena\n");
            return 5;
        }
    }
    else if (chapNum == 5)
    {
        printf("\nBefore reaching the final path to the dragon's nest, you come across a three-headed giant dog. It glares at you with anger. What will you do?\n");
        printf("\n1. Fight.\n");
        printf("\n2. Flee.\n");
        printf("\nEnter your choice (1 or 2): ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            printf("\nYou killed the poor doggo without hesitating :(\n");
            return 6;
        }
        else if (choice == 2)
        {
            printf("\nAfter attempting to escape, you realize that the dog only wants to play with you!\n");
            printf("You spend an hour playing with the giant dog, and you both have a great time.\n");
            printf("As a token of friendship, the dog gives you his enchanted bone to protect you from the dragon.\n");
            printf("What a cutie!\n");
            printf("Now equipped with the enchanted bone, you feel a newfound confidence.\n");
            printf("YAYY!! You got an item called Enhanced Bone!!.\n");
            (*itemNum)++;
            root = itemNodeCreator(root, &itemNum);
            printf("You have %d item in their inventory now! \n", root -> item);
            return 6;
        }
    }
    else if (chapNum == 6)
    {
        printf("\nThe time has come; you are ready to face the Elden Dragon. Your decisions throughout the journey may have an effect on the outcome of the fight.\n");
        printf("\n");
        root = itemNodeCreator(root, &itemNum);
        int bossFightResult = 0;

        if (root ->item == 0)
        {
            printf("\nDue to your poor decisions, the Elden Dragon easily defeated you!\n");
            printf("GAME OVER!!\n\n");
            return -1;
        }
        else if (root->item == 1)
        {
            bossFightResult = rand() % 4 + 1;
            printf("Dice rolled to: %d\n", bossFightResult);

            if (bossFightResult == 4)
            {
                printf("\nDespite of your poor desicions, you somewhat managed to defeat the Elden Dragon!\n");
                printf("YOU WIN!!\n");
                printf("Your Score: Bronze\n\n");
                return -1;
            }
            else
            {
                printf("\nThe Elden Dragon has defeated you :(\n");
                printf("GAME OVER!!\n\n");
                return -1;
            }
        }
        else if (root->item == 2)
        {
            bossFightResult = rand() % 4 + 1;
            printf("Dice rolled to: %d\n", bossFightResult);

            if (bossFightResult == 4 || bossFightResult == 3)
            {
                printf("\nWith your great bravery, you managed to defeat the Elden Dragon!\n");
                printf("YOU WIN!!\n");
                printf("Your Score: Silver\n\n");
                return -1;
            }
            else
            {
                printf("\nThe Elden Dragon has defeated you :(\n");
                printf("GAME OVER!!\n\n");
                return -1;
            }
        }
        else if (root->item == 3)
        {
            bossFightResult = rand() % 4 + 1;
            printf("Dice rolled to: %d\n", bossFightResult);

            if (bossFightResult == 1)
            {
                printf("\nAww so close, The Elden Dragon has defeated you :(\n");
                printf("GAME OVER!!\n\n");
                return -1;
            }
            else
            {
                printf("\nYou achieved a tremendous victory by defeating the Elden Dragon!\n");
                printf("The entire kingdom now knows your name, and you have finally earned the position of the royal guard.\n");
                printf("To honor your heroic deeds, the king has commissioned a statue of you in the capital city.\n");
                printf("What a glorious achievement!\n");
                printf("Your bravery and valor will be remembered for generations to come.\n");
                printf("YOU WIN!!\n");
                printf("Your Score: Gold\n\n");
                return -1;
            }
        }
        else if (root->item == 4)
        {
            printf("\nYou defeated the Elden Dragon with just one punch! What are you? A One-Punch Warrior?\n");
            printf("The incredible glory of your victory resonates throughout the entire kingdom.\n");
            printf("The fear of you defeating every soldier within the realm leads the king to pass his title to you.\n");
            printf("You are now the king! You are the mighty One-Punch Riddle Warrior known throughout the world!\n");
            printf("YOU WIN!!\n");
            printf("Your Score: Platinium\n\n");
            return -1;
        }
    }

    return 0;
}