#pragma once
#include <iostream>
#include <string>
#include "Validation.h"

using namespace std;

class Person {
protected:
    //Attributes
    //int id;
    string name;
    string password;
    //static int idCounter;

public:
    // Constructors
    //1-Defaule Cons
    //==========================
    Person() {
        //id = 0;
        //idCounter++;
    }

    //2-Parameterized Cons
    //============================
    Person(const string& name, const string& password) {
        //setId(id);
        setName(name);
        setPassword(password);
    }

    // Setters
    /*void setId(int id) {
        this->id = id;
    }*/

    void setName(const string& name) {
        if (Validation::validateName(name))
            this->name = name;
        else
            cout << "Invalid Name" << endl;
    }

    void setPassword(const string& password) {
        if (Validation::validatePassword(password))
            this->password = password;
        else
            cout << "Invalid Password" << endl;
    }

    // Getters
    /*int getId() const {
        return id;
    }*/

    string getName() const {
        return name;
    }

    string getPassword() const {
        return password;
    }

    // Methods
    virtual void displayInfo() = 0;
};
