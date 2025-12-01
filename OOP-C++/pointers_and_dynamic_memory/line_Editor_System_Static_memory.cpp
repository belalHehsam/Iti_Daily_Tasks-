#include <iostream>
#include <conio.h>
#include <string>
#include<windows.h>
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
    const DWORD ENABLE_VIRTUAL_TERMINAL_PROCESSING = 0x0004; // تعريف الماكرو يدوي
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);
}

int main() {

    enableVirtualTerminalProcessing();

    string line;

    int cursor = 0;
    int row = 8;
    int col = 25;

    while (true) {

        int boxWidth = max(80 , (int)line.size());

        moveCursor(row, col);
        setOrangeBackground();

        for (int i = 0; i < boxWidth; i++) {
            if (i < (int)line.size())
                cout << line[i];
            else
                cout << ' ';
        }

        resetColor();

        moveCursor(row, col + cursor);

        char ch = getch();

        if (ch == 0 || ch == -32) {
            char key = getch();
            if (key == 75) { // left arrow
                if (cursor > 0) cursor--;
            } else if (key == 77) { // right arrow
                if (cursor < (int)line.size()) cursor++;
            } else if (key == 71) { // home
                cursor = 0;
            } else if (key == 79) { // end
                cursor = line.size();
            } else if (key == 83) { // delete
                if (cursor < (int)line.size())
                    line.erase(line.begin() + cursor);
            }
        }


        else if (ch == 8) { // backspace
            if (cursor > 0) {
                line.erase(line.begin() + cursor - 1);
                cursor--;
            }
        }

        else if (ch == 13) { // enter
            break;
        }

        else if (isprint(ch)) {
            line.insert(line.begin() + cursor, ch);
            cursor++;
        }
    }

    return 0;
}
