#include <iostream>
#include <string>
#include <limits>

using namespace  std;

// making class of node with id,title,artist
class Node {
public:
    int id;
    string title;
    string artist;
    Node* Next;
    Node* Prev;

//    Node(int id, const string& title,const string& artist)
//            : id(id), title(title),artist(artist){}
    Node(int id, const string& title,const string& artist){
        this->id = id;
        this->title =title;
        this->artist=artist;
        Next = nullptr;
        Prev = nullptr;
    }
};

class playList{
private:
    Node* head;
    Node* tail;
public:
    playList(){
        head= nullptr;
        tail = nullptr;
    }
    ~playList(){
        Node* current = head;
        while (current!= nullptr){
            Node* nextNode = current->Next;
            delete current;
            current = nextNode;
        }
    }

    void addSongs(int id, const string&  title, const string& artist){
     Node* newNode = new Node(id,title,artist);
     if (head!= nullptr){
         tail->Next = newNode;
         newNode->Prev = tail;
         tail = newNode;
     }else { head = tail = newNode;}
    }

    void displayPlayList() const{
     Node* current = head;
     while(current!= nullptr){
         cout <<" id: " <<current->id << ", title:  " << current->title << ", artist: " << current->artist << endl ;
         current = current->Next;
     }
    }

    void reverseDisplayPlayList() const{
        Node* current = tail;
        while(current!= nullptr){
            cout <<" id: " <<current->id << ", title:  " << current->title << ", artist: " << current->artist << endl ;
            current = current->Prev;
        }
    }

    void removePlayList(int id ){
        Node* current = head;
        // Traverse the list to find the node with the given id
        while (current != nullptr && current->id != id) {
            current = current->Next;
        }

        if (current == nullptr) {
            cout << "Song with ID " << id << " not found in the playlist." << endl;
            return;
        }

        // Update pointers if current is not the head
        if (current->Prev != nullptr) {
            current->Prev->Next = current->Next;
        } else {
            // If current is the head, update the head pointer
            head = current->Next;
        }

        // Update pointers if current is not the tail
        if (current->Next != nullptr) {
            current->Next->Prev = current->Prev;
        } else {
            // If current is the tail, update the tail pointer
            tail = current->Prev;
        }

        //delete the current node
        delete current;
        cout << "Song with ID " << id << " has been deleted from the playlist." << endl;
    }
    // Function to search for a song by ID
    void searchSongByID(int id) const {
        Node* temp = head;
        while (temp != nullptr) {
            if (temp->id == id) {
                cout << "Song found: ID: " << temp->id << ", Title: " << temp->title << ", Artist: " << temp->artist << endl;
                return;
            }
            temp = temp->Next;
        }
        cout << "Song with ID " << id << " not found." << endl;
    }
};



int main() {
    playList myPLaylist;
    int id ;
    string title;
    string artist;

   int choice;
  do {
      cout << "============================================\n";
      cout << "[1] -------- Add new a song ---------------]\n";
      cout << "[2] -------- Remove a song by id ----------]\n";
      cout << "[3] -------- Display Playlist -------------]\n";
      cout << "[4] -------- Display in Reverse order -----]\n";
      cout << "[5] -------- Search a song ----------------]\n";
      cout << "[6] -------- Exit Program -----------------]\n";
      cout << "============================================\n";

      cout << " Input your choice (numeric only): " << endl ;
      cin >> choice ;

      switch (choice) {
          case 1:
              cout << "Write an Id: ";
              cin >> id ;
              cout << "Write song name: ";
              cin >> title ;
              cout << "Write artist name: ";
              cin >> artist ;
              myPLaylist.addSongs(id,title,artist);
              break;


          case 2:
              cout << "write song ID: " << endl;
              cin >> id;
              myPLaylist.removePlayList(id);
              break;
          case 3:
              cout << "Display my playlist : \n"<< endl;
              myPLaylist.displayPlayList();
              break;
          case 4:
              cout << "Display in reverse order: " << endl;
              myPLaylist.reverseDisplayPlayList();
              break;
          case 5:
              cout << "Search for a song: " << endl;
              cin >> id ;
              myPLaylist.searchSongByID(id);
              break;
          case 6:
              cout << "Program exited" << endl;
              break;
          default:
              cout << "Invalid choice , please try again.\n";
      }
  }while (choice != 6);
    return 0;
}
