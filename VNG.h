void SetColor(int backgound_color, int text_color)
{
    HANDLE hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

    int color_code = backgound_color * 16 + text_color;
    SetConsoleTextAttribute(hStdout, color_code);
}
//Show Hide scroll bar
void ShowScrollbar(BOOL Show)
{
    HWND hWnd = GetConsoleWindow();
    ShowScrollBar(hWnd, SB_BOTH, Show);
}
//Disable Resize Window
void DisableResizeWindow()
{
    HWND hWnd = GetConsoleWindow();
    SetWindowLong(hWnd, GWL_STYLE, GetWindowLong(hWnd, GWL_STYLE) & ~WS_SIZEBOX);
}
HWND WINAPI GetConsoleWindowNT(void)
{
    //declare function pointer type
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    //declare one such function pointer
    GetConsoleWindowT GetConsoleWindow;
    //get a handle on kernel32.dll
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    //assign procedure address to function pointer
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib
    ,TEXT("GetConsoleWindow"));
    //check if the function pointer is valid
    //since the function is undocumented
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    //call the undocumented function
    return GetConsoleWindow();
}

void InitWindowConsole()
{
    //SetColor(7,12);
    //Change location and size of console window
	HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd,0,405,1290,350,TRUE);
    //Hide scroll bar
    ShowScrollbar(0);
    //forbid changing size of console window
    DisableResizeWindow();
}

void InitEverythings(char GameName[])
{
    SetConsoleOutputCP(CP_UTF8);
    InitWindowConsole();
    initwindow(1290,400,GameName);
}

void StartConversation(char CharactorImageLink[],char ImageLink[],char CharactorName[],char Conversation[])
{
    readimagefile(ImageLink,50,0,1230,400);
    readimagefile(CharactorImageLink,100,200,300,400);

    int i=0;
    printf("\t%s\n\t",CharactorName);
    while(i<strlen(Conversation))
    {
        printf("%c",Conversation[i++]);
        Sleep(30);
    }
    printf("\n\n\tNhấn phím bất kì để tiếp tục...");
    getch();
    Beep(500,200);
    system("cls");
}