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


void set_data(node *h);
node *init();
node *find_name(node *h,char name[]);
void add_player(node *h);
void update_player(node *h);
void delete_player(node *h);
void open_file(node *h);
void server_filesave(node *h);
void data_player(node *t);
void read_player(node *h);
void read_squad(node *h);
void buy_player(node *h,int *account);
void sell_player(node *h,int *account);
void cmp_player(node *h);
int login();
int select_server();
int select_client();
int client_account();
void save_account(int num);
void deallocation(node *h);
