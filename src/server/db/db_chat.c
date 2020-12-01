#include "../../../inc/db.h"

bool db_checkchat(char *name) {
    char *path = strdup(DB_chat);
    strcat(path, name);
    if (access(path, F_OK | W_OK) == -1) {
        free(path);
        return false;
    }
    free(path);
    return true;
}

bool db_createchat(char *name) {
    char *path = strdup(DB_chat);
    strcat(path, name);
    FILE *chat = fopen(path, "wt");
    free(path);
    bool res = chat;
    fclose(chat);
    return res;
}

bool db_addmessage(char *chat, char *nick, char *text) {
    if (!db_checkchat(chat)) {
        db_checkchat(chat);
    }
    unsigned char *nick_encrypted = db_encryptdata(nick);
    unsigned char *text_encrypted = db_encryptdata(text);
    char *path = strdup(DB_chat);
    strcat(path, chat);
    FILE *f_chat = fopen(path, "r+t");
    free(path);
    if (!f_chat)
        return false;
    fseek(f_chat, 0, SEEK_END);
    fprintf(f_chat, "%s;%s;\n", nick_encrypted, text_encrypted);
    free(nick_encrypted);
    free(text_encrypted);
    fclose(f_chat);
    return true;
}


void db_sendhistory(t_users *user, char *chat, void (*sender)(t_users *, char *, char *)) {
    if (!db_checkchat(chat)) {
        return;
    }
    char *path = strdup(DB_chat);
    strcat(path, chat);
    FILE *f_chat = fopen(path, "rt");
    char line[MAX_INPUT_LEN+1];
    while (fgets(line, MAX_INPUT_LEN+1, f_chat)) {
        bool res = true;
        char *tmp = strdup(line);
        char *tmp2 = strdup(db_getfield(tmp, 1));
        char *tmp3 = db_decryptdata((unsigned char*)tmp2);
        free(tmp);
        free(tmp2);
        tmp = NULL;
        tmp = strdup(line);
        tmp2 = strdup(db_getfield(tmp, 2));
        char *tmp4 = db_decryptdata((unsigned char*)tmp2);
        free(tmp);
        free(tmp2);
        sender(user,tmp3,tmp4);
        free(tmp3);
        free(tmp4);
    }
    fclose(f_chat);
}


