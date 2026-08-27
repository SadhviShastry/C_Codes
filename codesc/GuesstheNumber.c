#include <stdio.h>
#include <stdlib.h>
#include <time.h> // Required for generating different random numbers each time
int main() {
int secretNumber, guess;
int attempts = 0;
// Seed the random number generator using current time
srand(time(NULL));
// Generate a random number between 1 and 100
secretNumber = (rand() % 100) + 1;
printf("=================================\n");
printf("Welcome to the Guess the Number game!\n");
printf("\nI have picked a number between 1 and 100. Try to guess it.\n");
printf("=================================\n");
do {
printf("Enter your guess: ");
scanf("%d", &guess);
attempts++;
if (guess > secretNumber) {
printf("Too high! Try a lower number.\n");
} else if (guess < secretNumber) {
printf("Too low! Try a higher number.\n");
} else {
printf("\nCongratulations! You guessed the number %d in %d attempts.\n",
secretNumber, attempts);
}
} while (guess != secretNumber); // Loop until the guess is correct
printf("=================================\n");
return 0;
}