#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Customer {
public:
  string firstname;
  string lastname;
  string id;
  Customer() {
    firstname = "";
    lastname = "";
    id = "";
  };
  Customer(string fn, string ln, string eyed) {
    firstname = fn;
    lastname = ln;
    id = eyed;
  }
  string returnfirstName() {
    return firstname;
  }
  string returnlastName() {
    return lastname;
  }
  string returnID() {
    return id;
  }
};

template <class T>
class Node {
public:
  T item;
  Node<T>* next;
  Node<T>* prev;
  Node();
  Node(T data) {
    item = data;
    next = nullptr;
    prev = nullptr;
  }
};

template <class T>
class List {
  Node<T>* head;
  Node<T>* tail;
  int itemCount = 0;
public:
  List() {
    head = nullptr;
    tail = nullptr;
  };
  bool isEmpty() {
    Node<T>* temp;
    temp = head;
    if (temp == nullptr) {
      return true;
    }
    else {
      return false;
    }
  }
  bool add(T newEntry) {
// adds to end of list
    if (head == nullptr) {
      Node<T>* a = new Node<T>(newEntry);
      head = a;
      tail = a;
      itemCount++;
      return true;
    }
    else {
      Node<T>* b = new Node<T>(newEntry);
      tail->next = b;
      b->prev = tail;
      tail = b;
      itemCount++;
      return true;
    }
  }
  bool remove(T anEntry) {
    if (head == nullptr) {
      cout << "The list is empty, cannot remove" << endl;
      return false;
    }
    else if (head->item == anEntry) {
        delete head;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        return true;
    }
    else {
      Node<T>* temp;
      temp = head;
      int counter = 0;
      while (temp->item != anEntry) {
        temp = temp->next;
        counter++;
        if (counter > itemCount) {
          cout << "The list does not contain " << anEntry << endl;
          return false;
        }
      }
      Node<T>* n;
      n = temp->prev;
      n->next = temp->next;
      if (temp->next == nullptr) {
        delete temp;
        tail = n;
        itemCount--;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        return true;
      }
      else {
        delete temp;
        itemCount--;
        cout << "The entry: " << anEntry << " has been successfully removed." << endl;
        temp->next->prev = n;
        return true;
      }
    }
  }
  void clear() {
    Node<T>* n;
    n = head;
    while (n) {
      cout << n->item << endl;
      if(n->prev) {
        delete n->prev;
      }
      n = n->next;
    }
    delete n;
    head = nullptr;
    tail = nullptr;
    itemCount = 0;
    cout << "The array has been successfully cleared" << endl;
  }
  int getFrequencyOf(T anEntry) {
    int counter = 0;
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
        if (a->item == anEntry) {
            counter++;
        }
        a = a->next;
    }
    return counter;
  }
  bool contains(T anEntry) {
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
        if (a->item == anEntry) {
            return true;
        }
        a = a->next;
    }
    return false;
  }
  int returnCount() {
    return itemCount;
  }
  T returnHead() {
    return head->item;
  }
  T returnTail() {
    return tail->item;
  }

  Node<T>* getHead() {
    return head;
  }
  Node<T>* getTail() {
    return tail;
  }

  //modified
  void print() {
    Node<T>* a;
    a = head;
    for (int i = 0; i < itemCount; i++) {
      //cout << a->item << endl;
      Customer x = a->item;
      string one = x.returnfirstName();
      string two = x.returnlastName();
      string three = x.returnID();

      cout << one << " " << two << endl;
      cout << "ID# " << three << endl;
      a = a->next;
    }
  }
  void printReverse() {
    Node<T>* a;
    a = tail;
    for (int i = 0; i < itemCount; i++) {
      cout << a->item << endl;
      a = a->prev;
    }
  }
};

template<class T>
class dynamicArray {
    T* base;
    int used;
    int size = 10;
public:
    dynamicArray(int);
    void resize();
    void allocate(int);
    void pop();
    void push(T&);
    void set(T&, int);
    T get(int);
    T begin();
    T end();
    int length();
    int capacity();
    int getUsed();
    void setUsed(int);
    int getSize();
    void setSize(int);
};

template<class T>
dynamicArray<T>::dynamicArray(int c) {
    allocate(c);
}

