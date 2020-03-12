#include "book_management.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>



// struct BookArray library;
// library.array[0].title="lmaolmafaoaooa";
// library.length=1;
extern struct BookArray library;
 int store_books( FILE *file){
         file=fopen("books.txt","a");
		for (int i=0;i<library.length;i++)
        {
            fprintf(file,"%s,%s,%d,%d\n",library.array[i].title,library.array[i].authors,library.array[i].year,library.array[i].copies);
        }
    
         fclose(file);
        return 0;

 }

int load_books(FILE *file){
    file=fopen("books.txt", "r");
    char *token;
    token=(char*) malloc(20*sizeof(char));
    char line[40];
         while(fgets(line, sizeof line, file) != NULL)
         {
            token = strtok(line,",");
            library.array[library.length].title=token;
            token = strtok(NULL,",");
            library.array[library.length].authors=token;
            token = strtok(NULL,",");
            library.array[library.length].year=atoi(token);
            token = strtok(NULL,",");
            library.array[library.length].copies=atoi(token);
            printf("%s\n",library.array[library.length].title);
            library.length++;
         }
         printf("%d\n",library.length);
         printf("%s\n",library.array[1].title);
        fclose(file);
    return 0;
}

struct BookArray find_book_by_author(const char *author){
    
    struct BookArray newbookarray;
    newbookarray.length=0;
    newbookarray.array= malloc(sizeof(struct Book)); 

    for (int i=0;i<library.length;i++)
        {
           if(strcmp(library.array[i].authors,author)==0){
            newbookarray.array[newbookarray.length]=library.array[i];
            newbookarray.length++;
           }
        }
    return newbookarray;
}


struct BookArray find_book_by_title(const char *title){
    
    struct BookArray newbookarray;
    newbookarray.length=0;
    newbookarray.array= malloc(sizeof(struct Book)); 

    for (int i=0;i<library.length;i++)
        {
           if(strcmp(library.array[i].title,title)==0){
            newbookarray.array[newbookarray.length]=library.array[i];
            newbookarray.length++;
           }
        }
    return newbookarray;
}


struct BookArray find_book_by_year(unsigned int year){
    
    struct BookArray newbookarray;
    newbookarray.length=0;
    newbookarray.array= malloc(sizeof(struct Book)); 

    for (int i=0;i<library.length;i++)
        {
           if(library.array[i].year==year){
            newbookarray.array[newbookarray.length]=library.array[i];
            newbookarray.length++;
           }
        }
    return newbookarray;
}


int add_book(struct Book book){
    library.array[library.length].title=book.title;
    library.array[library.length].authors=book.authors;
    library.array[library.length].year=book.year;
    library.array[library.length].copies=book.copies;
    library.length++;
}


int remove_book( struct Book book){
return 0;
}
