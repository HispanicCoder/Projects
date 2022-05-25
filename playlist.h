#include <iostream>
using namespace std;

struct Node {
    string uniqueID;
    string songName;
    string artistName;
    int songLength;
    Node* nextNodePtr = nullptr;
};

class PlayList{
public:
    PlayList(string PlayListName); //Default constructor

    PlayList(string PlayListName,string filename);
    //Parameterized constructor that reads data members of song from a
    // file and builds the PlayList

    ~PlayList(); //Deletes all nodes of the linked list

    bool InsertNodeLast(Node *myNewNode);
    //Inserts myNewNode at the end of the linked list
    bool InsertNodeFirst(Node *myNewNode);
     //Inserts myNewNode at the start of the linked list
    bool DeleteFirst(); //Deletes the first node of the linked list

    int Size() const { return size; }
    friend ostream& operator<< (ostream& out, const PlayList& LL);
    //Prints the linked list

    PlayList& operator=(const PlayList& other);
    //Overload the assignment operator such that the current PlayList
    // is reverse of the other PlayLis

    bool IsSongPresent(string uID);
    // Determines if the song with given uniqueId is present in the playlist
    // and returns accordingly.
    bool AddSong(string uID, string sName, string aName,
                  int sLength);
    // Adds song to the end of the list, if the song (based off the uniqueId)
    // is not already present
    bool RemoveSong(string uID);
    // Removes song with given uniqueId from the playlist,
    // if it exists, and returns true. Otherwise, returns false.
    bool PlayFirstSong();
    // "Plays" first song if list is not empty and then deletes it from the
    // PlayList. Otherwise, gives a message indicating list is empty.
    PlayList operator+(const PlayList& other);

    // Extra Credit Methods

    void Shuffle();
    void ChangeSongPosition(string uID, int position);

private:
    string playlistName;
    Node* first = nullptr;
    Node* last = nullptr;
    int size = 0;
};

