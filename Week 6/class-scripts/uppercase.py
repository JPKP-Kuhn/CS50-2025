before = input("Before: ")
# Would be like this in C
print("After: ", end='')
for c in before:
    print(c.upper(), end='')
print()

# But in python can be just this:
print(f"After: {before.upper()}")
