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

int account_list[100];


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
int select_server();
int select_client();
int client_account();
void deallocation(node *h);


int server_login();
void save_account(int u,int n); // 계좌파일로 업로드 - 구현완료 
int get_account(int n); // 해당 계좌 읽어들이기 - 구현완료 
int sign_in_or_up(); // 회원가입 로그인 선택하기 - 구현완료
void sign_in(); // 유저로서 회원가입 하기 - 구현완료 
int sign_up(); // 유저로서 로그인 하기 - 구현완료 