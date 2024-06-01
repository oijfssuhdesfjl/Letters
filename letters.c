#include <stdio.h>
#include <string.h>
#include <ctype.h>

int count_characters(const char* str) {
    return strlen(str);
}

int count_letters(const char* str) {
    int count = 0;
    while (*str) {
        if (isalpha(*str)) {
            count++;
        }
        str++;
    }
    return count;
}

int count_words(const char* str) {
    int count = 0;
    while (*str) {
        if (*str == ' ') {
            count++;
        }
        str++;
    }
    return count + 1; // +1 for the last word
}

double average_word_length(const char* str) {
    int letters = count_letters(str);
    int words = count_words(str);
    return (double)letters / words;
}

void capitalize_first_letter(char* str) {
    int in_word = 0;
    while (*str) {
        if (!in_word && isalpha(*str)) {
            *str = toupper(*str);
            in_word = 1;
        } else if (in_word && *str == ' ') {
            in_word = 0;
        } else {
            *str = tolower(*str);
        }
        str++;
    }
}

int main() {
    char phrase[1000];

    printf("phrase: ");
    fgets(phrase, sizeof(phrase), stdin);
    phrase[strcspn(phrase, "\n")] = '\0'; // Remove trailing newline

    int characters = count_characters(phrase);
    int letters = count_letters(phrase);
    int words = count_words(phrase);
    double avg_word_length = average_word_length(phrase);
    capitalize_first_letter(phrase);

    printf("characters: %d\n", characters);
    printf("letters: %d\n", letters);
    printf("words: %d\n", words);
    printf("average word length: %.3f\n", avg_word_length);
    printf("%s\n", phrase);

    return 0;
}