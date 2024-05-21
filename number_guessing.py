import random
number= random.randint(1, 100)
guesses = 0
print("Try to guess the correct number from 1-100")
while True:
        try:
            guess = int(input("Enter your guess: "))
            guesses += 1
            if guess < number:
                print("Guess was too low,Go Again")
            elif guess > number:
                print("Guess was too high,Go Again")
            else:
                print("You have guessed the number in",guesses, "attempts.")
                break
        except ValueError:
            print("Invalid input.Enter a number.")
