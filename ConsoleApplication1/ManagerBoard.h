#pragma once
#include<iostream>
#include<cstddef>
#include <cstdlib>
#include <iomanip>
#include<string>
#include "Manager.h"

using namespace std;

ManagerList MAlist;

class ManagerBoardMainMenu {
public:
    int Selection;

    ManagerBoardMainMenu() {
        Selection = NULL;
    }

    //Function Main Menu 
    void  ManagerMainMenu()
    {
        cout << "\033[31m";
        cout << "+++++++++++++++++++++++++++++++++ R A N W E L I   Resturant Management System ++++++++++++++++++++++" << endl;
        cout << "                                 *********************************************" << endl;
        cout << "\033[37m";
        cout << "\n\tPlease select your selection : \n\t 1. Insert new executive member \n\t 2. Delete executive member\n\t 3. Show executive members\n\t 4. Working Staff management System\n\t 5. Quit";
        cout << "\n\n\t Your selection :";
        cin >> Selection;

        string choise;

        while (cin.fail()) {
            cin.clear();
            string junk;
            getline(cin,junk);
            cout << "\033[31m";
            cout <<endl<< "Invalid input please try again!!! \n\n ";
            cout << "\033[37m";
            system("pause");
            system("cls");
            ManagerMainMenu();
        }

        switch (Selection)
        {
        case 1:
            system("cls");
            insert_new_manager();
            break;
        case 2:
            system("cls");
            MAlist.delete_item();
            break;
        case 3:
            system("cls");
            MAlist.displayList();
            break;
        case 4:
            system("cls");
            MAlist.enter_workingManagementSystem();
            break;
        case 5:
            system("cls");
            cout << "Are you sure you want to Exit from the system???\npress Y or N"<<endl;
            
            cin >> choise;
            if (choise == "Y" || choise == "y") {
                exit(0);
            }
            else if (choise == "N" || choise == "n") {
                system("cls");
                ManagerMainMenu();
            }
            break;
        default:
            system("cls");
            cout << "\033[31m";
            cout << "Invalid input please try again!!! \n\n ";
            system("pause");
            system("cls");
            cout << "\033[37m";
            ManagerMainMenu();
        }
        ManagerMainMenu();
    }

    void insert_new_manager() {
        string username, password, fName, lName, position, Living_city, tell_no;
        
        cout << "Please enter your username: ";
        cin >> username;
        cout << "Please enter your password: ";
        cin >> password;
        int C = MAlist.checkPasswordExists(password);
        if (C == 1) {
            ManagerMainMenu();
        }

        cout << "Please enter your first name: ";
        cin >> fName;
        cout << "Please enter your last name: ";
        cin >> lName;
        cout << "Please enter your position: ";
        cin >> position;
        cout << "Please enter your living city: ";
        cin >> Living_city;
        cout << "Please enter your phone number: ";
        cin >> tell_no;

        MAlist.addNode(username, password, fName, lName, position, Living_city, tell_no);
        cout << "\033[34m";
        cout <<endl<< "Manager Details Added Successfully!!!"<<endl;
        cout << "\033[37m";
        system("pause");
        system("cls");
        ManagerMainMenu();
    }  
};