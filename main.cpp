//start
#include <windows.h>    //include header files
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>


#define FILE_MENU_ABOUT 99  //defining program resources/constants
#define FILE_MENU_EXIT 98
#define BTN_PRESS 97
#define BUTTON_PRESS1 1
#define BUTTON_PRESS2 2
#define BUTTON_PRESS3 3
#define BUTTON_PRESS4 4
#define BUTTON_PRESS5 5
#define BUTTON_PRESS6 6
#define BUTTON_PRESS7 7
#define BUTTON_PRESS8 8
#define BUTTON_PRESS9 9
#define BUTTON_PRESS0 10
#define DIV 11
#define MUL 12
#define ADD 13
#define SUB 14
#define DOT 15
#define EQUAL 16
#define BUTTON_CLEAR 17
#define BUTTON_SQRT 18



LRESULT CALLBACK WindowProcedure(HWND, UINT, WPARAM, LPARAM);   //function prototypes
void AddControls(HWND);
void AddMenus(HWND);
void loadImages();
void AppendText(HWND, LPCTSTR);

HMENU hMenu;        //for calculator menu
HWND btnPress, hOutput;     //windows handlers
HBITMAP b1, b2, b3, b4, b5, b6, b7, b8, b9, b0, bAdd, bSub, bDiv, bMul, bDot, bEqual, bClear, bSqrt;    //bitmap images

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR args, int ncmdshow){     //creating the parent window


    WNDCLASSW wc = {0};         //creating the window class

    wc.hbrBackground = (HBRUSH) COLOR_WINDOW+6; //background color
    wc.hCursor = LoadCursor (NULL, IDC_ARROW);  //window cursor
    wc.hInstance = hInst;
    wc.lpszClassName = L"myWindowClass";        //defining class name
    wc.lpfnWndProc = WindowProcedure;           //calling window procedure

    if(!RegisterClassW(&wc))
        return -1;

    CreateWindowW(L"myWindowClass", L"Basic Calculator", WS_OVERLAPPEDWINDOW | WS_VISIBLE | ES_LEFT,
                  400, 100, 350, 480, NULL, NULL, NULL, NULL);   //parent window

    MSG msg = {0};

    while(GetMessage(&msg, NULL, NULL, NULL)){
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }

    return 0;
}

LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT msg, WPARAM wp, LPARAM lp){        //window procedure containing all window functionalities

    int mbVal;                          //declaring variables
    char fVal[100], sVal[100];
    bool operation = FALSE;
    TCHAR szBuffer[16];

    switch(msg){
    static double firstVal, secondVal, result;      //static variables
    static char op;

            case WM_COMMAND:{   //WM_COMMAND for any window actions

                if (LOWORD(wp) == BUTTON_PRESS1){       //accessing button events
                    AppendText(hOutput, TEXT("1"));}    //appending user input (button) to the edit text box
                if (LOWORD(wp) == BUTTON_PRESS2){
                    AppendText(hOutput, TEXT("2"));}
                if (LOWORD(wp) == BUTTON_PRESS3){
                    AppendText(hOutput, TEXT("3"));}
                if (LOWORD(wp) == BUTTON_PRESS4){
                    AppendText(hOutput, TEXT("4"));}
                if (LOWORD(wp) == BUTTON_PRESS5){
                    AppendText(hOutput, TEXT("5"));}
                if (LOWORD(wp) == BUTTON_PRESS6){
                    AppendText(hOutput, TEXT("6"));}
                if (LOWORD(wp) == BUTTON_PRESS7){
                    AppendText(hOutput, TEXT("7"));}
                if (LOWORD(wp) == BUTTON_PRESS8){
                    AppendText(hOutput, TEXT("8"));}
                if (LOWORD(wp) == BUTTON_PRESS9){;
                    AppendText(hOutput, TEXT("9"));}
                if (LOWORD(wp) == BUTTON_PRESS0){
                    AppendText(hOutput, TEXT("0"));}
                if (LOWORD(wp) == DOT){
                    AppendText(hOutput, TEXT("."));}
                else if (LOWORD(wp) == DIV){
                    operation = TRUE;
                    GetWindowText (hOutput, fVal, 100);             //getting text inside the edit text box
                    firstVal = static_cast<double>(atof(fVal));     //converting a LPWSTR to a static double for calculation
                    op = '/';
                    SetWindowText(hOutput, "/");}   //displaying operation
                else if (LOWORD(wp) == MUL){
                    operation = TRUE;
                    GetWindowText (hOutput, fVal, 100);
                    firstVal = static_cast<double>(atof(fVal));
                    op = '*';
                    SetWindowText(hOutput, "x");}
                else if (LOWORD(wp) == ADD){
                    operation = TRUE;
                    GetWindowText (hOutput, fVal, 100);
                    firstVal = static_cast<double>(atof(fVal));
                    op = '+';
                    SetWindowText(hOutput, "+");}
                else if (LOWORD(wp) == SUB){
                    operation = TRUE;
                    GetWindowText (hOutput, fVal, 100);
                    firstVal = static_cast<double>(atof(fVal));
                    op = '-';
                    SetWindowText(hOutput, "-");}

                    if (operation == TRUE){         //getting second value by allowing the user to press numerical buttons

                        SetWindowText(hOutput, "");
                        if (LOWORD(wp) == BUTTON_PRESS1){
                            AppendText(hOutput, TEXT("1"));}
                        if (LOWORD(wp) == BUTTON_PRESS2){
                            AppendText(hOutput, TEXT("2"));}
                        if (LOWORD(wp) == BUTTON_PRESS3){
                            AppendText(hOutput, TEXT("3"));}
                        if (LOWORD(wp) == BUTTON_PRESS4){
                            AppendText(hOutput, TEXT("4"));}
                        if (LOWORD(wp) == BUTTON_PRESS5){
                            AppendText(hOutput, TEXT("5"));}
                        if (LOWORD(wp) == BUTTON_PRESS6){
                            AppendText(hOutput, TEXT("6"));}
                        if (LOWORD(wp) == BUTTON_PRESS7){
                            AppendText(hOutput, TEXT("7"));}
                        if (LOWORD(wp) == BUTTON_PRESS8){
                            AppendText(hOutput, TEXT("8"));}
                        if (LOWORD(wp) == BUTTON_PRESS9){
                            AppendText(hOutput, TEXT("9"));}
                        if (LOWORD(wp) == BUTTON_PRESS0){
                            AppendText(hOutput, TEXT("0"));}
                        if (LOWORD(wp) == DOT){
                            AppendText(hOutput, TEXT("."));}
                    }
                        if (LOWORD(wp) == EQUAL){                       //once the user presses equal, compute the two accepted values
                            GetWindowText (hOutput, sVal, 100);
                            secondVal = static_cast<double>(atof(sVal));
                            AppendText(hOutput, TEXT("="));
                            SetWindowText(hOutput, "");

                            switch (op) {
                                case '+':                               //arithmetic operations for basic calculations
                                    result = firstVal + secondVal;
                                    break;
                                case '-':
                                    result = firstVal - secondVal;
                                    break;
                                case '*':
                                    result = firstVal * secondVal;
                                    break;
                                case '/':
                                    result = firstVal / secondVal;
                            }

                            sprintf( szBuffer, "%.3f", result );        //converting a double into a LPWSTR for the text box
                            SetWindowText(hOutput, szBuffer);           //displaying 3 decimal rounded values
                            }

                switch(wp){

                    case BUTTON_CLEAR:                  //clearing calculator screen
                        SetWindowText(hOutput, "");
                        break;
                    case FILE_MENU_ABOUT:{              //about menu
                        MessageBoxW(hWnd, L"Basic Calculator using WIN32 API \n\nby \nDalangin, John Rey G.\nFajel, Kenneth Q. \nRacelis, Glorie Alynna C\nRobles, John Joe Rimuel P.\nSiochi, Jamie Anne S.", L"About Calculator", MB_OK | MB_ICONINFORMATION);
                        }break;
                    case FILE_MENU_EXIT:{               //program exit menu
                        mbVal = MessageBoxW(hWnd, L"Exit Program?", L"Exit", MB_YESNO | MB_ICONEXCLAMATION);
                        if (mbVal == IDYES)             //built in IDs for Message Boxes
                            DestroyWindow(hWnd);
                        else if (mbVal == IDNO){}
                        }break;
            }
            }break;

        case WM_CREATE:{        //executed once the window is created
            loadImages();
            AddMenus(hWnd);
            AddControls(hWnd);
            }break;

        case WM_DESTROY:{       //exiting session
            PostQuitMessage(0);
            }break;
        default:
            return DefWindowProcW(hWnd, msg, wp, lp);
    }
}

