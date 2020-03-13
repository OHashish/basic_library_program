#include "library.h"
#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern struct BookArray library;
int library_init(){
        library.length=0;
         library.array= (struct Book*)malloc(1000*sizeof(struct Book));    
        for(int i=0;i<1000;i++)
        {

        library.array[i].title= (char*)malloc(20*sizeof(char));   
        library.array[i].authors= (char*)malloc(20*sizeof(char));     
        }
}

int borrow_book(char *user,struct BookU book){
    FILE *file;
    file=fopen("book_loan.txt", "w");
    
    fprintf(file,"%s %s",user,book.title);
    return 0;
}

int return_book(char *user,struct BookU book){
    return 0;
}
