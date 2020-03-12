#ifndef LIBRARY_GUARD__H
#define LIBRARY_GUARD__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct BookU {
		char *title; 
		char *authors; 
		unsigned int year;
};
int library_init();
int borrow_book(char *user,struct BookU book);

int return_book(char *user,struct BookU book);


#endif
