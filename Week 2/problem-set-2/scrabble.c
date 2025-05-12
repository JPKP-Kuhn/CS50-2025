#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

string calc_points(string p1, string p2);
string lower_case(string word);

int main(void)
{

  string a = get_string("Player 1: ");
  string b = get_string("Player 2: ");
  string player1 = lower_case(a);
  string player2 = lower_case(b);

  string result = calc_points(player1, player2);
  printf("%s\n", result);
}

string lower_case(string word)
{
  for (int i = 0, length = strlen(word); i < length ; i++)
  {
      word[i] = tolower(word[i]);
  }
  return word;
}

string calc_points(string p1, string p2)
{
  int points1 = 0;
  int points2 = 0;

  char letters[26];
  for (int i = 0; i < 26; i++)
  {
    letters[i] = 'a' + i;
  }
  
  // pontuation for each letter
  int points[26] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3,
                    1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};


  // points for p1
  for (int i = 0, length = strlen(p1); i < length; i++)
  {
    char letter = p1[i];
    if (isalpha(letter))
    {
      int index = letter - 'a';
      points1 += points[index];
    }
  }

  // points for p2 
  for (int i = 0, length = strlen(p2); i < length; i++)
  {
    char letter = p2[i];
    if (isalpha(letter))
    {
      int index = letter - 'a';
      points2 += points[index];
    }
  }

  if (points1 > points2)
  {
    return "Player 1 wins!";
  }
  else if (points2 > points1)
  {
    return "Player 2 wins!";
  }
  else {
    return "Tie!";
  }

}
