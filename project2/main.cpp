// the specification said that a union is needed but is not implemented as it is not
// very used now
#include <iostream>
#include <cstring>


const int Max_Contact = 100;
enum class Contact_type {  personal, work, family, other };
struct Contact {
    char c_name[50];
    char c_phone[20];
    char c_email[60];
    Contact_type c_type;

};

// Shows the initial menu of option for the user
void print_menu() {

    std::cout << "1. Add new contact (a)\n";
    std::cout << "2. Search contact (s)\n";
    std::cout << "3. List all contacts (l)\n";
    std::cout << "4. Delete contact (d)\n";
    std::cout << "5. Quit (q)\n";
};

Contact askNewContact() {
    Contact newContact;

    std::cout << "Name : \n";
    std::cin >>  newContact.c_name;
    std::cout << "Phone number : \n";
    std::cin >>  newContact.c_phone;
    std::cout << "Email : \n";
    std::cin >>  newContact.c_email;

    std::cout << "Type : (1)Familiy (2)Personal (3)Work (4)Other\n";
    char temp;
    std::cin >> temp;
    switch (temp) {
        case '1' : newContact.c_type = Contact_type::family; break;;
        case '2' : newContact.c_type = Contact_type::personal; break;;
        case '3' : newContact.c_type = Contact_type::work; break;;
        case '4' : newContact.c_type = Contact_type::other; break;;
        default:
            std::cout << "No valid type selected. \n Saved as other";
            newContact.c_type = Contact_type::other;
            break;;

    }

    return newContact;
};

void addNewContact(Contact * contacts, int& contact_counter, const Contact & contact) {
    contacts[contact_counter] = contact;
    ++contact_counter;
};


void printContact(const Contact & contact) {
    std::cout << contact.c_name << " : \t" <<  contact.c_phone << "\t" << contact.c_email << "\n";
};

void printAllContacts(const Contact * contacts, const int contact_counter) {

    if (contact_counter != 0) {
        // four iterations for each contact type
        for (int i = 0; i<4; ++i) {
            // types tittles
            if (i==0) std::cout << "\n----- FAMILY ----- \n";
            else if (i==1) std::cout << "\n----- PERSONAL ----- \n";
            else if (i==2) std::cout << "\n----- WORK ----- \n";
            else if (i==3) std::cout << "\n----- OTHER -----\n";

            //print eahc contact in the respective section
            for (int contact = 0; contact<contact_counter; ++contact) {
                if (i == 0 && contacts[contact].c_type == Contact_type::family)
                    printContact(contacts[contact]);
                if (i == 1 && contacts[contact].c_type == Contact_type::personal)
                    printContact(contacts[contact]);
                if (i == 2 && contacts[contact].c_type == Contact_type::work)
                    printContact(contacts[contact]);
                if (i == 3 && contacts[contact].c_type == Contact_type::other)
                    printContact(contacts[contact]);
            }

            if (i==3) std::cout << "-------------\n\n";
        }
    }
    else {
        std::cout << "No contacts saved yet.\n";
    }
};

void printSeachIn(const Contact * contacts,const int contact_counter, char * str) {

    bool found = false;

    std::cout << "Found contacts : \n";
    for (int i = 0; i<contact_counter; ++i ) {
        if (strstr(contacts[i].c_name, str) != nullptr) {
            printContact(contacts[i]);
            found |= true;
        }
    }
    if (!found) {
        std::cout<< "None contact found ";
    }
    std::cout <<"\n\n";


};


bool confirmDelete(const Contact & contact) {
    std::cout << "Confirm the deletion of  " << contact.c_name << " with phone number " << contact.c_phone << "(y/n)";
    char input;
    std::cin >> input;

    if (input == 'y')
        return true;
    return false;
};

void deleteContact(Contact * contacts, int& contact_counter, const char * str) {


    if (contact_counter != 0 ) {
        for (int i = 0; i < contact_counter; ++i) {
            if (strstr(contacts[i].c_name, str) != nullptr) {
                if (confirmDelete(contacts[i])) {
                    --contact_counter;
                    contacts[i] = contacts[contact_counter];
                    break;
                }
            }
        }
    }

};

int main() {

    // Variables
    Contact Contacts[Max_Contact];
    int contact_counter = 0;


    std::string selected_option = ".";
    std::cout << "Welcome to you contact book \n";
    print_menu();
    std::cin >> selected_option;

    while (selected_option != "q") {

        // Add new contact
        if (selected_option == "a") {
            Contact newContact = askNewContact();
            addNewContact(Contacts, contact_counter, newContact);
        }

        //Search
        else if (selected_option == "s") {
            std::cout << "Insert a name search : \n";
            char search_input[20];
            std:: cin >> search_input;
           printSeachIn(Contacts, contact_counter, search_input);
        }

        // List all contact
        else if (selected_option == "l") {
            printAllContacts(Contacts, contact_counter);
        }

        // Delect a contact
        else if (selected_option == "d") {
            std::cout << "Insert a contact name to delete : \n";
            char delete_input[20];
            std:: cin >> delete_input;
            deleteContact(Contacts, contact_counter, delete_input);
        }

        print_menu();
        std::cin >> selected_option;
    }

    return 0;
};