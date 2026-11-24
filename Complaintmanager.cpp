
#include "ComplaintManager.h"

// Constructor
ComplaintManager::ComplaintManager()
{
    nextComplaintID = 1001;
}

// Determine priority based on category
string ComplaintManager::determinePriority(string category) const
{
    // High priority
    if (category == "Electrical" || category == "Water")
    {
        return "High";
    }

    // Medium priority
    if (
        category == "AC" ||
        category == "Fan" ||
        category == "Projector" ||
        category == "Door/Lock" ||
        category == "Wi-Fi")
    {
        return "Medium";
    }

    // Low priority
    if (category == "Furniture" || category == "Other")
    {
        return "Low";
    }

    // Unknown category
    return "Invalid";
}
// Check whether priority is valid
bool ComplaintManager::isValidPriority(string priority) const
{
    if (
        priority == "High" ||
        priority == "Medium" ||
        priority == "Low")
    {
        return true;
    }

    return false;
}

// Check whether status change is allowed
bool ComplaintManager::isValidStatusTransition(
    string currentStatus,
    string newStatus) const
{
    if (currentStatus == "Pending" && newStatus == "Assigned")
    {
        return true;
    }

    if (currentStatus == "Assigned" && newStatus == "In Progress")
    {
        return true;
    }

    if (currentStatus == "In Progress" && newStatus == "Resolved")
    {
        return true;
    }

    return false;
}

// Add a new complaint
int ComplaintManager::addComplaint(
    string studentID,
    string category,
    string location,
    string description)
{

    // Determine priority automatically
    string priority = determinePriority(category);

    // Unknown category: reject
    if (priority == "Invalid")
    {
        return -1;
    }
    // Generate complaint ID
    int newID = nextComplaintID;

    // Create complaint object
    Complaint newComplaint(
        newID,
        studentID,
        category,
        location,
        description,
        priority);

    // Add complaint to vector
    complaints.push_back(newComplaint);

    // Increase ID for next complaint
    nextComplaintID++;

    return newID;
}

// View all complaints
void ComplaintManager::viewAllComplaints() const
{
    if (complaints.empty())
    {
        cout << "\nNo complaints found." << endl;
        return;
    }

    cout << "\n========== ALL COMPLAINTS ==========\n";

    for (size_t i = 0; i < complaints.size(); i++)
    {
        complaints[i].display();

        cout << "------------------------------------" << endl;
    }
}

// Update complaint status
bool ComplaintManager::updateStatus(
    int complaintID,
    string newStatus)
{
    for (size_t i = 0; i < complaints.size(); i++)
    {
        if (complaints[i].getComplaintID() == complaintID)
        {
            // Check valid status transition
            if (
                !isValidStatusTransition(
                    complaints[i].getStatus(),
                    newStatus))
            {
                return false;
            }

            complaints[i].setStatus(newStatus);

            return true;
        }
    }

    return false;
}

// Update complaint priority
bool ComplaintManager::updatePriority(
    int complaintID,
    string newPriority)
{
    // Check valid priority
    if (!isValidPriority(newPriority))
    {
        return false;
    }

    for (size_t i = 0; i < complaints.size(); i++)
    {
        if (complaints[i].getComplaintID() == complaintID)
        {
            complaints[i].setPriority(newPriority);

            return true;
        }
    }

    return false;
}

// Delete complaint
bool ComplaintManager::deleteComplaint(int complaintID)
{
    for (size_t i = 0; i < complaints.size(); i++)
    {
        if (complaints[i].getComplaintID() == complaintID)
        {
            complaints.erase(complaints.begin() + i);

            return true;
        }
    }

    return false;
}
