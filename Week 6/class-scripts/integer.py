n = input("Input: ")
if n.isnumeric():
    print("Integrer.")
else:
    print("Not integer")

# Mas também de outra maneira:
try:
    n = int(input("Input: "))
except ValueError: # lidando com a exceção
    print("Not integer")
else:
    print("Integer")
