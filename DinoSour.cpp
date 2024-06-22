#define _CRT_SECURE_NO_WARNINGS
#define TreeHigh 19
#define DinoY 11
#define TreeDistance 80
#define CRT_SECURE_NO_WARNINGS
#define CLS system("cls")

#include <stdio.h>
#include <windows.h>
#include <stdbool.h>
#include <conio.h>


void SetConsoleView(); // 콘솔창 크기 조정하기
void gotoXY(int x, int y); // X좌표와 Y좌표 조정하기
void DinoSour(int Dinoleg); // 공룡그림 그리기
void Tree1(int TreePosition); // 첫번째 나무 모양 그리기
void Tree2(int TreePostin1); // 두번째 나무 모양 그리기
int GetKeyDown(); // 문자를 받는 함수


int DinolegsSwing = true; // 공룡의 다리 초깃값을 true로 놓고 함수에 대입


int main(void)
{
    int TreeX2_Flag = 0; // 두번째 트리가 나오는 주기 설정
    int DinosourHigh = DinoY; // 공룡의 높이를 11로 지정
    int TreeX1 = TreeDistance; //첫번째 나무의 거리를 80으로 지정
    int TreeX2 = TreeDistance; // 두번째 나무의 거리를 80으로 지정
    int Jumping = false; // 처음 점프의 값을 false를 두고 시작
    int Bottom = true; // 공룡이 바닥에 있어야만 점프를 뛸 수 있음
    int JumpingLevel = false; // 점프의 최댓값에 다했다면 내려가기 위한 변수
    int StartOrder = 0;
    int UsersOrder = 0;
    int Score = 0;
    int End = 0;
    SetConsoleView();

    // 게임 메뉴 화면
    if (StartOrder == 0)
    {
        printf("         ============================================================================\n");
        printf("         |                                                                          |\n");
        printf("         |        ====        ==========    || ＼        ||      ==========         |\n");
        printf("         |        ||   ＼         | |       ||  ＼       ||     /          ＼       |\n");
        printf("         |        ||    ＼        | |       ||   ＼      ||    /            ＼      |\n");
        printf("         |        ||     |        | |       ||    ＼     ||   |              |      |\n");
        printf("         |        ||     |        | |       ||     ＼    ||   |              |      |\n");
        printf("         |        ||    /         | |       ||      ＼   ||   ＼             /      |\n");
        printf("         |        ||   /          | |       ||       ＼  ||    ＼           /       |\n");
        printf("         |        ====         ==========   ||        ＼ ||       =========         |\n");
        printf("         |                                                                          |\n");
        printf("         |         =======        ===========      =====        =====   ======      |\n");
        printf("         |       /               /            ＼      |            |    |      ＼   |\n");
        printf("         |      |               /              ＼     |            |    |       |   |\n");
        printf("         |       ＼            |                |     |            |    |       /   |\n");
        printf("         |         =======     |                |     |            |    |======     |\n");
        printf("         |                 |    ＼             /      |            |    | ＼        |\n");
        printf("         |                 /     ＼           /       ＼           /    |   ＼      |\n");
        printf("         |                /        ==========          ＼         /     |     ＼    |\n");
        printf("         |        ========                               ========                   |\n");
        printf("         ============================================================================\n");

    }

    // 게임 선택 메뉴
    printf("           1. 플  레  이                 2. 게  임  종  료                 3.빠 르 게           \n");
    printf("                                                  ");
Start:
    scanf("%d", &UsersOrder);

    // 만약 사용자가 2를 입력했다면 게임을 종료
    if (UsersOrder == 2)
    {
        printf("게임을 종료합니다.\n");
        exit(1);
    }
    // 사용자가 1을 입력헀다면 게임을 시작
    if (UsersOrder == 1)
    {
        printf("로  딩  중....");
        Sleep(1000); // 게임을 시작하기 전 콘솔을 잠깐 멈춤
        CLS;
        while (true)
        {
            Score++; // 점수를 위한 변수
            if (GetKeyDown() == ' '&&Bottom) //만약 스페이스 바를 입력하고 공룡이 바닥에 위치한다면 점프 가능
            {
                Bottom = false; //점프를 한다면 bottom이 거짓으로 변한다.
                Jumping = true;
            }

            if (Jumping)
            {
                DinosourHigh--; // 점프할때 y좌표 감소

            }

            if (DinosourHigh == 2) //만약 공룡이 일정 높이가 된다면 내려가야함 (공룡 높이의 한계)
            {
                JumpingLevel = true;
            }

            if (JumpingLevel)
            {
                DinosourHigh = DinoY; // 점프 높이를 DinoY(11)로 초기화
            }

            if (DinosourHigh == 11) // 만약 공룡이 원 위치로 돌아왔다면 다시 키입력을 받기 위한 변수들을 초기화
            {
                JumpingLevel = false;
                Jumping = false;
                Bottom = true;
            }

            TreeX1 -= 2; // 1번째 나무를 움직이는 변수

            if (TreeX1 <= 3) 
            {
                TreeX1 = TreeDistance; // 1번째 나무의 x좌표가 3보다 작아진다면 나무의 위치 초기화
            }

            if (TreeX1 == 40)
            {
                TreeX2_Flag += 1;; // 1번째 트리의 위치가 중간에 왔다면 2번째 트리 출력을 위한 변수 초기화
            }

            if (TreeX2_Flag == 1)
            {
                Tree2(TreeX2);
                TreeX2 -= 2;
            }

            if (TreeX2 <= 3)
            {
                TreeX2 = TreeDistance; // 2번째 트리의 x좌표가 3보다 작아진다면 위치 초기화
                TreeX2_Flag = 0;
            }


            if (TreeX1 == 7 || TreeX1 == 8) // 만약 1번째 트리의 x좌표가 7 또는 8이라면 (공룡 주위)
            {
                if (DinosourHigh == 11 || DinosourHigh == 10 || DinosourHigh == 9) // 공룡이 점프를 하지 않거나 조건보다 작게 점프했을때 (충돌처리)
                {
                    End++; // 게임 종료를 위한 변수 증가
                    CLS;
                    break;
                }
            }

            if (TreeX2 == 7 || TreeX2 == 8) //2번째 트리의 x좌표가 7 혹은 8이 되었을때 (공룡 주위)
            {
                if (DinosourHigh == 11 || DinosourHigh == 10 || DinosourHigh == 9) // 공룡이 점프를 하지 않거나 조건보다 작게 점프했을떄 (충돌처리)
                {
                    End++; // 게임 종료를 위한 변수 증가
                    CLS;
                    break;
                }
            }
            Tree1(TreeX1);
            DinoSour(DinosourHigh);

            Sleep(100);
            CLS;
        }
    }else if(UsersOrder==3)
    {
        printf("로  딩  중....");
        Sleep(1000); // 게임을 시작하기 전 콘솔을 잠깐 멈춤
        CLS;
        while (true)
        {
            Score++; // 점수를 위한 변수
            if (GetKeyDown() == ' '&&Bottom) //만약 스페이스 바를 입력하고 공룡이 바닥에 위치한다면 점프 가능
            {
                Bottom = false; //점프를 한다면 bottom이 거짓으로 변한다.
                Jumping = true;
            }

            if (Jumping)
            {
                DinosourHigh--; // 점프할때 y좌표 감소

            }

            if (DinosourHigh == 2) //만약 공룡이 일정 높이가 된다면 내려가야함 (공룡 높이의 한계)
            {
                JumpingLevel = true;
            }

            if (JumpingLevel)
            {
                DinosourHigh = DinoY; // 점프 높이를 DinoY(11)로 초기화
            }

            if (DinosourHigh == 11) // 만약 공룡이 원 위치로 돌아왔다면 다시 키입력을 받기 위한 변수들을 초기화
            {
                JumpingLevel = false;
                Jumping = false;
                Bottom = true;
            }

            TreeX1 -= 2; // 1번째 나무를 움직이는 변수

            if (TreeX1 <= 3) 
            {
                TreeX1 = TreeDistance; // 1번째 나무의 x좌표가 3보다 작아진다면 나무의 위치 초기화
            }

            if (TreeX1 == 40)
            {
                TreeX2_Flag += 1;; // 1번째 트리의 위치가 중간에 왔다면 2번째 트리 출력을 위한 변수 초기화
            }

            if (TreeX2_Flag == 1)
            {
                Tree2(TreeX2);
                TreeX2 -= 2;
            }

            if (TreeX2 <= 3)
            {
                TreeX2 = TreeDistance; // 2번째 트리의 x좌표가 3보다 작아진다면 위치 초기화
                TreeX2_Flag = 0;
            }


            if (TreeX1 == 7 || TreeX1 == 8) // 만약 1번째 트리의 x좌표가 7 또는 8이라면 (공룡 주위)
            {
                if (DinosourHigh == 11 || DinosourHigh == 10 || DinosourHigh == 9) // 공룡이 점프를 하지 않거나 조건보다 작게 점프했을때 (충돌처리)
                {
                    End++; // 게임 종료를 위한 변수 증가
                    CLS;
                    break;
                }
            }

            if (TreeX2 == 7 || TreeX2 == 8) //2번째 트리의 x좌표가 7 혹은 8이 되었을때 (공룡 주위)
            {
                if (DinosourHigh == 11 || DinosourHigh == 10 || DinosourHigh == 9) // 공룡이 점프를 하지 않거나 조건보다 작게 점프했을떄 (충돌처리)
                {
                    End++; // 게임 종료를 위한 변수 증가
                    CLS;
                    break;
                }
            }
            Tree1(TreeX1);
            DinoSour(DinosourHigh);

            Sleep(20);
            CLS;
        }
    }

    else //UsersOrder가 올바르게 입력되지 않았을 경우
    {
        printf("올바른 숫자를 입력하세요");
        goto Start; //69번째 Start: 로 이동하여 입력을 다시 받음
    }

    if (End == 1) // 게임이 끝났을 경우 
    {
           printf("\n\n");
        printf("     =======================================================================================\n"); Sleep(100);
        printf("     |      =========           ======     =======        ======           =========        |\n"); Sleep(100);
        printf("     |     /                   /          /       ＼     /      |          |                |\n"); Sleep(100);
        printf("     |    |                   /          /         ＼    |      |          |                |\n"); Sleep(100);
        printf("     |    ＼                 /           |          |    |      /          |                |\n"); Sleep(100);
        printf("     |      =========       |            |          |    |    /            |=========       |\n"); Sleep(100);
        printf("     |              |       |            ＼         /    |=====            |                |\n"); Sleep(100);
        printf("     |              |       ＼            ＼       /     |＼               |                |\n"); Sleep(100);
        printf("     |             /         ＼             ======       |   ＼            |                |\n"); Sleep(100);
        printf("     |      =======            =======                                     ==========       |\n"); Sleep(100);
        printf("     |                                                                                      |\n"); Sleep(100);
        printf("     |                                                                                      |\n"); Sleep(100);
        printf("     |                                                                                      |\n"); Sleep(100);
        printf("     |                            당신의 점수는 ? : %d                                      |\n", Score); Sleep(100);
        printf("     |                                                                                      |\n"); Sleep(100);
        printf("     |                                                                                      |\n"); Sleep(100);
        printf("     =======================================================================================\n"); Sleep(100);
       printf("                           1. 다 시 하 기                  2. 게  임  종  료                  \n"); Sleep(100);

         scanf("%d", &UsersOrder);
         if(UsersOrder==1)
         {
            main();
      }
      else if(UsersOrder==2)
      {
         exit(1);
      }
    }
}

