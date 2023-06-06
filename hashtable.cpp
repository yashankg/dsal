#include <bits/stdc++.h>
using namespace std;
#define size 10
struct node
{
    int value;
    node *next;
};//*HashTable[size];
struct node *HashTable[size];

class hashing
{
    public:
    hashing()
    {
        for(int i=0; i<size; i++)
        {
            HashTable[i]=NULL;
        }
    }

    node* create_node(int x)
    {
        node* temp = new node;
        temp->next = NULL;
        temp->value = x;
        return temp;
    }

    int Hashfunction(int);
    void insert(int);
    void display();
    int search(int);
    void deleteElem(int);
};

void hashing::insert(int value)
{
    int hash_val = Hashfunction(value);
    //node* prev = NULL;
    //node* entry = HashTable(hash_val);
    node* temp = new node;
    node* head = new node;
    head = create_node(value);
    temp = HashTable[hash_val];
    if(temp == NULL)
    {
        HashTable[hash_val] = head;
    }
    else
    {
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = head;
    }
}
int hashing::Hashfunction(int value)
{
    return (value%size);
}
void hashing::display()
{
    for(int i=0; i<size; i++)
    {
        node* temp = new node;
        temp = HashTable[i];
        cout<<"a["<<i<<"]: ";
        while(temp != NULL)
        {
            cout<<"-> "<<temp->value;
            temp = temp->next;
        }
        cout<<endl;
    }
}
int hashing::search(int value)
{
    bool flag = false;
    int hash_val = Hashfunction(value);
    node* entry = HashTable[hash_val];
    cout<<endl<<"Element found at: ";
    while(entry != NULL)
    {
        if(entry->value == value)
        {
            cout<<hash_val<<": "<<entry->value<<endl;
            flag = true;
        }
        entry = entry->next;
    }
    if(!flag)
    {
        return -1;
    }
}
void hashing::deleteElem(int value)
{
    int hash_val = Hashfunction(value);
    node* entry = HashTable[hash_val];
    if(entry == NULL)
    {
        cout<<"No Element FOUND";
        return;
    }
    if(entry->value == value)
    {
        HashTable[hash_val] = entry->next;
        return;
    }
    while((entry->next)->value != value)
    {
        entry = entry->next;
    }
    entry->next = (entry->next)->next;
}

int main()
{
    hashing h;
    int ch, data, search, del;
    cout<<endl<<"***Telephone Book Database***"<<endl;
    do
    {
        cout<<"Enter choice:\n1.Insert\n2.Display\n3.Search\n4.Delete\n0.EXIT"<<endl;
        cin>>ch;
        switch(ch)
        {
            case 1:
                cout<<"enter phone no. to insert: ";
                cin>>data;
                h.insert(data);
                cout<<"Phone no. "<<data<<" inserted";
                break;
            case 2:
                h.display();
                break;
            case 3:
                cout<<"enter phone no. to search: ";
                cin>>search;
                if(h.search(search) == -1)
                {
                    cout<<"No element found"<<endl;
                    continue;
                }
                break;
            case 4:
                cout<<"enter phone no. to delete: ";
                cin>>del;
                h.deleteElem(del);
                //cout<<"Phone no. DELETED"<<endl;
                break;
            default:
                cout<<"Enter correct choice"<<endl;
        }
    } while (ch!=0);
    

    return 0;
}