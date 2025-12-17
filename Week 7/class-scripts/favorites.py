import csv

with open("favorites.csv", "r") as file:
    reader = csv.DictReader(file)
    # next(reader) # Pula uma linha da leitura
    # scratch, python, c = 0, 0, 0
    counts = {}

    for row in reader:
        favorite = row["language"]
        if favorite in counts:
            counts[favorite] += 1
        else:
            counts[favorite] = 1

        # if favorite == "Scratch":
        #     scratch+=1
        # elif favorite == "C":
        #     c+=1
        # elif favorite == "Python":
        #     python+=1
        #
        # print(favorite)

# print(f"Scratch: {scratch}")
# print(f"Python: {python}")
# print(f"C: {c}")

for favorite in sorted(counts, key=counts.get, reverse=True): # type: ignore
    print(f"{favorite}: {counts[favorite]}")