template<class T>
void dynamicArray<T>::resize() {
    T* ptemp = new T [size*2];
    for (int i = 0; i < used; i++) {
        ptemp[i] = base[i];
    }
    delete [] base;
    base = ptemp;
    int x = capacity();
    x = x *2;
    setSize(x);
}

template<class T>
void dynamicArray<T>::allocate(int c) {
    setSize(c);
    base = new T [c];
}

template<class T>
void dynamicArray<T>::pop() {

    for (int i = 1; i < used; i++) {
        base[i - 1] = base[i];
        if (i == used - 2) {
            used--;
        }
        if (used == 0) {
            cout << "The value of variable 'used' is 0" << endl;
            cout << "" << endl;
        }
    }
}

template<class T>
void dynamicArray<T>::push(T& item) {
    set(item);
}

// modified
template<class T>
void dynamicArray<T>::set(T& item, int index) {
    while ((index == size) || (index > size)) {
        resize();
    }
    base[index] = item;
    used++;
}

template<class T>
T dynamicArray<T>::get(int c) {
    return base[c];
}

template<class T>
T dynamicArray<T>::begin() {
    return base[0];
}

template<class T>
T dynamicArray<T>::end() {
    return base[used - 1];
}

template<class T>
int dynamicArray<T>::length() {
    return used;
}

template<class T>
int dynamicArray<T>::capacity() {
    return size;
}

template<class T>
int dynamicArray<T>::getUsed() {
    return used;
}

template<class T>
void dynamicArray<T>::setUsed(int c) {
    used = c;
}

template<class T>
int dynamicArray<T>::getSize() {
    return size;
}

template<class T>
void dynamicArray<T>::setSize(int c) {
    size = c;
}

int hashID(string x) {
    int y, z, index;
    y = ((x[0] * x[1]) ^ x[5]) + (x[2] * x[3]) - ((x[4] + x[5] + x[6]) ^ x[7]);
    z = (x[3] * x[9] * x[10]) - (x[11] ^ (x[12])) + x[13] - (x[14] / x[15]);
    index = ((y * z) + z - y) % 997;
    return index;
}

int insertEntry(Customer c, dynamicArray<List<Customer>> a, int i) {
    int x;
    string cID = c.returnID();
    x = hashID(cID);
    List<Customer> y;
    y = a.get(x);
    if (y.isEmpty() == true) {
        bool t;
        t = y.add(c);
        a.set(y, x);
        return i;
    }
    else {
        bool t;
        t = y.add(c);
        a.set(y, x);
        i++;
        return i;
    }
}
int listCount(dynamicArray<List<Customer>> z) {
    int x;
    x = z.getUsed();
    return x;
}

int main()
{
    int collisionCounter = 0;
    dynamicArray<List<Customer>> xyz(1000);

    string line;
    ifstream infile;
    infile.open("Customer.csv");
    while (!infile.eof()) {
        int counter;
        getline(infile, line);
        string bg[3];
        stringstream ss( line );
        while( ss.good() )
        {
            for (int i = 0; i < 3; i++) {
                getline( ss, bg[i], ',' );
            }
        }
        Customer x = Customer(bg[1], bg[0], bg[2]);
        collisionCounter = insertEntry(x, xyz, collisionCounter);
    }
    infile.close();

    cout << "there were " << collisionCounter << " collisions in this hashtable" << endl;
    double collisionRate = collisionCounter / 512.0;
    collisionRate = collisionRate * 100.0;
    cout << "the collision rate of this hashtable is: " << collisionRate << "%"<< endl;
    cout << " " << endl;
    int jyotiIndex = hashID("50518638-4031160");
    cout << "jyoti should be at index " << jyotiIndex << endl;
    cout << "now printing index: " << jyotiIndex << endl;
    List<Customer> y;
    y = xyz.get(jyotiIndex);
    y.print();
    cout << " " << endl;
    int sylvesterIndex = hashID("90543795-1635151");
    cout << "sylvester should be at index " << sylvesterIndex << endl;
    cout << "now printing index: " << sylvesterIndex << endl;
    y = xyz.get(sylvesterIndex);
    y.print();
    cout << " " << endl;
    int johnIndex = hashID("88538012-2517621");
    cout << "john should be at index " << johnIndex << endl;
    cout << "now printing index: " << johnIndex << endl;
    y = xyz.get(johnIndex);
    y.print();

    return 0;
}
