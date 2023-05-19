#include "player.h"
// 이것은 플레이어 데이터를 담을 수 있는 코드 입니다! 

/*
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
*/

void set_data(node *h){ // addPlayer를 실행할 때 값을 넣을 보조 함수

        printf("[System] Player name : ");
        scanf("%s",h->name);
        getchar();
        while(1){

        printf("[System] Position(s/d/g) : ");
        scanf("%c",&h->position);
        if(h->position == 's' ||h->position == 'g' ||h->position == 'd' ) break;

        }

        printf("[System] Price : ");
        scanf("%d",&h->price);

        if(h->position =='s'){
                printf("[System] Pace : ");
                scanf("%hu",&h->p1);
                printf("[System] Shooting : ");
                scanf("%hu",&h->p2);
                printf("[System] Passing : ");
                scanf("%hu",&h->p3);
                printf("[System] Dribbling : ");
                scanf("%hu",&h->p4);
                h->stats=((h->p1)+(h->p2)+(h->p3)+(h->p4))/4;
        }
	else if(h->position =='d'){
                printf("[System] Pace : ");
                scanf("%hu",&h->p1);
                printf("[System] Physical : ");
                scanf("%hu",&h->p2);
                printf("[System] Composure : ");
                scanf("%hu",&h->p3);
                printf("[System] Defence : ");
                scanf("%hu",&h->p4);
                h->stats=((h->p1)+(h->p2)+(h->p3)+(h->p4))/4;
        }

        else if(h->position =='g'){
                printf("[System] Diving : ");
                scanf("%hu",&h->p1);
                printf("[System] Handling : ");
                scanf("%hu",&h->p2);
                printf("[System] Kick : ");
                scanf("%hu",&h->p3);
                printf("[System] Reaction : ");
                scanf("%hu",&h->p4);
                h->stats=((h->p1)+(h->p2)+(h->p3)+(h->p4))/4;
        }



        h->sold = false;

	}

node *init(){
        node *head;
        head =(node*)malloc(sizeof(node));
        head->link=NULL;

        return head;
}

node *find_name(node *h,char name[]){

 
        node *cur;
        cur =h;
        while(cur != NULL){
                if(strstr(cur->name,name)!=NULL){
                        return cur;
                }
                cur = cur->link;
        }

        return h;
}

 

void add_player(node *h){// add to head
        node *newnode;
        newnode = (node *)malloc(sizeof(node));
        set_data(newnode);
 

        newnode->link = h->link;
        h->link = newnode;

}

 
void update_player(node *h){

 
        char name[20];
        node *cur;
        printf("[System] Wich player will you update? : ");
        scanf("%s",name);
 

        cur =find_name(h,name);

 
        if(cur == h ) printf("[System] The player doesn't exist. \n");
        else {
          if(cur->position =='s'){
                printf("[System] Pace : ");
                scanf("%hu",&cur->p1);
                printf("[System] Shooting : ");
                scanf("%hu",&cur->p2);
                printf("[System] Passing : ");
                scanf("%hu",&cur->p3);
                printf("[System] Dribbling : ");
                scanf("%hu",&cur->p4);
                cur->stats = ((cur->p1)+(cur->p2)+(cur->p3)+(cur->p4))/4;
          }

          else if(cur->position =='d'){
                printf("[System] Pace : ");
                scanf("%hu",&cur->p1);
                printf("[System] Physical : ");
                scanf("%hu",&cur->p2);
                printf("[System] Composure : ");
                scanf("%hu",&cur->p3);
                printf("[System] Defence : ");
                scanf("%hu",&cur->p4);
                cur->stats = ((cur->p1)+(cur->p2)+(cur->p3)+(cur->p4))/4;
          }

          else if(cur->position =='g'){
                printf("[System] Diving : ");
                scanf("%hu",&cur->p1);
                printf("[System] Handling : ");
                scanf("%hu",&cur->p2);
                printf("[System] Kick : ");
                scanf("%hu",&cur->p3);
                printf("[System] Reaction : ");
                scanf("%hu",&cur->p4);
                cur->stats = ((cur->p1)+(cur->p2)+(cur->p3)+(cur->p4))/4;
           }

         printf("[System] The update has been completed.\n");

        }


}

 

void delete_player(node *h){

 
        char name[20];
        node *cur, *subcur;
        cur = h->link;
        subcur=h;
        printf("Which player will you delete? : ");
        scanf("%s",name);

        while(cur!=NULL){
                if(strcmp(cur->name,name)==0){
                        subcur->link = cur->link;

                        free(cur);
                        break;
                }
                cur = cur->link;
                subcur = subcur->link;
        }

        if(cur ==NULL ) printf("The player doesn't exist. \n");
        else printf("The deletion has been completed.\n");

}
 

