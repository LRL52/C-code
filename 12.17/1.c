#include <windows.h>
int main() {
	char user[]="XXXXXXXXXXX";
	char password[]="XXXXXX";
	ShellExecute(0,"open","http://home.xinkaoyun.com/login.html",0,0,1);
	Sleep(3000);
	SetCursorPos(1100,330);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP, 0,0,0,0);
	for (int i=0;i<11;i++) {
		keybd_event(user[i], 0, 0, 0);
		keybd_event(user[i],0, KEYEVENTF_KEYUP, 0);
		Sleep(100);
	}
	//以上为输入用户
	SetCursorPos(1100,380);
	mouse_event(MOUSEEVENTF_LEFTDOWN, 0,0,0,0);
	mouse_event( MOUSEEVENTF_LEFTUP, 0,0,0,0);
	for (int i=0;i<6;i++) {
		keybd_event(password[i], 0, 0, 0);
		keybd_event(password[i],0, KEYEVENTF_KEYUP, 0);
		Sleep(100);
	}
	//以上为输入密码
	SetCursorPos(1100,444);
	mouse_event(MOUSEEVENTF_LEFTDOWN,0,0,0,0);
	mouse_event(MOUSEEVENTF_LEFTUP,0,0,0,0);
	return 0;
}

