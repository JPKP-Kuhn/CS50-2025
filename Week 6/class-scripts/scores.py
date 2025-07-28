scores = []

for i in range(3):
    score = int(input())
    scores.append(score)
    # ou pode ser scores += [score]

average = sum(scores)/ len(scores)
print(f"Average: {average:.2f}")