void DinoSour(int DinoHeight) // 공룡을 나타내는 함수
{

    gotoXY(0, DinoHeight);
    {
        printf("         $$$$$$$  \n");
        printf("         $$ $$$$$ \n");
        printf("         $$$$$$$$ \n");
        printf("$       $$$      \n");
        printf("$$      $$$$$$   \n");
        printf("$$$    $$$$$     \n");
        printf(" $$   $$$$$$$$$  \n");
        printf(" $$$$$$$$$$$     \n");
        printf("   $$$$$$$$$     \n");
        printf("     $$$$$$$      \n");


        if (DinolegsSwing) // 공룡 발을 움직이는 조건
        {

            printf("     $    $$$\n");
            printf("     $$        ");
            DinolegsSwing = false;
        }

        else
        {
            printf("     $$$  $   \n");
            printf("          $$    ");
            DinolegsSwing = true;
        }
    }
}


void SetConsoleView()
{
    system("mode con cols=100 lines=25"); // 콘솔창을 가로 100 세로 25로 설정
    system("title Google DinoSour Game - YJM"); // 콘솔창 제목을 정함
}

void gotoXY(int x, int y) // 사물의 x좌표와 y좌표를 나타내는 함수
{
    COORD pos;
    pos.X = x;
    pos.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Tree1(int TreePosition) //첫번째 트리
{

    gotoXY(TreePosition, TreeHigh);
    printf("  # ");
    gotoXY(TreePosition, TreeHigh + 1);
    printf(" ### ");
    gotoXY(TreePosition, TreeHigh + 2);
    printf("#####");
    gotoXY(TreePosition, TreeHigh + 3);
    printf("  # ");
    gotoXY(TreePosition, TreeHigh + 4);
    printf("  # ");
}

void Tree2(int TreePostin1) // 두번째 트리
{
    gotoXY(TreePostin1, TreeHigh);
    printf("   #   ");
    gotoXY(TreePostin1, TreeHigh + 1);
    printf("#######");
    gotoXY(TreePostin1, TreeHigh + 2);
    printf("  ### ");
    gotoXY(TreePostin1, TreeHigh + 3);
    printf("  ### ");
    gotoXY(TreePostin1, TreeHigh + 4);
    printf("  ###  ");

}

int GetKeyDown() // 키 입력을 받는 함수
{
    if (_kbhit()!=0)
    {
        return getch();
    }
    return 0;
}
