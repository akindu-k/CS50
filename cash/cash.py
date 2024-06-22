#from cs50 import get_float


def main():
    while (True):
        cents = float(input("Change Owed: "))
        if (cents > 0):
            calculate(cents*100)
            break


def calculate(cents):
    quarters = calculate_quarters(cents)

    cents -= 25 * quarters
    dimes = calculate_dimes(cents)
    cents -= 10 * dimes
    nickels = calculate_nickels(cents)
    cents -= 5 * nickels
    pennies = calculate_pennies(cents)

    print(quarters + dimes + nickels + pennies)


def calculate_quarters(cents):
    quarters = 0
    while (cents >= 25):

        quarters += 1
        cents = cents - 25
    #print(quarters)
    return quarters


def calculate_dimes(cents):
    #global dimes
    dimes = 0
    while (cents >= 10):

        dimes += 1
        cents -= 10
    #print(dimes)
    return dimes


def calculate_nickels(cents):
    #global nickels
    nickels = 0
    while (cents >= 5):

        nickels += 1
        cents -= 5
    #print(nickels)
    return nickels


def calculate_pennies(cents):
    #global pennies
    pennies = 0
    while (cents >= 1):
        pennies += 1
        cents -= 1
    #print(pennies)
    return pennies


main()