void open_file(node *h){

        FILE *fp;
        node *tail;
        tail = NULL;
        char buffer[100];
        char *token;
        printf("openfile\n");
        for(int i=0;i<3;i++){ // 총 3개의 파일을 열어서 읽는다. 
                if(i==0) fp = fopen("striker.txt","r");
                else if(i==1) fp = fopen("defender.txt","r");
                else fp = fopen("goalkeeper.txt","r");
        
                if(fp ==NULL) {
                        fclose(fp);

                }
                else {
                        while(!feof(fp)){
                                node *new;
                                new= (node *)malloc(sizeof(node));
                                fgets(buffer,sizeof(buffer),fp); // 파일에서 한줄을 받아온다. 
                                token = strtok(buffer,","); // ','를 기준으로 단어를 나눈다. 
                                strcpy(new->name,token);
                                token = strtok(NULL,",");
                                strcpy(new->main_position,token);
                                token = strtok(NULL,",");
                                new->price = atoi(token);
                                token = strtok(NULL,",");
                                new->usernum= atoi(token);
                                token = strtok(NULL,",");
                                new->p1= atoi(token);
                                token = strtok(NULL,",");
                                new->p2= atoi(token);
                                token = strtok(NULL,",");
                                new->p3= atoi(token);
                                token = strtok(NULL,",");
                                new->p4= atoi(token);
                                new->position =i;

                                if(new->price ==0){ // feof가 제대로 실행되지 않는 것 같아서 조건 하나를 더 주었다.
                                        free(new);
                                }
                                else{   
                                        if(h->link == NULL){
                                                h->link = new;
                                                tail = new;
                                                tail -> link = NULL;
                                        }
                                        else{
                                                tail->link = new;
                                                new->link = NULL;
                                                tail = new;
                                        }
                                        
                                        new->stats=((new->p1)+(new->p2)+(new->p3)+(new->p4))/4;
                                        

                                }
                        }
                        fclose(fp);
                }
        }
}

void server_filesave(node *h){
        FILE *fp;
        for(int i=0;i<3;i++){
            if(i==0)      fp = fopen("striker.txt","w");
            else if(i==1) fp = fopen("defender.txt","w");
            else          fp = fopen("goalkeeper.txt","w");

            node *cur;
            cur = h->link;
            while(cur!=NULL){
                if((cur->link == NULL)&&(cur->position==i)) fprintf(fp,"%s,%s,%d,%hu,%hu,%hu,%hu,%hu",cur->name,cur->main_position,cur->price,cur->usernum,cur->p1, cur->p2, cur->p3, cur->p4);
                else {
                        if(cur->position==i){
                                if((cur->link)->position != cur->position) fprintf(fp,"%s,%s,%d,%hu,%hu,%hu,%hu,%hu",cur->name,cur->main_position,cur->price,cur->usernum,cur->p1, cur->p2, cur->p3, cur->p4);
                                else fprintf(fp,"%s,%s,%d,%hu,%hu,%hu,%hu,%hu\n",cur->name,cur->main_position,cur->price,cur->usernum,cur->p1, cur->p2, cur->p3, cur->p4);
                        }
                }
                cur = cur -> link;
            }
        fclose(fp);
        }
}
 

void data_player(node *t){
        printf("%9s %4d %4u %5u %5hu %8hu %8hu\n",t->name, t->price,t->stats, t->p1, t->p2, t->p3, t->p4);
}

void read_all_players(node *h){

        node *cur;
        cur = h->link;
        for (int i=0;i<3;i++){
            if(i == 0)      printf("\n----------------------Striker---------------------\n");
            else if(i == 1) printf("\n----------------------Defender--------------------\n");

            else printf("\n---------------------Goalkeeper-------------------\n");
       
            printf("Name                    Main position     Price    \n");
             while(cur != NULL){
 

                if(cur->position == i ){
                    printf("%-23s %-17s $%dm\n",cur->name, cur->main_position,cur->price);
                        //      Khvicha Kvaratskhelia   Centre-Forward    $180.00m
                } 

    
                cur = cur->link;
            }
            cur =h->link;
        }
}

