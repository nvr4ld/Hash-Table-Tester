#include <bits/stdc++.h>
using namespace std;
#define SIZE 100000
ofstream MyFile;
class HashMidSqr{
public:
    int hash_size;
    int keys[SIZE];
    HashMidSqr(){
        for(int i = 0; i < SIZE; i++){
            keys[i] = -2;
        }
        hash_size = 0;
    }
    void Insert(int x){
        bool flag = true;
        int index = (x*x) % SIZE;
        if(hash_size<SIZE) {
            while (keys[index] != -2) {
                if (keys[index] == x) {
                    flag = false;
                    break;
                }
                index = (index+1) % SIZE;
            }
            if (flag) {
                keys[index] = x;
                hash_size++;
            }
        }
    }
    void Delete(int x){
        bool flag = true;
        int index = (x*x) % SIZE;
        int starting = index;
        while(keys[index] != x) {
            if(keys[index] == -2){
                flag = false;
                break;
            }
            index = (index+1)%SIZE;
            if(index == starting){
                flag = false;
                break;
            }
        }
        if(flag){
            keys[index] = -1;
            hash_size--;
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " was deleted successfully" << endl;
//            printf("%d was deleted successfully\n", x);
            MyFile.close();
        }
        else{
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " does not exist" << endl;
//            printf("%d does not exist\n", x);
            MyFile.close();
        }
    }
    void Search(int x){
        bool flag = true;
        int index = (x*x) % SIZE;
        int starting = index;
        while(true) {
            if(keys[index] == -2){
                flag = false;
                break;
            }
            else if(keys[index] == x){
                flag = true;
                break;
            }
            index = (index+1)%SIZE;
            if(index == starting){
                flag = false;
                break;
            }
        }
        if(flag){
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " was found" << endl;
//            printf("%d was found\n", x);
            MyFile.close();
        }
        else{
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " does not exist" << endl;
//            printf("%d does not exist\n", x);
            MyFile.close();
        }
    }
};

class HashDiv{
public:
    int hash_size;
    int keys[SIZE];
    HashDiv(){
        for(int i = 0; i < SIZE; i++){
            keys[i] = -2;
        }
        hash_size = 0;
    }
    void Insert(int x) {
        int temp = x;
        bool flag = true;
        if (hash_size < SIZE){
            while (keys[temp % SIZE] != -2) {
                if (keys[temp % SIZE] == x) {
                    flag = false;
                    break;
                }
                temp++;
            }
            if (flag) {
                keys[temp % SIZE] = x;
                hash_size++;
            }
        }

    }
    void Delete(int x){
        int temp = x;
        bool flag = true;
        while(keys[temp%SIZE] != x) {
            if(keys[temp%SIZE] == -2){
                flag = false;
                break;
            }
            temp++;
            if(temp%SIZE == x%SIZE){
                flag = false;
                break;
            }
        }
        if(flag){
            keys[temp%SIZE] = -1;
            hash_size--;
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " was deleted successfully" << endl;
//            printf("%d was deleted successfully\n", x);
            MyFile.close();
        }
        else{
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " does not exist" << endl;
//            printf("%d does not exist\n", x);
            MyFile.close();
        }
    }
    void Search(int x){
        int temp = x;
        bool flag = true;
        while(true) {
            if(keys[temp%SIZE] == -2){
                flag = false;
                break;
            }
            else if(keys[temp%SIZE] == x){
                flag = true;
                break;
            }
            temp++;
            if(temp%SIZE == x%SIZE){
                flag = false;
                break;
            }
        }
        if(flag){
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " was found" << endl;
//            printf("%d was found\n", x);
            MyFile.close();
        }
        else{
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " does not exist" << endl;
//            printf("%d does not exist\n", x);
            MyFile.close();
        }
    }
};

