#include "8_countPalindroms.h"

int isPalindrome(char *begin, char *end) {
  end--;
  while (end - begin > 0) {
    if (*begin != *end)
      return 0;

    begin++;
    end--;
  }
  return 1;
}

int countOfPalindrome(char *s) {
  WordDescriptor word;
  word.begin = s;
  int count = 0;
  char *endOfString = getEndOfString(s);
  if (endOfString == s)
    return 0;

  do {
    word.end = find(word.begin, endOfString, ',');
    count += isPalindrome(word.begin, word.end);
    word.begin = getBeginOfWord(word.end + 1);
  } while (word.end != endOfString);
  return count;
}

void test_countOfPalindrome_allPalindromes() {
  char c[] = "abba, boob, bib, ABOBA";
  ASSERT_INT(4, countOfPalindrome(c));
}

void test_countOfPalindrome_anyPalindromes() {
  char c[] = "abba, boob, CCCP, ABOBA";
  ASSERT_INT(3, countOfPalindrome(c));
}

void test_countOfPalindrome_noPalindromes() {
  char c[] = "no, one, Palindrome";
  ASSERT_INT(0, countOfPalindrome(c));
}

void test_countOfPalindrome() {
  test_countOfPalindrome_allPalindromes();
  test_countOfPalindrome_anyPalindromes();
  test_countOfPalindrome_noPalindromes();
}