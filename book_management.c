
#include "book_management.h"
#include <stdio.h>

struct BookArray thebookarray;
 int store_books( FILE *file){

       file=fopen("books.txt","w");
		for (int i=0;i<thebookarray.length;i++)
        {
            
            
            fprintf(file,"%s\n",thebookarray.array[i].title);
        }
        fclose(file);
 return 0;

 }

// int add_book(struct Book book){

// }
