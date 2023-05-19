#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include "string.h"
#include <time.h>

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

// 완성 : 내용은 완성되었지만, 출력 부분의 수정이 필요한 함수들 입니다. 
//      출력 완성을 했으면 각 함수에 '//' 옆에 '출력부분 수정' 이라고 표시해주시면 감사하겠습니다! 

void reset_data(node *t,node *h);
        void random_stat_allocation(int *s,int n);
        void open_demo_file(node *h);



node *init(); // 링크드 리스트 선언 함수 // 
node *find_name(node *h,char name[]); // 이름을 찾아서 해당 노드를 리턴하는 함수 // 

void update_player(node *h); // 선수 정보 수정 함수 // 출력부분 수정
void delete_player(node *h); // 선수 정보 삭제 함수 // 출력부분 수정
void open_file(node *h); //  선수 정보를 리스트에 저장하는 함수 //
void server_filesave(node *h); // 리스트에 저장된 선수 정보를 파일에 저장하는 함수 // 
void data_player(node *t); // 선수들의 상세 정보를 출력하는 함수 // 
void read_player(node *h); // 선수 정보를 포지션 별로 구분하여 볼 수 있는 함수 // 
void read_squad(node *h,int n); // 자신의 스쿼드를 볼 수 있는 함수 //
void buy_player(node *h,int *account,int n); // 선수 구입 함수 //  출력부분 수정
void sell_player(node *h,int *account,int n); // 선수 판매 함수 // 출력부분 수정
void cmp_player(node *h); // 선수 비교 함수 // 출력부분 수정


int server_login(); // 서버 로그인 함수 // 출력부분 수정
int select_server(); // 서버 메뉴 함수 // 출력부분 수정
int select_client(); // 유저 메뉴 함수 // 출력부분 수정
void deallocation(node *h); // 링크드 리스트 할당을 해제 함수 //

void read_all_players(node *h); // 모든 선수 정보를 보는 함수 //

int sign_in_or_up(); // 회원가입 로그인 선택하기 // 출력부분 수정
void sign_in(); // 유저로서 회원가입 하기 // 출력부분 수정
int sign_up(); // 유저로서 로그인 하기 // 출력부분 수정
int get_account(int n); // 해당 계좌 읽어들이기 //
void save_account(int u,int n); // 계좌파일로 업로드 //
