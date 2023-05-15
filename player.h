#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"

typedef struct node{
        char name[30];
        char main_position[30];
        unsigned short position; // 0 : striker , 1: defender, 2: goalkeeper
        int price;
        unsigned short usernum; // 0 : not sold, a : usernum
        unsigned short p1;
        unsigned short p2;
        unsigned short p3;
        unsigned short p4;
        unsigned short stats;
        struct node *link;

}node;

int account_list[100];


void set_data(node *h);
node *init(); // 재활용 가능 
node *find_name(node *h,char name[]); // 재활용 가능 
void add_player(node *h);
void update_player(node *h);
void delete_player(node *h);
void open_file(node *h); // 업데이트 - 커밋 // 수정
void server_filesave(node *h); // 업데이트 -커밋 // 수정
void data_player(node *t);
void read_player(node *h);
void read_squad(node *h);
void buy_player(node *h,int *account);
void sell_player(node *h,int *account);
void cmp_player(node *h);
int server_login();
int select_server();
int select_client();
int client_account();
void deallocation(node *h);

void read_all_player(node *h);


//커밋
int sign_in_or_up(); // 회원가입 로그인 선택하기 - 구현완료 // 수정 
void sign_in(); // 유저로서 회원가입 하기 - 구현완료  // 수정 
int sign_up(); // 유저로서 로그인 하기 - 구현완료  // 수정 
int get_account(int n); // 해당 계좌 읽어들이기 - 구현완료  // 수정 
void save_account(int u,int n); // 계좌파일로 업로드 - 구현완료 // 수정 
