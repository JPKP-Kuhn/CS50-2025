import csv
import sys


def main():

    # TODO: Check for command-line usage
    if (len(sys.argv) != 3):
        print("Usage: python dna.py file.csv sequence-DNA.txt")
        return

    # TODO: Read database file into a variable
    rows = []
    with open(sys.argv[1], "r") as file:
        database = csv.DictReader(file)
        for row in database:
            rows.append(row)

    # TODO: Read DNA sequence file into a variable
    dna_sequence = 0
    with open(sys.argv[2], "r") as file:
        dna_sequence = file.read()

    # TODO: Find longest match of each STR in DNA sequence
    found_matches = dict()
    for i in range(len(rows)):
        for k in rows[i].keys():
            if k != "name":
                found_matches[k] = longest_match(dna_sequence, k)

    # TODO: Check database for matching profiles
    for row in rows:
        name = row["name"]
        match = 0
        for k, v in found_matches.items():
            if int(row[k]) == v:
                match += 1
        if match == len(found_matches):
            print(name)
            return

    print("No match")
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()

