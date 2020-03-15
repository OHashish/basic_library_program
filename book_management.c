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

 int store_books( FILE *file){
         file=fopen("books.txt","w");
		for (int i=0;i<library.length;i++)
        {
            fprintf(file,"%s,%s,%d,%d\n",library.array[i].title,library.array[i].authors,library.array[i].year,library.array[i].copies);
        }
    
         fclose(file);
        return 0;

 }

int load_books(FILE *file){
    file=fopen("/home/csunix/sc19orss/comp1921/sc19orss/build/books.txt", "r");
    char *token;
    token=(char*) malloc(30*sizeof(char));
    char line[40];
       
         while(fgets(line, sizeof(line), file) )
         {  
             
             token=(char*) malloc(20*sizeof(char));
            token = strtok(line,",");
            strcpy(library.array[library.length].title,token);
            token = strtok(NULL,",");
            strcpy(library.array[library.length].authors,token);
            token = strtok(NULL,",");
            library.array[library.length].year=atoi(token);
            token = strtok(NULL,",");
            library.array[library.length].copies=atoi(token);
            library.length++;
             
         }
        fclose(file);
    return 0;
}

struct BookArray find_book_by_author(const char *author){
    
     struct BookArray newbookarray;
    newbookarray.length=0;
    newbookarray.array= malloc(10*sizeof(struct Book)); 
    for(int i=0;i<10;i++)
        {

        newbookarray.array[i].title= (char*)malloc(20*sizeof(char));   
        newbookarray.array[i].authors= (char*)malloc(20*sizeof(char));     
        }

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
    newbookarray.array= malloc(10*sizeof(struct Book)); 
    for(int i=0;i<10;i++)
        {

        newbookarray.array[i].title= (char*)malloc(20*sizeof(char));   
        newbookarray.array[i].authors= (char*)malloc(20*sizeof(char));     
        }

    for (int i=0;i<library.length;i++)
        {
           if(strcmp(library.array[i].title,title)==0){
            newbookarray.array[newbookarray.length]=library.array[i];
            newbookarray.length++;
           }
        }
        printf("%d",newbookarray.length);
    return newbookarray;
}


struct BookArray find_book_by_year(unsigned int year){
    
     struct BookArray newbookarray;
    newbookarray.length=0;
    newbookarray.array= malloc(10*sizeof(struct Book)); 
    for(int i=0;i<10;i++)
        {

        newbookarray.array[i].title= (char*)malloc(20*sizeof(char));   
        newbookarray.array[i].authors= (char*)malloc(20*sizeof(char));     
        }
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
    printf("%s",book.title);
    printf("%s",book.authors);
    printf("%d",book.year);

    for (int i=0;i<library.length;i++){
        if(strcmp(library.array[i].title,book.title)==0 &&
        strcmp(library.array[i].authors,book.authors)==0 &&
        library.array[i].year==book.year){
            library.array[i]=library.array[library.length-1];
        }
    }
    library.length--;
return 0;
}
