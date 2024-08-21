#include <iostream>
#include <string>
#include <fstream>
#include <ctime>

using namespace std;

// Define a structure to store rental information
struct RentalInfo {
    string customerName;
    string modelName;
    time_t rentalTime;
    double duration;
};

class Car {
private:
    string model;
    string color;
    double pricePerHour;
    bool available;

public:
    Car(const string& model = "", const string& color = "", double pricePerHour = 0.0)
        : model(model), color(color), pricePerHour(pricePerHour), available(true) {}

    const string& getModel() const { return model; }
    const string& getColor() const { return color; }
    double getPricePerHour() const { return pricePerHour; }
    bool isAvailable() const { return available; }
    void setAvailable(bool status) { available = status; }

    void display() const {
        cout << "Model: " << model << ", Color: " << color
             << ", Price per Hour: $" << pricePerHour
             << ", Availability: " << (available ? "Available" : "Not Available") << endl;
    }

    void display(bool includeAvailability) const {
        if (includeAvailability) {
            display();
        } else {
            cout << "Model: " << model << ", Color: " << color
                 << ", Price per Hour: $" << pricePerHour << endl;
        }
    }

    virtual void start() const {
        cout << "Starting the " << model << "..." << endl;
    }

    void saveToFile(ofstream& file) const {
        file << model << "\n" << color << "\n" << pricePerHour << "\n" << available << "\n";
    }

    void loadFromFile(ifstream& file) {
        file >> ws; // to ignore any leading whitespace
        getline(file, model);
        getline(file, color);
        file >> pricePerHour >> available;
    }

    void editDetails(const string& newModel, const string& newColor, double newPricePerHour) {
        model = newModel;
        color = newColor;
        pricePerHour = newPricePerHour;
    }
};

class LuxuryCar : public Car {
public:
    LuxuryCar(const string& model = "", const string& color = "", double pricePerHour = 0.0)
        : Car(model, color, pricePerHour) {}

    void start() const override {
        cout << "Warming up the engine of the luxury " << getModel() << "..." << endl;
    }
};

class Customer {
private:
    string name;
    string contactNumber;

public:
    Customer(const string& name = "", const string& contactNumber = "")
        : name(name), contactNumber(contactNumber) {}

    const string& getName() const { return name; }
    const string& getContactNumber() const { return contactNumber; }
};

class CarRentalSystem {
private:
    Car cars[7]; // Fixed-size array for 7 cars
    const string fileName = "cars.txt";
    RentalInfo rentals[10]; // Array to store rental details
    int rentalCount;
    string ownerName;

public:
    CarRentalSystem() : rentalCount(0), ownerName("Saad") {
        loadFromFile();
    }

    ~CarRentalSystem() {
        saveToFile();
    }

    void rentCar(const string& model, const Customer& customer, double duration) {
        for (Car& car : cars) {
            if (car.getModel() == model && car.isAvailable()) {
                double totalPrice = car.getPricePerHour() * duration;
                car.setAvailable(false);
                cout << "Car rented successfully!" << endl;
                cout << "Customer Name: " << customer.getName() << ", Contact Number: " << customer.getContactNumber() << endl;
                cout << "Total Price: $" << totalPrice << endl;

                // Record rental details
                if (rentalCount < 10) {
                    rentals[rentalCount].customerName = customer.getName();
                    rentals[rentalCount].modelName = model;
                    rentals[rentalCount].rentalTime = time(nullptr); // Get current time
                    rentals[rentalCount].duration = duration;
                    rentalCount++;
                } else {
                    cout << "Rental limit reached, cannot store more rentals." << endl;
                }

                cout << "Thank you for choosing our service!" << endl;
                return;
            }
        }
        cout << "Car not available for rent." << endl;
    }

    void returnCar(const string& model) {
        for (Car& car : cars) {
            if (car.getModel() == model) {
                car.setAvailable(true);
                cout << "Car returned successfully!" << endl;
                cout << "Thank you for choosing our service!" << endl;
                return;
            }
        }
        cout << "Car not found." << endl;
    }

    void displayAvailableCars() const {
        cout << "Available Cars:" << endl;
        for (const Car& car : cars) {
            if (car.isAvailable()) {
                car.display();
            }
        }
    }

    bool isCarAvailable(const string& model) const {
        for (const Car& car : cars) {
            if (car.getModel() == model && car.isAvailable()) {
                return true;
            }
        }
        return false;
    }

    const Car* getCar(const string& model) const {
        for (const Car& car : cars) {
            if (car.getModel() == model) {
                return &car;
            }
        }
        return nullptr;
    }

    void editCar(const string& model, const string& newModel, const string& newColor, double newPricePerHour) {
        for (Car& car : cars) {
            if (car.getModel() == model) {
                car.editDetails(newModel, newColor, newPricePerHour);
                saveToFile();
                cout << "Car details edited successfully!" << endl;
                return;
            }
        }
        cout << "Car not found." << endl;
    }

    void deleteCar(const string& model) {
        for (int i = 0; i < 7; ++i) {
            if (cars[i].getModel() == model) {
                for (int j = i; j < 6; ++j) { // Shift cars to the left
                    cars[j] = cars[j + 1];
                }
                cars[6] = Car(); // Clear the last car
                saveToFile();
                cout << "Car deleted successfully!" << endl;
                return;
            }
        }
        cout << "Car not found." << endl;
    }

