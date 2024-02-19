
#include <iostream>
#include <Windows.h>
#include <stdlib.h>
#include "ManagerBoard.h"

using namespace std;

ManagerBoardMainMenu mainMenu;
string loginPassword;
int loginAttempt = 0;


int main()
{
    cout << "\033[33m";
    cout << " \t__       __        ________        __               ______          ______         __       __        ________ \r\n\t/  |  _  /  |      /        |      /  |             /      \\        /      \\       /  \\     /  |      /        |\r\n\t$$ | / \\ $$ |      $$$$$$$$/       $$ |            /$$$$$$  |      /$$$$$$  |      $$  \\   /$$ |      $$$$$$$$/ \r\n\t$$ |/$  \\$$ |      $$ |__          $$ |            $$ |  $$/       $$ |  $$ |      $$$  \\ /$$$ |      $$ |__    \r\n\t$$ /$$$  $$ |      $$    |         $$ |            $$ |            $$ |  $$ |      $$$$  /$$$$ |      $$    |   \r\n\t$$ $$/$$ $$ |      $$$$$/          $$ |            $$ |   __       $$ |  $$ |      $$ $$ $$/$$ |      $$$$$/    \r\n\t$$$$/  $$$$ |      $$ |_____       $$ |_____       $$ \\__/  |      $$ \\__$$ |      $$ |$$$/ $$ |      $$ |_____ \r\n\t$$$/    $$$ |      $$       |      $$       |      $$    $$/       $$    $$/       $$ | $/  $$ |      $$       |\r\n\t$$/      $$/       $$$$$$$$/       $$$$$$$$/        $$$$$$/         $$$$$$/        $$/      $$/       $$$$$$$$/ \r\n";
    cout << "\033[31m";
    cout << "\n\n\n\n\t\t\t\t\t\tR A N W E L I  R E S T A U R A N T";
    cout << "\n\n\t\t\tW E L C O M E  T O  T H E  R E S T A U R A N T  M A N A G E M E N T  S Y S T E M !!\t\t\t";

    cout << "\n\t\t\t____________________________________________________________________________________\t\t\t";

    cout << "\033[37m";
    cout << "\n\n\n\n\n\n\n\n";
    system("pause");
    system("cls");

    while (loginAttempt < 5)
    {



        //Get the Login Details
        cout << endl;
        cout << "Enter login password: ";
        cin >> loginPassword;

        if (loginPassword == "1")
        {
            system("cls");
            mainMenu.ManagerMainMenu();
            break;
        }

        else
        {
            cout << "Invalid login attempt. Please try again.\n" << '\n';
            loginAttempt++;
        }
    }
    if (loginAttempt == 5)
    {
        cout << "Too many login attempts! The program will now terminate.";
        return 0;
    }
}