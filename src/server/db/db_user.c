#include "../../../inc/db.h"

bool db_checkuser(char *nick) {
    FILE *users = fopen(DB_users, "rt");
    char line[1024];
    while (fgets(line, 1024, users)) {
        char *tmp = strdup(line);
        char *tmp2 = strdup(db_getfield(tmp, 1));
        char *tmp3 = db_decryptdata((unsigned char*)tmp2);
        if (strcmp(tmp3,nick) == 0) {
            free(tmp);
            free(tmp2);
            free(tmp3);
            fclose(users);
            return true;
        }
        free(tmp);
        free(tmp2);
        free(tmp3);
    }
    fclose(users);
    return false;
}


bool db_adduser(char *nick, char *password) {
    FILE *users = fopen(DB_users, "r+t");
    fseek(users, 0, SEEK_END);
    unsigned char *nick_crypt = db_encryptdata(nick);
    unsigned char *pass_crypt = db_encryptdata(password);
    fprintf(users, "%s;%s;\n", nick_crypt, pass_crypt);
    fclose(users);
    return true;
}

bool db_validateuser(t_users *user, const char *nick, const char *password) {
    FILE *users = fopen(DB_users, "rt");
    char line[1024];
    while (fgets(line, 1024, users)) {
        bool res = true;
        char *tmp = strdup(line);
        char *tmp2 = strdup(db_getfield(tmp, 1));
        char *tmp3 = db_decryptdata((unsigned char*)tmp2);
        if (strcmp(tmp3,nick) != 0) {
            res = false;
        }
        if (!res) {
            free(tmp);
            free(tmp2);
            free(tmp3);
            continue;
        }
        free(tmp);
        free(tmp2);
        free(tmp3);
        tmp = NULL;
        tmp = strdup(line);
        tmp2 = strdup(db_getfield(tmp, 2));
        tmp3 = db_decryptdata((unsigned char*)tmp2);
        if (strcmp(tmp3, password) != 0) {
            res = false;
        }
        if (res) {
            fclose(users);
            user->nick.nick_len = (int) strlen(nick);
            strcpy(user->nick.nick, nick);
            user->logined=true;
            free(tmp);
            free(tmp2);
            free(tmp3);
            return true;
        }
        free(tmp);
        free(tmp2);
        free(tmp3);
    }
    fclose(users);
    return false;
}

bool db_validatenick(char *nick) {
    return !(strlen(nick) > MAX_NICK_LEN || strlen(nick) < 4);
}
