#ifndef HashTable_h
#define HashTable_h
#include <LinkedList.h>
#include <iostream>
#include <ostream>
#include <string>

using namespace std;
//This reverse function reverses the word that is taken in
/*  string reverse( string word){
    reverse(word.begin(), word.end());
    return word;
}  */
struct HashTable{
 //data is the linkedlist pointer 
    LinkedList* data;
//initialise size 
    long size;
    
    // A default constructor
    HashTable(){
        // Start off by allocating memory for Hashtable 
        size= 252047376; //(126^4), ASCII has 126 charaters 
        data = new LinkedList[size]; //linkedlist pointer, named data, is being assigned the size 126^4
    }
    //this function takes in a string (word)
    long hashFunction(string word){
        //keyvalue initialized to 1
        long keyValue= 1; 
//checks to see if the words is at least 4 characters long. if not it will fill it up with spaces
        for (long i=0; i<word.length()-1 && i < 4; i++){
            keyValue*=long(word.at(i));
//keyValue = keyValue * word at i
        }   
        // cheecks if the word has 4 characters if not it will add spaces till it reaches four
        if (word.length() < 4){
            keyValue*=((4-word.length())*(long(" ")));
        }

keyValue = keyValue % size;
return keyValue;
    }

    //inserts word into hashTable
    void insertString(string word){
        long key = hashFunction(word);
        data[key].append(word);
    }


// searches for reversable words (live and evil)
    bool containsString(string word) {
        long tempKey= hashFunction(word);
        if (data[tempKey].head == NULL){
            return false;
        }else{
        if (data[tempKey].search(word)){
            return true;
        }

        }
        return false;
    }
};


#endif

