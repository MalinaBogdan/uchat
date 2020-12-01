#include "../../../inc/db.h"

const char* db_getfield(char* line, int num)
{
    const char* tok;
    for (tok = strtok(line, ";");
         tok && *tok;
         tok = strtok(NULL, ";"))
    {
        if (!--num)
            return tok;
    }
    return NULL;
}

char * db_decryptdata(unsigned char *str) {
    char *todecrypt = (char*)malloc(sizeof(char )*(strlen(str)+1));
    ft_memset(todecrypt,0,strlen(str)+1);
    rc4_decrypt(SECRET_KEY, (unsigned char*)str, (unsigned char *)todecrypt, (int)strlen((const char*)str)+1);
    return todecrypt;
}

unsigned char * db_encryptdata(char *str) {
    unsigned char *toencrypt = (unsigned char*)malloc(sizeof(unsigned char )*(strlen(str)+1));
    ft_memset(toencrypt,0,strlen(str)+1);
    rc4_encrypt(SECRET_KEY, (unsigned char*)str, toencrypt, (int)strlen(str)+1);
    return toencrypt;
}
