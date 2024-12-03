#include <iostream>
#include "Customer.h"

void signUpCustomer(){

    int id = 1; //sample id
    string email; // sample
    string password; //sample


    cout << "=== Sign Up ===" << endl;
    cout << "Enter Email: ";
    cin >> email;

    cout << "Enter Password: ";
    cin >> password;

    //constructor
    Customer* customer = new Customer(id, " ", password, email);

    cout<<"Sign-up Succefully! Profile Created."<<endl;

    //save customer to file
    customer->saveToFile("customer.txt"); 

    // Clean up dynamically allocated memory
    delete customer;

}

void showProfile(const customer& customer){
    cout<<"My Profile";
  
    if(customer.getName() == " "){
        cout<<"Name: [Not Set]"<<endl;        
    }else{
        cout<<"Name: "<<customer.getName()<<endl;
    }

    if(customer.getEmail() == " "){
        cout<<"Email: [Not Set]"<<endl;        
    }else{
        cout<<"Email: "<<customer.getEmail()<<endl;
    }

    if(customer.getPhone() == " "){
        cout<<"Phone: [Not Set]"<<endl;        
    }else{
        cout<<"Phone: "<<customer.getPhone()<<endl;
    }

    if(customer.getPoints() == " "){
        cout<<"Point: 0"<<endl;        
    }else{
        cout<<"Phone: "<<customer.getPhone()<<endl;
    }

    cout << "Last Login: " << (customer.getLastLogin() == 0 ? "[Never Logged In]" : ctime(&customer.getLastLogin()));
    //last_login timestamp is 0, it displays [Never Logged In]
    cout << "Ticket: " << (customer.getTicket().empty() ? "[No Ticket Purchased]" : customer.getTicket()) << endl;

}

    

void editProfile(){

}
