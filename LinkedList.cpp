/**
 * LinkedList
 * Written By Josh Harshman
 * 08/13/2015
 * */

#include "LinkedList.h"

template <class T>
class LinkedList {

private:

    /*
     * Nested Node Class
     * Class Function Definitions and Implementations
     */
    template <class U>
    class Node {
    protected:
        T data;
        Node<U> *next;
    public:
        /* Constructors */
        Node();
        Node(T data, Node<U> *next);
        Node(const Node<U> &orig);
        ~Node();

        /* Assessors */
        T getData() const { return data; }
        Node<U> *getNext() const { return next; }

        /* Modifiers */
        void setData(T data);
        void setNext(Node<U> *next);
    };

    /*
     * Linked List Class
     * Function Definitions and Implementations
     */
public:
    /* Constructors */
    LinkedList();
    ~LinkedList();
    LinkedList(const LinkedList<T> &orig);

    /* Subroutines */
    bool isEmpty() { return (this->head->getNext() == NULL); }
    int getSize() const { return size; }
    void addFirst(T data);
    void addLast(T data);
    bool add(T data);
    bool add(int index, T data);
    bool remove(T data);
    void clear();

private:
    Node<T> *head;
    Node<T> *cur;
    int size;
};

/**
 * Nested Node Implementation
 * */
template <class T>
template <class U>
LinkedList<T>::Node<U>::Node() {
    data = nullptr;
    next = nullptr;
}

template <class T>
template <class U>
LinkedList<T>::Node<U>::Node(const LinkedList<T>::Node<U> &orig) {
    setData(orig.getData());
    setNext(orig.getNext());
}

template <class T>
template <class U>
void LinkedList<T>::Node<U>::setData(T data) {
    this->data = data;
}

template <class T>
template <class U>
void LinkedList<T>::Node<U>::setNext(Node<U> *next) {
    this->next = next;
}

// --- [ END NODE CLASS IMPLEMENTATION ] ---

/**
 * Linked List Implementation
 * */

/*
template <class T>
LinkedList<T>::LinkedList() : head(0),  cur(0) { }

template <class T>
void LinkedList<T>::addFirst(T data) {
    Node *cur = this->head;
    cur->setNext( new Node(data, NULL) );
    this->size++;
}

template <class T>
void LinkedList<T>::addLast(T data) {
    if( isEmpty() )
        addFirst(data);
    else {
        Node *cur = this->head;
        while ( cur->getNext() != NULL )
            cur = cur->getNext();
        cur->setNext( new Node(data, NULL) );
        this->size++;
    }
}

template <class T>
bool LinkedList<T>::add(T data) {
    if( isEmpty() ) {
        addFirst(data);
        return true;
    }
    Node *cur = this->head;
    while( cur->getNext() != NULL )
        cur = cur->getNext();
    cur->setNext( new Node(data, NULL) );
    this->size++;
    return true;
}

template <class T>
bool LinkedList<T>::add(int index, T data) {
    if( isEmpty() ) {
        addFirst(data);
    }
    else {
        Node *cur = this->head;
        for( int i = 0; i < index; i++ ) {
            cur = cur->getNext();
        }
        cur->setNext( new Node(data, cur->getNext()) );
        this->size++;
    }
}

template <class T>
bool LinkedList<T>::remove(T data) {
    //TODO: Implement this
    return false;
}

template <class T>
void LinkedList<T>::clear() {
    head->setNext(NULL);
    size=0;
}





/*
template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &orig) {
    deepCopy(orig);
}

template <class T>
bool LinkedList<T>::seek(const T &element) {
    T tmp;
    if( first(tmp) )
        do {
            if( element == tmp )    return true;

        } while( getNext(tmp) );
    return false;
}

template <class T>
bool LinkedList<T>::first(T &element) {
    if(!head)   return false;
    element = head->getData();
    cur = head;
    return true;
}

template <class T>
bool LinkedList<T>::remove(T &element) {

}

template <class T>
bool LinkedList<T>::remove(int index) {

}

template <class T>
bool LinkedList<T>::removeall(T &data) {

}

template <class T>
inline void LinkedList<T>::deepCopy(const LinkedList<T> &orig) {
    head = cur = NULL;
    if( orig.head == NULL )  return;
    Node<T> *copy = head = new Node<T>;
    Node<T> *original = orig.head;
    copy->setData( original->getData() );
    if( original == orig.head ) head = copy;
    while( original->getNext() != NULL ) {
        original = original->getNext();
        copy->setNext(new Node<T>);
        copy = copy->getNext();
        copy->setData( original->getData() );
        if( original == orig.head ) head = copy;
    }
    copy->setNext(NULL);
}

template <class T>
inline bool LinkedList::getNext(T &element) {
    if(!cur)    return false;
    cur = cur->getNext();
    if(!cur)    return false;
    element = cur->getData();
    return true;
}

// --- [ END LINKEDLIST CLASS IMPLEMENTATION ] ---

*/