void AddMenus(HWND hWnd){       //add menu function that accepts the window handler as the parameter

    hMenu = CreateMenu();       //creating menus using HMENU

    AppendMenu(hMenu, MF_STRING, FILE_MENU_ABOUT, "About");     //menus
    AppendMenu(hMenu, MF_STRING, FILE_MENU_EXIT, "Exit Calculator");

    SetMenu(hWnd, hMenu);
}

void AddControls(HWND hWnd){    //AddControl function to declare all the controls of the program, such as the buttons and text boxes


    hOutput = CreateWindowW(L"Edit", L"", WS_VISIBLE | WS_CHILD | ES_MULTILINE | ES_AUTOVSCROLL | ES_RIGHT, //declaring the editable text box (the user can input or press the button if they want)
                  30, 15, 270, 57.5, hWnd, NULL, NULL, NULL);
    HFONT hFont = CreateFont (52.5, 0, 0, 0, FW_DONTCARE, FALSE, FALSE, FALSE, ANSI_CHARSET,                // loading font style using HFONT
      OUT_TT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
      DEFAULT_PITCH | FF_DONTCARE, TEXT("Arial"));
    SendMessage(hOutput, WM_SETFONT, (LPARAM)hFont, TRUE);


    HWND hClear = CreateWindowW(L"Button", L"1", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP, //declaring all the buttons, these are distinguishable using their IDs
                  240, 83, 60, 30, hWnd, (HMENU)BUTTON_CLEAR, NULL, NULL);
    SendMessageW(hClear, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bClear);
    HWND h1 = CreateWindowW(L"Button", L"1", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  30, 120, 60, 60, hWnd, (HMENU)BUTTON_PRESS1, NULL, NULL);
    SendMessageW(h1, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)b1);
    HWND h2 = CreateWindowW(L"Button", L"2", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  100, 120, 60, 60, hWnd, (HMENU)BUTTON_PRESS2, NULL, NULL);
    SendMessageW(h2, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)b2);
    HWND h3 = CreateWindowW(L"Button", L"3", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  170, 120, 60, 60, hWnd, (HMENU)BUTTON_PRESS3, NULL, NULL);
    SendMessageW(h3, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)b3);
    HWND hDiv = CreateWindowW(L"Button", L"/", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  240, 120, 60, 60, hWnd, (HMENU)DIV, NULL, NULL);
    SendMessageW(hDiv, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bDiv);


    HWND h4 = CreateWindowW(L"Button", L"4", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  30, 190, 60, 60, hWnd, (HMENU)BUTTON_PRESS4, NULL, NULL);
    SendMessageW(h4, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)b4);
    HWND h5 = CreateWindowW(L"Button", L"5", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  100, 190, 60, 60, hWnd, (HMENU)BUTTON_PRESS5, NULL, NULL);
    SendMessageW(h5, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)b5);
    HWND h6 = CreateWindowW(L"Button", L"6", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  170, 190, 60, 60, hWnd, (HMENU)BUTTON_PRESS6, NULL, NULL);
    SendMessageW(h6, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)b6);
    HWND hMul = CreateWindowW(L"Button", L"x", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  240, 190, 60, 60, hWnd, (HMENU)MUL, NULL, NULL);
    SendMessageW(hMul, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bMul);

    HWND h7 = CreateWindowW(L"Button", L"7", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  30, 260, 60, 60, hWnd, (HMENU)BUTTON_PRESS7, NULL, NULL);
    SendMessageW(h7, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)b7);
    HWND h8 = CreateWindowW(L"Button", L"8", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  100, 260, 60, 60, hWnd, (HMENU)BUTTON_PRESS8, NULL, NULL);
    SendMessageW(h8, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)b8);
    HWND h9 = CreateWindowW(L"Button", L"9", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  170, 260, 60, 60, hWnd, (HMENU)BUTTON_PRESS9, NULL, NULL);
    SendMessageW(h9, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)b9);
    HWND hAdd = CreateWindowW(L"Button", L"+", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  240, 260, 60, 60, hWnd, (HMENU)ADD, NULL, NULL);
    SendMessageW(hAdd, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bAdd);

    HWND h0 = CreateWindowW(L"Button", L"0", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  30, 330, 60, 60, hWnd, (HMENU)BUTTON_PRESS0, NULL, NULL);
    SendMessageW(h0, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)b0);
    HWND hDot = CreateWindowW(L"Button", L".", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  100, 330, 60, 60, hWnd, (HMENU)DOT, NULL, NULL);
    SendMessageW(hDot, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bDot);
    HWND hEqual = CreateWindowW(L"Button", L"=", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP ,
                  170, 330, 60, 60, hWnd, (HMENU)EQUAL, NULL, NULL);
    SendMessageW(hEqual, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bEqual);
    HWND hSub = CreateWindowW(L"Button", L"-", WS_VISIBLE | WS_CHILD | SS_CENTER | BS_BITMAP,
                  240, 330, 60, 60, hWnd, (HMENU)SUB, NULL, NULL);
    SendMessageW(hSub, BM_SETIMAGE, IMAGE_BITMAP, (LPARAM)bSub);
}

