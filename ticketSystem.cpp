#include<iostream>
#include<string>
#include<queue>
#include<stack>
using namespace std;
class TicketSystem{
    int ticketID;
    public:
    int getId(){return ticketID;}
    TicketSystem(int id){
        ticketID = id;
    }
    void displayTicket(){
        cout << "Ticket ID: " << ticketID << ".\n";
    }
};
class TicketSystemControl{
    queue <TicketSystem> ticketQueue;
    public:
    
    bool isUnique(int id){
        queue<TicketSystem> temp = ticketQueue;
        while( !temp.empty() ){
            if(temp.front().getId() == id){// temp.front() returns an object 
                return false;
            }
            temp.pop();
        }
        return true;
    }
    void addTicket(int id){
        if (id < 1000 || id > 9999) {
            cout << "Invalid ID. Must be exactly 4 digits.\n";
            return;
        } 
        //check for uniqueness
        if( !isUnique(id) ){
            cout<<"ID is not unique, returning to menu.";
            return;
        }
        ticketQueue.push( TicketSystem(id) );
        cout << "Ticket " << id << " added.\n";

    }
    void resolveTicket(){
        if (ticketQueue.empty()) {
            cout << "No tickets to resolve.\n";
            return;
        }
        cout << "Resolving Ticket ID: " << ticketQueue.front().getId() << "\n";
        ticketQueue.pop();
    }
    void nextTicket() {
        if (ticketQueue.empty()) {
            cout << "No tickets in queue.\n";
            return;
        } 
        
        cout << "Next ticket to resolve: " << ticketQueue.front().getId() << "\n";
        
    }
    void displayTickets(){
        if (ticketQueue.empty()) {
            cout << "No tickets in queue.\n";
            return;
        } 
        queue<TicketSystem> temp = ticketQueue;
        cout<<"Pending tickets: "<<endl;
        while(!temp.empty()){
            temp.front().displayTicket();//front returns an object
            temp.pop();
        }
    }
};
int main() {
    TicketSystemControl control;
    int choice;
    int id;

    while (true) {
        cout << "\n--- Ticket System Menu ---\n";
        cout << "1. Add New Ticket\n";
        cout << "2. Resolve Ticket\n";
        cout << "3. Show Next Ticket\n";
        cout << "4. Display All Tickets\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1:
                cout << "Enter 4-digit Ticket ID: ";
                cin>>id;
                control.addTicket(id);
                break;
            case 2:
                control.resolveTicket();
                break;
            case 3:
                control.nextTicket();
                break;
            case 4:
                control.displayTickets();
                break;
            case 5:
                cout << "Exiting system.\n";
                return 0;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
}