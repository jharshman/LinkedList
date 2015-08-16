/**
 * LinkedList
 * Written By Josh Harshman
 * 08/13/2015
 * */

//#include "LinkedList.h"
#include <iostream>
#include <sstream>

template <class T>
class LinkedList {

private:

    /*
     * Nested Node Class
     * Class Function Definitions and Inline Implementations
     */
    class Node {
    protected:
        T data;
        Node *next;
    public:
        /* Constructors */
        Node();
        Node(T data);
        Node(T data, Node *next);
        Node(const Node &orig);
        ~Node() { };

        /* Assessors */
        T getData() const { return data; }
        Node *getNext() const { return next; }

        /* Modifiers */
        void setData(T data);
        void setNext(Node *next);

    };

    /**
     * Nested Iterator Class
     * Class Function Definitions and Inline Implementations
     * */
    class Iterator {
    private:
        Node *nextNode;
        int index;

    public:
        Iterator() {}
        Iterator(Node *start) {
            this->nextNode = start;
            this->index = 0;
        }
        bool hasNext() {
            return (nextNode != NULL);
        }
        T next() {
            if( !hasNext() ) return 0;
            T res = nextNode->getData();
            nextNode = nextNode->getNext();
            return res;
        }

    };

    /*
     * Linked List Class
     * Function Definitions and Inline Implementations
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
    T remove_at_index(int index);
    bool removeAll(T data);
    void clear();
    void print();
    T get();

    /* Operator Overload */
    //friend std::ostream &operator<< <>(std::ostream& out , const LinkedList<T>& data);
    LinkedList &operator=(const LinkedList &rhs);


private:
    Node *head;
    int size;
};


/**
 * Operator Overload Implementation
 * */
template <class T>
LinkedList<T> &LinkedList<T>::operator=(const LinkedList &rhs) {
    if(&rhs != this) {
        Node *tmp = head;
        while( tmp->getNext() != NULL) {
            head = head->getNext();
            delete tmp;
            tmp = head;
        }

        this->size = 0;
        tmp = rhs.head;
        while (tmp!= NULL) {
            add(tmp->getData(), tmp->getNext());
        }

    }
    return *this;
}
/*
template <class T>
std::ostream& operator<<(std::ostream &out, const LinkedList<T> &data) {
    std::stringstream ss;
    Node *cur = data.head;
    while ( cur != NULL )
        ss << "[ " << cur->getData() << " ]~> ";
    ss << std::endl;
    out << ss.str();
    return out;
}
 */

/**
 * Nested Node Implementation
 * */
template <class T>
LinkedList<T>::Node::Node() {
    data = NULL;
    next = NULL;
}

template <class T>
LinkedList<T>::Node::Node(T data) {
    this->data = data;
    this->next = NULL;
}

template <class T>
LinkedList<T>::Node::Node(T data, Node *next) {
    setData(data);
    setNext(next);
}

template <class T>
LinkedList<T>::Node::Node(const LinkedList<T>::Node &orig) {
    setData(orig.getData());
    setNext(orig.getNext());
}

template <class T>
void LinkedList<T>::Node::setData(T data) {
    this->data = data;
}

template <class T>
void LinkedList<T>::Node::setNext(Node *next) {
    this->next = next;
}

// --- [ END NODE CLASS IMPLEMENTATION ] ---

/**
 * Linked List Implementation
 * */

template <class T>
LinkedList<T>::LinkedList() : head( new Node(0) ), size(0) { }

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> &orig) {
    Node *tmp = orig.head;
    while (tmp != NULL)
        add(tmp->getData(), tmp->getNext());
}

template <class T>
LinkedList<T>::~LinkedList() {
    clear();
    delete head;
}

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
void LinkedList<T>::clear() {
    head->setNext(NULL);
    size=0;
}

template <class T>
void LinkedList<T>::print() {
    std::stringstream out;
    out << "Contents: " << std::endl;
    Node *cur = this->head;
    while ( cur != NULL ) {
        out << "[ " << cur->getData() << " ]~>";
        cur = cur->getNext();
    }
    out << std::endl;
    std::cout << out.str();
}

template <class T>
bool LinkedList<T>::remove(T data) {
    if( isEmpty() || data == NULL ) return false;
    for(Node *prev = this->head, *cur = this->head->getNext(); cur != NULL; prev = cur, cur = cur->getNext()) {
        if(cur->getData() == data) {
            prev->setNext(cur->getNext());
            this->size--;
            return true;
        }
    }
    return false;
}

template <class T>
T LinkedList<T>::remove_at_index(int index) {
    if(index < 0 || index >= this->size )
        return 0;
    Node *cur, *prev;
    cur = this->head->getNext();
    prev = NULL;
    T data;

    if(index == 0) {
        data = this->head->getNext()->getData();
        this->head->setNext(this->head->getNext()->getNext());
        this->size--;
        return data;
    }

    for(int i = 0; i < index; i++) {
        prev = cur;
        cur = cur->getNext();
    }
    prev->setNext(cur->getNext());
    this->size--;
    return cur->getData();
}

template <class T>
bool LinkedList<T>::removeAll(T data) {
    Node *cur = this->head->getNext();
    int index = 0;
    if( data == NULL )  return false;
    while ( cur != NULL ) {
        if(cur->getData() == data) {
            remove(data);
        }
        cur = cur->getNext();
        index++;
    }
    return true;
}

template <class T>
T LinkedList<T>::get() {
    return ( this->head->getData() );
}

// --- [ END LINKEDLIST CLASS ] ---

