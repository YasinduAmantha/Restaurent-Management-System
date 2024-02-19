#pragma once
#include<iostream>
#include<cstddef>
#include <iomanip>

using namespace std;

class NodeB {
public:
    int N;
    int BillNo;
    int* ItemN;
    int* DishN;  
    int TotAmount;
    string Address;
    string TellNo;
    NodeB* next;

    NodeB() {
        N = NULL;
        BillNo = NULL;
        ItemN = NULL;
        DishN = NULL;
        TotAmount = NULL;
        Address = "";
        TellNo = "";
    }

    NodeB(int n, int bill_no,int tot_amount,string address, string tell_no) {
        N = n;
        BillNo = bill_no;
        ItemN = new int[n];
        DishN = new int[n];
        TellNo = tell_no;
        TotAmount = tot_amount;
        Address = address;
    }
};

class BillList {
public:
    NodeB* head;
    NodeB* tail;
    int size;

    BillList() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(int n, int bill_no, int tot_amount, string address, string tell_no,int* item_n, int* dish_n) {
        NodeB* new_node = new NodeB(n, bill_no, tot_amount, address, tell_no);
        new_node->ItemN = item_n;
        new_node->DishN = dish_n;

        if (tail == NULL) {
            head = tail = new_node;
        }
        else {
            tail->next = new_node;
            tail = new_node;
        }
        size++;
    }

    void dequeue() {
        if (head == NULL) {
            cout << "\033[31m";
            cout << "The delivery bill list is empty!!!" << endl;
            cout << "\033[37m";
            system("pause");
            system("cls");
            return;
        }
        else {
            NodeB* old_head = head;
            head = head->next;
            cout << "\033[31m";
            cout << "Bill No : " << old_head->BillNo << " removed from the list" << endl;
            delete old_head;
            if (head == NULL) {
                tail = NULL;
            }

            cout << "\033[37m";
            system("pause");
            system("cls");
            return;
        }
    }


    void printQueue() {
        cout << "-----------------------------------------------------------" << endl;
        cout << "| Bill No |    Address     |   Telephone No.   | Total Amt |" << endl;
        cout << "-----------------------------------------------------------" << endl;

        NodeB* curr = head;
        while (curr != NULL) {

            cout << "| " << setw(8) << left << curr->BillNo << " |";
            cout << " " << setw(15) << left << curr->Address << " |";
            cout << " " << setw(17) << left << curr->TellNo << " |";
            cout << " " << setw(10) << left << curr->TotAmount << " |" << endl;
            cout << "-----------------------------------------------------------" << endl;

            curr = curr->next;
        }

        cout << endl;
        system("pause");
        system("cls");
        return;
    }


};

