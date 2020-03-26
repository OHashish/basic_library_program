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
    
    char line_of_string[200];

    file=fopen("../user_login_data.txt","r");
    if (file==NULL) 
    {
        printf("Login file returned a null pointer ");
        return -2;
    } 
    char *token;
    token=(char*) malloc(60*sizeof(char));

    while ((fgets(line_of_string, sizeof(line_of_string), file)) != NULL)
    {

        token=(char*) malloc(50*sizeof(char));
        token = strtok(line_of_string,",");
        if(strcmp(line_of_string,book.user)==0){
           
            borrow_set.array[borrow_set.length]=book;
            borrow_set.length++;
            return 0;
        }

    }
        
        
    fclose(file);
    return 1;
}

int load_loans(FILE *file){
    
   
   if (file==NULL){
       printf("Book loan file returned a Null Pointer");
       return -1;
   }
    char *token;
    token=(char*) malloc(30*sizeof(char));
    char line[200];
    borrow_set.length=0;
    

    while(fgets(line, 200, file)!=NULL )
        {  
            token=(char*) malloc(20*sizeof(char));
            token = strtok(line,",");
            strcpy(borrow_set.array[borrow_set.length].title,token);
            token = strtok(NULL,",");
            strcpy(borrow_set.array[borrow_set.length].user,token);
            borrow_set.length++;
             
        }
    
    return 1;

}
int return_book(struct Borrow book){   
    for (int i=0;i<borrow_set.length;i++){
        if(strcmp(borrow_set.array[i].title,book.title)==0 &&
        strcmp(borrow_set.array[i].user,book.user)==0){
            borrow_set.array[i]=borrow_set.array[borrow_set.length-1];
            borrow_set.length--;
            return 1;
        }
    }
    return 0;
}

int store_loans(FILE *file){
   
    if (file==NULL){
       printf("Book loan file returned a Null Pointer");
       return -1;
   }
		for (int i=0;i<borrow_set.length;i++)
        {
            fprintf(file,"%s,%s,\n",borrow_set.array[i].title,borrow_set.array[i].user);
        }
    
        
    return 1;
}
