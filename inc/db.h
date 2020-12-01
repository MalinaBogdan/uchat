#ifndef DB_H
#define DB_H

#include <stdbool.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <malloc/_malloc.h>

#include "server.h"

#define DB_users "data/u_users"
#define DB_chat "data/u_"


bool db_init();


bool db_checkuser(char *nick);

bool db_adduser(char *nick, char *password);

bool db_validateuser(t_users *user, const char *nick, const char *password);

bool db_validatenick(char *nick);


bool db_checkchat(char *name);

bool db_createchat(char *name);

bool db_addmessage(char *chat, char *nick, char *text);

void db_sendhistory(t_users *user, char *chat, void(*sender)(t_users *, char *, char *));


char *db_decryptdata(unsigned char *str);

unsigned char *db_encryptdata(char *str);

const char *db_getfield(char *line, int num);

#endif
