
#ifndef COMPLAINTMANAGER_H
#define COMPLAINTMANAGER_H

#include "Complaint.h"
#include <vector>
#include <string>

using namespace std;

class ComplaintManager
{
private:
    // Stores all complaints
    vector<Complaint> complaints;

    // Generates complaint ID
    int nextComplaintID;

    // Determines complaint priority
    string determinePriority(string category) const;

    // Checks valid priority
    bool isValidPriority(string priority) const;

    // Checks valid status change
    bool isValidStatusTransition(
        string currentStatus,
        string newStatus) const;

public:
    // Constructor
    ComplaintManager();

    // Add complaint
    int addComplaint(
        string studentID,
        string category,
        string location,
        string description);

    // View all complaints
    void viewAllComplaints() const;

    // Update complaint status
    bool updateStatus(int complaintID, string newStatus);

    // Update complaint priority
    bool updatePriority(int complaintID, string newPriority);

    // Delete complaint
    bool deleteComplaint(int complaintID);
};

#endif
