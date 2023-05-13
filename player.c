#include "player.h"
// 이것은 플레이어 데이터를 담을 수 있는 코드 입니다! 


void set_data(node *h){ // addPlayer를 실행할 때 값을 넣을 보조 함수

        printf("Player name : ");
        scanf("%s",h->name);
        getchar();
        while(1){

        printf("Position(s/d/g) : ");
        scanf("%c",&h->position);
        if(h->position == 's' ||h->position == 'g' ||h->position == 'd' ) break;

        }

        printf("Price : ");
        scanf("%d",&h->price);

        if(h->position =='s'){
                printf("Pace : ");
                scanf("%hu",&h->p1);
                printf("Shooting : ");
                scanf("%hu",&h->p2);
                printf("Passing : ");
                scanf("%hu",&h->p3);
                printf("Dribbling : ");
                scanf("%hu",&h->p4);
                h->stats=((h->p1)+(h->p2)+(h->p3)+(h->p4))/4;
        }
	else if(h->position =='d'){
                printf("Pace : ");
                scanf("%hu",&h->p1);
                printf("Physical : ");
                scanf("%hu",&h->p2);
                printf("Composure : ");
                scanf("%hu",&h->p3);
                printf("Defence : ");
                scanf("%hu",&h->p4);
                h->stats=((h->p1)+(h->p2)+(h->p3)+(h->p4))/4;
        }

        else if(h->position =='g'){
                printf("Diving : ");
                scanf("%hu",&h->p1);
                printf("Handling : ");
                scanf("%hu",&h->p2);
                printf("Kick : ");
                scanf("%hu",&h->p3);
                printf("Reaction : ");
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
                if(strcmp(cur->name,name)==0){
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
        printf("Wich player will you update? : ");
        scanf("%s",name);
 

        cur =find_name(h,name);

 
        if(cur == h ) printf("The player doesn't exist. \n");
        else {
          if(cur->position =='s'){
                printf("Pace : ");
                scanf("%hu",&cur->p1);
                printf("Shooting : ");
                scanf("%hu",&cur->p2);
                printf("Passing : ");
                scanf("%hu",&cur->p3);
                printf("Dribbling : ");
                scanf("%hu",&cur->p4);
                cur->stats = ((cur->p1)+(cur->p2)+(cur->p3)+(cur->p4))/4;
          }

          else if(cur->position =='d'){
                printf("Pace : ");
                scanf("%hu",&cur->p1);
                printf("Physical : ");
                scanf("%hu",&cur->p2);
                printf("Composure : ");
                scanf("%hu",&cur->p3);
                printf("Defence : ");
                scanf("%hu",&cur->p4);
                cur->stats = ((cur->p1)+(cur->p2)+(cur->p3)+(cur->p4))/4;
          }

          else if(cur->position =='g'){
                printf("Diving : ");
                scanf("%hu",&cur->p1);
                printf("Handling : ");
                scanf("%hu",&cur->p2);
                printf("Kick : ");
                scanf("%hu",&cur->p3);
                printf("Reaction : ");
                scanf("%hu",&cur->p4);
                cur->stats = ((cur->p1)+(cur->p2)+(cur->p3)+(cur->p4))/4;
           }

         printf("The update has been completed.\n");

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
        fp = fopen("server.txt","r"); // 서버파일을 읽기모드로 연다.
        if(fp ==NULL) {
                fclose(fp);

        }
        else {
                while(!feof(fp)){
                        node *new;
                        new= (node *)malloc(sizeof(node));
                        fscanf(fp,"%s %c %d %d %hu %hu %hu %hu",new->name,&new->position, &new->price, &new->sold, &new->p1, &new->p2, &new->p3, &new->p4);
                        if(new->price  ==0){ // feof가 제대로 실행되지 않는 것 >같아서 조건 하나를 더 주었다.
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

void server_filesave(node *h){
        FILE *fp;
        fp = fopen("server.txt","w");
        node *cur;
        cur = h->link;
        while(cur!=NULL){
                fprintf(fp,"%s %c %d %d %hu %hu %hu %hu\n",cur->name,cur->position, cur->price, cur->sold, cur->p1, cur->p2, cur->p3, cur->p4);
                cur = cur -> link;
        }
        fclose(fp);



}
 

void data_player(node *t){
        printf("%9s %4d %4u %5u %5hu %8hu %8hu\n",t->name, t->price,t->stats, t->p1, t->p2, t->p3, t->p4);
}

void read_player(node *h){


        node *cur;
        cur = h;
        printf("\n--------------------------Striker--------------------------\n");
        printf("     Name Price Stats Pace Shooting Passing Dribbling\n");

        while(cur != NULL){
 

                if(cur->position == 's'&&cur->sold == false) data_player(cur);

 
                cur = cur->link;
        }
        cur =h;

        printf("\n--------------------------Defender-------------------------\n");
        printf("     Name Price Stats Pace Physical Composure Defense\n");

        while(cur != NULL){
 

                if(cur->position == 'd'&&cur->sold == false) data_player(cur);

 
                cur = cur->link;
        }
        cur =h;

        printf("\n-------------------------Goalkeeper------------------------\n");
        printf("     Name Price Stats Diving Handling Kick Reaction\n");

        while(cur != NULL){
 
                if(cur->position == 'g'&&cur->sold == false) data_player(cur);

 
                cur = cur->link;
        }


}


 

void read_squad(node *h){

 
        node *cur;
        cur = h;
        printf("\n--------------------------Striker--------------------------\n");
        printf("     Name Price Stats Pace Shooting Passing Dribbling\n");

        while(cur != NULL){
 

                if(cur->position == 's'&&cur->sold == true) data_player(cur);

 
                cur = cur->link;
        }
        cur =h;

        printf("\n--------------------------Defender-------------------------\n");
        printf("     Name Price Stats Pace Physical Composure Defense\n");

        while(cur != NULL){
 

                if(cur->position == 'd'&&cur->sold == true) data_player(cur);

 
                cur = cur->link;
        }
        cur =h;

        printf("\n-------------------------Goalkeeper------------------------\n");
        printf("     Name Price Stats Diving Handling Kick Reaction\n");

        while(cur != NULL){
 

                if(cur->position == 'g'&&cur->sold == true) data_player(cur);

 
                cur = cur->link;
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
        printf("Access as Server(0) or Client(1): ");
        scanf("%d",&log);
        if(log==0){
                printf("Input password : ");
                scanf("%d",&s_log);
                if(s_log == s_pw) {
                        printf("Access as server \n");
                        return 0;
                }
                else{
                        printf("Access as client \n");
                        return 1;
                }
                }
        else{
                        printf("Access as client \n");
                        return 1;

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



int client_account(){
        int a;
        FILE *fp;
        fp = fopen("account.txt","r");
        fscanf(fp,"%d",&a);
        fclose(fp);
        return a;

}

void save_account(int u,int n){
        FILE *fp;
        fp = fopen("account.txt","w");
        int i=0;

        while(account_list[i]!=-1){
            if(i+1==u) fprintf(fp,"%d",n);
            else  fprintf(fp,"%d",account_list[i]);
            i++;
        }
        
        fclose(fp);

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

void sign_in(){
    FILE *p;
    p= fopen("login_info.txt","r");
    char make_ID[20];
    char file_ID[20];
    int make_PW;
    int verify_PW;
    int exist=0;
    int default_account;

    while(1){ //아이디 정하기 
        printf("생성할 아이디를 입력하세요. : ");
        scanf("%s",make_ID);
        while(!feof(p)){
            fscanf(p,"%s",file_ID);
            if(strcmp(make_ID,file_ID)==0) {
                exist =1;
                break;
            }
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

    fprintf(p,"%s %d\n",make_ID,make_PW);
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


