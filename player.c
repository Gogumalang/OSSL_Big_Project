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
                                new->stats=((new->p1)+(new->p2)+(new->p3)+(new->p4))/4;
                                new->link = h->link;
                                h->link = new;

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

int login(){
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

void save_account(int num){
        FILE *fp;
        fp = fopen("account.txt","w");
        fprintf(fp,"%d",num);
        fclose(fp);

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
