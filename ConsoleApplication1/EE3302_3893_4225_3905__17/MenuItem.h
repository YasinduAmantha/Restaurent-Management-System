#pragma once
#include<iostream>
#include<cstddef>
#include <iomanip>

using namespace std;

//Defining Menu Dish Node
class NodeM {
public:
    int index;
    string name;
    int price;
    int cost;
    NodeM* next;

    NodeM()
    {
        index = NULL;
        name = "";
        price = NULL;
        cost = NULL;
        next = NULL;
    }

    NodeM(int Index, string Name, int Price, int Cost)
    {
        index = Index;
        name = Name;
        price = Price;
        cost = Cost;
        next = NULL;
    }
};

//Define Menu List Singly Linked List
class MenuItems {

public:
    NodeM* head;
    int size;

public:
    MenuItems() {
        head = NULL;
        size = 0;
    }

    //Insert New Menu Dish function
    void addNode(int index, string name, int price, int cost) {
        NodeM* newNode = new NodeM(index, name, price, cost);
        newNode->next = head;
        head = newNode;
        size++;
    }

    //Print Menu Dish function
    void printNodes() {
        NodeM* current = head;
        cout << left << setw(10) << "Index" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Cost" << endl;
        while (current != NULL) {
            cout << left << setw(10) << current->index << setw(20) << current->name << setw(10) << current->price << setw(10) << current->cost << endl;
            current = current->next;
        }
    }

    //Delete  Menu Dish Item function
    void deleteNode(int index) {
        NodeM* temp = head;
        NodeM* prev = NULL;

        while (temp != NULL) {
            if (temp->index == index) {
                if (prev != NULL) {
                    prev->next = temp->next;
                }
                else {
                    head = temp->next;
                }
                delete temp;
                cout << "\033[34m";
                cout << "Menu Item Successfully Deleted!!!"<<endl;
                cout << "\033[37m";
                system("pause");
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        system("cls");
        cout << "\033[31m";
        cout << "Invalid Menu Item Index!!!";
        system("pause");
        cout << "\033[37m";
    }

    //Serch and update
    void SearchByIndexUpdate(int searchIndex) {
        NodeM* current = head;

        while (current != NULL) {
            if (current->index == searchIndex) {
                system("cls");
                cout << setw(5) << "Index" << setw(20) << "Name" << setw(15) << "Cost Price" << setw(15) << "Sale Price" << endl;
                cout << "---------------------------------------------------\n";
                cout << setw(5) << current->index << setw(20) << current->name << setw(15) << current->cost << setw(15) << current->price << endl;

                cout << endl;

                cout << "1.) Update Name" << endl << "2.) Update Cost Price" << endl << "3.) Update Sale Price" << endl;
                int choice;
                cout << endl << "Enter your choice : "; cin >> choice;

                string newName;
                int newCostPrice, newSalePrice;

                switch (choice)
                {
                case 1:
                    system("cls");
                    cout << "Current Name: " << current->name << endl;
                    cout << "Enter new Name: "; cin >> newName;
                    current->name = newName;
                    cout << "\033[34m";
                    cout << "Name updated successfully!!! \n\n";
                    system("pause");
                    system("cls");
                    cout << "\033[37m";
                    return;
                    break;
                case 2:
                    system("cls");
                    cout << "Current Cost Price: " << current->cost << endl;
                    cout << "Enter new Cost Price: "; cin >> newCostPrice;
                    current->cost = newCostPrice;
                    cout << "\033[34m";
                    cout << "Cost Price updated successfully!!! \n\n";
                    system("pause");
                    system("cls");
                    cout << "\033[37m";
                    return;
                    break;
                case 3:
                    system("cls");
                    cout << "Current Sale Price: " << current->price << endl;
                    cout << "Enter new Sale Price: "; cin >> newSalePrice;
                    current->price = newSalePrice;
                    cout << "\033[34m";
                    cout << "Sale Price updated successfully!!! \n\n";
                    system("pause");
                    system("cls");
                    cout << "\033[37m";
                    return;
                    break;
                default:
                    system("cls");
                    cout << "\033[31m";
                    cout << "Invalid choice, please try again!!! \n\n";
                    system("pause");
                    system("cls");
                    cout << "\033[37m";
                    return;
                }
            }
            current = current->next;
        }
        system("cls");
        cout << "\033[31m";
        cout << "Invalid index, please try again!!! \n\n";
        system("pause");
        system("cls");
        cout << "\033[37m";
        return;
    }

    //Return the price
    int return_menu_price(int index) {
        NodeM* temp = head;
        NodeM* prev = NULL;

        while (temp != NULL) {
            if (temp->index == index) {
                return temp->price;
            }
            prev = temp;
            temp = temp->next;
        }
        system("cls");
        cout << "\033[31m";
        cout << "Invalid Menu Item Index!!!";
        system("system");
        cout << "\033[37m";
        system("cls");
        return -1;
    }
};

