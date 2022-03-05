#include <stdio.h>
#include <stdlib.h>
#include <stdio.h>   //для стандартних вводу-виводу
#include <windows.h> // для HANDLE, курсора, кольора,
#include <conio.h>   //для kbhit, getch


void gotoxy(const int X,const int Y)    //визначення gotoxy
{
    HANDLE OutputHandle;
    CONSOLE_SCREEN_BUFFER_INFO ScreenBufInfo;
    OutputHandle=GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(OutputHandle,&ScreenBufInfo);
    ScreenBufInfo.dwCursorPosition.X=X;
    ScreenBufInfo.dwCursorPosition.Y=Y;
    SetConsoleCursorPosition(OutputHandle,ScreenBufInfo.dwCursorPosition);
}


void frame(int x1, int y1, int x2, int y2) //визначення рамки рамку
{
    int i;
    for (i = y1 + 1; i < y2; i++)
    {
        gotoxy(x1, i);
        printf("%c",'\272');
        gotoxy(x2, i);
        printf("%c",'\272');
    }
    for (i = x1 + 1; i < x2; i++)
    {
         gotoxy(i, y1);
         printf("%c", '\315');
         gotoxy(i, y2);
         printf("%c", '\315');
    }
    gotoxy(x1, y1);
    printf("%c", '\311');
    gotoxy(x1, y2);
    printf("%c", '\310');
    gotoxy(x2, y1);
    printf("%c", '\273');
    gotoxy(x2, y2);
    printf("%c", '\274');
}


void text(int x1, int y1, int x2, int y2)  //добавляю в рамку текст з інформацією
{
    int x = (x1 + x2 - 1) /3, y = (y1 + y2 - 1) / 2;
    gotoxy((x-12), (y-3));
     printf("Programming");
    gotoxy(x-12, y-1);
     printf("DKR");
    gotoxy(x-12, y+1);
     printf("variant 12");
    gotoxy(x-12,y2-1);
     printf("Kyiv 2020");
     gotoxy(x2-15, y2-3);
     printf("Rybalka Vikroriia");
    gotoxy(x2-15, y2-1);
     printf("NTUU ""KPI"", FPM, KV-01\n\n");

}


void sleep(int ms)   // затримка рамки перед глядачем перед тим, як почнеться програма
{
while (ms -- > 0)
    usleep(1000);
}


void func(int mas[3], const int n) //визначаю функцію, яка проводить операції з невідомими, що відповідають дню, місяцю і року
{
    int a, b, c, d;
    printf("\n\t   insert day(from 1 to 31): ");
    scanf("%d", &mas[0]);
    printf("\n\n\t   insert month(from 1 to 12): ");
    scanf("%d", &mas[1]);
    printf("\n\n\t   insert year(from 1800 to 2030): ");
    scanf("%d", &mas[2]);
    if(32 > mas[0] && 13 > mas[1] && mas[0] > 0 && mas[1] >= 1 && mas[2] > 1800 && mas[2] < 2031)
    {
        a=mas[0], b=mas[1], c=mas[2];
        d=28+(b+b/8)%2+2%b+(1/b)*2;
        if(a==1 && b==1)
        {
            a=d;
            b=12;
            c--;
        }
        else if(a==1 && b!=1)
        {
            a=d;
            b--;
        }
        else
        {
           a--;
        }
        mas[0]=a;
        mas[1]=b;
        mas[2]=c;
    }
    else
    {
        printf("\n\t   undefined, check your input. The restrictions for dd/mm/yyyy are above");
    }
}


void func2(int mas[3], const int n)        // визначаю функцію, яка виводить поппередню дату
{
    if(32 > mas[0] && 13 > mas[1] && mas[0] > 0 && mas[1] >= 1 && mas[2] > 1800 && mas[2] < 2031)
    {
        printf("\n\t   The privious date is: ");
        for(int i=0; i < n; i++)
        {
            printf("%d ", mas[i]);
        }
    }
    printf("\n");
}


int main()
{
    int a=100,b=20;
    frame(1,1,a,b);
    text(4,3,75,10);
    sleep(1000);
    printf("\n\n=================================================================================================\n\n");
    printf("This program gives you the previous date when you enter dd/mm/yyyy within the restrictions below\n");
    printf("\n=================================================================================================\n\n");
    const int n = 3;
    const int numbers;
    int mas[3];
    printf("How many times would you like to use this program before exiting?: ");
    scanf("%d", &numbers);
    for(int i=0; i<numbers; i++)
    {
        func(mas, 3);
        func2(mas, 3);
    }
    printf("\nEnd of the program. Press any bottom to escape.\n");
    return 0;
}