void read_player(node *h){

        // 무엇을 보고 싶은지 선택한다. 구매 내역이 없는 선수만 보여준다. 
        node *cur;
        cur = h->link;
        int position;
        printf("어느 포지션을 보고 싶은가? (0:st 1:df 2:gk) : ");
        scanf("%d",&position);

        if(position == 0)      printf("\n----------------------Striker---------------------\n");
        else if(position == 1) printf("\n----------------------Defender--------------------\n");

        else if(position == 2) printf("\n---------------------Goalkeeper-------------------\n");
        else {
            printf("다른 번호를 입력하였습니다. \n");
            return;
        }
            

        printf("Name                    Main position     Price    \n");
        while(cur != NULL){
 

            if((cur->position == position) &&(cur->usernum == 0)){
                printf("%-23s %-17s $%dm\n",cur->name, cur->main_position,cur->price);
                    //      Khvicha Kvaratskhelia   Centre-Forward    $180.00m
            } 

 
            cur = cur->link;
        }
}

void read_squad(node *h,int n){

        node *cur;
        cur = h;
        for (int i=0;i<3;i++){
            if(i == 0)      printf("\n----------------------Striker---------------------\n");
            else if(i == 1) printf("\n----------------------Defender--------------------\n");

            else printf("\n---------------------Goalkeeper-------------------\n");
       
            printf("Name                    Main position     Price    \n");
             while(cur != NULL){
 

                if((cur->position == i) &&(cur->usernum == n)){
                    printf("%-23s %-17s $%dm",cur->name, cur->main_position,cur->price);
                } 

    
                cur = cur->link;
            }
            cur =h;
        }


}

 



void buy_player(node *h,int *account){

 
        char name[20];
        node *cur;
        int buy;
        printf("Which player will you buy? : ");
        scanf("%s",name);
 

        cur =find_name(h,name);

 
        if(cur == h ) printf("The player doesn't exist. \n");
        else if(cur->sold ==true) printf("The player is sold. \n");
        else {
                if(*(account) <cur ->price) printf("Your account is not enough\n");
                else {
                        printf("Buy ? (yes : 1 No : 0) : ");
                        scanf("%d",&buy);
                        if(buy ==1){

                                cur->sold = true;
                                *account -=cur->price;
                                printf("The perchase has been completed.!\n Account : %d \n",*account);
                        }
                }
        }

}

void sell_player(node *h,int *account){

 
        char name[20];
        node *cur;
        int sell;
        printf("Wich player will you sell? : ");
        scanf("%s",name);
 
        cur =find_name(h,name);

 
        if(cur == h ) printf("The player doesn't exist. \n");
        else if(cur->sold ==false) printf("The player isn't in your squad. \n");
        else {
                printf("Sell ? (yes : 1 No : 0) : ");
                scanf("%d",&sell);
                if(sell == 1){
                        cur->sold = false;
                        *account +=cur->price;
                        printf("The sales has been completed.!\n Account : %d \n",*account);
                }
        }

}

 
 
void cmp_player(node *h){

 
        node *cur,*cur2;
        char name[2][20];
        int serch;
        printf("Player who you're looking for : ");
        scanf("%s",name[0]);
 

        cur = find_name(h,name[0]);

 
        if(cur == h ) printf("The player doesn't exist. \n");
        else{
                printf("Compare?(1) No (0) : ");
                scanf("%d",&serch);
                if(serch ==1){
                        while(1){
                        printf("Player who is compared(quit: q) : ");
                        scanf("%s",name[1]);
                        if(strcmp(name[1],"q")==0) break;
 

                        cur2=find_name(h,name[1]);

 
                        if(cur2 == h ) printf("The player doesn't exist. \n");
                        else if(cur->position == cur2->position){
                                break;
                        }
                        else printf("Diffrent position \n");
                        }
                   }
               if(cur -> position == 's'){
                        printf("\n--------------------------Striker--------------------------\n");
                        printf("     Name Price Stats Pace Shooting Passing Dribbling\n");

               }
                else if(cur -> position =='d'){
                        printf("\n--------------------------Defender-------------------------\n");
                        printf("     Name Price Stats Pace Physical Composure Defense\n");
                }
                else{
                        printf("\n-------------------------Goalkeeper------------------------\n");
                        printf("     Name Price Stats Diving Handling Kick Reaction\n");
                }
 

                data_player(cur);
                if((serch==1)&&(strcmp(name[1],"q")!=0)) data_player(cur2);

  
        }

}



int server_login(){
        int log;
        int s_log;
        int s_pw=2023; // 서버 관리자로 접근 가능한 패스워드
       
        
        printf("Input password : ");
        scanf("%d",&s_log);
        if(s_log == s_pw) {
                printf("Access as server \n");
                return 1;
        }
        else{
                printf("You can't have access as server \n");
                return 0;
        }
                

}

int select_server(){
        int menu;
        printf("\n\n\n---------MENU-----------\n\n");
        printf(" 1. Add player \n");
        printf(" 2. Update player \n");
        printf(" 3. Delete Player \n");
        printf(" 4. Read Player info\n");
        printf(" 0. Exit \n");
        printf("-------------------------\n");
        printf("Input Number : ");
        scanf("%d",&menu);
        return menu;
}




