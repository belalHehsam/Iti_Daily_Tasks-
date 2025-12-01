#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std;

void moveCursor(int row, int col) {
    cout << "\033[" << row << ";" << col << "H";
}

void clearLine() {
    cout << "\033[2K";
}

void setOrangeBackground() {
    cout << "\033[48;5;208m\033[30m";
}

void resetColor() {
    cout << "\033[0m";
}

void enableVirtualTerminalProcessing() {
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    const DWORD ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004;
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

int main() {
    enableVirtualTerminalProcessing();

     int MAX_LEN;
     cout<<"Enter the Length For String"<<endl;
    cin>>MAX_LEN;
    char* line = new char[MAX_LEN];

    int length = 0;

    int cursor = 0;
    int row = 12;
    int col = 20;

    while (true) {

        int boxWidth = max(80, length);

        clearLine();
        moveCursor(row, col);
        setOrangeBackground();

        for (int i = 0; i < boxWidth; i++) {
            if (i < length)
                cout << line[i];
            else
                cout << ' ';
        }

        resetColor();

        moveCursor(row, col + cursor);

        char ch = getch();

        if (ch == 0 || ch == -32) {
            char key = getch();
            if (key == 75 && cursor > 0) cursor--;           // left
            else if (key == 77 && cursor < length) cursor++;  // right
            else if (key == 71) cursor = 0;                   // Home
            else if (key == 79) cursor = length;              // End
            else if (key == 83 && cursor < length) {          // Delete key
                //  Shift left
                for (int i = cursor ; i < length - 1; i++) {
                    line[i] = line[i + 1];
                }

                length--;
                line[length] = '\0';
            }
        }
        else if (ch == 8 && cursor > 0) { // Backspace
            // Shift left (remove char before cursor)
            for (int i = cursor - 1; i < length - 1; i++) {
                line[i] = line[i + 1];
            }
            cursor--;
            length--;
            line[length] = '\0';
        }

        else if (ch == 13) { // Enter
            break;
        }
        else if (isprint(ch) && length < MAX_LEN - 1) {

            // Shift right (insert char at cursor)
            for (int i = length; i > cursor; i--) {
                line[i] = line[i - 1];
            }

            line[cursor] = ch;
            cursor++;
            length++;
            line[length] = '\0';
        }
    }


    cout << "\n\nYou typed: " << line << endl;
    delete[] line;
    return 0;
}
