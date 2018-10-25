#include <stdio.h>
#include <stdbool.h>

typedef struct Letter
{
    char letter;
    bool ud;
    bool lr;
    bool center;
} Letter;

void set_letter(Letter *letters, char letter, bool ud, bool lr, bool center)
{
    letters[letter - 'A'].letter = letter;
    letters[letter - 'A'].ud = ud;
    letters[letter - 'A'].lr = lr;
    letters[letter - 'A'].center = center;
}
int main()
{
    Letter letters[26];
    set_letter(letters, 'A', false, true, false);
    set_letter(letters, 'B', true, false, false);
    set_letter(letters, 'C', true, false, false);
    set_letter(letters, 'D', true, false, false);
    set_letter(letters, 'E', true, false, false);
    set_letter(letters, 'F', false, false, false);
    set_letter(letters, 'G', false, false, false);
    set_letter(letters, 'H', true, false, false);
    set_letter(letters, 'I', true, true, true);
    set_letter(letters, 'J', false, false, false);
    set_letter(letters, 'K', true, false, false);
    set_letter(letters, 'L', false, false, false);
    set_letter(letters, 'M', false, true, false);
    set_letter(letters, 'N', false, false, true);
    set_letter(letters, 'O', true, true, true);
    set_letter(letters, 'P', false, false, false);
    set_letter(letters, 'Q', false, false, false);
    set_letter(letters, 'R', false, false, false);
    set_letter(letters, 'S', false, false, true);
    set_letter(letters, 'T', false, true, false);
    set_letter(letters, 'U', false, true, false);
    set_letter(letters, 'V', false, true, false);
    set_letter(letters, 'W', false, true, false);
    set_letter(letters, 'X', true, true, true);
    set_letter(letters, 'Y', false, true, false);
    set_letter(letters, 'Z', false, false, true);
    char chr;
    scanf("%c", &chr);
    if (letters[chr - 'A'].ud)
        printf("up-down\n");
    if (letters[chr - 'A'].lr)
        printf("left-right\n");
    if (letters[chr - 'A'].center)
        printf("center\n");
    if (!(letters[chr - 'A'].ud || letters[chr - 'A'].lr || letters[chr - 'A'].center))
        printf("common\n");
    return 0;
}