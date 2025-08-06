def get_float(question):
    while True:
        try:
            n = float(input(question))
        except ValueError:
            print("Try again! Input must be a positive number")
        else:
            if n > 0:
                break
    return n


cash = get_float("Change: ") * 100
coins = 0
while cash > 0:
    if cash >= 25:
        cash -= 25
        coins += 1
    elif cash >= 10:
        cash -= 10
        coins += 1
    elif cash >= 5:
        cash -= 5
        coins += 1
    elif cash >= 1:
        cash -= 1
        coins += 1

print(coins)

