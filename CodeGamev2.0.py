from colorama import Fore

your_code = list(input("Input YOUR password: "))
while not len(your_code) == 4:
    your_code = list(input("Code must be 4 numbers. Try again: "))

guess_conversion = {
    1: "First",
    2: "Second",
    3: "Third",
    4: "Fourth",
    5: "Fifth",
    6: "Sixth",
    7: "Seventh",
    8: "Eighth",
    9: "Ninth",
    10: "Tenth",
    11: "Eleventh",
    12: "Twelfth",
    13: "Thirteenth",
    14: "Fourteenth",
    15: "Fifteenth",
    16: "Sixteenth",
    17: "Seventeenth",
    18: "Eighteenth",
    19: "Nineteenth",
    20: "Twentieth",
    21: "Twenty-First",
    22: "Twenty-Second",
    23: "Twenty-Third",
    24: "Twenty-Fourth",
    25: "Twenty-Fifth",
}

print(Fore.RED + "YOUR CODE: " + str(your_code))

win = 0
n = 1
s = 1
x = 1

while win == 0:
    their_guess = list(input(Fore.BLUE + "Their " + guess_conversion.get(n) + " guess was (\"s\" to skip): "))
    if their_guess[0].lower() == "s":
        if x == 1:
            print("The other player started first.")
            n -= 1
        else:
            print("You Skipped.")
    else:
        while not len(their_guess) == 4:
            their_guess = list(input("Code must be 4 numbers. Try again: "))
        i = 0
        count = 0
        while i < 4:
            if their_guess[i] == your_code[i]:
                count += 1
            i += 1
        if count == 4:
            print(Fore.GREEN + "WINNER! They guessed your code " + str(their_guess) + " in " + str(n) + " guesses!")
            break
        else:
            print("Their guess of " + str(their_guess) + " got " + str(count) + " correct.")
    your_guess = list(input(Fore.YELLOW + "What was your " + str(guess_conversion.get(s)) + " guess (\"s\" to skip): "))
    if your_guess[0].lower() == "s":
        print("You Skipped.")
    else:
        while not len(your_guess) == 4:
            your_guess = list(input("Code must be 4 numbers. Try again: "))
        guess_correct = int(input("How many correct did your guess get: "))
        if guess_correct == 4:
            print(Fore.GREEN + "WINNER! You guessed the code " + str(your_guess) + " in " + str(s) + " guesses!")
            break
        else:
            print(Fore.RED + "Your guess " + str(your_guess) + " got " + str(guess_correct) + " correct. ")
    n += 1
    s += 1
    x += 1

print("Thank you for playing!")
