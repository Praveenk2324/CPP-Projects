#include<iostream>
#include<string>
using namespace std;

struct Song {
    string title;
    string artist;
    Song* next;
    Song* prev;

    Song(string t, string a){
        title = t;
        artist = a;
        next = nullptr;
        prev = nullptr;
    }
};

class Playlist{
private:
    Song* head;
    Song* tail;
    Song* current;

public:
    Playlist(){
        head = nullptr;
        tail = nullptr;
        current = nullptr;
    }

    void addSong(string title, string artist){
        Song* newSong = new Song(title, artist);

        if (head == nullptr){
            head =newSong;
            tail = newSong;
            current = newSong;
        }
        else {
            tail->next = newSong;
            newSong->prev = tail;
            tail = newSong;
        }
        cout << "Added: " << title << " by " << artist << endl;
    }

    void playNext(){
        if(current == nullptr){
            cout << "Playlist is empty" << endl;
            return;
        }
        if (current->next == nullptr){
            cout << "End of playlist" << endl;
        } else {
            current = current->next;
            cout <<"Now playing: " << current->title << endl;
        }
    }

    void playPrevious() {
        if (current==nullptr){
            cout << "Playlist is empty" << endl;
            return;
        }
        if (current->prev == nullptr){
            cout << "This is the first song" << endl;
        }else {
            current = current->prev;
            cout << "Now playing: " << current->title << endl;
        }
    }

    void deleteCurrentSong(){
        if(current==nullptr) return ;

        Song* toDelete = current;
        cout << "Deleting: " << toDelete->title << endl;

        if (head == tail) {
            head = nullptr;
            tail = nullptr;
            current = nullptr;
        }

        else if(toDelete == head){
            head = head->next;
            head->prev = nullptr;
            current = head;
        }

        else if (toDelete == tail){
            tail = tail->prev;
            tail->next = nullptr;
            current = tail;
        }

        else {
            toDelete->prev->next = toDelete->next;
            toDelete->next->prev = toDelete->prev;
            current = toDelete->next;
        }

        delete toDelete;
    }

    void showStatus() {
        if (current) {
            cout << "\n[ CURRENTLY PLAYING: " << current->title << " - " << current->artist << " ]" << endl;
        } else {
            cout << "\n[ Player Stopped ]" << endl;
        }
    }

    void showAll() {
        cout << "\n--- Full Playlist ---" << endl;
        Song* temp = head;
        int index = 1;
        while (temp != nullptr) {
            cout << index << ". " << temp->title << " (" << temp->artist << ")";
            if (temp == current) cout << " <--- PLAYING";
            cout << endl;
            temp = temp->next;
            index++;
        }
        cout << "---------------------" << endl;
    }
};

int main() {
    Playlist mySpotifLite;
    int choice;
    string t, a;

    while (true) {
        mySpotifLite.showStatus();
        cout << "1. Add Song\n2. Next\n3. Previous\n4. Delete Current\n5. Show List\n6. Exit\nChoice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter Title: ";
                cin.ignore(); // Clear buffer
                getline(cin, t);
                cout << "Enter Artist: ";
                getline(cin, a);
                mySpotifLite.addSong(t, a);
                break;
            case 2: mySpotifLite.playNext(); break;
            case 3: mySpotifLite.playPrevious(); break;
            case 4: mySpotifLite.deleteCurrentSong(); break;
            case 5: mySpotifLite.showAll(); break;
            case 6: return 0;
        }
    }
}
