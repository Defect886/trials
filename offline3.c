#include <stdio.h>
int func_strlen(char str[]){
     int length=0;
     while(str[length]!='\0'){
        length++;
     }
     return length;
}

void func_strcpy(char nstr[], char str[] ){
    int i=0;
    while(str[i]!='\0'){
        nstr[i]=str[i];
        i++;
    }
    nstr[i]='\0';
}

int func_strcmp(char str1[], char str2[]){
    int i=0;
    while(str1[i]!='\0' && str2[i]!='\0'){
        if(str1[i]!=str2[i]){
            return str1[i]-str2[i];
        }
        i++;
    }
    return str1[i]-str2[i];
}

int func_substr(char str[], char subsr[]){
    int str_length=func_strlen(str);
    int subsr_length=func_strlen(subsr);
    for(int i=0; i<=str_length-subsr_length; i++){
        int found=1;
        for(int j=0; j<subsr_length; j++){
            if(str[i+j]!=subsr[j]){
                found=0;
                break;
            }
        }
        if(found==1){
            return 1;
        }
    }
        return 0;
    }


#define ROLL 2505080
#define PROFILE ((((ROLL - 1) * 37) / 370) * 19 + ((ROLL * 11 + 7) % 19)) / 19
#define ANAGRAM_INDEX (PROFILE % 3)
#define CIPHER_INDEX ((PROFILE / 3) % 3)
#define GUESS_INDEX ((PROFILE / 9) % 3)
#define SHIFT ((PROFILE % 23) + 3)

char anagram_word[3][20]={"listen", "earth", "binary"};
char caeser_phrases[3][50]={"there is a secret code", "attack at dawn", "meet me at the park"};
char word_guess[3][20]={"program", "network", "science"};

int anagram_solved = 0;
int caesar_solved = 0;
int word_solved = 0;

int number_rotate(char original[]){
    int L= func_strlen(original);
    int rotate_by=(PROFILE % (L - 1)) + 1;
    return rotate_by;
}

void rotate_left(char original[], char rotated[], int rotate_by) {
    int L = func_strlen(original);
    int i;
    for (i = 0; i < L; i++) {
        rotated[i] = original[(rotate_by + i) % L];
    }
    rotated[L] = '\0';
}


void display_menu() {
    printf("+=======================================+\n");
    printf("|              GAME WORLD               |\n");
    printf("|       Words, Ciphers, Victory         |\n");
    printf("+=======================================+\n");
    printf("1. Start Game\n");
    printf("2. Exit\n");
}


int anagram(){
    char word[20];
    char rotated[20];
    int score;

    func_strcpy(word, anagram_word[ANAGRAM_INDEX]);

    int rotate_by=number_rotate(word);
    rotate_left(word, rotated, rotate_by);

    printf("Starting Anagram Challenge...\n");
    printf("Scramble word : %s\n", rotated);

    int attempts=0, solve=0;
    char guess[20];
    while(attempts<3 && solve==0){
        printf("Your guess : ");
        scanf("%s", guess);
        if(func_strcmp(word, guess)==0){
            solve=1;
            attempts++;
            printf("Correct! You solved it in %d attempt(s).\n", attempts);
        }
        else{
            attempts++;
            printf("Incorrect! Try again.\n");
        }
    }

    if(solve==0){
        printf("You've run out of attempts! The correct word was: %s\n", word);
        score = 0;
    }
    else{
        int remaining=3-attempts;
        score=(remaining*10)+10;
        anagram_solved = 1;
    }
    while(getchar() != '\n');
    return score;
}

void caesar_encrypt(char input[], char output[], int rotate_by){
    int L= func_strlen(input);
    for(int i=0; i<L; i++){
        if(input[i]==' '){
            output[i]=' ';
        }
        else{
            output[i]=((input[i]-'a'+rotate_by)%26)+'a';
        }
    }
    output[L]='\0';
}

void caesar_decrypt(char input[], char output[], int rotate_by){
    int L= func_strlen(input);
    for(int i=0; i<L; i++){
        if(input[i]==' '){
            output[i]=' ';
        }
        else{
            output[i]=((input[i]-'a'-rotate_by+26)%26)+'a';
        }
    }
    output[L]='\0';
}

