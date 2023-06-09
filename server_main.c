#include "player.h"

int main(){
    node *h;
    node *t;
    int log = server_login();
    int server_menu;

    if(log == 0 ) return 0; // 서버 로그인 실패 

    h= init();
    open_file(h);


    while(1){
                        server_menu = select_server();

                        if(server_menu == 1) {
                                log = server_login();
                                if(log == 1){
                                        t = init();
                                        reset_data(t,h);
                                        server_filesave(t);
                                        deallocation(t);
                                        return 0; 
                                }
                                
                        }
                        else if(server_menu == 2) update_player(h);
                        else if(server_menu == 3) delete_player(h);
                        else if(server_menu == 4) read_all_players(h);

                        else if(server_menu == 0) {
                                server_filesave(h);
                                break;
                        }
                        else {
                                printf("choose in 0 to 4\n");
                        }

            }
    deallocation(h);
    return 0;
}