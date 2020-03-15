#include "users.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// static struct User *all_users = 0;
// static int users_number = 0;
// static int user_array_size = 0;

int register_user(struct User u) {
        FILE *fp;
		fp=fopen("/home/csunix/sc19orss/comp1921/sc19orss/build/user_login_data.txt","a");
        fprintf(fp,"\n%s %s",u.username,u.password);
        fclose(fp);
        printf("Registered successfully!!!");
        return 0;
		
}
int login_user(struct User u) {
        FILE *fp;
        struct User c;
        char line_of_string[200];
         c.username=(char*) malloc(20*sizeof(char));
	     c.password=(char*) malloc(20*sizeof(char));
		 fp=fopen("/home/csunix/sc19orss/comp1921/sc19orss/build/user_login_data.txt","r");
           
            while ((fgets(line_of_string, sizeof(line_of_string), fp)) != NULL)
            {
                fscanf(fp,"%s %s",c.username,c.password);          
            
             if (strcmp(u.username,c.username)==0 && strcmp(u.password,c.password)==0)
             {
                 printf("Success!!");
                 return 1;
             }

            }
        
        
         fclose(fp);
         printf("Not registered");
         return 0;
         
}
int login_librarian(char *librarian_pass){
    FILE *fp;
    char *comp;
    comp=(char*) malloc(20*sizeof(char));
	fp=fopen("/home/csunix/sc19orss/comp1921/sc19orss/build/librarian_pass.txt","r");
           
    fscanf(fp,"%s",comp);          
            
    if (strcmp(comp,librarian_pass)==0)
    {
        printf("WELCOME!");
        return 1;
    }
        
    fclose(fp);
    printf("Incorrect Password");
    return 0;
}