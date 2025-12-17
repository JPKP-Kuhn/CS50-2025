from cs50 import SQL

db = SQL("sqlite:///favorites.db")

favorite = input("Favorite Language: ")

# List od rows as response
rows = db.execute("SELECT COUNT(*) AS n FROM favorites WHERE language = ?", favorite)
row = rows[0]

print(row["n"])
