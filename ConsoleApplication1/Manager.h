#pragma once
#include<iostream>
#include<cstddef>
#include <iomanip>
#include "MainMenuClass.h"

using namespace std;

MainMenuClass mmc;


//Executive member Node
class NodeK {
public:
    string username;
    string password;
    string fName;
    string lName;
    string position;
    string Living_city;
    string tell_no;
    NodeK* next;

public:

    NodeK() {
        username = "";
        password = "";
        fName = "";
        lName = "";
        position = "";
        Living_city = "";
        tell_no = "";
        next = NULL;
    }

    NodeK(string Username, string Password, string FName, string LName, string Position, string Living_City, string Tell_no){
        username = Username;
        password = Password;
        fName = FName;
        lName = LName;
        position = Position;
        Living_city = Living_City;
        tell_no = Tell_no;
        next = NULL;
    }



};

//class Executive member singly linked list
class ManagerList {
public:
    NodeK* head;
    int size;

    ManagerList() {
        head = NULL;
        size = 0;
    }
    //Check Password is Exist in the Linked List
    int checkPasswordExists(string password) {
        NodeK* current = head;
        while (current != NULL) {
            if (current->password == password) {
                cout << "Error: Password already exists. Please enter a different password.\n";
                system("pause");
                system("cls");
                return 1;
            }
            current = current->next;
        }
    }

    //Add a new manager
    void addNode(string username, string password, string fName, string lName, string position, string Living_city, string tell_no) {
        NodeK* newNode = new NodeK(username, password, fName, lName, position, Living_city, tell_no);
        newNode->next = head;
        head = newNode;
        size++;
    }
    
    //Display entire list
    void displayList() {
        NodeK* current = head;
        int count = 1;

        cout << "List of all employees:\n";
        cout << left << setw(4) << "No." << setw(15) << "First Name" << setw(15) << "Last Name" << setw(15) << "Position" << setw(20) << "Living City" << setw(15) << "Phone Number" << setw(15) << endl;
        while (current != NULL) {
            cout << left << setw(4) << count << setw(15) << current->fName << setw(15) << current->lName << setw(15) << current->position << setw(20) << current->Living_city << setw(15) << current->tell_no << setw(15) << endl;
            current = current->next;
            count++;
        }
        system("pause");
        system("cls");
    }

    //delete node from list
    void delete_item() {
        string uName;
        string pwd;
        cout << "Enter user name: "; cin >> uName;
        cout << "Enter Password: "; cin >> pwd;
        NodeK* curr = head;
        NodeK* prev = NULL;

        while (curr != NULL) {
            if (curr->password == pwd && curr->username == uName) {
                if (prev == NULL) {
                    head = curr->next;
                }
                else {
                    prev->next = curr->next;
                }
                delete curr;
                cout << "Manager Details Deleted Successfully!!!";
                system("pause");
                system("cls");
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Invalid User name or Password!!!" << endl;
        system("pause");
        system("cls");
    }

    //Access to staff management system
    void enter_workingManagementSystem() {
        string uName;
        string pwd;
        cout << "Enter user name: "; cin >> uName;
        cout << "Enter Password: "; cin >> pwd;
        NodeK* curr = head;
        NodeK* prev = NULL;

        while (curr != NULL) {
            if (curr->password == pwd && curr->username == uName) {
                cout << endl << "User Name and Password are Correct!!!"<<endl;
                system("pause");
                system("cls");
                mmc.MainMenu();
                return;
            }
            prev = curr;
            curr = curr->next;
        }
        cout << "Invalid User name or Password!!!" << endl;
        system("pause");
        system("cls");
    }
};





