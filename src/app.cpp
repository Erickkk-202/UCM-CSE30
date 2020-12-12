
 #include <iostream>
#include <fstream>
#include <string>
#include <Array.h>
#include <LinkedList.h>
#include <TimeSupport.h>
#include <RandomSupport.h>
#include <HashTable.h>
#include <BST.h>
#include <algorithm>
#include <cmath>


using namespace std;

 
//gets words and reverses them and returns them reversed
 string reverse( string word){
    reverse(word.begin(), word.end());
    return word;
} 
int main(int argc, char* argv[]){

//takes in file by an input
string fileName;
cout<<"Please Enter File Name: such as (words.txt) "<<endl;
cin>> fileName;

string nameOfFile = fileName;

    fstream file;

  //opens file name
    file.open(nameOfFile,ios::in);
    HashTable test;
    if (file.is_open()){
        string tp;
        while(getline(file, tp)){
            //inserts the words to the hashtable
           test.insertString(tp);  
        }
        //closes file
        file.close(); 
    }
    else{
        //if no file found print (could not read file)
        cout << "Could not read file..." << endl;
    }  

//palindrome
long pal=0;
//reversable words
long rev=0;

//opens file 
file.open(nameOfFile,ios::in);

timestamp start = current_time();
if (file.is_open()){
    string tp; 
    //goes each line
    while(getline(file,tp)){
        //reverses a tp(word) and sets it to newWord
        string newWord= reverse(tp);
//if reverse word equals the word add 1 to the palindrome
if(newWord==tp){
    pal++;
}
//searches for words that when spelled backwards makes another word
if (test.containsString(newWord)){
    rev++;
    }
}
//closes file
file.close();
}
else{
    cout << "Could not read file..." << endl;
}

//counts how many reversable/ palidrums words there are and prints them with a time stamp.
cout<<"Total count: "<< (pal+rev)<<endl;
timestamp end = current_time();
long duration = time_diff(start,end);
cout<<"duration for search: "<< duration<< "ms."<< endl;

 //counts how many palindromes there are in the file
cout<<"Total count for palindromes: "<< (pal)<<endl;
//counts how many words that can be spelled backwards make a new word.
cout<<"Total count for reversable words: "<< (rev)<<endl;
     
 return 0;
}

 















