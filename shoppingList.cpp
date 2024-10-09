#include <iostream>
using namespace std;

class ShoppingItem{
    string name;
    int quantity;
    double price;
   ShoppingItem *next;
   ShoppingItem *prev;
public:
   ShoppingItem(){
        this->name="";
        this->quantity=0;
        this->price=0.0;
        this->next=nullptr;
        this->prev=nullptr;
    }

    void addShoppingItem(ShoppingItem **head,string newName,int newQuantity,double newPrice){
       ShoppingItem *newShoppingItem=new ShoppingItem();
        newShoppingItem->name=newName;
        newShoppingItem->quantity=newQuantity;
        newShoppingItem->price=newPrice;
        newShoppingItem->next=*head;
        newShoppingItem->prev=NULL;

        if(*head!=NULL){
            (*head)->prev=newShoppingItem;
        }

        (*head)=newShoppingItem;
    }

    void displayLinkedList(ShoppingItem *head){
       ShoppingItem *current=new ShoppingItem;
        cout<<"Transversal in forward direction"<<endl;
        while(head!=NULL){
            cout<<"Name: "<<head->name<<" ";
            cout<<"Quantity: "<<head->quantity<<" ";
            cout<<"Price: "<<head->price<<endl;
            current=head;
            head=head->next;
        }
        cout<<"NULL"<<endl; 

        cout<<"Transverse in backward direction"<<endl;
        while(current!=NULL){
           cout<<"Name: "<<current->name<<" ";
            cout<<"Quantity: "<<current->quantity<<"";
            cout<<"Price: "<<current->price<<endl;
            current =current->prev;
        }
        cout<<"NULL"<<endl;
    }
};

int main(){
   ShoppingItem *newShoppingItem= new ShoppingItem();
   ShoppingItem *head=NULL;
    newShoppingItem->addShoppingItem(&head,"Head & Shoulder",5,40.12);
    newShoppingItem->addShoppingItem(&head,"LifeBouy",10,100.00);
    newShoppingItem->addShoppingItem(&head,"Lux",20,525.99);
    newShoppingItem->addShoppingItem(&head,"ToothBrush",1,70.00);
    cout<<"Doubly linked list is as follow"<<endl;
    newShoppingItem->displayLinkedList(head);
    return 0;
}