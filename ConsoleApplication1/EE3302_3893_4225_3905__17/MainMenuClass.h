#pragma once
#include<iostream>
#include<cstddef>
#include <iomanip>
#include "MenuItem.h"
#include "WorkingStaff.h"
#include "BillQueue.h"

using namespace std;

MenuItems mList;
Working_Staff sList;
BillList bList;

class MainMenuClass
{

public:
    int Selection;

    MainMenuClass() {
        Selection = NULL;
	}

    //Function Main Menu 
    void MainMenu()
    {
        cout << "\033[31m";
        cout << "+++++++++++++++++++++++++++++++++ Working Staff Management System ++++++++++++++++++++++" << endl;
        cout << "                                 *********************************" << endl;
        cout << "\033[37m";
        cout << "\n\tPlease select your selection : \n\t 1. Manage Working Staff \n\t 2. Manage Menu Item Dishes\n\t 3. Salary Calculation\n\t 4. Manage Home Delivery Bills\n\t 5. Go Back";
        cout << "\n\n\t Your selection :";
        cin >> Selection;
        
        while (cin.fail()) {
            cin.clear();
            string junk;
            getline(cin, junk);
            cout << "\033[31m";
            cout << endl << "Invalid input please try again!!! \n\n ";
            cout << "\033[37m";
            system("pause");
            system("cls");
            MainMenu();

        }

        switch (Selection)
        {
        case 1:
            system("cls");
            ManageWorkingStaff();
            break;
        case 2:
            system("cls");
            ManageMenuItems();
            break;
        case 3:
            system("cls");
            Sal_Cal();
            break;
        case 4:
            system("cls");
            delivery_bills();
            break;
        case 5:
            system("cls");
            system("pause");
            system("cls");
            return;
        default:
            system("cls");
            cout << "\033[31m";
            cout << "Invalid input please try again!!! \n\n ";
            system("pause");
            system("cls");
            cout << "\033[37m";
            MainMenu();
        }
        MainMenu();
    }

