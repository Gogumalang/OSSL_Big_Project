#include <stdio.h>

typedef struct {
  char ID[100]; // 아디디
  char PW[100]; // 비밀번호
} login_info;

void saveData(login_info a) { //로그인 정보 저장
  FILE *fp;
  fp = fopen("login_info.txt", "a");

  fprintf(fp, " %s %s \n", a.ID, a.PW);

  fclose(fp); //파일 닫기
}

void get_info() {
  login_info a;

  printf("Enter your ID : ");
  scanf("%s", a.ID);

  printf("Enter your PW : ");
  scanf("%s", a.PW);

  saveData(a);
}
