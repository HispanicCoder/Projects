#include "playlist.h"
#include <cstddef>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

PlayList::PlayList(string PlayListName){
    playlistName = PlayListName;

}

PlayList::PlayList(string PlayListName,string filename){
    playlistName = PlayListName;
    ifstream fin;
    stringstream ss;
    string uID, sName, aName, songL;
    int sLength;

    fin.open(filename);

    while(!fin.eof()){
        getline(fin,uID);

        Node *newNode = new Node;

        getline(fin,sName);
        getline(fin,aName);
        getline(fin,songL);


        ss.clear();
        ss.str(songL);

        ss >> sLength;


        newNode->artistName = aName;
        newNode->uniqueID = uID;
        newNode->songName = sName;
        newNode->songLength = sLength;

        InsertNodeLast(newNode);

    }

    fin.close();
}

bool PlayList::InsertNodeFirst(Node* myNewNode){
    if(myNewNode == NULL){
        return false;
    }
    if(size == 0){
       first = myNewNode;
       last = myNewNode;

       size++;
       return true;
    }
    myNewNode -> nextNodePtr = first;
    first = myNewNode;

    size++;
    return true;
}

bool PlayList::InsertNodeLast(Node* myNewNode){
    if(myNewNode == NULL){
        return false;
    }
    if(size == 0){
        first = myNewNode;
        last = myNewNode;

        size++;
        return true;
    }
    last -> nextNodePtr = myNewNode;
    last = myNewNode;

    size++;
    return true;

}

bool PlayList::DeleteFirst(){
    if(size == 0){
        return false;
    }
    Node* temp = first;

    if(size == 1){
        first = nullptr;
        last = nullptr;

        size--;

        delete temp;
        return true;
    }
    first = first -> nextNodePtr;
    temp -> nextNodePtr = nullptr;

    delete temp;
    size--;

    return true;

}

ostream& operator<< (ostream& out, const PlayList& LL){
    Node* temp = LL.first;
    int playlistTime = 0;

    for(int i = 0; i < LL.size; i++){
        playlistTime += temp->songLength;
        temp = temp ->nextNodePtr;
    }

    temp = LL.first;
    out << "***Playlist " << LL.playlistName << " contains " << LL.size
        << " songs with a total playtime of " << playlistTime
        << " seconds***" << endl;

    for(int i = 0; i < LL.size; i++){
    out << "\"" << (temp -> songName) << "\" by " << temp -> artistName
        << " is " << temp -> songLength << " seconds long (ID "
        << temp->uniqueID << ")." << endl;
        temp = temp -> nextNodePtr;
    }

    return out;
}

PlayList& PlayList::operator=(const PlayList& other){

    if(this == &other){
        return *this;
    }

    while(DeleteFirst()); // Clears current list

    Node* temp = other.first;

    while(temp != NULL){
        Node* ptr = new Node;

        ptr -> artistName = temp -> artistName;
        ptr -> songLength = temp -> songLength;
        ptr -> songName = temp -> songName;
        ptr -> uniqueID = temp -> uniqueID;

        InsertNodeFirst(ptr);

        temp = temp -> nextNodePtr;
    }

    return *this;

}

bool PlayList::IsSongPresent(string uID){
    Node* temp = first;
    if(size == 0){
        return false;
    }
    for(int i = 0; i < size; i++){
        if((temp->uniqueID) == uID){
            return true;
        }
        temp = temp ->nextNodePtr;
    }
    return false;
}

 bool PlayList::AddSong(string uID, string sName, string aName, int sLength){
    if(IsSongPresent(uID)){
        cout << "Song with unique ID " << uID << " already exists. Skipping ..."
             << endl;
        return false;
    }
    Node* ptr = new Node;

    ptr -> artistName = aName;
    ptr -> songName = sName;
    ptr -> songLength = sLength;
    ptr -> uniqueID = uID;

    InsertNodeLast(ptr);
    return true;
}

bool PlayList::PlayFirstSong(){
    if(size == 0){
        cout << "Sorry, play list is empty!" << endl;
        return false;
    }
    Node* temp = first;

    cout << "Playing \"" << temp->songName << "\" by " << temp ->artistName
         << endl;

    return DeleteFirst();
}

PlayList PlayList::operator+(const PlayList& other){
    string newListName = playlistName + other.playlistName;

    PlayList comList(newListName);

    Node* temp = (*this).first;
    Node* holder = other.first;
    for(int i = 0; i < (*this).size; i++){
        comList.AddSong(temp->uniqueID, temp->songName, temp->artistName,
                        temp->songLength);
        temp = temp -> nextNodePtr;
    }
    for(int i = 0; i < other.size; i++){
        comList.AddSong(holder->uniqueID, holder->songName, holder->artistName,
                        holder->songLength);
        holder = holder->nextNodePtr;

    }
    return comList;
}

bool PlayList::RemoveSong(string UniqueID){
    if(!IsSongPresent(UniqueID)){
        cout << "Song with unique ID " << UniqueID << " does not exist."
             << endl;
        return false;
    }
    if(UniqueID == (first -> uniqueID)){
        return DeleteFirst();
    }
    Node* temp = first;
    Node* holder = temp -> nextNodePtr;
    for(int i = 0; i<(size);i++){
        if((holder-> uniqueID) == UniqueID){
            (temp->nextNodePtr) = (holder->nextNodePtr);
            holder->nextNodePtr = nullptr;
            delete holder;
            size--;
            return true;
        }
        holder = holder -> nextNodePtr;
        temp = temp -> nextNodePtr;
    }
    if(holder->uniqueID == last->uniqueID){
        if(holder->uniqueID == UniqueID){
            last = temp;
            last->nextNodePtr = nullptr;
            delete holder;
            size--;
        }
    }
    return true;
}

void PlayList::Shuffle(){


}

void PlayList::ChangeSongPosition(string uID, int Position){
    int counter = 0;
    if(!IsSongPresent(uID)){
        return;
    }
    if((Position > size) || (Position < 0)){
        return;
    }
    if((first->uniqueID == uID) && (Position == 1)){
        return;
    }
    if((last->uniqueID == uID) && (Position == size)){
        return;
    }
    Node* temp = first;
    Node* holder = first;
    while(temp->uniqueID != uID){
        temp = temp->nextNodePtr;
        counter++;
    }
    for(int i = 0; i < (counter-1); i++){
        holder = holder -> nextNodePtr;
    }
    if(Position == 1){
        holder -> nextNodePtr = temp -> nextNodePtr;
        temp -> nextNodePtr = first;
        first = temp;
        return;
    }
    if(Position == size){
        holder -> nextNodePtr = temp -> nextNodePtr;
        last -> nextNodePtr = temp;
        last = temp;
        temp -> nextNodePtr = nullptr;
        return;
    }
/*
    holder -> nextNodePtr = temp -> nextNodePtr;
    holder = first;
    for(int i = 0; i < (Position - 1); i++){
        holder = holder->nextNodePtr;
    }
    temp -> nextNodePtr = holder -> nextNodePtr;
    holder -> nextNodePtr = temp;
    return;
*/

}

PlayList::~PlayList(){
    while(DeleteFirst());
}
