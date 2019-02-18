/*
 Author: Simba

 Topic :ToDo List
*/

#include <stdio.h>
#include <stdlib.h>

struct Todo{            //linked list declaration
    char data[100];
    struct Todo* link;
    int count;

};

typedef struct Todo todo; //changes Todo to todo

    todo* head;
    //functions
    void welcome();
    void viewList();
    void deleteList();
    void refreshList();
    void  createList();
    void updatecount();
    void  addList();
    void displayList();


/*1;view
2;add
3,delete
4,refresh
5;print
6,exit
*/
 void displayList(){ //displays function
    todo*temp=head;
    if(temp==NULL){
        printf("EMPTY LIST.\n");
    }
    while(temp!=NULL){
        printf("%d).%s \n\n",temp->count,temp->data);
        temp=temp->link;
    }
    printf("\n\n");
    system("pause");

}
int main() //app driver
{

    int userChoice;
    welcome();
    system("pause");
    while(1){ //infinity loop
    system("cls");

    printf("1.ViewList.\n");
    printf("2.Create List.\n");
    printf("3.Delete name List.\n");
    printf("4.Add to entry to list.\n");
    printf("5.Refresh List.\n");
    printf("6.Exit.\n");

    printf("\nSelect operation:\n");

    scanf("%d",&userChoice);
    switch(userChoice){
    case 1:
        viewList();
        break;
    case 2:
        createList();
        break;
    case 3:
        deleteList();
        break;
    case 4:
        addList();
        break;
    case 5:
        refreshList();
        break;

    case 6:
        exit(0);
    }

    }


    return 0;
}
void welcome(){
    //welcome screen
    int width = 12, height = 5, b = 0, a = 0;  // initialize local variables
    for (a = 0; a != height; a++) {
        for (b = 0; b != width; b++ ) {
            if ((a == 0) || (a == height-1) || (b == width-1) || (b == 0)){
                printf("*");
            }else   // if not to print *, print space
                printf("= ");
                }
            printf("\n");
        }

    return 0;
    system("pause");

}

void viewList(){        //allows user to view list
    system("cls");
    todo*temp=head;
    if(temp==NULL){
        printf("EMPTY LIST.\n");
    }
    while(temp!=NULL){
        printf("%d).%s \n\n",temp->count,temp->data);
        temp=temp->link;
    }
    printf("\n\n");
    system("pause");

}

void  createList(){ //create list

    char op;
    todo*temp;
    todo*temp1;

    system("cls"); //clear console
    while(1){
        printf("\nAdd To-do?..y/n\n");
        fflush(stdin);
        scanf("%c",&op);
        if(op=='n'){
            break;
        }else if(op=='y'){
            if(head==NULL){
                temp=(todo*)malloc(sizeof(todo));
                head=temp;
                printf("\nAdd To-do... \n");
                scanf("%s",temp->data);
                temp->count=1;
                head->link=NULL;
            }
            else{
                temp1=(todo*)malloc(sizeof(todo));
                printf("\nAdd To-do...\n");
              //scanf("\n%s",temp->data);
                fflush(stdin);
                gets(temp1->data);
                temp1->link=NULL;
                temp->link=temp1;
                temp=temp->link;
            }
            updatecount();
        }
    }


}
void deleteList(){
    system("cls");
    int deletenum;
    todo*temp,*temp1;
    printf("Current List is   --:\n");
    displayList();
    fflush(stdin);
    printf("\nEnter entry number to be deleted\n");
    scanf("%d",&deletenum);
    temp1=head;
    temp=head->link;
    while(1){
        if(temp1->count==deletenum){
            head=head->link;
           free(temp1);
            updatecount();
            break;
        }
        if(temp->count==deletenum){
            temp1->link=temp->link;
            free(temp);
            updatecount();
            break;
        }
        else{
            temp1=temp;
            temp=temp->link;
        }

    }
    system("cls");
    printf("Success....\n");
    displayList();

}

 void addList(){
    system("cls");
    todo*temp,*temp1;
    char op;
    while(1){
        printf("WANT TO ADD To-do?.y/n\n");
        fflush(stdin);
       scanf("%c",&op);
        if(op=='n'){
            break;
        }
        printf("Procced...\n");
        temp=(todo*)malloc(sizeof(todo));
        fflush(stdin);
        gets(temp->data);
        temp->link=NULL;
        temp1=head;

        while(temp1->link!=NULL){
        temp1=temp1->link;
    }
    temp1->link=temp;
    updatecount();

    }
    printf("\n\n");
    system("pause");
 }

 void updatecount(){
    todo*temp;
    int num=1;
    temp=head;
    while(temp!=NULL){
        temp->count=num;
        num++;
        temp=temp->link;
    }

 }


 void refreshList(){
    todo*temp;
    char op;
    system("cls");

    puts("WARNING: This Action Will Delete All Your Entires.Do You Wish To Proceed?..y/n");
    fflush(stdin);
    scanf("%c",&op);
    if(op=='n'){
        system("cls");
        printf("\nList Not Compromised\n");
        displayList();
    }else{
        head=NULL;
        free(temp);
        system("cls");

        printf("\nList Compromised\n");
        displayList();
    }

}

