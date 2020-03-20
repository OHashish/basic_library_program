#include "library.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


extern struct BookArray library;
extern struct BorrowArray borrow_set;
int borrow_set_init(){
        borrow_set.length=0;
        borrow_set.array= (struct Borrow*)malloc(1000*sizeof(struct Borrow));    
        for(int i=0;i<1000;i++)
        {

        borrow_set.array[i].title= (char*)malloc(20*sizeof(char));   
        borrow_set.array[i].user= (char*)malloc(20*sizeof(char));     
        }
}
int borrow_book(struct Borrow book){
    FILE *file;
    file=fopen("/home/csunix/sc19orss/comp1921/sc19orss/build/book_loan.txt", "a");
    
    fprintf(file,"%s,%s,\n",book.title,book.user);
    fclose(file);
    return 1;
}

int return_book(struct Borrow book){
    FILE *file;
   file=fopen("/home/csunix/sc19orss/comp1921/sc19orss/build/book_loan.txt", "r");
    char *token;
    token=(char*) malloc(30*sizeof(char));
    char line[40];
    borrow_set.length=0;
    int flag=0;

    while(fgets(line, sizeof(line), file)!=NULL )
        {  
            token=(char*) malloc(20*sizeof(char));
            token = strtok(line,",");
            strcpy(borrow_set.array[borrow_set.length].title,token);
            token = strtok(NULL,",");
            strcpy(borrow_set.array[borrow_set.length].user,token);
            borrow_set.length++;
             
        }
    fclose(file);


   
    for (int i=0;i<borrow_set.length;i++){
        if(strcmp(borrow_set.array[i].title,book.title)==0 &&
        strcmp(borrow_set.array[i].user,book.user)==0){
            borrow_set.array[i]=borrow_set.array[borrow_set.length-1];
            borrow_set.length--;
            flag =1;
        }
    }
    



    file=fopen("/home/csunix/sc19orss/comp1921/sc19orss/build/book_loan.txt","w");
		for (int i=0;i<borrow_set.length;i++)
        {
            fprintf(file,"%s,%s,\n",borrow_set.array[i].title,borrow_set.array[i].user);
        }
    
         fclose(file);
    if (flag) 
    return 1;
    else 
    return 0;
}
