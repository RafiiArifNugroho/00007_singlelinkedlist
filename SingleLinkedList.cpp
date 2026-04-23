#include <iostream>
#include <string>
using namespace std;

class Node
{
public:
    int noMhs;
    Node *next;
};

class LinkedList
{
private:
    Node *START;

public:
    LinkedList()
    {
        START = NULL;
    }

    void addNode()
    {
        int nim;
        cout << "\nMasukkan Nomor Mahasiswa: ";
        cin >> nim;

        Node *nodeBaru = new Node;
        nodeBaru->noMhs = nim;
        nodeBaru->next = NULL;

        if (START == NULL || nim <= START->noMhs)
        {
            if ((START != NULL) && (nim == START->noMhs))
            {
                cout << "\nDuplikasi tidak diijinkan\n";
                return;
            }
            nodeBaru->next = START;
            START = nodeBaru;
            return;
        }

        Node *previous = START;
        Node *current = START;

        while ((current != NULL) && (nim > current->noMhs))
        {
            previous = current;
            current = current->next;
        }

        if ((current != NULL) && (nim == current->noMhs))
        {
            cout << "\nDuplikasi tidak diijinkan\n";
            return;
        }
