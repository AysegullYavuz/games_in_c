#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_WRONG_GUESS 8
#define MAX_WORD_LENGTH 15

int main() {
    char word[MAX_WORD_LENGTH];
    int wrongGuesses = 0;
    int correctGuesses = 0;

    printf("**Hangman Game**!\n");

    printf("\nEnter a word: ");
    scanf("%s", word);

    int wordLength = strlen(word);

    char guessedWord[wordLength + 1];
    for (int i = 0; i < wordLength; i++) {
        guessedWord[i] = '_';
    }
    guessedWord[wordLength] = '\0'; // Terminate the string

    while (wrongGuesses < MAX_WRONG_GUESS && correctGuesses < wordLength) {
        printf("\nWord: %s\n", guessedWord);
        printf("Guess a letter: ");
        char guess;
        scanf(" %c", &guess); // Take a letter guess from the user
        int isGuessCorrect = 0;

        for (int i = 0; i < wordLength; i++) {
            if (tolower(word[i]) == tolower(guess) && guessedWord[i] == '_') {
                guessedWord[i] = word[i];
                correctGuesses++;
                isGuessCorrect = 1;
            }
        }

        if (!isGuessCorrect) {
            wrongGuesses++;
            printf("Wrong guess! Remaining guesses: %d\n", MAX_WRONG_GUESS - wrongGuesses);
        }
    }

    if (correctGuesses == wordLength) {
        printf("\nCongratulations! You guessed the word correctly: %s\n", word);
    } else {
        printf("\nSorry! You've run out of guesses. The correct word was: %s\n", word);
    }

    return 0;
}

