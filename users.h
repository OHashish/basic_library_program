#ifndef USERS_GUARD_H
#define USERS_GUARD_H
#include <stdio.h>

struct User {
     char *username;
     char *password;
};

int register_user(struct User u);

int login_user(struct User u);

int login_librarian();

#endif
