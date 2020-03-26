#include "users.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// static struct User *all_users = 0;
// static int users_number = 0;
// static int user_array_size = 0;

int register_user(struct User u) {
        FILE *fp;
		fp=fopen("../user_login_data.txt","a");
        fprintf(fp,"%s,%s,\n",u.username,u.password);
        fclose(fp);
        return 0;
		
}
int login_user(struct User u) {
        FILE *fp;
        
        char line_of_string[200];
         
		 fp=fopen("../user_login_data.txt","r");
        char *token;
        token=(char*) malloc(60*sizeof(char));
        if (fp==NULL){
            printf("File not found");
            return -1;
        }
           
            while ((fgets(line_of_string, sizeof(line_of_string), fp)) != NULL)
            {
                         
                 token=(char*) malloc(50*sizeof(char));
                token = strtok(line_of_string,",");
                if (strcmp(u.username,token)==0)
                {
                    token = strtok(NULL,",");
                    if( strcmp(u.password,token)==0)
                    {
                        return 1;
                    }
                }

            }
        
        
         fclose(fp);
         
         return 0;
         
}
int login_librarian(char *librarian_pass){
    FILE *fp;
    char *comp;
    comp=(char*) malloc(20*sizeof(char));
	fp=fopen("../librarian_pass.txt","r");
    if (fp==NULL)
    {
        printf("File not found");
        return -1;
    }       
    fscanf(fp,"%s",comp);          
            
    if (strcmp(comp,librarian_pass)==0)
    {
        
        return 1;
    }
        
    fclose(fp);
    
    return 0;
}