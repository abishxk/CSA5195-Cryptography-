//ceasar cypher exp 1

#include<stdio.h>
#include<string.h>
#include<ctype.h>

int main() {

    char text[500], ch,text2[500];
    int key;
    printf("Enter a message to encrypt: ");
    scanf("%s", text);
    strcpy(text2,text);
    printf("Enter the key: ");
    scanf("%d", & key);
    for (int i = 0; text[i] != '\0'; ++i) {
        ch = text[i];
        if (isalnum(ch)) {
            if (islower(ch)) {
                ch = (ch - 'a' + key) % 26 + 'a';
            }
            if (isupper(ch)) {
                ch = (ch - 'A' + key) % 26 + 'A';
            }
            if (isdigit(ch)) {
                ch = (ch - '0' + key) % 10 + '0';
            }
        }
        else {
            printf("Invalid Message");
        }
        text[i] = ch;

    }

    printf("Encrypted message: %s\n", text);
    
    printf("After decrytion : %s",text2);

    return 0;
}
