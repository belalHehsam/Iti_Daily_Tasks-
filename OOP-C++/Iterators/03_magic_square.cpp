#include <iostream>
#include <iomanip>
#include <windows.h>

#ifndef ENABLE_VIRTUAL_TERMINAL_PROCESSING
#define ENABLE_VIRTUAL_TERMINAL_PROCESSING 0x0004
#endif

using namespace std;

int main() {

    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    DWORD dwMode = 0;
    GetConsoleMode(hOut, &dwMode);
    dwMode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    SetConsoleMode(hOut, dwMode);

    int n;
    cout << "Enter an odd number (3,5,7,...): ";
    cin >> n;

    // Validate odd/even
    if (n % 2 == 0 || n < 3) {
        cout << "\033[31mError: must be odd and >= 3\033[0m\n";
        //3\033[0m\n"===> reset the colors

        return 0;
    }

    int magicConstant = n * (n * n + 1) / 2;
    //35m lon banfsgy

    cout << "\033[35mMagic Constant = " << magicConstant << "\033[0m\n\n";

    // We will print values directly using logic (no arrays)
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {

            // Formula for magic square (works only for odd n)
            int value = n * ((i + j - 1 + (n / 2)) % n) + ((i + 2 * j - 2) % n) + 1;

            // Color based on odd/even
            string color = (value % 2 == 0) ? "\033[33m" : "\033[36m";
            //setw(4 b7gz beha msafat 34an 4kl el tba3a
            cout << color << setw(4) << value << "\033[0m";
        }

        cout << "\n";
    }

    return 0;
}