int caesar(){
    char phrase[50];
    char encrypted[50];
    int score = 0;

    func_strcpy(phrase, caeser_phrases[CIPHER_INDEX]);
    caesar_encrypt(phrase, encrypted, SHIFT);

    printf("Starting Caesar Cipher Challenge (Shift: %d)...\n", SHIFT);
    printf("Encrypted phrase : %s\n", encrypted);

    int attempts = 0, solve = 0;
    char guess[50];

    while(attempts < 3 && solve == 0){
        printf("Your guess : ");
        fgets(guess, sizeof(guess), stdin);

        int len = func_strlen(guess);
        if(guess[len-1] == '\n'){
            guess[len-1] = '\0';
        }

        if(func_strcmp(guess, phrase) == 0){
            solve = 1;
            attempts++;
            printf("Correct! You decrypted it in %d attempt(s).\n", attempts);
        }
        else{
            attempts++;
            printf("Incorrect! Try again.\n");
        }
    }

    if(solve == 0){
        printf("You've run out of attempts! The correct phrase was: %s\n", phrase);
        score = 0;
    }
    else{
        int remaining = 3 - attempts;
        score = (remaining * 10) + 10;
        caesar_solved = 1;
    }

    return score;
}

void show_hint(char word[]){
    int L = func_strlen(word);
    printf("Hint : ");
    for(int i = 0; i < L; i++){
        if(i < 3){
            printf("%c", word[i]);
        }
        else{
            printf("_");
        }
    }
    printf("\n");
}

int word_challenge(){
    char word[20];
    int score = 0;

    func_strcpy(word, word_guess[GUESS_INDEX]);

    printf("Starting Word Guessing Challenge...\n");
    show_hint(word);

    int attempts = 0, solve = 0;
    int used_substring = 0;   
    int used_length = 0;     
    int utility_uses = 0;    

        while(attempts < 3 && solve == 0){
        printf("Select an option : 1. Write Answer 2. Check Substring 3. Check Length\n");
        int option;
        scanf("%d", &option);
        while(getchar() != '\n');

        if(option == 1){
                    
            char guess[20];
            printf("Enter your guess : ");
            scanf("%s", guess);
            while(getchar() != '\n');

            attempts++;

            if(func_strcmp(guess, word) == 0){
                solve = 1;
            }
            else{
                printf("Incorrect! Try again.\n");
            }
        }
    
        else if(option == 2){
            if(used_substring == 1){
                printf("Error : utility function already used.\n");
            }
            else{
                char sub[20];
                printf("Enter substring : ");
                scanf("%s", sub);
                while(getchar() != '\n');

                used_substring = 1;
                utility_uses++;

                if(func_substr(word, sub) == 1){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
            }
        }
        
        else if(option == 3){
            if(used_length == 1){
                printf("Error : utility function already used.\n");
            }
            else{
                int len_guess;
                printf("Enter length : ");
                scanf("%d", &len_guess);
                while(getchar() != '\n');

                used_length = 1;
                utility_uses++;

                if(len_guess == func_strlen(word)){
                    printf("Yes\n");
                }
                else{
                    printf("No\n");
                }
            }
        }
    }

        if(solve == 0){
        printf("You've run out of attempts! The correct word was: %s\n", word);
        score = 0;
    }
    else{
        int remaining = 3 - attempts;
        score = (remaining * 10) + 10;
        score = score - (2 * utility_uses);

        if(utility_uses == 0){
            printf("Correct! You guessed it in %d attempt(s).\n", attempts);
        }
        else if(utility_uses == 1){
            printf("Correct! You guessed it in %d attempt(s) using one utility function.\n", attempts);
        }
        else{
            printf("Correct! You guessed it in %d attempt(s) using two utility functions.\n", attempts);
        }
        word_solved = 1;
    }
    return score;
}

int main(){
    int choice;
    display_menu();
    printf("Enter your choice :");
    scanf("%d", &choice);
    while(getchar() != '\n');
    if(choice==2){
        printf("Goodbye!\n");
        return 0;
    }

    if(choice==1){
        int total_score=0;
        total_score+=anagram();
        total_score += caesar();
        total_score += word_challenge();

        if(anagram_solved == 1 && caesar_solved == 1 && word_solved == 1){
    total_score += 5;
}
        printf("Game Over!\n");
        printf("Your total score : %d points\n", total_score);
    }
    return 0;
}