void loadImages(){                  // to load all the bitmap images. we used 24 depth bitmap for the win32api to be able to read
    b1 = (HBITMAP)LoadImageW(NULL, L"1.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    b2 = (HBITMAP)LoadImageW(NULL, L"2.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    b3 = (HBITMAP)LoadImageW(NULL, L"3.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    b4 = (HBITMAP)LoadImageW(NULL, L"4.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    b5 = (HBITMAP)LoadImageW(NULL, L"5.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    b6 = (HBITMAP)LoadImageW(NULL, L"6.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    b7 = (HBITMAP)LoadImageW(NULL, L"7.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    b8 = (HBITMAP)LoadImageW(NULL, L"8.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    b9 = (HBITMAP)LoadImageW(NULL, L"9.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    b0 = (HBITMAP)LoadImageW(NULL, L"0.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    bAdd = (HBITMAP)LoadImageW(NULL, L"add.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    bSub = (HBITMAP)LoadImageW(NULL, L"subtract.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    bDiv = (HBITMAP)LoadImageW(NULL, L"divide.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    bMul = (HBITMAP)LoadImageW(NULL, L"multiply.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    bDot = (HBITMAP)LoadImageW(NULL, L"dot.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    bEqual = (HBITMAP)LoadImageW(NULL, L"equal.bmp", IMAGE_BITMAP, 60, 60, LR_LOADFROMFILE);
    bClear = (HBITMAP)LoadImageW(NULL, L"clear.bmp", IMAGE_BITMAP, 60, 30, LR_LOADFROMFILE);
}

void AppendText(HWND hEditWnd, LPCTSTR Text)            //appending text to the editable text box
{
    int idx = GetWindowTextLength(hOutput);
    SendMessage(hOutput, EM_SETSEL, (WPARAM)idx, (LPARAM)idx);
    SendMessage(hOutput, EM_REPLACESEL, 0, (LPARAM)Text);
}

//end
