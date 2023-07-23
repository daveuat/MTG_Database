#include <iostream>
#include <string>

// Add the using namespace directive for the std namespace
using namespace std;

// Define the structure of the Node for the linked list
struct Node {
    string website;
    Node* next;
    Node* prev;
};

// WebList class to manage the linked list and all related operations
class WebList {
private:
    Node* head;
    Node* tail;
    Node* current;

    // Function to find a website in the linked list and return the Node pointer if found
public:
    WebList();
    void displayList(); // displays the linked list
    void goForward(); // go forward in the list and display the webpage
    void goBackward(); // go backward in the list and display the webpage
    void addWebsite(string website); // add a new website to the list
    void deleteWebsite(string website); // delete a website from the list
    Node* findWebsite(string website);  // my function to find a website
    void menu();
};

// Implement the WebList member functions
WebList::WebList() {
    head = nullptr;
    tail = nullptr;
    current = nullptr;
}

// Function to display the linked list
void WebList::displayList() {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->website << " -> ";
        temp = temp->next;
    }
    cout << "End of list. " << endl;
}

// Function to move the current position forward in the linked list and display the webpage
void WebList::goForward() {
    if (current && current->next) {
        current = current->next;
        cout << "Forward: " << current->website << endl;
    }
    else {
        cout << "End of the list reached." << endl;
    }
}

// Function to move the current position backward in the linked list and display the webpage
void WebList::goBackward() {
    if (current && current->prev) {
        current = current->prev;
        cout << "Backward: " << current->website << endl;
    }
    else {
        cout << "Beginning of the list reached." << endl;
    }
}

// Function to add a new website to the linked list
void WebList::addWebsite(string website) {
    Node* newNode = new Node;
    newNode->website = website;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (!head) {
        head = newNode;
        tail = newNode;
        current = newNode;
    }
    else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to delete a website from the linked list
void WebList::deleteWebsite(string website) {
    Node* nodeToDelete = findWebsite(website);
    if (!nodeToDelete) {
        cout << "Website not found in the list." << endl;
        return;
    }

    if (nodeToDelete == head) {
        head = head->next;
    }
    else if (nodeToDelete == tail) {
        tail = tail->prev;
        tail->next = nullptr;
    }
    else {
        nodeToDelete->prev->next = nodeToDelete->next;
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    delete nodeToDelete;
}

// Function to find a website in the linked list and return the Node pointer if found to the screen
Node* WebList::findWebsite(string website) {
    Node* temp = head;
    while (temp != nullptr) {
        if (temp->website == website) {
            return temp;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Function to display the interactive menu for the user
void WebList::menu() {
    int choice;
    string website;
    Node* result;

    while (true) {
        cout << "----- Menu Options -----" << endl;
        cout << "1. Display the site list" << endl;
        cout << "2. Go forward and then display the webpage" << endl;
        cout << "3. Go backward and then display the webpage" << endl;
        cout << "4. Add another site to the list" << endl;
        cout << "5. Delete a site from the list" << endl;
        cout << "6. Find an item in the list" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            displayList();
            break;
        case 2:
            goForward();
            break;
        case 3:
            goBackward();
            break;
        case 4:
            cout << "Please enter the website you want to add: "; // prompt the user to enter the website
            cin.ignore(); // ignores the newline character from previous input the user entered
            getline(cin, website); // use getline() to read the entire line with all spaces
            addWebsite(website); // call the addWebsite() function to add the website to the linked list
            break; // break out of the switch statement
        case 5:
            cout << "Please enter the website youw want to delete: ";
            cin.ignore();
            getline(cin, website);
            deleteWebsite(website);
            break; // break out of the switch statement
        case 6:
            cout << "Enter the website to find: ";
            cin.ignore();
            getline(cin, website);
            result = findWebsite(website);
            if (result) {
                cout << "Website found in the list. " << endl;
            }
            else {
                cout << "Website not found in the list. " << endl;
            }
            break; // break out of the switch statement
        case 7:
            cout << "Now Exiting... " << endl;
            return;
        default:
            cout << "Invalid choice. Please try again. " << endl;
        }

        cout << endl;
    }
}

int main() {
    // Logo for the application - https://patorjk.com/software/taag/#p=display&f=Graffiti&t=
    cout << R"(
                    _        _____  ___   ___             
  /\/\   __ _  __ _(_) ___  /__   \/ __\ / _ \            
 /    \ / _` |/ _` | |/ __|   / /\/ /   / /_\/            
/ /\/\ \ (_| | (_| | | (__   / / / /___/ /_\\             
\/    \/\__,_|\__, |_|\___|  \/  \____/\____/             
              |___/                                       
 __ _ _            ___      _        _                    
/ _(_) |_ ___     /   \__ _| |_ __ _| |__   __ _ ___  ___ 
\ \| | __/ _ \   / /\ / _` | __/ _` | '_ \ / _` / __|/ _ \
_\ \ | ||  __/  / /_// (_| | || (_| | |_) | (_| \__ \  __/
\__/_|\__\___| /___,' \__,_|\__\__,_|_.__/ \__,_|___/\___|
)" << '\n';

    WebList webList;
    string website;

    // 20 Websites for MTG in the linked list
    webList.addWebsite("https://scryfall.com");
    webList.addWebsite("https://www.moxfield.com");
    webList.addWebsite("https://mtggoldfish.com");
    webList.addWebsite("https://cardkingdom.com");
    webList.addWebsite("https://gatherer.wizards.com");
    webList.addWebsite("https://deckbox.org");
    webList.addWebsite("https://echomtg.com");
    webList.addWebsite("https://mtgassist.com");
    webList.addWebsite("https://aetherhub.com");
    webList.addWebsite("https://www.mtgdatabase.com/en/search/");
    webList.addWebsite("https://mtg.fandom.com/wiki/Main_Page");
    webList.addWebsite("https://www.delverlab.com/");
    webList.addWebsite("https://cardmavin.com/category/mtg");
    webList.addWebsite("https://draftsim.com/");
    webList.addWebsite("https://tappedout.net/");
    webList.addWebsite("https://infinite.tcgplayer.com/magic-the-gathering");
    webList.addWebsite("https://www.magicarenacardlist.com/");
    webList.addWebsite("https://mtg-search.com/");
    webList.addWebsite("https://www.mtgnexus.com/");
    webList.addWebsite("http://whisper.wisdom-guild.n");

    webList.menu(); // calls the menu function and displays the interactive menu for the user

    return 0; // return 0 to indicate successful termination
}