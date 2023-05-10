#include <stdio.h>
#include <string.h>

typedef struct {
  char ID[100]; // 아디디
  char PW[100]; // 비밀번호
} login_info;

void saveData(login_info *a) { //로그인 정보 저장
  FILE *fp;
  fp = fopen("login_info.txt", "a");

  fprintf(fp, " %s %s \n", a->ID, a->PW);

  fclose(fp); //파일 닫기
}

int login_compare(login_info *a, int count) {
  char log_id[100];
  char log_pw[100];

  for (int i = 0; i < count; i++) {
    printf("%s %s\n", a[i].ID, a[i].PW);
  }

  printf("[login] Enter your ID : ");
  scanf("%s", log_id);

  for (int i = 0; i < count; i++) {
    if (strcmp(a[i].ID, log_id) == 0) {
      printf("[login] Enter your PW : ");
      scanf("%s", log_pw);
      if (strcmp(a[i].PW, log_pw) == 0) {
        printf("you logged in!\n");
        return 1;
      } else {
        printf("pw invalid\n");
      }
    }
  }
  printf("[login] user not found \n");
  return 0;
}

void get_info(login_info a[]) {

  printf("Enter your ID : ");
  scanf("%s", a->ID);

  printf("Enter your PW : ");
  scanf("%s", a->PW);

  saveData(a);
}

int selectMenu() {
  int menu;
  printf("1. get info\n");
  printf("2. login\n");
  printf("7. exit\n");
  scanf("%d", &menu);

  return menu;
}

int main(void) {
  int count = 0;
  int menu;
  login_info a[20];

  while (1) {
    menu = selectMenu();
    if (menu == 1) {
      get_info(&a[count]);
      count++;
    }

    else if (menu == 2) {
      int try = login_compare(a, count);
      if (try == 1) {

        // 로그인 성공했다고 띄우고 접속시키기
        printf("hello \n");
      }
    }

    else if (menu == 7) {
      printf("bye");
      break;
    }
  }

  return 0;
}
