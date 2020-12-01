#include "../../../inc/db.h"


bool db_init() {
    struct stat st = {0};
    if (stat("data", &st) == -1) {
        mkdir("data", 0700);
    }
    if (stat("data", &st) == -1) {
        return false;
    }
    if (access(DB_users, F_OK | W_OK) == -1) {
        FILE *users = fopen(DB_users, "wt");
        if (!users)
            return false;
        fclose(users);
    }
    return true;
}