class HashMult{
public:
    int hash_size;
    int keys[SIZE];
    double A = 0.617845;
    HashMult(){
        for(int i = 0; i < SIZE; i++){
            keys[i] = -2;
        }
        hash_size = 0;
    }
    void Insert(int x) {
        bool flag = true;
        int index = floor(SIZE*(fmod(x*A, 1)));
        if (hash_size < SIZE){
            while (keys[index] != -2) {
                if (keys[index] == x) {
                    flag = false;
                    break;
                }
                index = (index+1) % SIZE;
            }
            if (flag) {
                keys[index] = x;
                hash_size++;
            }
        }

    }
    void Delete(int x){
        bool flag = true;
        int index = floor(SIZE*(fmod(x*A, 1)));
        int starting = index;
        while(keys[index] != x) {
            if(keys[index] == -2){
                flag = false;
                break;
            }
            index = (index+1) % SIZE;
            if(index == starting){
                flag = false;
                break;
            }
        }
        if(flag){
            keys[index] = -1;
            hash_size--;
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " was deleted successfully" << endl;
//            printf("%d was deleted successfully\n", x);
            MyFile.close();
        }
        else{
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " does not exist" << endl;
//            printf("%d does not exist\n", x);
            MyFile.close();
        }
    }
    void Search(int x){
        int index = floor(SIZE*(fmod(x*A, 1)));
        int starting = index;
        bool flag = true;
        while(true) {
            if(keys[index] == -2){
                flag = false;
                break;
            }
            else if(keys[index] == x){
                flag = true;
                break;
            }
            index = (index + 1) % SIZE;
            if(index == starting){
                flag = false;
                break;
            }
        }
        if(flag){
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " was found" << endl;
//            printf("%d was found\n", x);
            MyFile.close();
        }
        else{
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " does not exist" << endl;
//            printf("%d does not exist\n", x);
            MyFile.close();
        }
    }
};

class Node{
public:
    int value;
    Node* left;
    Node* right;
    Node(int x, Node* par){
        value = x;
        right = nullptr;
        left = par;
    }
};

class LinkedList{
public:
    Node* root;
    LinkedList(){
        root = nullptr;
    }
};

class HashLinked{
public:
    LinkedList arr[100];
    HashLinked(){
        for(int i = 0; i < 100; i++){
            arr[i] = LinkedList();
        }
    }
    void Insert(int x){
        int w = x % 100;
        bool flag = true;
        Node* temp = arr[w].root;

        if(temp == nullptr){
            arr[w].root = new Node(x, nullptr);
        }
        else{
            if(temp->value == x)
                flag = false;
            else{
                while (temp->right != nullptr) {
                    if (temp->right->value == x){
                        flag = false;
                        break;
                    }
                    temp = temp->right;
                }
            }
            if(flag){
                Node* newNode = new Node(x, temp);
                temp->right = newNode;
            }
        }
    }

    void Delete(int x){
        int w = x%100;
        bool flag = false;
        Node* temp = arr[w].root;
        while(temp!=nullptr){
            if(temp->value == x){
                if(temp == arr[w].root){
                    arr[w].root = temp->right;
                }
                else{
                    temp->left->right = temp->right;
                }
                if(temp->right != nullptr) {
                    temp->right->left = temp->left;
                }
                MyFile.open("test.txt", ofstream::app);
                MyFile << x << " was deleted successfully" << endl;
//            printf("%d was deleted successfully\n", x);
                MyFile.close();
                flag = true;
                break;
            }
            temp = temp->right;
        }
        if(!flag){
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " does not exist" << endl;
//            printf("%d does not exist\n", x);
            MyFile.close();
        }
    }

    void Search(int x){
        int w = x%100;
        bool flag = false;
        Node* temp = arr[w].root;
        while(temp!=nullptr){
            if(temp->value == x){
                flag = true;
                MyFile.open("test.txt", ofstream::app);
                MyFile << x << " was found" << endl;
//            printf("%d was found\n", x);
                MyFile.close();
                break;
            }
            temp = temp->right;
        }
        if(!flag){
            MyFile.open("test.txt", ofstream::app);
            MyFile << x << " does not exist" << endl;
//            printf("%d does not exist\n", x);
            MyFile.close();
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned int seed = 117454;
    unsigned int numOperations = 10000;
    unsigned int keyUpperBound = 10000;

    mt19937 rng(seed);
    uniform_int_distribution< unsigned int> valGen(0, keyUpperBound);
    discrete_distribution<unsigned int> optGen({40, 40, 20}); // generator for no. of {search, insert, delete}, 40% search, 40% insert, 20% delete.

    HashDiv hashTable;
    MyFile.open("test.txt", ofstream::trunc);
    MyFile.close();
    auto start = chrono::steady_clock::now();

    for (unsigned int i = 0; i < numOperations; i++)
    {
        unsigned int opt = optGen(rng);
        unsigned int val = valGen(rng);

        if (opt == 0) // search
        {
            hashTable.Search(val);
        }
        else if (opt == 1) // insert
        {
            hashTable.Insert(val);
        }
        else // delete
        {
            hashTable.Delete(val);
        }
    }
    auto end = chrono::steady_clock::now();
    cout << endl << "Elapsed time in microseconds: " << chrono::duration_cast<chrono::microseconds>(end - start).count() << " microseconds" << endl;
}