# Não existe do while loop no python, mas pode ser feito assim:
while True:
    n = int(input("Height: "))
    if n > 0:
        break

for i in range(n):
    print('#')


for i in range(4):
    print('?', end='')
print()

print('?' * 4) # Mesma coisa

for i in range(3):
    print('#' * 3)
