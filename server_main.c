#include "player.h"

int main(){
    node *h;
    int log = server_login();
    int server_menu;

    if(log == 0 ) return 0; // 서버 로그인 실패 

    h= init();
    openfile(h);


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

    return 0;
}