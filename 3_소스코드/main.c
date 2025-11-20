#include <stdio.h>
#include <string.h>

/*
    1. [설계]에서 정의한 변수, 배열, 구조체를 선언
*/

struct Train {
    int trainNumber;     // 기차 번호
    char departure[20];  // 출발역
    char arrival[20];    // 도착역
    char time[10];       // 출발 시간
};

struct Train trains[100];   // 기차 정보 최대 100개 저장
int count = 0;              // 현재 등록된 기차 수


/*
    2. [알고리즘]에서 설계한 핵심 기능 함수 선언
*/

void 기차정보등록();
void 기차정보조회();
void 전체기차목록보기();


int main() {

    int menu;

    printf("--- C언어 미니 프로젝트 시작! ---\n");

    while (1) {
        printf("\n===== 메뉴 =====\n");
        printf("1. 기차 정보 등록\n");
        printf("2. 기차 정보 조회\n");
        printf("3. 전체 기차 목록 보기\n");
        printf("4. 종료\n");
        printf("메뉴 선택: ");
        scanf("%d", &menu);

        if (menu == 1) {
            기차정보등록();
        }
        else if (menu == 2) {
            기차정보조회();
        }
        else if (menu == 3) {
            전체기차목록보기();
        }
        else if (menu == 4) {
            printf("프로그램을 종료합니다.\n");
            break;
        }
        else {
            printf("잘못된 입력입니다.\n");
        }
    }

    return 0;
}



/*
    ===== 핵심 기능 1: 기차 정보 등록 =====
*/
void 기차정보등록() {

    if (count >= 100) {
        printf("더 이상 등록할 수 없습니다.\n");
        return;
    }

    printf("기차 번호 입력: ");
    scanf("%d", &trains[count].trainNumber);

    printf("출발역 입력: ");
    scanf("%s", trains[count].departure);

    printf("도착역 입력: ");
    scanf("%s", trains[count].arrival);

    printf("출발 시간 입력(예: 14:30): ");
    scanf("%s", trains[count].time);

    count++;

    printf("기차 정보 등록이 완료되었습니다.\n");
}



/*
    ===== 핵심 기능 2: 기차 정보 조회 =====
*/
void 기차정보조회() {

    int searchNo;
    int found = 0;

    printf("조회할 기차 번호 입력: ");
    scanf("%d", &searchNo);

    for (int i = 0; i < count; i++) {
        if (trains[i].trainNumber == searchNo) {
            printf("\n--- 조회 결과 ---\n");
            printf("기차 번호: %d\n", trains[i].trainNumber);
            printf("출발역: %s\n", trains[i].departure);
            printf("도착역: %s\n", trains[i].arrival);
            printf("출발 시간: %s\n", trains[i].time);

            found = 1;
            break;
        }
    }

    if (!found) {
        printf("해당 기차 정보를 찾을 수 없습니다.\n");
    }
}



/*
    ===== 핵심 기능 3: 전체 기차 목록 보기 =====
*/
void 전체기차목록보기() {

    if (count == 0) {
        printf("등록된 기차 정보가 없습니다.\n");
        return;
    }

    printf("\n===== 전체 기차 목록 =====\n");

    for (int i = 0; i < count; i++) {
        printf("[%d번째 기차]\n", i + 1);
        printf("기차 번호: %d\n", trains[i].trainNumber);
        printf("출발역: %s\n", trains[i].departure);
        printf("도착역: %s\n", trains[i].arrival);
        printf("출발 시간: %s\n\n", trains[i].time);
    }
}