#include <iostream>
#include <string>
#include <windows.h>

using namespace std;


HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void print_in(int x, int y, string text);

int main(){
    /*  
        These are the words:
        FELIZ
        CUMPLE
        NATHAN
        They're stylized in ASCII code
    */
    string word[]={

        "\xDC\xDB\xDB\xDB\xDB  \xDC\xDB\xDB\xDB\xDC   \xDB     \xDC\xDB  \xDC\xDC\xDC\xDC\xDC\xDC  ",
        "\xDB\xDF   \xDF \xDB\xDF   \xDF  \xDB     \xDB\xDB \xDF   \xDC\xDC\xDF  ",
        "\xDB\xDF\xDF    \xDB\xDB\xDC\xDC    \xDB     \xDB\xDB  \xDC\xDF\xDF   \xDC\xDF",
        "\xDB      \xDB\xDC   \xDC\xDF \xDB\xDB\xDB\xDC  \xDF\xDB  \xDF\xDF\xDF\xDF\xDF\xDF       ",
        " \xDB     \xDF\xDB\xDB\xDB\xDF       \xDF  \xDF          ",
        "  \xDF                                 ",

        "\xDC\xDB\xDC      \xDC   \xDB\xDF\xDC\xDF\xDB \xDB \xDC\xDC  \xDB     \xDC\xDB\xDB\xDB\xDC  ",
        "\xDB\xDF \xDF\xDC     \xDB  \xDB \xDB \xDB \xDB   \xDB \xDB     \xDB\xDF   \xDF",
        "\xDB   \xDF  \xDB   \xDB \xDB \xDC \xDB \xDB\xDF\xDF\xDF  \xDB     \xDB\xDB\xDC\xDC  ",
        "\xDB\xDC  \xDC\xDF \xDB   \xDB \xDB   \xDB \xDB     \xDB\xDB\xDB\xDC  \xDB\xDC   \xDC\xDF ",
        "\xDF\xDB\xDB\xDB\xDF  \xDB\xDC \xDC\xDB    \xDB   \xDB        \xDF \xDF\xDB\xDB\xDB\xDF   ",

        "        \xDF\xDF\xDF    \xDF     \xDF                ",
        "   \xDC   \xDB\xDB      \xDC\xDC\xDC\xDC\xDF  \xDC  \xDB \xDB\xDB      \xDC  ",
        "    \xDB  \xDB \xDB  \xDF\xDF\xDF \xDB    \xDB   \xDB \xDB \xDB      \xDB  ",
        "\xDB\xDB   \xDB \xDB\xDC\xDC\xDB     \xDB    \xDB\xDB\xDF\xDF\xDB \xDB\xDC\xDC\xDB \xDB\xDB   \xDB",
        "\xDB \xDB  \xDB \xDB  \xDB    \xDB     \xDB   \xDB \xDB  \xDB \xDB \xDB  \xDB ",
        "\xDB  \xDB \xDB    \xDB   \xDF         \xDB     \xDB \xDB  \xDB \xDB",
        "\xDB   \xDB\xDB   \xDB             \xDF     \xDB  \xDB   \xDB\xDB",
        "        \xDF                   \xDF       "

    };
    string dragon[] = {
        "                    +   +                               ",
        "                  +  ++                                 ",
        "                ++ ++++++++                    +++      ",
        "               ++++++  ++++++/\\     / \\     +++    ++   ",
        "              +++         ++++ \\   /   \\    ++      +   ",
        "                           +++++   /     \\   +++    +   ",
        "                          +++++ | |   |   \\    +++      ",
        "                         +++++  |   |      |     +++    ",
        "                         +++++   ||  |  |   |    +++    ",
        "                        +++++++ /  |     | |   ++++     ",
        "                       ++++++++    | |   || +++++       ",
        "                       ++++++++++   | | /++++++         ",
        "                       ++++++++++++++++++++++           ",
        "                        +++++++++++++++++++++           ",
        "                        ++++++++++++++++++++            ",
        "                        ++++++++++++++++++++            ",
        "                         ++++++++++++++++++++           ",
        "                          ++ ++++ +++++ +++++           ",
        "                           ++ ++++   ++ ++++            ",
        "                           ++   +++    +  +++           ",
        "                           ++    ++    ++  +++          ",
        "                          ++     ++   ++  ++            "
    };
    
    string empty = " ";
    string buffer = " ";
    
    string border(56,'\xCD');
    string space(56,' ');

    int x;
    int randomNumber = 0;

    // print base canvas

    SetConsoleTextAttribute(console, 10);
    cout<< "\t\xC9" << border << "\xBB" <<endl;
    cout<< "\t\xBA" << space << "\xBA" <<endl;
    for ( x = 0; x < 22; x++)
    {
       cout<< "\t\xBA" << dragon[x] << "\xBA" <<endl;
    }
    for (x = 0; x < 22; x++)
    {
        cout<< "\t\xBA" << space << "\xBA" <<endl;
    }
    cout << "\t\xC8" << border << "\xBC" << endl;
    
    

    do{
        randomNumber = rand()%11;

        if(randomNumber <= 2){
            SetConsoleTextAttribute(console, 12);
            for (x=0;x<19;x++)
		    {   
                Sleep(60);
			    print_in(11,25+x,word[x]);
		    }
        }else{
            SetConsoleTextAttribute(console, 10);
            for (x=0;x<19;x++)
		    {
                Sleep(60);
			    print_in(11,25+x,word[x]);
		    }
        }

        

        
    }while(true);
}

void print_in(int x, int y, string text) 
{ 
	CursorPosition.X = x; 
	CursorPosition.Y = y; 
	SetConsoleCursorPosition(console,CursorPosition);
	cout <<"\t"<< text;
}