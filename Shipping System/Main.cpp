#include <iostream>
#include <fstream>
#include <sstream>
#include "Stack.h"
#include "Queue.h"
#include "Destination.h"
#include "Package.h"
#include "Truck.h"
using namespace std;

struct Node {
    Package data;
    struct Node* next;
    struct Node* prev;
};

/* Function to delete a node in a Doubly Linked List.
   head_ref --> pointer to head node pointer.
   del  -->  pointer to node to be deleted. */
void deleteNode(struct Node** head_ref, struct Node* del)
{
    /* base case */
    if (*head_ref == NULL || del == NULL)
        return;

    /* If node to be deleted is head node */
    if (*head_ref == del)
        *head_ref = del->next;

    /* Change next only if node to be deleted is NOT
       the last node */
    if (del->next != NULL)
        del->next->prev = del->prev;

    /* Change prev only if node to be deleted is NOT
       the first node */
    if (del->prev != NULL)
        del->prev->next = del->next;

    /* Finally, free the memory occupied by del*/
    free(del);
}

/* Function to delete the node at the given position
   in the doubly linked list */
void deleteNodeAtGivenPos(struct Node** head_ref, int n)
{
    /* if list in NULL or invalid position is given */
    if (*head_ref == NULL || n <= 0)
        return;

    struct Node* current = *head_ref;
    int i;

    /* traverse up to the node at position 'n' from
       the beginning */
    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;

    /* if 'n' is greater than the number of nodes
       in the doubly linked list */
    if (current == NULL)
        return;

    /* delete the node pointed to by 'current' */
    deleteNode(head_ref, current);
}

/* Function to insert a node at the beginning
   of the Doubly Linked List */
void append(struct Node** head_ref, Package new_data)
{
    /* 1. allocate node */
    struct Node* new_node = new Node;

    struct Node* last = *head_ref; /* used in step 5*/

    /* 2. put in the data  */
    new_node->data = new_data;

    /* 3. This new node is going to be the last node, so
          make next of it as NULL*/
    new_node->next = NULL;

    /* 4. If the Linked List is empty, then make the new
          node as head */
    if (*head_ref == NULL) {
        new_node->prev = NULL;
        *head_ref = new_node;
        return;
    }

    /* 5. Else traverse till the last node */
    while (last->next != NULL)
        last = last->next;

    /* 6. Change the next of last node */
    last->next = new_node;

    /* 7. Make last node as previous of new node */
    new_node->prev = last;

    return;
}

/* Function to print nodes in a given doubly
   linked list */
void printList(struct Node* head)
{

    while (head != NULL) {


        cout << head->data.getPack() << " ";

        head = head->next;

    }
}
string printPack(struct Node* head,int pos)
{
    int i = 0;
    while (head != NULL) {

        if (i == pos) {
            //cout << head->data.getPack() << " ";
            return head->data.getPack();
        }
        head = head->next;
        i++;
    }
}
int findSize(struct Node *node)
{
    int res = 0;
    while (node != NULL)
    {
        res++;
        node = node->next;
    }
    return res;
}






