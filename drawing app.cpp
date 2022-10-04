#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
#include <windows.h> 
#include <cstdlib>
using namespace std;
void gotoxy(int x, int y);
void piesinys(string paintingfile);
int main()
{

    setlocale(LC_ALL, "Lithuanian");
    string name, filename, txt, paintxt, password, savedpassword, savedname, paintingfile;
    int i=0, x=20, y=10, sp, spp=15, p, p1;
	bool log = true;
	txt = "file.txt";
	paintxt = "painting.txt";
	cout << "\n\n\n\t\tPiesimas\n\n\n\n" << endl;
	cout << "1) Registruotis" << endl;
	cout << "2) Prisijungti" << endl;
	cin >> p1;
	while(p1!=1 && p1!=2)
    {
        system("CLS");
        cout << "Choose one of the options!";
        Sleep(2000);
        system("CLS");
        cout << "1) Register " << endl;
        cout << "2) Login " << endl;
        cin >> p1;
    }
    if(p1==1)
    {
        system("CLS");
        cout << "Username : " << endl;
        cin >> name;
        system("CLS");
        cout << "Password : " << endl;
        cin >> password;
        system("CLS");
        filename = name + txt;
        ofstream out(filename);
        out << name << endl;
        out << password << endl;
    }
    if(p1==2)
    {
        system("CLS");
        cout << "Username : " << endl;
        cin >> name;
        system("CLS");
        cout << "Password : " << endl;
        cin >> password;
        system("CLS");
        filename = name + txt;
        ifstream in(filename);
        in >> savedname;
        in >> savedpassword;

       while(name != savedname || password != savedpassword)
       {
           cout << "Wrong username or password! ";
           Sleep(2000);
           system("CLS");
           cout << "Username : " << endl;
            cin >> name;
            system("CLS");
            cout << "Password : " << endl;
            cin >> password;
            system("CLS");
            filename = name + txt;
            ifstream in(filename);
            in >> savedname;
            in >> savedpassword;
       }
       if(savedname == name && savedpassword == password)
       {
        cout << "Successfully logged in";
        Sleep(2000);
        system("CLS");
        paintingfile = name + paintxt;
       }
	cout << "\n\t\t1. Naujas piesinys ";
	cout << "\n\t\t2. Pratesti paskutini piesini " << endl;
	cout << "\n\t\t3. Parodyti paskutini piesini " << endl;
	cin >> p;
	while(p!= 1 && p!=2 && p!=3)
{
    system("CLS");
        cout << "Pasirinkite viena is duotu variantu!"<<endl;
        Sleep(2000);
        system("CLS");
        cout << "\n\n\n\t\tPiesimas\n\n\n\n" << endl;
	cout << "\n\t\t1. Naujas piesinys ";
	cout << "\n\t\t2. Parodyti paskutini piesini\n\n\ " << endl;
	cout << "\n\t\t3. Parodyti paskutini piesini " << endl;
	cin >> p;
}
    if(p == 1)
{
    ofstream out(paintingfile);
    system("CLS");
    cout << "Pasirinkinte spalva : " << endl;
	cout << "1. Raudona" << endl;
	cout << "2. Zalia" << endl;
	cout << "3. Geltona" << endl;
	cout << "4. Zydra" << endl;
	cout << "5. Balta" << endl;
	cout << "6. Violetine" << endl;
	cin >> sp;
	 while(sp!= 1 && sp!=2 && sp!= 3 && sp!= 4 && sp!= 5 && sp!= 6)
    {
        system("CLS");
        cout << "Pasirinkite viena is duotu variantu!"<<endl;
        Sleep(2000);
        system("CLS");

        cout << "Pasirinkinte spalva : " << endl;
        cout << "1. Raudona" << endl;
        cout << "2. Zalia" << endl;
        cout << "3. Geltona" << endl;
        cout << "4. Zydra" << endl;
        cout << "5. Balta" << endl;
        cout << "6. Violetine" << endl;
        cin >> sp;
    }
  if(sp == 1) spp=12;
        if(sp == 2 ) spp=10;
        if (sp == 3 ) spp=14;
        if (sp == 4) spp= 11;
        if (sp == 5) spp = 15;
        if (sp == 6) spp = 13;
        if (sp == 0) spp = 0;
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("CLS");
        cout << "Spalvos" << endl;
        cout << "0. Trintukas" << endl;
        cout << "1. Raudona" << endl;
        cout << "2. Zalia" << endl;
        cout << "3. Geltona" << endl;
        cout << "4. Zydra" << endl;
        cout << "5. Balta" << endl;
        cout << "6. Violetine" << endl;
        cout << "Space - Isvalo vaizda" << endl;

        if(sp == 1) spp=12;
        if(sp == 2 ) spp=10;
        if (sp == 3 ) spp=14;
        if (sp == 4) spp= 11;
        if (sp == 5) spp = 15;
        if (sp == 6) spp = 13;
        if (sp == 0) spp = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), spp);

	while(log)
	{
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            log = false;
            out.close();

        }
        if(GetAsyncKeyState(VK_RIGHT)) x++;
        if(GetAsyncKeyState(VK_LEFT)) x--;
        if(GetAsyncKeyState(VK_UP)) y--;
        if(GetAsyncKeyState(VK_DOWN)) y++;
        if(GetAsyncKeyState(VK_SPACE))
        {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("CLS");
        cout << "Spalvos" << endl;
        cout << "0. Trintukas" << endl;
        cout << "1. Raudona" << endl;
        cout << "2. Zalia" << endl;
        cout << "3. Geltona" << endl;
        cout << "4. Zydra" << endl;
        cout << "5. Balta" << endl;
        cout << "6. Violetine" << endl;
        cout << "Space - Isvalo vaizda" << endl;
       //out.close();
       // ofstream out("piesinys.txt");
        }
        if(GetAsyncKeyState(0x30)) spp=0;
        if(GetAsyncKeyState(0x31)) spp=12;
        if(GetAsyncKeyState(0x32)) spp=10;
        if(GetAsyncKeyState(0x33)) spp=14;
        if(GetAsyncKeyState(0x34)) spp=11;
        if(GetAsyncKeyState(0x35)) spp=15;
        if(GetAsyncKeyState(0x36)) spp=13;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), spp);
        gotoxy(x, y);
        cout << "*" << endl;
        out << x <<" " << y <<" " << spp << endl;
        Sleep(100);
}


       // Sleep(100)
        //system("CLS");
    }

    if(p==2)
    {

        system("CLS");

        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        cout << "Spalvos" << endl;
        cout << "0. Trintukas" << endl;
        cout << "1. Raudona" << endl;
        cout << "2. Zalia" << endl;
        cout << "3. Geltona" << endl;
        cout << "4. Zydra" << endl;
        cout << "5. Balta" << endl;
        cout << "6. Violetine" << endl;
        cout << "Space - Isvalo vaizda" << endl;
        piesinys(paintingfile);
        ofstream out(paintingfile);
        if(sp == 1) spp=12;
        if(sp == 2 ) spp=10;
        if (sp == 3 ) spp=14;
        if (sp == 4) spp= 11;
        if (sp == 5) spp = 15;
        if (sp == 6) spp = 13;
        if (sp == 0) spp = 0;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), spp);

	while(log)
	{
        if(GetAsyncKeyState(VK_ESCAPE))
        {
            log = false;
            out.close();

        }
        if(GetAsyncKeyState(VK_RIGHT)) x++;
        if(GetAsyncKeyState(VK_LEFT)) x--;
        if(GetAsyncKeyState(VK_UP)) y--;
        if(GetAsyncKeyState(VK_DOWN)) y++;
        if(GetAsyncKeyState(VK_SPACE))
        {
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        system("CLS");
        cout << "Spalvos" << endl;
        cout << "0. Trintukas" << endl;
        cout << "1. Raudona" << endl;
        cout << "2. Zalia" << endl;
        cout << "3. Geltona" << endl;
        cout << "4. Zydra" << endl;
        cout << "5. Balta" << endl;
        cout << "6. Violetine" << endl;
        cout << "Space - Isvalo vaizda" << endl;
       //out.close();
        //ofstream out("piesinys.txt");
        }
        if(GetAsyncKeyState(0x30)) spp=0;
        if(GetAsyncKeyState(0x31)) spp=12;
        if(GetAsyncKeyState(0x32)) spp=10;
        if(GetAsyncKeyState(0x33)) spp=14;
        if(GetAsyncKeyState(0x34)) spp=11;
        if(GetAsyncKeyState(0x35)) spp=15;
        if(GetAsyncKeyState(0x36)) spp=13;
         SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), spp);
        gotoxy(x, y);
        cout << "*" << endl;
        out << x <<" " << y <<" " << spp << endl;
        Sleep(100);

    }
    }
    if(p==3)
    {
        system("CLS");
        piesinys(paintingfile);
        Sleep(3000);
        system("CLS");
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
        main();
    }
    return 0;

}
}


