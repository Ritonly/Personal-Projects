
#include <stdio.h>
enum choice
{
    ROCK,
    PAPER,
    SCISSORS
};
typedef enum choice Choice;
Choice get_choice(void);
Choice get_choice2(void);
void clear_keyboard_buffer(void);
int user_wishes_to_continue(void);

int main(int argc, char *argv[])
{
    do
    {
        Choice p1 = get_choice();
        Choice p2 = get_choice2();
        if (p1 == ROCK && p2 == SCISSORS)
        {
            printf("Rock breaks Scissors. Player 1 wins\n");
        }
        else if (p1 == SCISSORS && p2 == PAPER)
        {
            printf("Scissors cuts Paper. Player 1 wins\n");
        }
        else if (p1 == PAPER && p2 == ROCK)
        {
            printf("Paper covers Rock. Player 1 wins\n");
        }
        else if (p2 == ROCK && p1 == SCISSORS)
        {
            printf("Rock breaks Scissors. Player 2 wins\n");
        }
        else if (p2 == SCISSORS && p1 == PAPER)
        {
            printf("Scissors cuts Paper. Player 2 wins\n");
        }
        else if (p2 == PAPER && p1 == ROCK)
        {
            printf("Paper covers Rock. Player 2 wins\n");
        }
        else
        {
            printf("Draw,nobody wins\n");
        }

    } while (user_wishes_to_continue());

    return 0;
}
Choice get_choice(void)
{
    char choice;
    int noc;
    printf("Player 1, it is your turn.\n");
    printf("Please choose (r)ock, (p)aper, (s)cissors: ");
    noc = scanf(" %c", &choice);
    clear_keyboard_buffer();

    while (noc != 1 || choice != 'r' && choice != 's' && choice != 'p' && choice != 'R' && choice != 'S' && choice != 'P')
    {
        printf("I'm sorry, you must enter 'r', 'p', or 's':\n");
        printf("Please choose (r)ock, (p)aper, (s)cissors: ");
        noc = scanf(" %c", &choice);
        clear_keyboard_buffer();
    }
    switch (choice)
    {
    case 'R':
    case 'r':
        return ROCK;
    case 'P':
    case 'p':
        return PAPER;
    case 'S':
    case 's':
        return SCISSORS;
    default:
        return 0;
    }
}
Choice get_choice2(void)
{
    char choice;
    int noc;
    printf("Player 2, it is your turn.\n");
    printf("Please choose (r)ock, (p)aper, (s)cissors: ");
    noc = scanf(" %c", &choice);
    clear_keyboard_buffer();
    while (noc != 1 || choice != 'r' && choice != 's' && choice != 'p' && choice != 'R' && choice != 'S' && choice != 'P')
    {
        printf("I'm sorry, you must enter 'r', 'p', or 's':\n");
        printf("Please choose (r)ock, (p)aper, (s)cissors: ");
        noc = scanf(" %c", &choice);
        clear_keyboard_buffer();
    }
    switch (choice)
    {
    case 'R':
    case 'r':
        return ROCK;
    case 'P':
    case 'p':
        return PAPER;
    case 'S':
    case 's':
        return SCISSORS;
    default:
        return 0;
    }
}
void clear_keyboard_buffer(void)
{
    char c;
    scanf("%c", &c);
    while (c != '\n')
    {
        scanf("%c", &c);
    }
}
int user_wishes_to_continue(void)
{
    char answer;
    printf("Do you wish to continue? (y/n):\n");
    scanf(" %c", &answer);
    clear_keyboard_buffer();
    while (answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N')
    {
        printf("Im sorry i do not understand,you must enter 'y' or 'n'\n");
        printf("Do you wish to continue? (y/n):");
        scanf(" %c", &answer);
        clear_keyboard_buffer();
    }
    return answer == 'y' || answer == 'Y';
}
