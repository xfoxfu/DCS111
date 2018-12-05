#include <stdio.h>
#include <string.h>

typedef struct
{
    char name[15];
    char capital[15];
} State;

const State states[] = {
    {"Alabama", "Montgomery"},
    {"Alaska", "Juneau"},
    {"Arizona", "Phoenix"},
    {"Arkansas", "Little Rock"},
    {"California", "Sacramento"},
    {"Colorado", "Denver"},
    {"Connecticut", "Hartford"},
    {"Delaware", "Dover"},
    {"Florida", "Tallahassee"},
    {"Georgia", "Atlanta"},
    {"Hawaii", "Honolulu"},
    {"Idaho", "Boise"},
    {"Illinois", "Springfield"},
    {"Maryland", "Annapolis"},
    {"Minnesota", "Saint Paul"},
    {"Iowa", "Des Moines"},
    {"Maine", "Augusta"},
    {"Kentucky", "Frankfort"},
    {"Indiana", "Indianapolis"},
    {"Kansas", "Topeka"},
    {"Louisiana", "Baton Rouge"},
    {"Oregon", "Salem"},
    {"Oklahoma", "Oklahoma City"},
    {"Ohio", "Columbus"},
    {"North Dakota", "Bismark"},
    {"New York", "Albany"},
    {"New Mexico", "Santa Fe"},
    {"New Zersey", "Trenton"},
    {"New Hampshire", "Concord"},
    {"Nevada", "Carson City"},
    {"Nebraska", "Lincoln"},
    {"Montana", "Helena"},
    {"Missouri", "Jefferson City"},
    {"Mississippi", "Jackson"},
    {"Massachusettes", "Boston"},
    {"Michigan", "Lansing"},
    {"Pennslyvania", "Harrisburg"},
    {"Rhode Island", "Providence"},
    {"South Carolina", "Columbia"},
    {"South Dakota", "Pierre"},
    {"Tennessee", "Nashville"},
    {"Texas", "Austin"},
    {"Utah", "Salt Lake City"},
    {"Vermont", "Montpelier"},
    {"Virginia", "Richmond"},
    {"Washington", "Olympia"},
    {"West Virginia", "Charleston"},
    {"Wisconsin", "Madison"},
    {"Wyoming", "Cheyenne"},
};
const char null_captial[] = "";

const char *get_capital(char *state)
{
    for (int i = 0; i < sizeof(states) / sizeof(State); i++)
        if (strcmp(state, states[i].name) == 0)
            return states[i].capital;
    return null_captial;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        char state[15];
        char capital[15];
        scanf("%s%s", state, capital);
        const char *correct_captial = get_capital(state);
        if (strcmp(correct_captial, capital) == 0)
            printf("Your answer is correct.\n");
        else
            printf("The capital of %s is %s.\n", state, correct_captial);
    }
    return 0;
}