#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int getUserChoice(){
    int userChoice;
    printf("Choose your weapon from the following:\n\t1.Rock\n\t2.Paper\n\t3.Scissors\n");

    while(1) {
        scanf("%d", &userChoice);

        if (userChoice==1 || userChoice==2 || userChoice==3){
            break;
        }

        printf("Invalid selection! please enter 1, 2 or 3\n");
    }

    return userChoice;
}

int getComputerChoice(){
    srand(time(0));
    int choice = rand() % 3;

    return choice+1;
}

void calcResult(int user, int computer){

    if (user == computer){
        printf("You both chose the same weapon\nIt's a draw!!\n");
    }

    if (user==1 && computer==2){
        printf("Rock is smothered by Paper\nYou lose!!\n");
    }
    if (user==1 && computer==3){
        printf("Rock smashes up Scissors\nYou win!!\n");
    }

    if (user==2 && computer==1){
        printf("Paper smothers Rock\nYou win!!\n");
    }
    if(user==2 && computer==3){
        printf("Paperis slashed up by Scissors\nYou lose!!\n");
    }

    if (user==3 && computer==1){
        printf("Scissors is smashed up by Rock\n You lose!!\n");
    }
    if (user==3 && computer==2){
        printf("Scissors slashes up Paper\nYou win!!\n");
    }
}

int main() {
    // get user choice and computer choice
    int userChoice = getUserChoice();
    int computerChoice = getComputerChoice();
    
    // display user choice
    char options[3][9] = {"Rock", "Paper", "Scissors"};
    printf("\n%s vs ", options[userChoice-1]);
    fflush(stdout);

    // build tension
    sleep(1);
    printf("\r%s vs .", options[userChoice-1]);
    fflush(stdout);
    sleep(1);
    printf("\r%s vs ..", options[userChoice-1]);
    fflush(stdout);
    sleep(1);
    printf("\r%s vs ...", options[userChoice-1]);
    fflush(stdout);
    sleep(1);

    // display computer choice
    printf("\r%s vs %s\n\n", options[userChoice-1], options[computerChoice-1]);
    sleep(1);

    // display result
    calcResult(userChoice, computerChoice);

    return 0;
}