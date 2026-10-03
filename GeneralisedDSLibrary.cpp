    ////////////////////////////////////////////////////////////////////////////////////////////////////
//                              Generalised Data Structure Library
////////////////////////////////////////////////////////////////////////////////////////////////////

/*--------------------------------------------------------------------------------------------------------------
Type                    Name of Class For Node                               Name of Class for Functionality
----------------------------------------------------------------------------------------------------------------
Singly Linear           SinglyLLLnode                                        SinglyLLL          Done
Singly Circular         SinglyCLLnode                                        SinglyCLL          Done
Doubly Linear           DoublyLLLnode                                        DoublyLLL          Done
Doubly Circular         DoublyCLLnode                                        DoublyCLL          Done
----------------------------------------------------------------------------------------------------------------*/

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////////
//                        Singly Linear Linked list Using Generic apporach
////////////////////////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// Sinlgy Linear Linked List (Using Templates)
// -----------------------------------------------------------------------------
// Description  : Implementation of Singly Linear Linked List in C++
//                using generic programming (templates).
// Author       : Prathamesh Rajesh Bawane
// Date         : 07/01/2026
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name : SinglyLLLnode
//  Description    : Represents a node of Singly Linear Linked List
//  Template Type  : T (Generic data type)
//  Members        :
//      data  - Stores value of type T
//      next  - Pointer to next node
//
////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class SinglyLLLnode
{
    public:
        T data;
        SinglyLLLnode<T> *next;

        SinglyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name   : SinglyLLL
//  Description  : Generic (template-based) Singly Linear Linked List.
//                 Supports insertion, deletion, traversal, and counting
//                 operations for any data type.
//  Author       : Prathamesh Rajesh Bawane
//  Date         : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyLLL
{
    private:
        SinglyLLLnode<T> * first;
        int iCount;

    public:
        SinglyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name : SinglyLLL
//  Description      : Initializes linked list with zero nodes.
//  Author           : Prathamesh Rajesh Bawane
//  Date             : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyLLL<T>::SinglyLLL()
{
    cout<<"Object of SinglyLL get created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the singly linear linked list
//                  from first node to last node.
//  Input         : void
//  Output        : Prints all node data of type T on screen
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::Display()
{
    if(first == NULL)
    {
        return;
    }

    SinglyLLLnode<T> * temp = first;

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp -> next;
    }
    
    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns total number of nodes present in the linked list.
//  Input         : void
//  Output        : Integer value representing count of nodes
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding a node at first position
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertFirst(T no)
{
    SinglyLLLnode<T> * newn = NULL;

    newn = new SinglyLLLnode<T>(no);

    newn->next = this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding a node at last position
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertLast(T no)
{
    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    newn = new SinglyLLLnode<T>(no);

    if(this->iCount == 0)
    {
        this->first = newn;
    }
    else
    {
        temp = this->first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a new node at the specified position in the linked list.
//  Input         : T no   → Data to be inserted
//                  int pos → Position at which node is to be inserted
//  Output        : Linked list is modified by inserting node at given position
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::InsertAtPos(T no,int pos)
{
    int iCnt = 0;

    SinglyLLLnode<T> * newn = NULL;
    SinglyLLLnode<T> * temp = NULL;

    if(pos < 1 || pos > this->iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->InsertFirst(no);
    }
    else if(pos == this->iCount + 1)
    {
        this->InsertLast(no);
    }
    else
    {
        newn = new SinglyLLLnode<T>(no);

        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        this->iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Deletes the first node of the linked list.
//  Input         : void
//  Output        : Removes first node and deallocates its memory
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteFirst()
{
    SinglyLLLnode<T> *  temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;
        this->first = this->first->next;
        delete temp;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Deletes the last node of the linked list.
//  Input         : void
//  Output        : Removes last node and deallocates its memory
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteLast()
{
    SinglyLLLnode<T> * temp = NULL;

    if(this->first == NULL)
    {
        return;
    }
    else if(this->first->next == NULL)
    {
        delete this->first;
        this->first = NULL;
    }
    else
    {
        temp = this->first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
        
        delete temp->next;
        temp->next = NULL;
    }

    this->iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes a node from the specified position in the linked list.
//  Input         : int pos → Position of node to be deleted
//  Output        : Linked list is modified by removing the node from given position
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyLLL<T>::DeleteAtPos(int pos)
{
    int iCnt = 0;

    SinglyLLLnode<T> * temp = NULL;
    SinglyLLLnode<T> * target = NULL;

    if(pos < 1 || pos > this->iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        this->DeleteFirst();
    }
    else if(pos == this->iCount)
    {
        this->DeleteLast();
    }
    else
    {
        temp = this->first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        this->iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                        Doubly Linear Linked list Using Generic apporach
//////////////////////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
//  Doubly Linear Linked List (Using Templates)
// -----------------------------------------------------------------------------
// Description  : Implementation of Doubly Linear Linked List in C++
//                using generic programming (templates).
// Author       : Prathamesh Rajesh Bawane
// Date         : 07/01/2026
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Structure Name : DoublyLLLnode
// Description    : Represents a single node of a Doubly Linear Linked List.
// Template Type  : T (Generic data type)
// Members        :
//      data  - Stores data of generic type
//      next  - Pointer to next node
//      prev  - Pointer to previous node
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
struct DoublyLLLnode
{
    public:
        T data;
        struct DoublyLLLnode<T> *next;
        struct DoublyLLLnode<T> *prev;

        DoublyLLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name  : DoublyLLL
// Description : Provides functionality to manage Doubly Linear Linked List.
// Features    :
//      - Insertion at first, last, and specific position
//      - Deletion from first, last, and specific position
//      - Display list elements
//      - Count total number of nodes
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyLLL
{
    private:
        DoublyLLLnode<T> * first;           // Pointer to first node
        int iCount;                         // Stores number of nodes

    public:
        DoublyLLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constructor Name : DoublyLLL
// Description      : Initializes an empty doubly linked list.
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyLLL<T>::DoublyLLL()
{
    cout<<"Object of DoublyLLL gets created.\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays all elements of the doubly linked list
//                 in forward direction.
// Input         : void
// Output        : Prints node data on console
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::Display()
{
    DoublyLLLnode<T> * temp = first;

    cout<<"\n NULL <=> ";

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }

    cout<<"NULL\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Returns total number of nodes present in the linked list.
// Input         : void
// Output        : Integer value representing node count
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyLLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a new node at the beginning of the linked list.
// Input         : T no → Data to be inserted
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertFirst(T no)
{
    DoublyLLLnode<T> * newn = new DoublyLLLnode<T>(no);

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a new node at the end of the linked list.
// Input         : T no → Data to be inserted
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertLast(T no)
{
    DoublyLLLnode<T> * newn = new DoublyLLLnode<T>(no);
    DoublyLLLnode<T> * temp = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a node at the specified position.
// Input         : T no  → Data to be inserted
//                 int pos → Position for insertion
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::InsertAtPos(T no,int pos)
{
    int iCnt = 0;

    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        DoublyLLLnode<T> * newn = new DoublyLLLnode<T>(no);
        DoublyLLLnode<T> * temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes the first node from the linked list.
// Input         : void
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteFirst()
{
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        DoublyLLLnode<T> * temp = first;
        first = first->next;
        first->prev = NULL;
        delete temp;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node from the linked list.
// Input         : void
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteLast()
{
    DoublyLLLnode<T> * temp =NULL;

    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }

        delete temp->next;
        temp->next = NULL;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes a node from the specified position.
// Input         : int pos → Position of node to delete
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyLLL<T>::DeleteAtPos(int pos)
{
    int iCnt = 0;
    DoublyLLLnode<T> * temp = NULL;
    DoublyLLLnode<T> * target = NULL;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        delete target;

        iCount--;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                        Singly Circular Linked list Using Generic apporach
//////////////////////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
// Singly Circular Linked List (Using Templates)
// -----------------------------------------------------------------------------
// Description  : Implementation of Singly Circular Linked List in C++
//                using generic programming (templates).
// Author       : Prathamesh Rajesh Bawane
// Date         : 07/01/2026
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Structure Name : SinglyCLLnode
//  Description    : Represents a node of Singly Circular Linked List
//  Template Type  : T (Generic data type)
//  Members        :
//      data  - Stores value of type T
//      next  - Pointer to next node
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma pack(1)
template <class T>
class SinglyCLLnode
{
    public:
        T data;
        SinglyCLLnode<T> *next;

        SinglyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name   : SinglyCLL
//  Description  : Generic (template-based) Singly Circular Linked List.
//                 The last node points back to the first node.
//                 Supports insertion, deletion, traversal, and counting
//                 operations for any data type.
//  Author       : Prathamesh Rajesh Bawane
//  Date         : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class SinglyCLL
{
    private:
        SinglyCLLnode<T> * first;
        SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Constructor Name : SinglyCLL
//  Description      : Initializes an empty Singly Circular Linked List.
//  Author           : Prathamesh Rajesh Bawane
//  Date             : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
SinglyCLL<T>::SinglyCLL()
{
    cout<<"Inside constructor of SinglyCLL\n";

    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the circular linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding node at first position
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertFirst(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;
        last->next = first;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the circular linked list.
//  Input         : T no → Data to be inserted
//  Output        : Linked list is modified by adding node at last position
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertLast(T no)
{
    SinglyCLLnode<T> * newn = NULL;

    newn = new SinglyCLLnode<T>(no);

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
        last->next = first;
    }
    else
    {
        last->next = newn;
        last = newn;
        last->next = first;
    }

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Deletes the first node of the circular linked list.
//  Input         : void
//  Output        : Removes first node and deallocates its memory
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete last->next;
        last->next = first;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Deletes the last node of the circular linked list.
//  Input         : void
//  Output        : Removes last node and deallocates its memory
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteLast()
{
    SinglyCLLnode<T> * temp = NULL;

    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        temp = first;

        while(temp->next != last)
        {
            temp = temp->next;
        }

        delete last;
        last = temp;
        last->next = first;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the singly circular linked list.
//  Input         : void
//  Output        : Prints all node data of type T on screen
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::Display()
{
    if(first == NULL && last == NULL)
    {
        return;
    }

    SinglyCLLnode<T> * temp = first;

    do
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    } while(temp != last->next);

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Returns total number of nodes present in the circular linked list.
//  Input         : void
//  Output        : Integer value representing count of nodes
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int SinglyCLL<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes a node from the specified position in the circular linked list.
//  Input         : int pos → Position of node to be deleted
//  Output        : Linked list is modified by removing the node from given position
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::DeleteAtPos(int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * target = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        delete target;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a new node at the specified position in the circular linked list.
//  Input         : T no   → Data to be inserted
//                  int pos → Position at which node is to be inserted
//  Output        : Linked list is modified by inserting node at given position
//  Author        : Prathamesh Rajesh Bawane
//  Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void SinglyCLL<T>::InsertAtPos(T no, int pos)
{
    SinglyCLLnode<T> * temp = NULL;
    SinglyCLLnode<T> * newn = NULL;
    int i = 0;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new SinglyCLLnode<T>(no);

        temp = first;

        for(i = 1; i < pos-1; i++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;

        iCount++;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                        Doubly Circular Linked list Using Generic apporach
//////////////////////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
//  Doubly Circular Linked List (Using Templates)
// -----------------------------------------------------------------------------
// Description  : Implementation of Doubly Circular Linked List in C++
//                using generic programming (templates).
// Author       : Prathamesh Rajesh Bawane
// Date         : 07/01/2026
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name           : DoublyCLLnode
// Description    : Represents a single node of Doubly Circular Linked List.
// Template Type  : T (Generic data type)
// Members        :
//      data  - Stores data of generic type
//      next  - Pointer to next node
//      prev  - Pointer to previous node
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#pragma pack(1)
template <class T>
class DoublyCLLnode
{
    public:
        T data;
        DoublyCLLnode<T> *next;
        DoublyCLLnode<T> *prev;

        DoublyCLLnode(T no)
        {
            this->data = no;
            this->next = NULL;
            this->prev = NULL;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name  : DoublyCLL
// Description : Implements Doubly Circular Linked List operations.
// Features    :
//      - Insert node at first, last, and specific position
//      - Delete node from first, last, and specific position
//      - Display list elements
//      - Count total number of nodes
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class DoublyCLL
{
    private:
        DoublyCLLnode<T> * first;           // Pointer to first node
        DoublyCLLnode<T> * last;            // Pointer to last node
        int iCount;                         // Stores number of nodes

    public:
        DoublyCLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void DeleteFirst();
        void DeleteLast();
        void Display();
        int Count();
        void DeleteAtPos(int pos);
        void InsertAtPos(T no, int pos);
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constructor Name : DoublyCLL
// Description      : Initializes an empty doubly circular linked list.
// Input            : void
// Output           : Sets first and last pointers to NULL
// Author           : Prathamesh Rajesh Bawane
// Date             : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
DoublyCLL<T>::DoublyCLL()
{
    cout<<"Object of DoublyCLL gets created.\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays all elements of the doubly circular linked list
//                 in forward circular manner.
// Input         : void
// Output        : Prints all node data on console
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::Display()
{
    DoublyCLLnode<T> * temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"Linked list is empty\n";
        return;
    }

    cout<<" <=> ";

    do
    {
        cout<<"| "<<temp->data<<" | <=> ";
        temp = temp->next;
    }while(temp != last->next);

    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Returns total number of nodes present in the linked list.
// Input         : void
// Output        : Integer value representing node count
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int DoublyCLL<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertFirst
// Description   : Inserts a new node at the beginning of doubly circular linked list.
// Input         : T no → Data to be inserted
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertFirst(T no)
{
    DoublyCLLnode<T> * newn = new DoublyCLLnode<T>(no);

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertLast
// Description   : Inserts a new node at the end of doubly circular linked list.
// Input         : T no → Data to be inserted
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertLast(T no)
{
    DoublyCLLnode<T> * newn = new DoublyCLLnode<T>(no);

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        newn->prev = last;
        last->next = newn;
        last = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : InsertAtPos
// Description   : Inserts a new node at the specified position.
// Input         : T no  → Data to be inserted
//                 int pos → Position for insertion
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::InsertAtPos(T no,int pos)
{
    int iCnt = 0;

    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount + 1)
    {
        InsertLast(no);
    }
    else
    {
        DoublyCLLnode<T> * newn = new DoublyCLLnode<T>(no);
        DoublyCLLnode<T> * temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        temp->next->prev = newn;
        temp->next = newn;

        iCount++;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteFirst
// Description   : Deletes the first node from doubly circular linked list.
// Input         : void
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        last->next = first;
        first->prev = last;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteLast
// Description   : Deletes the last node from doubly circular linked list.
// Input         : void
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete first;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;
        last->next = first;
        first->prev = last;
    }

    iCount--;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeleteAtPos
// Description   : Deletes a node from the specified position.
// Input         : int pos → Position of node to delete
// Output        : Linked list is updated
// Author        : Prathamesh Rajesh Bawane
// Date          : 07/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void DoublyCLL<T>::DeleteAtPos(int pos)
{
    int iCnt = 0;
    DoublyCLLnode<T> * temp = NULL;

    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid position\n";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;

        for(iCnt = 1; iCnt < pos - 1; iCnt++)
        {
            temp = temp->next;
        }

        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;

        iCount--;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//                                  Stack Using Generic apporach
////////////////////////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
//  Stack (Using Templates)
// -----------------------------------------------------------------------------
// Description  : Implementation of Stack data structure in C++
//                using generic programming (templates).
// Author       : Prathamesh Rajesh Bawane
// Date         : 08/01/2026
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name           : StackNode
// Description    : Represents a single node of Stack data structure.
// Template Type  : T (Generic data type)
// Members        :
//      data  - Stores data of generic type
//      next  - Pointer to next node (used to maintain stack linkage)
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Stacknode
{
    public:
        T data;
        Stacknode<T> * next;

        Stacknode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name  : Stack
// Description : Implements Stack data structure operations.
// Features    :
//      - Push element into the stack
//      - Pop element from the stack
//      - Peep top element of the stack
//      - Display stack elements
//      - Count total number of elements in the stack
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Stack
{
    private:
        Stacknode<T> * first;
        int iCount;

    public:
        Stack();

        void Push(T);         
        T Pop();            
        T Peep();
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Stack (Constructor)
// Description   : Initializes an empty stack by setting the top pointer
//                 to NULL and element count to zero.
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Stack<T> :: Stack()
{
    cout<<"Stack is Created...\n";
    this->first = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name  : Push
//  Description    : Inserts an element at the top of the stack
//  Input          : Integer value
//  Output         : None
//  Author         : Prathamesh Rajesh Bawane
//  Date           : 08/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T> :: Push(T no)
{
    Stacknode<T> * newn = NULL;
    newn = new Stacknode<T>(no);

    newn -> next= this->first;
    this->first = newn;

    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name  : Pop
//  Description    : Removes and returns the top element from the stack
//  Input          : None
//  Output         : Integer (removed element)
//  Author         : Prathamesh Rajesh Bawane
//  Date           : 08/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T>:: Pop()
{
    T Value = 0;
    Stacknode<T> * temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    this->first = this->first->next;
    delete temp;

    this->iCount--;

    return Value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name  : Peep
//  Description    : Returns the top element of the stack without removing it
//  Input          : None
//  Output         : Integer (top element)
//  Author         : Prathamesh Rajesh Bawane
//  Date           : 08/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T Stack<T> :: Peep()
{
    T Value = 0;

    if(this->first == NULL)
    {
        cout<<"Stack is empty\n";
        return -1;
    }

    Value = this->first->data;

    return Value;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name  : Display
//  Description    : Displays all elements of the stack from top to bottom
//  Input          : None
//  Output         : Stack elements
//  Author         : Prathamesh Rajesh Bawane
//  Date           : 08/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Stack<T> :: Display()
{
    Stacknode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL)
    {
        cout<<"Stack is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"|\t"<<temp->data<<"\t|\n";
        temp = temp -> next;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name  : Count
//  Description    : Returns the total number of elements present in the queue
//  Input          : None
//  Output         : Integer (count of elements)
//  Author         : Prathamesh Rajesh Bawane
//  Date           : 08/01/2026
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Stack<T> :: Count()
{
    return this->iCount;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//                        Queue Using Generic apporach
//////////////////////////////////////////////////////////////////////////////////////////////////

// -----------------------------------------------------------------------------
//  Queue (Using Templates)
// -----------------------------------------------------------------------------
// Description  : Implementation of Queue data structure in C++
//                using generic programming (templates).
// Author       : Prathamesh Rajesh Bawane
// Date         : 08/01/2026
// -----------------------------------------------------------------------------

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Name           : QueueNode
// Description    : Represents a single node of Queue data structure.
// Template Type  : T (Generic data type)
// Members        :
//      data  - Stores data of generic type
//      next  - Pointer to next node (used to maintain queue linkage)
//
////////////////////////////////////////////////////////////////////////////////////////////////////

#pragma pack(1)
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> * next;

        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name  : Queue
// Description : Implements Queue data structure operations.
// Features    :
//      - Enqueue element into the queue
//      - Dequeue element from the queue
//      - Display queue elements
//      - Count total number of elements in the queue
// Notes       :
//      - Maintains two pointers:
//            * first - Points to the front element of the queue
//            * last  - Points to the rear element of the queue
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
class Queue
{
    private:
        Queuenode<T> * first;
        Queuenode<T> * last;
        int iCount;

    public:
        Queue();

        void EnQueue(T);    
        T DeQueue();          
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Queue (Constructor)
// Description   : Initializes an empty queue by setting both first and last
//                 pointers to NULL and element count to zero.
//
////////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
Queue<T> :: Queue()
{
    cout<<"Queue is Created...\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name  : EnQueue
//  Description    : Inserts an element at the rear end of the queue
//  Input          : Integer value
//  Output         : None
//  Author         : Prathamesh Rajesh Bawane
//  Date           : 08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: EnQueue(T no)
{
    Queuenode<T> * newn = NULL;
    newn = new Queuenode<T>(no);

    if(this->first == NULL && this->last == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = this->last->next;      // this->last = newn;
    }

    this->iCount++;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name  : Dequeue
//  Description    : Removes and returns the front element from the queue
//  Input          : None
//  Output         : Integer (removed element)
//  Author         : Prathamesh Rajesh Bawane
//  Date           : 08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
T Queue<T> :: DeQueue()
{
    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is empty\n";
        return -1;
    }

    T Value;
    Queuenode<T> * temp = this->first;

    Value = this->first->data;

    if(this->first == this->last)
    {
        delete first;
        this->first = NULL;
        this->last = NULL;
    }
    else
    {
        this->first = this->first -> next;
        delete temp;
    }

    this->iCount--;

    return Value;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name  : Display
//  Description    : Displays all elements of the queue from front to rear
//  Input          : None
//  Output         : Queue elements
//  Author         : Prathamesh Rajesh Bawane
//  Date           : 08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void Queue<T> :: Display()
{
    Queuenode<T> * temp = NULL;
    temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" |--";
        temp = temp -> next;
    }
    cout<<"\n";
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name  : Count
//  Description    : Returns the total number of elements present in the queue
//  Input          : None
//  Output         : Integer (count of elements)
//  Author         : Prathamesh Rajesh Bawane
//  Date           : 08/01/2026
//
//////////////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int Queue<T> :: Count()
{
    return this->iCount;
}

/////////////////////////////////////////////End Of Library/////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Entry point function : Main
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main()
{

    cout<<"-----------------------------------------------------------------------------------------------------\n";
    
    int iRet = 0;

    SinglyLLL<int> * obj = new SinglyLLL<int>();

    obj->InsertFirst(51);
    obj->InsertFirst(21);
    obj->InsertFirst(11);

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj->InsertLast(101);
    obj->InsertLast(111);
    obj->InsertLast(121);

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj->DeleteFirst();

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj->DeleteLast();

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj->InsertAtPos(105, 4);

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    obj->DeleteAtPos(4);

    obj->Display();

    iRet = obj->Count();
    cout << "Total nodes are: "<< iRet << "\n";

    /*---------------------------------------------------------------------------------------------------------*/

    cout<<"-----------------------------------------------------------------------------------------------------\n";

    DoublyLLL<char> * dobj = new DoublyLLL<char>();

    dobj->InsertFirst('A');
    dobj->InsertFirst('B');
    dobj->InsertFirst('c');

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    dobj->InsertLast('X');
    dobj->InsertLast('Y');
    dobj->InsertLast('Z');

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    dobj->DeleteFirst();

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    dobj->DeleteLast();

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    dobj->InsertAtPos('$', 4);

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    dobj->DeleteAtPos(4);

    dobj->Display();
    cout<<"Total Elements are: "<<dobj->Count()<<"\n";

    cout<<"-----------------------------------------------------------------------------------------------------\n";

    DoublyCLL<char> * cobj = new DoublyCLL<char>();

    cobj->InsertFirst('D');
    cobj->InsertFirst('E');
    cobj->InsertFirst('T');

    cobj->Display();
    cout<<"Total Elements are: "<<cobj->Count()<<"\n";

    cobj->InsertLast('L');
    cobj->InsertLast('M');
    cobj->InsertLast('N');

    cobj->Display();
    cout<<"Total Elements are: "<<cobj->Count()<<"\n";

    cobj->DeleteFirst();

    cobj->Display();
    cout<<"Total Elements are: "<<cobj->Count()<<"\n";

    cobj->DeleteLast();

    cobj->Display();
    cout<<"Total Elements are: "<<cobj->Count()<<"\n";

    cobj->InsertAtPos('@', 4);

    cobj->Display();
    cout<<"Total Elements are: "<<cobj->Count()<<"\n";

    cobj->DeleteAtPos(4);

    cobj->Display();
    cout<<"Total Elements are: "<<cobj->Count()<<"\n";

    delete obj;
    delete dobj;
    delete(cobj);

    return 0;
}