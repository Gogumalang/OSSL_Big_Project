#include "player.h"
// 이 파일은 메인 파일입니다. 

int main(){
        node *h;
        int account=client_account();
        h = init();

        open_file(h);

        int mode;
        int server_menu;
        int client_menu;
        mode = server_login();

        if(mode == 0){ // 관리자라면
                while(1){
                        server_menu = select_server();

                        if(server_menu == 1) add_player(h);
                        else if(server_menu == 2) update_player(h);
                        else if(server_menu == 3) delete_player(h);
                        else if(server_menu == 4) read_player(h);

                        else if(server_menu == 0) {
                                server_filesave(h);
                                break;
                        }
                        else {
                                printf("choose in 0 to 4\n");
                        }

                }
        }
        else { // 사용자라면
                while(1){
                        client_menu = select_client();

                        if(client_menu == 1) read_squad(h);
                        else if(client_menu == 2) buy_player(h,&account);
                        else if(client_menu == 3) sell_player(h,&account);
                        else if(client_menu == 4) read_player(h);
                        else if(client_menu == 5) cmp_player(h);
                        else if(client_menu == 0){
                                server_filesave(h);
                                save_account(account);
                                break;
                        }
                        else{
                                printf("choose in 0 to 5\n");

                        }
                }
        }

        deallocation(h);
        return 0;
}
