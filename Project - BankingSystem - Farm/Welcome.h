#pragma once
#include <stdio.h>
#include <windows.h>
#include "iostream"
#include <string>
using namespace std;

class Welcome
{
public:
    //To Get Text In Middle Of The Screen
    static int getConsoleWidth() {
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        int width = 80;

        if (GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi)) {
            width = csbi.srWindow.Right - csbi.srWindow.Left + 1;
        }
        return width;
    }

    static void printCentered(string text) {
        int consoleWidth = getConsoleWidth();
        int padding = (consoleWidth - text.length()) / 2;

        if (padding > 0) {
            cout << string(padding, ' ');
        }
        cout << text << endl;
    }

    static void setConsoleColor() {
        string colorCode;
        system("color 2F"); // C: Background Color, F: Text Color
        /*Color Code :
                   0: Black        | 1: Blue         | 2: Green        | 3: Cyan        | 4: Red        | 5: Violet | 6: Yellow
                   7: White - gray | 8: Dark gray    | 9: Light blue   | A: Light green | B : Light cyan
                   C: Light red    | D: Light purple | E: Light yellow | F: Bright white*/
    }

    static void hello() {
        system("cls");
        setConsoleColor();
        string art[] = {
            "  ||     || |||||||| ||       ||        ||||||  ",
            "  ||     || ||       ||       ||       ||    || ",
            "   ||     || ||       ||       ||       ||    ||  ",
            "  ||||||||| ||||||   ||       ||       ||    || ",
            "  ||     || ||       ||       ||       ||    || ",
            "  ||     || ||       ||       ||       ||    || ",
            "   ||     || |||||||| |||||||| |||||||| ||||||||  "
        };

        for (string line : art) {
            printCentered(line);
            Sleep(100);
        }
        cout << "\n\n\n";
    }

    static void welcome() {
        //system("cls");
        setConsoleColor();
        string art[] = {
           " __          __  _                            _           __                       _                 _    ",
           " \\ \\        / / | |                          | |         / _|                     | |               | |   ",
           "  \\ \\  /\\  / /__| | ___ ___  _ __ ___   ___  | |_ ___   | |_ __ _ _ __ _ __ ___   | |__   __ _ _ __ | | __",
           "   \\ \\/  \\/ / _ \\ |/ __/ _ \\| '_ ` _ \\ / _ \\ | __/ _ \\  |  _/ _` | '__| '_ ` _ \\  | '_ \\ / _` | '_ \\| |/ /",
           "    \\  /\\  /  __/ | (_| (_) | | | | | |  __/ | || (_) | | || (_| | |  | | | | | | | |_) | (_| | | | |   < ",
           "     \\/  \\/ \\___|_|\\___\\___/|_| |_| |_|\\___|  \\__\\___/  |_| \\__,_|_|  |_| |_| |_| |_.__/ \\__,_|_| |_|_|\\_\\",
           "                                                                                                           ",
           "                                                                                                           "
        };

        for (string line : art) {
            printCentered(line);
            Sleep(100);
        }
        cout << "\n";
    }

    static void message() {
        setConsoleColor();
        cout << "\033[1mAbout Us - FARM Bank \033[0m" << endl;
        cout << "Our name is inspired by our founders: " << "\033[1m Fatma, Amr, Rozana, and Mai& Mohamed \033[0m " << endl;
        cout << "reflecting our spirit of collaboration and shared growth." << endl;
        cout << "At FARM Bank, we believe that every financial success starts as a small seed,\n"
            << "growing with vision and dedication.\n" << endl;
        cout << "\033[1m Contact Us : \033[0m" << endl;
        cout << "\033[1m Address: \033[0m" << "123 Finance & Business St., Cairo, Egypt" << endl;
        cout << "\033[1m Phone  : \033[0m" << "+20 100 123 4567" << endl;
        cout << "\033[1m Fax    : \033[0m" << "+20 2 2345 6789" << endl;
        cout << "\033[1m Email  : \033[0m" << "support@farmbank.com" << endl;
        cout << "\033[1m For inquiries, \033[0m" << "feel free to reach out! Our team is always ready to assist you" << endl;
    }
};

