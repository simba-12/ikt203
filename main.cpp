#include <iostream>
#include <string>

using namespace  std;

// create class of node with id,title,artist
class Node {
public:
    int id;         // This is unique identify of the song
    string title;   // The title of the song
    string artist;  // The name of the artist
    Node* Next;     // Pointer to the next node in the list
    Node* Prev;     // pointer to the previous  nod in the list

//    Node(int id, const string& title,const string& artist)
//            : id(id), title(title),artist(artist){}

    // Constractor for the Node class with an ID, title, and artist
    Node(int id, const string& title,const string& artist){
        this->id = id;          // Putting the id  on the node's id
        this->title =title;     // Putting the title  on the node's title
        this->artist=artist;    // The artist is now the node's artist
        Next = nullptr;         // No next node yet
        Prev = nullptr;         // No previous node yet

    }
};
// class  of playlist
class playList{
private:
    Node* head;             // Here pointer to the first node
    Node* tail;             // This line pointer to the last node
public:
    playList(){
        head= nullptr;      // set the head to nullptr
        tail = nullptr;     // set the tail to nullptr
    }
    ~playList(){
        Node* current = head;                   // Begin with head node
        while (current!= nullptr){
            Node* nextNode = current->Next;     // Save the next node
            delete current;                     // Delete current node
            current = nextNode;                 // Move to the next node
        }
    }
    // Function of addSongs
    void addSongs(int id, const string&  title, const string& artist){
     Node* newNode = new Node(id,title,artist); // New node creating
     if (head!= nullptr){
         tail->Next = newNode;                  // Connect last node to the new node here
         newNode->Prev = tail;                  // Connect the new node back to the last node
         tail = newNode;                        // Change tail to point to the new node
     }else { head = tail = newNode;}            // Head and tail should be set to a new node if the list is empty
    }
   // Function of DisplayPlayList
    void displayPlayList() const{
     Node* current = head;                      // Begin with top node here
     while(current!= nullptr){
         cout <<" id: " <<current->id << ", title:  " << current->title << ", artist: " << current->artist << endl ;
         current = current->Next;               // Go to the nex node here
     }
    }
    // Function of reverseDisplayPlayList
    void reverseDisplayPlayList() const{
        Node* current = tail;                   // Start  with head node in this line
        while(current!= nullptr){
            cout <<" id: " <<current->id << ", title:  " << current->title << ", artist: " << current->artist << endl ;
            current = current->Prev;            // Go to the nex Node in here
        }
    }

    // This is function  of removePlaylis
    void removePlayList(int id ){
        Node* current = head;                   // Begin with the top node here
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


        delete current;  //delete the current node
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
    playList myPLaylist;    // play list object creat in here
    int id ;                // Here is variable for song ID
    string title;           // Title of song variable
    string artist;          // Variable of the arist name

   int choice;
  do {
      // Display menu options
      cout << "=================================================\n";
      cout << "[1] -------- Add new a song ---------------------]\n";
      cout << "[2] -------- Remove a song by id ----------------]\n";
      cout << "[3] -------- Display Playlist -------------------]\n";
      cout << "[4] -------- Display in Reverse order -----------]\n";
      cout << "[5] -------- Search a song by ID ----------------]\n";
      cout << "[6] -------- Exit Program -----------------------]\n";
      cout << "==================================================\n";

      cout << " Input your choice (numeric only): " << endl ;
      cin >> choice ;

      switch (choice) {
          case 1:
              //Case of add new song
              cout << "Write an Id: ";
              cin >> id ;
              cout << "Write song name: ";
              cin >> title ;
              cout << "Write artist name: ";
              cin >> artist ;
              myPLaylist.addSongs(id,title,artist);
              break;


          case 2:
              // Case two remove song using their ID
              cout << "write song ID: " << endl;
              cin >> id;
              myPLaylist.removePlayList(id);
              break;

          case 3:
              // Display playlist in here
              cout << "Display my playlist : \n"<< endl;
              myPLaylist.displayPlayList();
              break;

          case 4:
              // In this case Display playlist in reverse order
              cout << "Display in reverse order: " << endl;
              myPLaylist.reverseDisplayPlayList();
              break;

          case 5:
              // In case user can search song using Id
              cout << "Search for a song: " << endl;
              cin >> id ;
              myPLaylist.searchSongByID(id);
              break;
          case 6:
              // Last case is exit the program
              cout << "Program exited" << endl;
              break;
          default:
              cout << "Invalid choice , please try again.\n";
      }
  }while (choice != 6);
    return 0;
}
