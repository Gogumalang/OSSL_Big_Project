#include "player.h"

int main(){
    node *h;
    int log = sign_in_or_up();
    int user; // 로그인한 유저의 고유 값
    int account; // 유저의 계좌
    int client_menu;
    
    if(log ==0 ) {// 회원가입 
        sign_in();
        return 0;
    }
    else {        // 로그인
        user = sign_up();
        if(user==0) return 0;
    }
    
    h= init(); // 리스트 초기화
    open_file(h); // 리스트에다 선수 파일 정보 담기
    account = get_account(user); // 잔액 가져오기


    while(1){
                        client_menu = select_client();

                        if(client_menu == 1) read_squad(h,user);
                        else if(client_menu == 2) buy_player(h,&account,user);
                        else if(client_menu == 3) sell_player(h,&account,user);
                        else if(client_menu == 4) read_player(h);
                        else if(client_menu == 5) cmp_player(h);
       
                        else if(client_menu == 0){
                                server_filesave(h);
                                save_account(user,account);
                                break;
                        }
                        else{
                                printf("choose in 0 to 5\n");

                        }
                }



    deallocation(h);
    return 0;
}