void gotoxy(int x, int y)
{
    COORD pos = {x, y};
    HANDLE output = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleCursorPosition(output, pos);
}

void piesinys(string paintingfile)
{
	int x, y, sp;
	ifstream in(paintingfile);
	while(in >> x >> y >> sp)
    {
        gotoxy(x, y);
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), sp);
        cout << "*" << endl;
    }
	in.close();
}
/* klavisu kodai:
VK_LBUTTON 0x01 Left mouse button
VK_RBUTTON 0x02 Right mouse button
VK_CANCEL 0x03 Control-break processing
VK_MBUTTON 0x04 Middle mouse button (three-button mouse)
VK_XBUTTON1 0x05 X1 mouse button
VK_XBUTTON2 0x06 X2 mouse button
VK_BACK 0x08 BACKSPACE key
VK_TAB 0x09 TAB key
VK_RETURN 0x0D ENTER key
VK_SHIFT 0x10 SHIFT key
VK_CONTROL 0x11 CTRL key
VK_PAUSE 0x13 PAUSE key
VK_CAPITAL 0x14 CAPS LOCK key
VK_ESCAPE 0x1B ESC key
VK_SPACE 0x20 SPACEBAR
VK_PRIOR 0x21 PAGE UP key
VK_NEXT 0x22 PAGE DOWN key
VK_END 0x23 END key
VK_HOME 0x24 HOME key
VK_LEFT 0x25 LEFT ARROW key
VK_UP 0x26 UP ARROW key
VK_RIGHT 0x27 RIGHT ARROW key
VK_DOWN 0x28 DOWN ARROW key
VK_INSERT 0x2D INS key
VK_DELETE 0x2E DEL key
*/
