#include <iostream>
#include <string>
#include <vector>
#include <cstdlib> // For generating random ads

// User class to store user information
class User {
public:
    std::string username;
    std::string password;
    std::vector<std::string> activityHistory;
    float balance;

    // Constructor
    User(const std::string& username, const std::string& password)
        : username(username), password(password), balance(0.0f) {}

    // Function to add activity to the history
    void addActivity(const std::string& activity) {
        activityHistory.push_back(activity);
    }
};

// Function to generate random ads
std::string generateRandomAd() {
    std::vector<std::string> ads = {
        "Get 10% off on your next purchase!",
        "Introducing our new rewards program.",
        "Save money with our exclusive offers.",
        "Upgrade to premium membership for extra benefits."
    };

    int index = rand() % ads.size();
    return ads[index];
}

int main() {
    // Sample user
    User user("karim", "12345");
    user.addActivity("Account created");

    // Login page
    std::cout << "Welcome to Online Banking!" << std::endl;
    std::cout << generateRandomAd() << std::endl;

    std::string username, password;
    std::cout << "Username: ";
    std::cin >> username;
    std::cout << "Password: ";
    std::cin >> password;

    // Check username and password
    if (username == user.username && password == user.password) {
        std::cout << "Login successful!" << std::endl;
        std::cout << "Balance: $" << user.balance << std::endl;

        // Deposit/Withdraw
        std::cout << "Enter 1 to deposit, 2 to withdraw: ";
        int option;
        std::cin >> option;

        float amount;
        if (option == 1) {
            std::cout << "Enter amount to deposit: $";
            std::cin >> amount;
            user.balance += amount;
            user.addActivity("Deposited $" + std::to_string(amount));
        } else if (option == 2) {
            std::cout << "Enter amount to withdraw: $";
            std::cin >> amount;
            if (amount <= user.balance) {
                user.balance -= amount;
                user.addActivity("Withdrew $" + std::to_string(amount));
            } else {
                std::cout << "Insufficient balance!" << std::endl;
            }
        }

        std::cout << "Balance: $" << user.balance << std::endl;

        // Display activity history
        std::cout << "Activity History:" << std::endl;
        for (const std::string& activity : user.activityHistory) {
            std::cout << "- " << activity << std::endl;
        }
    } else {
        std::cout << "Invalid username or password. Login failed!" << std::endl;
    }

    return 0;
}
