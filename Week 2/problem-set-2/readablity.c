#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>


int calc_words(string text){
  int words = 0;
  int inside_word = 0;

  for (int i = 0; text[i] != '\0'; i++){
    if (text[i] == ' ' || text[i] == '\n'){
      inside_word = 0;
    } else if (inside_word == 0){
      inside_word = 1;
      words++;
    }
  }
  return words;
}

int calc_sentences(string text) {
    int sentences = 0;
    for (int i = 0; text[i] != '\0'; i++) {
        if (text[i] == '.' || text[i] == '!' || text[i] == '?') {
            sentences++;
        }
    }
    return sentences;
}

int calc_letter(string text){
  int letters = 0;

  for (int i = 0, length = strlen(text); i < length; i++){
    if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z')){
      letters++;
    }
  }

  return letters;
}


double calc_average_letters(int letters, int words) {
    return (100.0 * letters) / words;
}

double calc_average_sentences(int sentences, int words) {
    return (100.0 * sentences) / words;
}

int main(){
  string text = get_string("Text: ");

  int words = calc_words(text);
  int sentences = calc_sentences(text);
  int letters = calc_letter(text);

  double index;

  double average_letter = calc_average_letters(letters, words);
  double average_sentences = calc_average_sentences(sentences, words);

  index = (0.0588 * average_letter - 0.296 * average_sentences - 15.8);

  printf("%f\n", index);
  if (index < 1) {
    printf("Before Grade 1\n");
  } else if (index >= 16) {
    printf("Grade 16+\n");
  } else {
    printf("Grade %.0f\n", index);
  }
}