    //Function Manage Menu Items 
    void ManageMenuItems() {
        cout << "\n\t 1. Insert new Menu Item \n\t 2. Print current Menu list \n\t 3. Remove a Menu Item \n\t 4. Update Menu Item\n\t 5. Go back to Main Menu";
        cout << "\n\n\t Your selection :";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
            system("cls");
            Insert_Menu_Item();
            break;
        case 2:
            system("cls");
            Show_Menu_Items();
            break;
        case 3:
            system("cls");
            Delete_Menu_item();
            break;
        case 4:
            system("cls");
            Update_Menu_item();
            break;
        case 5:
            system("cls");
            system("pause");
            system("cls");
            MainMenu();
            break;
        default:
            system("cls");
            cout << "\033[31m";
            cout << "Invalid input please try again!!! \n\n ";
            system("system");
            system("cls");
            cout << "\033[37m";
            MainMenu();
        }

    }

    //Function Insert Menu Items
    void Insert_Menu_Item() {
        int price;
        int cost;
        int index = mList.size + 1;
        string name;

        cout << "1. Enter index: "<<index<<endl; 
        cout << "2. Enter Menu name: "; cin >> name;
        cout << "3. Enter selling price of one dish: "; cin >> price;
        cout << "4. Enter cost: "; cin >> cost;

        mList.addNode(index, name, price, cost);
        
        cout << "\033[34m";
        cout << "New Menu Item successfully added" << endl;
        cout << "\033[37m";
        system("pause");
        system("cls");
        ManageMenuItems();
    }

    //Function Dispaly Menu Items
    void Show_Menu_Items() {
        mList.printNodes();
        system("pause");
        system("cls");
        ManageMenuItems();
    }

    //Delete menu item
    void Delete_Menu_item() {
        int index;
        cout << "enter index to remove : "; cin >> index;
        mList.deleteNode(index);
        system("cls");
        ManageMenuItems();
    }

    void Update_Menu_item() {
        int index;
        cout << "Enter an index number: ";
        cin >> index;
        mList.SearchByIndexUpdate(index);
        ManageMenuItems();
    }

    //function Manage Working Staff
    void ManageWorkingStaff() {
        cout << "\n\t 1. insert new staff member \n\t 2.print current member list \n\t 3. remove a member \n\t 4. Update Member Details\n\t 5. Go Back to main Menu ";
        cout << "\n\n\t Your selection :";
        cin >> Selection;

        switch (Selection)
        {
        case 1:
            system("cls");
            Insert_Member();
            system("pause");
            system("cls");
            break;
        case 2:
            system("cls");
            Show_Members();
            system("pause");
            break;
        case 3:
            system("cls");
            Delete_Member();
            system("pause");
            break;
        case 4:
            system("cls");
            Update_Member();
            system("pause");
            break;
        case 5:
            system("cls");
            system("pause");
            system("cls");
            MainMenu();
            break;
        default:
            system("cls");
            cout << "\033[31m";
            cout << "Invalid input please try again!!!\n\n ";
            system("system");
            cout << "\033[37m";
            system("cls");
            MainMenu();
        }
    }

    //Insert staff membber
    void Insert_Member() {
        int index = sList.size + 1;
        string fName, lName, position, livingCity, tellNo;
        int salaryPerDay;
        cout << "1. Enter index: "<<index<<endl;
        cout << "2. Enter first name: "; cin >> fName;
        cout << "3. Enter last name: "; cin >> lName;
        cout << "4. Enter position: "; cin >> position;
        cout << "5. Enter living city: "; cin >> livingCity;
        cout << "6. Enter phone number: "; cin >> tellNo;
        cout << "7. Enter salary per hour: "; cin >> salaryPerDay;
        sList.addNode(index, fName, lName, position, livingCity, tellNo, salaryPerDay);
        cout << "\033[34m";
        cout << "New Staff Member successfully added!!!" << endl;
        cout << "\033[37m";
        system("pause");
        system("cls");
        ManageWorkingStaff();
    }

    //Show Member function
    void Show_Members() {
        sList.printNodes();
        system("pause");
        system("cls");
        ManageWorkingStaff();
    }

    //Delete a staff Member 
    void Delete_Member() {
        int index;
        cout << "enter index to remove : "; cin >> index;
        sList.deleteNode(index);
        system("cls");
        ManageWorkingStaff();
    }

    //Function update member details
    void Update_Member() {
        int index;
        cout << "Enter an index number: ";
        cin >> index;
        sList.SearchByIndexUpdate(index);
        ManageWorkingStaff();
    }
    
    //Salary Calculation Function
    void Sal_Cal() {
        cout << "\033[33m" << "Salary Calculation Form." << endl << "++++++++++++++++++++++++++++++++" << "\033[37m"<<endl<<endl;
        int index;
        cout << "Enter index : "; cin >> index;
        sList.search_sal_cal(index);
        system("cls");
        MainMenu();
    }

    //Manage Home delivery Bills
    void delivery_bills() {
        cout << "1.) Place a Order\n2.) Remove the already delivered Order\n3.)Show Available Orders\n4.)Go Back\n\nEnter your Choise.....";
        cin >> Selection;
        switch (Selection)
        {
        case 1:
            system("cls");
            place_order();
            system("cls");
            break;
        case 2:
            system("cls");
            bList.dequeue();
            system("cls");
            break;
        case 3:
            system("cls");
            bList.printQueue();
            system("cls");
            break;
        case 4:
            system("cls");
            system("pause");
            system("cls");
            return;
        default:
            system("cls");
            cout << "\033[31m";
            cout << "Invalid input please try again!!!\n\n ";
            system("pause");
            cout << "\033[37m";
            system("cls");
            return;
        }
        delivery_bills();
    }

    //Place a order 
    void place_order() {
        mList.printNodes();

        int index = bList.size + 1000, tot_amaount = 0, N;
        int* dishN;
        int* itemN;
        string tellNo, city;

        cout << "\n\nBill No : " << index<<endl;
        cout << "Customer Tell No : "; cin >> tellNo;
        cout << "Delivery City : "; cin >> city;
        cout << "Enter Number of menu items : "; cin >> N;

        dishN = new int[N];
        itemN = new int[N];
        for (int i = 0; i < N; i++) {
            cout << endl;
            cout << "enter menu item index: "; cin >> itemN[i];
            int dish_price = mList.return_menu_price(itemN[i]);
            if (dish_price == -1) {
                system("cls");
                cout << "\033[31m";
                cout<<"Invalid Meny Item index Entered!!!";
                cout << "\033[37m";
                cout << endl;
                system("pause");
                system("cls");
                return;
            }
            else {
                cout << "enter number of dishes: "; cin >> dishN[i];
                cout << "The amount : " <<dish_price * dishN[i]<<endl;
                tot_amaount += dish_price * dishN[i];
            }
        }
        cout << endl;
        cout << "The grand total : " << tot_amaount;
        bList.enqueue(N, index, tot_amaount, city, tellNo, itemN, dishN);
        cout << endl;
        cout << "\033[34m";
        cout << "Order Placed Successfully!!!";
        cout << "\033[37m";
        system("pause");
        system("cls");
        delivery_bills();
    }
};
