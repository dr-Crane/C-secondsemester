#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *crypt(char *sent , int key){

    unsigned int sent_len = strlen(sent);
    char *text = (char*) malloc(sent_len+1);
    if(text == NULL) return NULL;
    text[sent_len] = '\0';
    for(int i=0 ; i<strlen(sent) ; i++)  text[i] = sent[i] ^ key;
    return text;

}

int main(){

    char sent[] = "Hello, world!";
    for(int i=0; i<strlen(sent); i++) printf("%c", sent[i]);
    printf("\n");
    int key = 5;
    char *text = crypt(sent , key);
    if(text == NULL){
        printf("ERROR_1");
        return 0;
    }
    for(int i=0; i<strlen(text); i++) printf("%c", text[i]);
    printf("\n");
    char *decrypt = crypt(text, key);
    for(int i=0; i<strlen(decrypt); i++) printf("%c", decrypt[i]);

}
