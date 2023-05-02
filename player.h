#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"

typedef struct node{
        char name[20];
        char position;
        int price;
        bool sold;
        unsigned short p1;
        unsigned short p2;
        unsigned short p3;
        unsigned short p4;
        unsigned short stats;
        struct node *link;

}node;

void setdata(node *h);
node *init();
node *findname(node *h,char name[]);
void addPlayer(node *h);
void updatePlayer(node *h);
void deletePlayer(node *h);
void openfile(node *h);
void server_filesave(node *h);
void dataPlayer(node *t);
void readPlayer(node *h);
void readSquad(node *h);
void buyPlayer(node *h,int *account);
void sellPlayer(node *h,int *account);
void cmpPlayer(node *h);
int login();
int select_server();
int select_client();
int client_account();
void save_account(int num);
void deallocation(node *h);

