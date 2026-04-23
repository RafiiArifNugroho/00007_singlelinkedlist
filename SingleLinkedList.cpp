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

        nodeBaru->next = current;
        previous->next = nodeBaru;
    }
    bool listEmpty()
    {
        return (START == NULL);
    }

    bool Search(int nim, Node **previous, Node **current)
    {
        *previous = NULL;
        *current = START;

        while ((*current != NULL) && (nim != (*current)->noMhs))
        {
            *previous = *current;
            *current = (*current)->next;
        }

        return (*current != NULL);
    }

    bool delNode(int nim)
    {
        Node *current, *previous;

        if (!Search(nim, &previous, &current))
            return false;

        if (current == START)
            START = START->next;
        else
            previous->next = current->next;

        delete current;
        return true;
    }

    void traverse()
    {
        if (listEmpty())
        {
            cout << "\nList Kosong\n";
        }
        else
        {
            cout << "\nData dalam list:\n";
            Node *currentNode = START;

            while (currentNode != NULL)
            {
                cout << currentNode->noMhs << endl;
                currentNode = currentNode->next;
            }
        }
    }
};

int main()
{
    LinkedList mhs;
    int nim;
    char ch;

    do
    {
        cout << "\nMenu\n";
        cout << "1. Tambah data\n";
        cout << "2. Hapus data\n";
        cout << "3. Tampilkan data\n";
        cout << "4. Cari data\n";
        cout << "5. Keluar\n";
        cout << "Pilihan: ";
        cin >> ch;

        switch (ch)
        {
        case '1':
            mhs.addNode();
            break;

        case '2':
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong\n";
                break;
            }
            cout << "\nMasukkan NIM yang dihapus: ";
            cin >> nim;

            if (!mhs.delNode(nim))
                cout << "Data tidak ditemukan\n";
            else
                cout << "Data berhasil dihapus\n";
            break;

        case '3':
            mhs.traverse();
            break;

        case '4':
        {
            if (mhs.listEmpty())
            {
                cout << "\nList Kosong\n";
                break;
            }

            Node *previous, *current;
            cout << "\nMasukkan NIM yang dicari: ";
            cin >> nim;

            if (!mhs.Search(nim, &previous, &current))
                cout << "Data tidak ditemukan\n";
            else
                cout << "Data ditemukan: " << current->noMhs << endl;
            break;
        }