int main(int argc, char *argv[]) {

    freopen(argv[5],"w",stdout);

    Stack<Package> s;
    Queue<Truck> q;
    string top;
    //Package p1("a");
    //Truck t1("b");


    string line;
    string line1;
    string line2;
    int counter =0;

    ifstream Des(argv[1]);
    while (getline(Des, line)) {
        counter++;
    }


    int i = 0;
    Destination destArr[counter];
    ifstream Des1(argv[1]);

    while (getline(Des1, line1)) {

        destArr[i] = Destination (line1,s,q);

        string packLine;
        ifstream pck(argv[2]);
        while (getline(pck,packLine)) {
            string delimiter = " ";
            string split[2];
            size_t pos = 0;
            string token;
            int a = 0;
            while ((pos = packLine.find(delimiter)) != string::npos) {
                token = packLine.substr(0, pos);
                split[a] = token;
                packLine.erase(0, pos + delimiter.length());
                a++;
            }
            split[a] = packLine;
            //cout << line1 << endl;
            //cout<< split[1] <<endl;

            if (split[1] == line1) {

                destArr[i].s.push(Package(split[0]));
            }
        }
            string truckLine;
            ifstream trc(argv[3]);

        while (getline(trc,truckLine)) {
            string delimiter1 = " ";
            string tSplit[3];
            size_t pos1 = 0;
            string token1;
            int a1 = 0;
            while ((pos1 = truckLine.find(delimiter1)) != string::npos) {
                token1 = truckLine.substr(0, pos1);
                tSplit[a1] = token1;
                truckLine.erase(0, pos1 + delimiter1.length());
                a1++;
            }
            tSplit[a1] = truckLine;
            if (tSplit[1] == line1){
                destArr[i].q.enqueue(Truck(tSplit[0]));
            }

        }
        i++;
    }


    ifstream Mis(argv[4]);
    while (getline(Mis, line2)) {

        string del = "-";
        string mission[6];
        size_t pos2 = 0;
        string token2;
        int a2 = 0;
        Truck tru("");
        while ((pos2 = line2.find(del)) != string::npos) {
            token2 = line2.substr(0, pos2);
            mission[a2] = token2;
            line2.erase(0, pos2 + del.length());
            a2++;
        }
        mission[a2] = line2;



        struct Node* head = NULL;


        for (int i = 0; i < counter; i++) {

            if (destArr[i].getCity() == mission[0]) {
                int asd = 0;
                stringstream y(mission[3]);
                int x = 0;
                y >> x;
                destArr[i].q.getFront(tru);
                destArr[i].q.dequeue();
                while (asd < x) {
                    Package p;
                    destArr[i].s.getTop(p);

                    append(&head, p);
                    destArr[i].s.pop();
                    asd++;
                }
            }
        }
        for (int i = 0; i < counter; i++) {
            if (destArr[i].getCity() == mission[1]) {


                int asd = 0;
                stringstream y(mission[4]);
                int x = 0;
                y >> x;

                while (asd < x) {
                    Package p;
                    destArr[i].s.getTop(p);
                    append(&head, p);
                    destArr[i].s.pop();
                    asd++;
                }
                string ayrac = ",";
                string sss = mission[5];
                size_t pos3 = 0;
                string token3;
                int a3 = 0;
                while ((pos3 = sss.find(ayrac)) != string::npos) {
                    token3 = sss.substr(0, pos3);
                    //mission[a2] = token2;
                    sss.erase(0, pos3 + ayrac.length());
                    a3++;
                }
                string index[a3 + 1];
                string ss = mission[5];
                size_t pos4 = 0;
                string token4;
                int a4 = 0;
                //cout << mission[5]<<endl;
                //cout << a3<<endl;

                while ((pos4 = ss.find(ayrac)) != string::npos) {
                    token4 = ss.substr(0, pos4);
                    index[a4] = token4;
                    ss.erase(0, pos4 + ayrac.length());
                    a4++;
                }
                index[a4] = ss;

                int indexArr[a3 + 1];
                for (int i = 0; i < a3 + 1; i++) {
                    stringstream yy(index[i]);
                    int xx = 0;
                    yy >> xx;
                    indexArr[i] = xx;

                }
                for (int i = 0; i < a3 + 1; i++) {
                    for (int j = 0; j < a3 + 1; j++) {
                        if (i < j && indexArr[i] < indexArr[j]) {
                            indexArr[j] = indexArr[j] - 1;

                        }
                    }
                }
                int birak = 0;

                while (birak < a3 + 1) {


                    destArr[i].s.push(Package(printPack(head, indexArr[birak])));
                    deleteNodeAtGivenPos(&head, indexArr[birak] + 1);
                    birak++;

                }

            }
        }
        for (int i = 0; i < counter; i++) {
            if (destArr[i].getCity() == mission[2]){
                destArr[i].q.enqueue(tru);
                while (findSize(head) !=0){

                    destArr[i].s.push(Package(printPack(head,0)));
                    deleteNodeAtGivenPos(&head,1);

                }
            }

        }


    }


    //destArr[0].s.push(Package("P7"));
    for (int i = 0; i < counter; i++) {
        Package p1("");
        cout <<destArr[i].getCity()<<endl;
        cout <<"Packages:"<<endl;
        while (!destArr[i].s.isEmpty()) {
            destArr[i].s.getTop(p1);
            cout << p1.getPack()<<endl;
            destArr[i].s.pop();

        }
        cout <<"Trucks:"<<endl;
        Truck t2("");
        while (!destArr[i].q.isEmpty()) {
            destArr[i].q.getFront(t2);
            cout << t2.getTruck() << endl;
            destArr[i].q.dequeue();
        }
        cout <<"-------------"<<endl;
    }

}
