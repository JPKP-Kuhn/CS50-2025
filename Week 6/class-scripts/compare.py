print("Comparing int")
x = int(input("Value for x: "))
y = int(input("Value for y: "))

if x < y:
    print("x is less than y")
elif x > y:
    print("x is greater than y")
else:
    print("x is equal to y")


print("Comparing str")
s = input("s: ")
t = input("t: ")
if s == t:
    print("Same")
else:
    print("Different")

c = input("Do you agree? ").lower()
if c in ['y', 'yes']:
    print("Agreed")
elif c in ['n', 'no']:
    print("Not agreed")
