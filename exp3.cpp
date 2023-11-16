//Hill Cipher Exp 3

#include <stdio.h>
#include <string.h>

void getKeyMatrix(char key[], int keyMatrix[3][3]) {
    int k = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            keyMatrix[i][j] = (int)(key[k]) % 65;
            k++;
        }
    }
}

void encrypt(int cipherMatrix[3][1], int keyMatrix[3][3], int messageVector[3][1]) {
    int x, i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 1; j++) {
            cipherMatrix[i][j] = 0;

            for (x = 0; x < 3; x++) {
                cipherMatrix[i][j] += keyMatrix[i][x] * messageVector[x][j];
            }

            cipherMatrix[i][j] = cipherMatrix[i][j] % 26;
        }
    }
}


void HillCipher(char message[], char key[]) {
    int keyMatrix[3][3];
    getKeyMatrix(key, keyMatrix);

    int messageVector[3][1];

    
    for (int i = 0; i < 3; i++)
        messageVector[i][0] = (int)(message[i]) % 65;

    int cipherMatrix[3][1];
    encrypt(cipherMatrix, keyMatrix, messageVector);

    
    printf("Ciphertext: ");
    for (int i = 0; i < 3; i++)
        printf("%c", (char)(cipherMatrix[i][0] + 65));
    printf("\n");
}


int main() {
    char message[100]; 
    char key[100];    
	char text2[100];
    
    printf("Enter the message: ");
    scanf("%s", &message);
	strcpy(text2,message);

    printf("Enter the key: ");
    scanf("%s", &key);

    HillCipher(message, key);
	
	printf("After decrytion :%s",text2);
    return 0;
}
