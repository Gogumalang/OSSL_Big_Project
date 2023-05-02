#include "player.h"
// 이 파일은 메인 파일입니다. 

int main(){
        node *h;
        int account=client_account();
        h = init();
        openfile(h);
        int mode;
        int server_menu;
        int client_menu;
        mode = login();

        if(mode == 0){ // 관리자라면
                while(1){
                        server_menu = select_server();
                        if(server_menu == 1) addPlayer(h);
                        else if(server_menu == 2) updatePlayer(h);
                        else if(server_menu == 3) deletePlayer(h);
                        else if(server_menu == 4) readPlayer(h);
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
                        if(client_menu == 1) readSquad(h);
                        else if(client_menu == 2) buyPlayer(h,&account);
                        else if(client_menu == 3) sellPlayer(h,&account);
                        else if(client_menu == 4) readPlayer(h);
                        else if(client_menu == 5) cmpPlayer(h);
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
