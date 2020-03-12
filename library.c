#include "library.h"
#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern struct BookArray library;
int library_init(){
        library.length=0;
        library.array= malloc(50*sizeof(struct Book));    
}

int borrow_book(char *user,struct BookU book){
    return 0;
}

int return_book(char *user,struct BookU book){
    return 0;
}
