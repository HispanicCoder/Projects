#include <iostream>
#include <sstream>
#include "playlist.h"
using namespace std;
/*
int main( ) {
    PlayList a("P1", "file1.txt");
    cout << a;

    cout << endl << "Reversing the play list" << endl;
    PlayList b("P2");
    b = a;
    cout << b;

    cout << endl << "Removing Song JJ456 from Playlist 1..." << endl;
    a.RemoveSong("JJ456");
    cout << endl << a;

    cout << endl << "Removing Song SD123 from Playlist 1..." << endl;
    a.RemoveSong("SD123");
    cout << endl << a;

    cout << endl << "Playing first Song from Playlist 1..." << endl;
    a.PlayFirstSong();
    cout << endl << a;

    cout << endl << "Playing first Song from Playlist 1..." << endl;
    a.PlayFirstSong();

    cout << endl << "Removing Song JJ234 from Playlist 1..." << endl;
    a.RemoveSong("JJ234");

    cout << endl << "Adding Song J345 to Playlist 1..." << endl;
    a.AddSong("J345", "Canned Heat", "Jamiroquai", 330);
    cout << endl << a;

    cout << endl << "Adding Song J345 to Playlist 1..." << endl;
    a.AddSong("J345", "Canned Heat", "Jamiroquai", 330);

    cout << endl << "Adding Song SD123 to Playlist 1..." << endl;
    a.AddSong("SD123", "Peg", "Steely Dan", 237);
    cout << endl << a;

    cout << endl << "Adding Song W219 to Playlist 2..." << endl;
    b.AddSong("W219", "Love is all around", "Wet Wet Wet", 339);
    cout << endl << b;

    cout << endl << "Removing Song JJ234 from Playlist 2..." << endl;
    b.RemoveSong("JJ234");
    cout << endl << b;

    cout << endl << "Adding the two play lists (playlist P1 + playlist P2)" << endl;
    PlayList c = a + b;
    cout << endl << c;

    cout << endl << "Playing first Song from the combined Playlist P1P2..." << endl;
    c.PlayFirstSong();
    cout << endl << c;

    cout << endl << "Adding the two play lists (playlist P1P2 + playlist P2)" << endl;
    PlayList d = c + b;
    cout << endl << d;
}
*/
int main( ) {


    PlayList a("P1", "file2.txt");
    cout << a;

    int choice;
    cin >> choice;

    if (choice == 0)
    {
       a.Shuffle();
       cout << endl << a << endl;

       a.PlayFirstSong();

       a.Shuffle();
       cout << endl << a;
    }
    else
    {
       a.ChangeSongPosition("W219",2);
       a.ChangeSongPosition("SD567",5);
       a.ChangeSongPosition("JJ234",1);
       a.ChangeSongPosition("SD123",6);
       cout << endl << a << endl;

       a.PlayFirstSong();
       cout << endl << a;

    }

   return 0;
}



