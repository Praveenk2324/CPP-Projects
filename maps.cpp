#include<iostream>
#include<map>
#include<string>
#include<print>

using namespace std;

int main(){
    map<string, string> myDictionary;

    myDictionary.insert(pair<string, string>("apple", "der Apfel"));
    myDictionary.insert(pair<string, string>("banana", "der Banane"));
    myDictionary.insert(pair<string, string>("orange", "die Orange, die Apfelsine"));
    myDictionary.insert(pair<string, string>("strawberry", "die Erdbeere"));

    for(auto pair:myDictionary){
        cout << pair.first << " - " << pair.second <<'\n';
    }
    int array[5];
   
    println("Hello");

} 