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
        int yes;
        node *cur;
        printf("[System] Wich player will you update? : ");
        getchar();
        fgets(name,sizeof(name),stdin);
        name[strlen(name)-1]='\0';
        cur =find_name(h,name);

        


 
        if(cur == h ) printf("[System] The player doesn't exist. \n");
        else {
           printf("[System] %s : You want to update info of this player? (yes : 1) : ",cur->name);
           scanf("%d",&yes);

          if(yes!=1) return;
          if(cur->position ==0){
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

          else if(cur->position ==1){
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

          else if(cur->position ==2){
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
        int yes;
        node *cur, *subcur;
        cur = h->link;
        subcur=h;
        printf("[System] Which player will you delete? : ");
        getchar();
        fgets(name,sizeof(name),stdin);
        name[strlen(name)-1]='\0';

        while(cur!=NULL){
                if(strcasestr(cur->name,name)!=NULL){
                        printf("[System] %s : You want to delete this player? (yes : 1) : ",cur->name);
                        scanf("%d",&yes);
                        if(yes ==1){
                                subcur->link = cur->link;

                                free(cur);
                                break;
                        }
                        
                }
                cur = cur->link;
                subcur = subcur->link;
        }

        if(cur ==NULL ) printf("[System] The player doesn't exist. \n");
        else printf("[System] The deletion has been completed.\n");

}
 


void open_file(node *h){

        FILE *fp;
        node *tail;
        tail = NULL;
        char buffer[100];
        char *token;
        printf("[System] openfile...\n");
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
 

void data_player(node *t){ // 출력 화면을 다듬을 필요가 있음.
        printf("%-23s %-17s $%dm %5hu %5hu %8hu %8hu %8hu\n",t->name, t->main_position, t->price,t->stats, t->p1, t->p2, t->p3, t->p4);
}

void read_all_players(node *h){

        node *cur;
        cur = h->link;
        for (int i=0;i<3;i++){
            if(i == 0)      printf("\n----------------------[ Striker ]---------------------\n");
            else if(i == 1) printf("\n----------------------[ Defender ]--------------------\n");

            else printf("\n---------------------[ Goalkeeper ]-------------------\n");
       
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
        printf("[System] What position are you looking for? (0:st 1:df 2:gk) : ");
        scanf("%d",&position);

        if(position == 0)      printf("\n----------------------[ Striker ]---------------------\n");
        else if(position == 1) printf("\n----------------------[ Defender ]--------------------\n");

        else if(position == 2) printf("\n---------------------[ Goalkeeper ]-------------------\n");
        else {
            printf("[System] Please Enter Proper Number \n");
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
            if(i == 0)      printf("\n----------------------[ Striker ]---------------------\n");
            else if(i == 1) printf("\n----------------------[ Defender ]--------------------\n");

            else printf("\n---------------------[ Goalkeeper ]-------------------\n");
       
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

 



void buy_player(node *h,int *account,int n){

 
        char name[20];
        node *cur;
        int buy;
        printf("[System] Which player will you buy? : ");
        getchar();
        fgets(name,sizeof(name),stdin);
        name[strlen(name)-1]='\0';
 

        cur =find_name(h,name);

 
        if(cur == h ) printf("[System] The player doesn't exist. \n");
        else if(cur->usernum !=0) printf("[System] The player is sold. \n");
        else {
                if(*(account) <cur ->price) printf("[System] Your account is not enough\n");
                else {  
                        printf("[System] %s\n",cur->name);
                        printf("[System] Buy ? (yes : 1 No : 0) : ");
                        scanf("%d",&buy);
                        if(buy ==1){

                                cur->usernum = n;
                                *account -=cur->price;
                                printf("[System] The perchase has been completed.!\n Account : %d \n",*account);
                        }
                }
        }

}

void sell_player(node *h,int *account,int n){

 
        char name[20];
        node *cur;
        int sell;
        printf("[System] Wich player will you sell? : ");
        getchar();
        fgets(name,sizeof(name),stdin);
        name[strlen(name)-1]='\0';
 
        cur =find_name(h,name);

 
        if(cur == h ) printf("[System] The player doesn't exist. \n");
        else if(cur->usernum != n) printf("[System] The player isn't in your squad. \n");
        else {
                printf("[System] %s\n",cur->name);
                printf("[System] Sell ? (yes : 1 No : 0) : ");
                scanf("%d",&sell);
                if(sell == 1){
                        cur->usernum= 0;
                        *account +=cur->price;
                        printf("[System] The sales has been completed.!\n Account : %d \n",*account);
                }
        }

}

 
 
void cmp_player(node *h){

 
        node *cur,*cur2;
        char name[2][30];
        int serch;
        printf("[System] Enter the player you're looking for : ");
        getchar();
        fgets(name[0],sizeof(name[0]),stdin);
        name[0][strlen(name[0])-1]='\0';
        
        cur = find_name(h,name[0]);

 
        if(cur == h ) printf("[System] The player doesn't exist. \n");
        else{   
                printf("%s\n",cur->name);
                printf("[System] Compare?(1) No (0) : ");
                scanf("%d",&serch);
                if(serch ==1){
                        while(1){
                        printf("[System] Which player you want to compare (quit: q) : ");
                        getchar();
                        fgets(name[1],sizeof(name[1]),stdin);
                        name[1][strlen(name[1])-1]='\0';
                        if(strcmp(name[1],"q")==0) break;
 

                        cur2=find_name(h,name[1]);

 
                        if(cur2 == h ) printf("[System] The player doesn't exist. \n");
                        else if(cur->position == cur2->position){
                                break;
                        }
                        else printf("[System] Diffrent position \n");
                        }
                   }
               if(cur -> position == 0){
                        printf("\n----------------------[ Striker ]---------------------\n");
                        printf("Name                    Main position     Price Stats Pace Shooting Passing Dribbling\n");
                        

               }
                else if(cur -> position ==1){
                        printf("\n----------------------[ Defender ]--------------------\n");
                        printf("Name                    Main position     Price Stats Pace Physical Composure Defense\n");
                }
                else{
                        printf("\n---------------------[ Goalkeeper ]-------------------\n");
                        printf("Name                    Main position     Price Stats Diving Handling Kick Reaction\n");
                }
                

                data_player(cur);
                if((serch==1)&&(strcmp(name[1],"q")!=0)) data_player(cur2);

  
        }

}



int server_login(){
        int log;
        int s_log;
        int s_pw=2023; // 서버 관리자로 접근 가능한 패스워드
       
        
        printf("[System] Input password : ");
        scanf("%d",&s_log);
        if(s_log == s_pw) {
                printf("[System] Access as server admin \n");
                return 1;
        }
        else{
                printf("[System] You don't have access as server \n");
                return 0;
        }
                

}

int select_server(){
        int menu;
        printf("\n\n\n---------[ Server menu ]-----------\n\n");
        printf(" 1. Add player \n");
        printf(" 2. Update player \n");
        printf(" 3. Delete Player \n");
        printf(" 4. Read Player info\n");
        printf(" 0. Exit \n");
        printf("-------------------------\n");
        printf("[System] Input Number : ");
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
        printf("\n\n\n---------[ Client MENU ]-----------\n\n");
        printf(" 1. My squad \n");
        printf(" 2. Buy Player \n");
        printf(" 3. Sell Player \n");
        printf(" 4. Read Player info\n");
        printf(" 5. Compare players \n");
        printf(" 0. Exit \n");
        printf("-------------------------\n");
        printf("[System] Input Number : ");
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
        printf("[Register] Enter your New ID : ");
        scanf("%s",make_ID);
        while(!feof(p)){
            fscanf(p,"%d %s %d",&last_user_num,file_ID,&pw);
            if(strcmp(make_ID,file_ID)==0) exist =1;
        }
        if(exist==0) break;
        if(exist == 1) printf("[Register] Your ID exists already. \n");
        exist =0;

    }
    fclose(p);

    while(1){
        printf("[Register] Enter your password.(ONLY Number): ");
        scanf("%d",&make_PW);

        printf("[Register] Enter your password again. : ");
        scanf("%d",&verify_PW);
        if(make_PW==verify_PW) {
            printf("[Register] The Registration has been completed. Restart this program and login again please. \n");
            break;
        }
        else printf("[Register] Invalid Password. Set your password again.\n");

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
    printf("[System] Login(1) Registation(0) : ");
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

    printf("[System] ID : "); 
    scanf("%s",ID);

    p = fopen("login_info.txt","r");

    while(!feof(p)){
        fscanf(p,"%d %s %d",&user_num,cur,&pw);
        if(strcmp(ID,cur) == 0 ) {
            printf("[System] PW : ");
            scanf("%d",&PW);
            if(PW == pw) {
                printf("[System] Logged in successfully!\n");
                i=1;
            }
            else { 
                i=2;
                while(count<=3){
                    printf("[System] Invaild PW (%d/3)\n",count);
                    printf("[System] PW : ");
                    scanf("%d",&PW);
                    if(PW == pw) {
                        printf("[System] Logged in successfully!\n");
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
        printf("[System] Non-exist ID\n");
        user_num =0;
    }
    if(i==2) {
        printf("[System] Failed login\n");
        user_num =0;
    }

    fclose(p);

    return user_num;

}



void reset_data(node *t,node *h){
        node *t_cur;
        node *h_cur;
        open_demo_file(t);
        t_cur =t;
        h_cur = h;
        while(t_cur != NULL){ // 기존에 존재했던 유저 구매목록을 업데이트 시킨다. 
                h_cur = find_name(h,t_cur->name);
                if(h_cur != h ) t_cur -> usernum = (h_cur->usernum);
                t_cur = t_cur->link;
        }

        deallocation(h);                 

}

void open_demo_file(node *h){

        FILE *fp;
        node *tail;
        tail = NULL;
        char buffer[100];
        char *token;
        int stat; 
        int s[4];
        int pre_price=0;
        int n[150];
        int c=0;
        srand(time(NULL));
        for (int i =0;i<150;i++){
                n[i]=rand();
        }
        printf("open demo file\n");
        for(int i=0;i<3;i++){ // 총 3개의 파일을 열어서 읽는다. 
                if(i==0) fp = fopen("demo_striker.txt","r");
                else if(i==1) fp = fopen("demo_defender.txt","r");
                else fp = fopen("demo_goalkeeper.txt","r");
                stat = 102;

                if(fp ==NULL) {
                        fclose(fp);

                }
                else {
                        while(!feof(fp)){
                                node *new;
                                new= (node *)malloc(sizeof(node));
                                fgets(buffer,sizeof(buffer),fp); // 파일에서 한줄을 받아온다.
                        
                                token = strtok(buffer,"\t"); // ','를 기준으로 단어를 나눈다. 
                                strcpy(new->name,token);
                                token = strtok(NULL,"\t");
                                strcpy(new->main_position,token);
                                token = strtok(NULL,"\t");
                                new->price = atoi(token);
                                new->usernum= 0;
                                
                                random_stat_allocation(s,n[c]);
                                c++;
                                if(pre_price != new->price) {
                                        stat -=2;
                                        pre_price = new->price;
                                }
                                new->p1= stat + s[0];
                               
                                new->p2= stat + s[1];
                            
                                new->p3= stat + s[2];
                               
                                new->p4= stat + s[3];
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
        printf("close demo file\n");
}



void random_stat_allocation(int *s,int n){ // 가격에 따른 총 스탯은 같지만 점수를 할당하는 방식은 다르게 하고 싶어서 고안했다. 

        srand((unsigned)n);
        
        int form1,form2;
        int alloc_presedure[4]; // 스탯 4가지 중에 값을 랜덤하게 할당할 리스트 // 내용의 의미는 stat의 index 번호이다. 
        
        
        for(int i=0;i<4;i++){ // 중복없이 stat list에 값을 할당할 순서를 정했다. 
                alloc_presedure[i] = rand()%4;
                for(int j=0;j<i;j++){
                        if(alloc_presedure[i]==alloc_presedure[j]) i--;
                }
        }
        form1 = rand()%6; // 0~5까지 stat의 값을 넣는다. 
        form2 = rand()%6; // 0~5까지 stat의 값을 넣는다. 
        s[alloc_presedure[0]] = form1;
        s[alloc_presedure[1]] = form2;
        if(form1 == 0 ) s[alloc_presedure[2]] = 0;
        else s[alloc_presedure[2]] = -form1;
        if(form2 == 0 ) s[alloc_presedure[3]] = 0;
        else s[alloc_presedure[3]] = -form2;
        //위 스탯에 할당할 값들의 총합은 0이 되어야한다. 따라서 양수로 나왔으면 반드시 똑같은 값의 음수를 할당해줘야하고, 0이 나왔다면 0도 할당해줘야한다. 
}