    void saveToFile() const {
        ofstream file(fileName);
        if (file.is_open()) {
            for (const Car& car : cars) {
                car.saveToFile(file);
            }
        }
    }

    void loadFromFile() {
        ifstream file(fileName);
        if (file.is_open()) {
            for (Car& car : cars) {
                car.loadFromFile(file);
            }
        } else {
            // If the file does not exist, initialize with default cars
            cars[0] = Car("Toyota Camry", "Black", 25.0);
            cars[1] = Car("Honda Civic", "Red", 50.0);
            cars[2] = Car("Ford Mustang", "Blue", 60.0);
            cars[3] = Car("BMW 3 Series", "White", 75.0);
            cars[4] = Car("Mercedes-Benz C-Class", "Silver", 80.0);
            cars[5] = Car("Audi A4", "Grey", 70.0);
            cars[6] = Car("Chevrolet Malibu", "Green", 40.0);
        }
    }

    void displayRentalDetails(const Customer& customer) const {
        bool found = false;
        for (int i = 0; i < rentalCount; ++i) {
            if (rentals[i].customerName == customer.getName()) {
                const RentalInfo& info = rentals[i];
                cout << "Rental Details for " << customer.getName() << ":" << endl;
                cout << "Car Model: " << info.modelName << endl;
                cout << "Rental Time: " << ctime(&info.rentalTime); // Convert time to string using ctime
                cout << "Duration: " << info.duration << " hours" << endl;

                // Calculate return time
                time_t returnTime = info.rentalTime + static_cast<time_t>(info.duration * 3600); // Convert hours to seconds
                cout << "Return Time: " << ctime(&returnTime); // Convert time to string using ctime
                found = true;
            }
        }
        if (!found) {
            cout << "No rental details found for " << customer.getName() << endl;
        }
    }

    void displayOwnerName() const {
        cout << "Car Rental System Owner: " << ownerName << endl;
    }
};

void displayMenu() {
    cout << "Car Rental System Menu:" << endl;
    cout << "1. Display available cars" << endl;
    cout << "2. Rent a car" << endl;
    cout << "3. Return a car" << endl;
    cout << "4. Edit car details" << endl;
    cout << "5. Delete car" << endl;
    cout << "6. Display rental details for a customer" << endl;
    cout << "7. Display owner name" << endl;
    cout << "8. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    CarRentalSystem rentalSystem;

    while (true) {
        displayMenu();
        int choice;
        cin >> choice;
        cin.ignore(100, '\n'); // To ignore the newline character after entering choice

        if (choice == 1) {
            rentalSystem.displayAvailableCars();
        } else if (choice == 2) {
            string model;
            cout << "Enter the model of the car you want to rent: ";
            getline(cin, model);

            if (rentalSystem.isCarAvailable(model)) {
                cout << "The car is available for rent." << endl;
                const Car* car = rentalSystem.getCar(model);
                if (car) {
                    car->display();
                    cout << "Enter customer name: ";
                    string name;
                    getline(cin, name);
                    cout << "Enter contact number: ";
                    string contactNumber;
                    getline(cin, contactNumber);
                    double duration;
                    cout << "Enter duration of rental (in hours): ";
                    while (!(cin >> duration) || duration <= 0) {
                        cin.clear(); // Clear the error flag
                        cin.ignore(100, '\n'); // Discard invalid input
                        cout << "Invalid input. Please enter a positive numeric value for the duration: ";
                    }
                    cin.ignore(100, '\n'); // To clear any leftover newline character
                    Customer customer(name, contactNumber);
                    car->start();
                    rentalSystem.rentCar(model, customer, duration);
                } else {
                    cout << "Car details not found." << endl;
                }
            } else {
                cout << "The car is not available for rent." << endl;
            }
        } else if (choice == 3) {
            string model;
            cout << "Enter the model of the car you want to return: ";
            getline(cin, model);
            rentalSystem.returnCar(model);
        } else if (choice == 4) {
            string model;
            cout << "Enter the model of the car you want to edit: ";
            getline(cin, model);
            string newModel, newColor;
            double newPricePerHour;
            cout << "Enter new model: ";
            getline(cin, newModel);
            cout << "Enter new color: ";
            getline(cin, newColor);
            cout << "Enter new price per hour: ";
            while (!(cin >> newPricePerHour)) {
                cin.clear(); // clear the error flag
                cin.ignore(100, '\n'); // discard invalid input
                cout << "Invalid input. Please enter a numeric value for the price per hour: ";
            }
            cin.ignore(100, '\n'); // to clear any leftover newline character
            rentalSystem.editCar(model, newModel, newColor, newPricePerHour);
        } else if (choice == 5) {
            string model;
            cout << "Enter the model of the car you want to delete: ";
            getline(cin, model);
            rentalSystem.deleteCar(model);
        } else if (choice == 6) {
            string name;
            cout << "Enter customer name: ";
            getline(cin, name);
            Customer customer(name, "");
            rentalSystem.displayRentalDetails(customer);
        } else if (choice == 7) {
            rentalSystem.displayOwnerName();
        } else if (choice == 8) {
            break;
        } else {
            cout << "Invalid choice, please try again." << endl;
        }
    }

    return 0;
}