#pragma once
#include<iostream>
#include<cstddef>
#include <iomanip>
#include "MainMenuClass.h"

using namespace std;

class Node {
public:
    int index;
    string fName;
    string lName;
    string position;
    string Living_city;
    string tell_no;
    int salaryPerHour;
    Node* next;

    Node()
    {
        index = NULL;
        fName = "";
        lName = "";
        position = "";
        Living_city = "";
        tell_no = "";
        salaryPerHour = NULL;
        next = NULL;
    }

    Node(int Index, string FName, string LName, string Position, string Living_City, string Tell_no, int SalaryPerDay)
    {
        index = Index;
        fName = FName; 
        lName = LName; 
        position = Position;
        Living_city = Living_City;
        tell_no = Tell_no;
        salaryPerHour = SalaryPerDay;
        next = NULL;
    }
};

class Working_Staff {
public:
    Node* head;
    int size;


    Working_Staff() {
        head = NULL;
        size = 0;
    }

    //Insert member
    void addNode(int index, string fName, string lName, string position, string Living_city, string tell_no, int salaryPerDay) {
        Node* newNode = new Node(index, fName, lName, position, Living_city, tell_no, salaryPerDay);
        newNode->next = head;
        head = newNode;
        size++;
    }

    //print all the members
    void printNodes() {
        Node* current = head;
        cout << setw(5) << "ID" << setw(20) << "Name" << setw(20) << "Last Name" << setw(15) << "Position" << setw(15) << "Living City" << setw(20) << "Telephone Number" << setw(15) << "Salary/Hour" << endl;
        cout << "------------------------------------------------------------------------------------------\n";
        while (current != NULL) {
            cout << setw(5) << current->index << setw(20) << current->fName << setw(20) << current->lName << setw(15) << current->position << setw(15) << current->Living_city << setw(20) << current->tell_no << setw(15) << current->salaryPerHour << endl;
            current = current->next;
        }
    }

    //delete member
    void deleteNode(int index) {
        Node* temp = head;
        Node* prev = nullptr;

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
                cout << "Member Details Successfully Deleted!!!";
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

    //salary calculation

    void search_sal_cal(int index) {
        Node* temp = head;
        Node* prev = NULL;
        int D;
        while (temp != NULL) {
            if (temp->index == index) {
                cout << "\n\nEnter number of working days : "; cin >> D;
                int* hours = new int[D];
                for (int i = 0; i < D; i++) {
                    cout << endl << "Day " << i + 1 << " ,working hours : "; cin >> hours[i];
                }
                int sumHours = 0;
                for (int i = 0; i < D; i++) {
                    sumHours += hours[i];
                }
                cout << endl;
                cout << "Name : " << temp->fName << " " << temp->lName << endl;
                cout << "Salary per hour : " << temp->salaryPerHour<<endl;
                cout << "Total salary for working days : " << temp->salaryPerHour * sumHours<<endl;
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

    //update member list

    void SearchByIndexUpdate(int searchIndex) {
        Node* current = head;

        while (current != NULL) {
            if (current->index == searchIndex) {
                system("cls");
                cout << setw(5) << "ID" << setw(20) << "First Name" << setw(20) << "Last Name" << setw(15) << "Position" << setw(15) << "Living City" << setw(20) << "Telephone Number" << setw(15) << "Salary/Day" << endl;
                cout << "------------------------------------------------------------------------------------------\n";
                cout << setw(5) << current->index << setw(20) << current->fName << setw(20) << current->lName << setw(15) << current->position << setw(15) << current->Living_city << setw(20) << current->tell_no << setw(15) << current->salaryPerHour << endl;
                
                cout << endl;

                cout << "1.)Update First Name : " << endl << "2.)Update Last Name" << endl << "3.)Update Position" << endl << "4.Update Living City)" << endl << "5.)Update Telephone Number" << endl << "6.)Update Salary/Day" << endl;
                int S;
                cout << endl << "Enter Your Choice : "; cin >> S;

                string nFname, nLname, nPosition, nLivingCity, nTel;
                int nSal;

                switch (S)
                {
                case 1:
                    system("cls");
                    cout << "Current First Name : " << current->fName<<endl;
                    cout << "Enter new First name : "; cin >> nFname;
                    current->fName = nFname;
                    cout << "\033[34m";
                    cout << "First Name Updated Successfully!!! \n\n ";
                    system("pause");
                    system("cls");
                    cout << "\033[37m";
                    return;
                    break;
                case 2:
                    system("cls");
                    cout << "Current Last Name : " << current->lName << endl;
                    cout << "Enter new Last name : "; cin >> nLname;
                    current->lName = nLname;
                    cout << "\033[34m";
                    cout << "Last Name Updated Successfully!!! \n\n ";
                    system("pause");
                    system("cls");
                    cout << "\033[37m";
                    return;
                    break;
                case 3:
                    system("cls");
                    cout << "Current Position : " << current->position << endl;
                    cout << "Enter new Position : "; cin >> nPosition;
                    current->position = nPosition;
                    cout << "\033[34m";
                    cout << "Position Updated Successfully!!! \n\n ";
                    system("pause");
                    system("cls");
                    cout << "\033[37m";
                    return;
                    break;
                case 4:
                    system("cls");
                    cout << "Current Living City : " << current->Living_city << endl;
                    cout << "Enter new Living City : "; cin >> nLivingCity;
                    current->Living_city = nLivingCity;
                    cout << "\033[34m";
                    cout << "Living City Updated Successfully!!!\n\n ";
                    system("pause");
                    system("cls");
                    cout << "\033[37m";
                    return;
                    break;
                case 5:
                    system("cls");
                    cout << "Current Tel.Num. : " << current->tell_no << endl;
                    cout << "Enter new Tel. Num. : "; cin >> nTel;
                    current->tell_no = nTel;
                    cout << "\033[34m";
                    cout << "Tel. Num. Updated Successfully!!! \n\n ";
                    system("pause");
                    system("cls");
                    cout << "\033[37m";
                    return;
                    break;
                case 6:
                    system("cls");
                    cout << "Current Salary Per Day : " << current->salaryPerHour << endl;
                    cout << "Enter new Salary Per Day : "; cin >> nSal;
                    current->salaryPerHour = nSal;
                    cout << "\033[34m";
                    cout << "Salary per Day Updated Successfully!!! \n\n ";
                    system("pause");
                    system("cls");
                    cout << "\033[37m";
                    return;
                    break;
                default:
                    system("cls");
                    cout << "\033[31m";
                    cout << "Invalid index please try again!!! \n\n ";
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
        cout << "Invalid index please try again!!! \n\n ";
        system("pause");
        system("cls");
        cout << "\033[37m";
        return;
    }
};