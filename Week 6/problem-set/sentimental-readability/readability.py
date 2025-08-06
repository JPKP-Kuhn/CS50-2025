def calc_letters(text):
    letters = 0
    for i in text:
        if i.isalpha():
            letters += 1

    return letters


def calc_words(text):
    words = 0
    inside_word = False

    for char in text:
        if char == ' ' or char == '\n':
            inside_word = False
        elif not inside_word:
            inside_word = True
            words += 1

    return words


def calc_sentences(text):
    sentences = 0
    for char in text:
        if char in ['.', '?', '!']:
            sentences += 1

    return sentences


if __name__ == "__main__":
    text = input("Text: ")

    tot_letters = calc_letters(text)
    tot_words = calc_words(text)
    tot_sentences = calc_sentences(text)

    average_letters = (100 * tot_letters) / tot_words
    average_sentences = (100 * tot_sentences) / tot_words

    liau = 0.0588 * average_letters - 0.296 * average_sentences - 15.8
    rliau = round(liau)
    if rliau >= 16:
        print("Grade 16+")
    elif rliau < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {round(liau)}")