void deallocation(node *h){
        node *d;
        node* cur;
        cur =h;
        while(cur->link !=NULL){
                d=cur;
                cur = cur->link;
                free(d);
        }
}

int select_client(){
        int menu;
        printf("\n\n\n---------MENU-----------\n\n");
        printf(" 1. My squad \n");
        printf(" 2. Buy Player \n");
        printf(" 3. Sell Player \n");
        printf(" 4. Read Player info\n");
        printf(" 5. Compare players \n");
        printf(" 0. Exit \n");
        printf("-------------------------\n");
        printf("Input Number : ");
        scanf("%d",&menu);
        return menu;
}



int get_account(int n){
    FILE *p;
    p=fopen("account.txt","r");
    int i=0;
    int account;
    while(!feof(p)){
        fscanf(p,"%d",&account_list[i]);
        if(i+1 == n) account = account_list[i];
        i++;
        
    }
    account_list[i]= -1;
    fclose(p);

    return account;


}

void save_account(int u,int n){
        FILE *fp;
        fp = fopen("account.txt","w");
        int i=0;

        while(account_list[i]!=-1){
            if(i+1==u) fprintf(fp,"%d",n);
            else  fprintf(fp,"%d",account_list[i]);
            if(account_list[i+1]!=-1) fprintf(fp,"\n");
            i++;
        }
        
        fclose(fp);

}


void sign_in(){
    FILE *p;
    p= fopen("login_info.txt","r");
    char make_ID[20];
    char file_ID[20];
    int make_PW;
    int verify_PW;
    int exist=0;
    int default_account;
    int last_user_num;
    int pw;
    while(1){ //아이디 정하기 
        printf("생성할 아이디를 입력하세요. : ");
        scanf("%s",make_ID);
        while(!feof(p)){
            fscanf(p,"%d %s %d",&last_user_num,file_ID,&pw);
            if(strcmp(make_ID,file_ID)==0) exist =1;
        }
        if(exist==0) break;
        if(exist == 1) printf("이미 아이디를 사용 중입니다. \n");
        exist =0;

    }
    fclose(p);

    while(1){
        printf("비밀번호를 입력하시오.(숫자만 가능): ");
        scanf("%d",&make_PW);

        printf("비밀번호를 다시 한번 입력하시오. : ");
        scanf("%d",&verify_PW);
        if(make_PW==verify_PW) {
            printf("회원가입이 완료되었습니다. 다시 재시동하여 로그인을 하세요. \n");
            break;
        }
        else printf("비밀번호가 확인되지 않았습니다. 다시 비밀번호를 설정하세요.\n");

    }

    default_account = 100000;
    p = fopen("login_info.txt","a"); // 회원 정보를 파일에 저장하기

    fprintf(p,"%d %s %d\n",last_user_num+1,make_ID,make_PW);
    fclose(p);

    p = fopen("account.txt","a");

    fprintf(p,"%d\n",default_account); // 잔액 파일에 저장하기 
    fclose(p);
}

int sign_in_or_up(){
    int sign;
    printf("로그인(1) 회원가입(0) : ");
    scanf("%d",&sign);
    return sign;
}

int sign_up(){

    FILE *p;
    char ID[20]; // 사용자에게 입력받을 ID 
    char cur[20]; // 파일에서 찾을 ID 
    int i=0; // 사용자가 입력한 아이디가 존재하는 지 확인여부
    int PW; // 사용자에게 입력받은 PW
    int pw; // 파일에서 찾을 pw
    int user_num;
    int count=1; // pw 입력 횟수 제한

    printf("ID : "); 
    scanf("%s",ID);

    p = fopen("login_info.txt","r");

    while(!feof(p)){
        fscanf(p,"%d %s %d",&user_num,cur,&pw);
        if(strcmp(ID,cur) == 0 ) {
            printf("PW : ");
            scanf("%d",&PW);
            if(PW == pw) {
                printf("login succes!\n");
                i=1;
            }
            else { 
                i=2;
                while(count<=3){
                    printf("Wrong PW (%d/3)\n",count);
                    printf("PW : ");
                    scanf("%d",&PW);
                    if(PW == pw) {
                        printf("Login succes!\n");
                        i=1;
                        break;
                    }
                    count++;
                }
            }
            if(i==1) break;
            }
        
    }

    if(i==0) {
        printf("Non-exist ID\n");
        user_num =0;
    }
    if(i==2) {
        printf("Fail login\n");
        user_num =0;
    }

    fclose(p);

    return user_num;

}



