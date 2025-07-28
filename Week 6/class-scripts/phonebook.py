names = ["Joao", "Maria", "Pedro"]

name = input("Name: ")

if name in names:
    print("Found")
else:
    print("Not found")

"""
for n in names:
    if name == n:
        print("Found")
        break
else:
    print("Not found")
"""

print("Now with dictionaries")
people = [
    {"name" : "Joao", "number" : "112399312"},
    {"name" : "Maria", "number" : "38482942"},
    {"name" : "Pedro", "number" : "32424242"}
]

name = input("Name: ")
for person in people:
    if person["name"] == name:
        number = person["number"]
        print(f"Found {number}")
        break
else:
    print("Not found")

people = {
    "Joao" : "112399312",
    "Maria" : "38482942",
    "Pedro" : "32424242"
}

name = input("Name: ")

if name in people:
    print(f"Number: {people[name]}")
else:
    print("Not found")

print("Now CSV files")

import csv

name = input("Name: ")
number = input("Number: ")

with open("phonebook.csv", "a") as file: # a significa append, o with não precisa colocar file.close()
    #writer = csv.writer(file)
    #writer.writerow([name, number])
    writer = csv.DictWriter(file, fieldnames=["name", "number"])
    writer.writerow({"name" : name, "number" : number})
