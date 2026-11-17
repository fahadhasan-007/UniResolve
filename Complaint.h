
#ifndef COMPLAINT_H
#define COMPLAINT_H

#include <iostream>
#include <string>

using namespace std;

class Complaint
{
private:
    int complaintID;
    string studentID;
    string category;
    string location;
    string description;
    string priority;
    string status;

public:
    // Constructor
    Complaint(
        int id,
        string studentID,
        string category,
        string location,
        string description,
        string priority);

    // Getter functions
    int getComplaintID() const;
    string getStudentID() const;
    string getCategory() const;
    string getLocation() const;
    string getDescription() const;
    string getPriority() const;
    string getStatus() const;

    // Setter functions
    void setPriority(string newPriority);
    void setStatus(string newStatus);

    // Display complaint
    void display() const;
};

#endif
