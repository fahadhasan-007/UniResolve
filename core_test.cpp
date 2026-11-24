
#include <iostream>
#include "ComplaintManager.h"

using namespace std;

int main()
{
    ComplaintManager manager;

    cout << "===== UniResolve Core Logic Demo =====\n\n";

    // 1. Add complaints
    cout << "1. Adding Complaints...\n";

    int id1 = manager.addComplaint(
        "41250202878",
        "Water",
        "Room 302",
        "Water Tap is not working");

    int id2 = manager.addComplaint(
        "41250202759",
        "Wi-Fi",
        "Library",
        "Internet is not working");

    cout << "Complaint added. ID: " << id1 << endl;
    cout << "Complaint added. ID: " << id2 << endl;

    // 2. Display all complaints
    cout << "\n2. Displaying All Complaints...\n";

    manager.viewAllComplaints();

    // 3. Update complaint status
    cout << "\n3. Updating Complaint Status...\n";

    if (manager.updateStatus(id1, "Assigned"))
    {
        cout << "Status updated successfully!\n";
    }
    else
    {
        cout << "Status update failed!\n";
    }

    // 4. Update complaint priority
    cout << "\n4. Updating Complaint Priority...\n";

    if (manager.updatePriority(id2, "High"))
    {
        cout << "Priority updated successfully!\n";
    }
    else
    {
        cout << "Priority update failed!\n";
    }

    // 5. Display updated complaints
    cout << "\n5. Displaying Updated Complaints...\n";

    manager.viewAllComplaints();

    // 6. Delete a complaint
    cout << "\n6. Deleting Complaint...\n";

    if (manager.deleteComplaint(id2))
    {
        cout << "Complaint deleted successfully!\n";
    }
    else
    {
        cout << "Complaint deletion failed!\n";
    }

    // 7. Display final complaints
    cout << "\n7. Final Complaint List...\n";

    manager.viewAllComplaints();

    cout << "\n===== Logic Example Showed =====\n";

    return 0;
}
