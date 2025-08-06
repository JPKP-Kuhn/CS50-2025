height = 0
while True:
    try:
        height = int(input("Height: "))
    except ValueError:
        print("Height must be a number between 1 and 8")
    else:
        if (height > 0 and height < 9):
            break

if height == 1:
    print('#  #')
else:
    for i in range(1, height+1):
        print(' ' * (height-i), end='')
        print('#' * i, end='')
        print('  ', end='')
        print('#' * i)
