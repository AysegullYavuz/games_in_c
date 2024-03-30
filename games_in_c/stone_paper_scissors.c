#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int userChoice();
int computerChoice();
void result(int user, int computer);

int main() {
    int user, computer;

    printf("Stone (0), Paper (1), Scissors (2) - Please make your choice: ");
    user = userChoice();

    computer = computerChoice();

    result(user, computer);

    return 0;
}


int userChoice() {
    int choice;
    scanf("%d", &choice);
    return choice;
}

int computerChoice() {
    srand(time(NULL));
    return rand() % 3;
}

void result(int user, int computer) {
    printf("\nYou: ");
    switch (user) {
        case 0:
            printf("Stone\n");
            break;
        case 1:
            printf("Paper\n");
            break;
        case 2:
            printf("Scissors\n");
            break;
        default:
            printf("Invalid Choice\n");
            return;
    }

    printf("Computer : ");
    switch (computer) {
        case 0:
            printf("Stone\n");
            break;
        case 1:
            printf("Paper\n");
            break;
        case 2:
            printf("Scissors\n");
            break;
    }
    if (user == computer) {
        printf("\nDraw!\n");
    } else if ((user == 0 && computer == 2) || 
               (user == 1 && computer == 0) || 
               (user == 2 && computer == 1)) {
        printf("\nYou win!\n");
    } else {
        printf("\nComputer wins!\n");
    }
}

