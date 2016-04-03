#include <vector>
#include "Node.h"

#pragma once


using namespace std;

template<class ItemType>
class SortedDoublyLinkedList {
    //DO NOT MODIFY THIS CLASS DECLARATION. FIND T-O-D-O-S to work on.
private:
    Node<ItemType> *head;
    Node<ItemType> *tail;
    int size;
public:

    SortedDoublyLinkedList();

    SortedDoublyLinkedList(Node<ItemType> *head, Node<ItemType> *tail, int size);

    SortedDoublyLinkedList(const SortedDoublyLinkedList<ItemType> &list);    // Copy constructor

    Node<ItemType> *getPointerTo(const ItemType &target) const;

    virtual ~ SortedDoublyLinkedList();    // Destructor should be virtual

    int getCurrentSize() const;

    bool isEmpty() const;

    bool add(const ItemType &newEntry);

    bool remove(const ItemType &anEntry);

    bool contains(const ItemType &anEntry) const;

    int getFrequencyOf(const ItemType &anEntry) const;

    vector<ItemType> toVector() const;

};

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList() : head(nullptr), tail(nullptr),
                                                             size(0) { }

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList(Node<ItemType> *head, Node<ItemType> *tail, int size) :
        head(head), tail(tail), size(size) { }

template<class ItemType>
SortedDoublyLinkedList<ItemType>::SortedDoublyLinkedList(const SortedDoublyLinkedList<ItemType> &list) {
    //TODO - Implement the copy constructor
    size=0;
    Node<ItemType> *ptr=list.head;
    while(ptr != nullptr){
      this->add(ptr->getItem());
        ptr=ptr->getNext();
    }

}

template<class ItemType>
Node<ItemType> *SortedDoublyLinkedList<ItemType>::getPointerTo(const ItemType &target) const {
    //TODO - Return the Node pointer that contains the target(return nullptr if not found)
    if(size==0)return nullptr;
    Node<ItemType> *ptr=this->head;

    do{
        if(ptr->getItem()==target)return ptr;
        ptr=ptr->getNext();
    }while(ptr!= nullptr);

    return nullptr;
}

template<class ItemType>
SortedDoublyLinkedList<ItemType>::~SortedDoublyLinkedList() {
    //TODO - Implement the destructor

}

template<class ItemType>
int SortedDoublyLinkedList<ItemType>::getCurrentSize() const {
    //TODO - Return the current size

    return this->toVector().size();
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::isEmpty() const {
    //TODO - Return True if the list is empty

    return (size==0);
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::add(const ItemType &newEntry) {
    //TODO - Add an item to the sorted Doubly Linked list
    Node<ItemType> *nE =new Node<ItemType>(newEntry);
    if(this->size==0){
        this->head=nE;
        head->setPrev(nullptr);
        head->setNext(nullptr);
        this->tail=nE;
        tail->setPrev(nullptr);
        tail->setNext(nullptr);
        size++;
        return true;
    }
    Node<ItemType> *ptr=this->head;
    do{
        if (newEntry <= ptr->getItem()){
            if(ptr->getPrev()== nullptr) {
                this->head->setPrev(nE);
                nE->setNext(head);
                nE->setPrev(nullptr);
                head=nE;
                size++;
                return true;
            }
            if(ptr->getPrev()!= nullptr){
                nE->setPrev(ptr->getPrev());
                ptr->getPrev()->setNext(nE);
                nE->setNext(ptr);
                ptr->setPrev(nE);
                size++;
                return true;
            }
        }
        if(newEntry >= ptr->getItem()){
            if(ptr->getNext()== nullptr) {
                this->tail->setNext(nE);
                nE->setNext(nullptr);
                nE->setPrev(tail);
                tail=nE;
                size++;
                return true;
            }
        }
        ptr=ptr->getNext();
    }while(ptr!= nullptr);


    return false;
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::remove(const ItemType &anEntry) {
    //TODO - Remove the Item(anEntry) from the list - Return true if successful

    Node<ItemType> *ptr=this->getPointerTo(anEntry);
    if(size==1){
        head= nullptr;
        tail= nullptr;
        size--;
        return true;
    }
    if(size==0)return false;
    if(ptr->getPrev()== nullptr){
        ptr=ptr->getNext();
        ptr->setPrev(nullptr);
        head=ptr;
        size--;
        return true;
    }
    if(ptr->getNext()== nullptr){
        ptr=ptr->getPrev();
        ptr->setNext(nullptr);
        tail=ptr;
        size--;
        return true;
    }
    if (ptr->getNext()!= nullptr){
        ptr->getNext()->setPrev(ptr->getPrev());
        ptr->getPrev()->setNext(ptr->getNext());
        size--;
        return true;
    }
    return false;
}

template<class ItemType>
bool SortedDoublyLinkedList<ItemType>::contains(const ItemType &anEntry) const {
    //TODO - Check if the List contains the Item(anEntry)- Return true if successful
    if(size==0)return false;
    Node<ItemType> *ptr=this->head;

    do{
        if(ptr->getItem()==anEntry)return true;
        ptr=ptr->getNext();
    }while(ptr!= nullptr);

    return false;
}

template<class ItemType>
int SortedDoublyLinkedList<ItemType>::getFrequencyOf(const ItemType &anEntry) const {
    //TODO - Return the frequency of the Item(anEntry) in the list
    int counter=0;
    if(size==0)return 0;
    Node<ItemType> *ptr=this->head;

    do{
        if(ptr->getItem()==anEntry)counter++;
        ptr=ptr->getNext();
    }while(ptr!= nullptr);

    return counter;
}

template<class ItemType>
vector<ItemType> SortedDoublyLinkedList<ItemType>::toVector() const {
    // DO NOT MODIFY THIS FUNCTION
    vector <ItemType> myVector;
    Node<ItemType> *cur;
    cur = this->head;
    while (cur != nullptr) {
        myVector.push_back(cur->getItem());
        cur = cur->getNext();
    }
    return myVector;
}

