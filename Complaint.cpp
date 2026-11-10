
#include "Complaint.h"

// Constructor
Complaint::Complaint(
    int id,
    string studentID,
    string category,
    string location,
    string description,
    string priority)
{
    complaintID = id;
    this->studentID = studentID;
    this->category = category;
    this->location = location;
    this->description = description;
    this->priority = priority;

    status = "Pending";
}

// Getter functions

int Complaint::getComplaintID() const
{
    return complaintID;
}

string Complaint::getStudentID() const
{
    return studentID;
}

string Complaint::getCategory() const
{
    return category;
}

string Complaint::getLocation() const
{
    return location;
}

string Complaint::getDescription() const
{
    return description;
}

string Complaint::getPriority() const
{
    return priority;
}

string Complaint::getStatus() const
{
    return status;
}

// Setter functions

void Complaint::setPriority(string newPriority)
{
    priority = newPriority;
}

void Complaint::setStatus(string newStatus)
{
    status = newStatus;
}

// Display complaint information

void Complaint::display() const
{
    cout << "Complaint ID : " << complaintID << endl;
    cout << "Student ID   : " << studentID << endl;
    cout << "Category     : " << category << endl;
    cout << "Location     : " << location << endl;
    cout << "Description  : " << description << endl;
    cout << "Priority     : " << priority << endl;
    cout << "Status       : " << status << endl;
}
