#ifndef LIBRARY_GUARD__H
#define LIBRARY_GUARD__H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Borrow {
		char *title; 
		char *user;
};
struct BorrowArray{
		struct Borrow* array;
		unsigned int length;
};
struct BorrowArray borrow_set;

int borrow_set_init();
int borrow_book(struct Borrow);

int return_book(struct Borrow);
int load_loans(FILE *file);
int store_loans(FILE *file);

#endif
