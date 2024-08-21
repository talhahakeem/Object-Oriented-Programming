//MEDICAL STORE MANAGEMENT SYSTEM

/*   GROUP MEMBERS
		1. MUHAMMAD HUZAIFA (065) 03-134222-065
		2. MUHAMMAD HASSAN KHAN (064) 03-134222-064
		3. MUHAMMAD IMAN KHAN (068) 03-134222-068
*/

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <exception>

using namespace std;

class MedicalItem
{
    protected:
        string name;
        float price;
        string manufacturer;
        time_t manufacturerDate;
        time_t expiryDate;
        int quantity;
        float wholesalePrice;
        float retailPrice;
        double discount;
    public:
        MedicalItem(const string& name, float wholesalePrice, const string& manufacturer, time_t manufacturerDate, time_t expiryDate, int quantity) : name(name), manufacturer(manufacturer), manufacturerDate(manufacturerDate), expiryDate(expiryDate), quantity(quantity), wholesalePrice(wholesalePrice)
        {
            // Calculate the retail price with a 40% markup from the wholesale price
            retailPrice = wholesalePrice + (0.4 * wholesalePrice);
            price = retailPrice + (0.15 * retailPrice);
            // Apply a 5% discount to the price
            discount = price * (5/100);
        }

        const string& getName()
        {
        return name;
        }
        
        void setName(string n)
        {
        	name = n;
        }
		
		double getDiscount()
		{
			return discount;
		}
		
        float getPrice()
        {
            return price;
        }

        const string& getManufacturer()
        {
            return manufacturer;
        }

        time_t getManufacturerDate()
        {
            return manufacturerDate;
        }

        time_t getExpiryDate()
        {
            return expiryDate;
        }

        int getQuantity()
        {
            return quantity;
        }

        float getWholesalePrice()
        {
            return wholesalePrice;
        }

        float getRetailPrice()
        {
            return retailPrice;
        }

        void setQuantity(int newQuantity)
        {
            quantity = newQuantity;
        }

        void display()
        {
            cout << "Name: " << name << endl;
            cout << "Price: " << price << endl;
            cout << "Manufacturer: " << manufacturer << endl;
            cout << "Manufacturer Date: " << ctime(&manufacturerDate);
            cout << "Expiry Date: " << ctime(&expiryDate);
            cout << "Quantity: " << quantity << endl;
            cout << "Wholesale Price: " << wholesalePrice << endl;
            cout << "Retail Price: " << retailPrice << endl;
            cout << endl;
        }
        void writeToFile(ofstream& file)
		{
		    file << "Name: " << name << endl;
		    file << "Price: " << price << endl;
		    file << "Manufacturer: " << manufacturer << endl;
		    file << "Manufacturer Date: " << ctime(&manufacturerDate);
		    file << "Expiry Date: " << ctime(&expiryDate);
		    file << "Quantity: " << quantity << endl;
		    file << "Wholesale Price: " << wholesalePrice << endl;
		    file << "Retail Price: " << retailPrice << endl;
		    file << "Discount: " << discount << endl;
		    file << endl;
		}
};

class Bill
{
    private:
        string customerName;
        time_t purchaseDate;
        MedicalItem* item;
        int quantity;

    public:
        Bill(const string& customerName, time_t purchaseDate, MedicalItem* item, int quantity) : customerName(customerName), purchaseDate(purchaseDate), item(item), quantity(quantity) {}

        void generateBill()
        {
            cout << "------------ Bill ------------" << endl;
            cout << "Customer Name: " << customerName << endl;
            cout << "Purchase Date: " << ctime(&purchaseDate);
            cout << "Medicine: " << item->getName() << endl;
            cout << "Quantity: " << quantity << endl;
            float totalAmount = item->getRetailPrice() * quantity;
            cout << "Total Amount: " << totalAmount << endl;
            float discount = item->getDiscount();
            if (discount > 0)
            {
            float discountAmount = totalAmount * (discount / 100);
            cout << "Discount: " << discountAmount << endl;
            cout << "Final Amount: " << totalAmount - discountAmount << endl;
            }
            cout << "-------------------------------" << endl;
        }
};

class MedicalStore
{
    private:
        MedicalItem* inventory[100];
        int itemCount;

    public:
        MedicalStore() : itemCount(0) {}
        
        //Destructor
        ~MedicalStore()
	    {
	        for (int i = 0; i < itemCount; i++)
	        {
	            delete inventory[i];
	        }
	    }
        
        void saveInventoryToFile(const string& filename)
		{
	        ofstream file(filename);
	
	        if (file.is_open())
			{
	            for (int i = 0; i < itemCount; i++)
				{
	                inventory[i]->writeToFile(file);
	            }
	
	            file.close();
	            cout << "Inventory saved to file: " << filename << endl;
	        }
			else
			{
	            cout << "Failed to open file: " << filename << endl;
	        }
	    }
	
	    // Add a function to load the inventory from a file
	    void loadInventoryFromFile(const string& filename)
		{
	        ifstream file(filename);
	
	        if (file.is_open())
			{
	            string line;
	
	            while (getline(file, line))
				{
	                // Read the item's data from the file
	                string name;
	                float price;
	                string manufacturer;
	                time_t manufacturerDate;
	                time_t expiryDate;
	                int quantity;
	                float wholesalePrice;
	                float retailPrice;
	
	                // Parse the data from the file
	
	                // Create a new MedicalItem object and add it to the inventory
	                MedicalItem* item = new MedicalItem(name, wholesalePrice, manufacturer, manufacturerDate, expiryDate, quantity);
	                inventory[itemCount++] = item;
	            }
	
	            file.close();
	            cout << "Inventory loaded from file: " << filename << endl;
	        }
			else
			{
	            cout << "Failed to open file: " << filename << endl;
	        }
	    }

        void addMedicalItem(const MedicalItem& item)
        {
        try
		{
		    if (itemCount >= 100)
        {
            throw itemCount;
        }
    	}
    	catch(...)
    	{
    		cout << "Inventory Is Full. Cannot Add More Items." << endl ;
		}
        inventory[itemCount++] = new MedicalItem(item);
        }

        void displayMedicalItems()
        {
        if (itemCount == 0)
        {
            cout << "Inventory is empty." << endl;
        }
        else
        {
            for (int i = 0; i < itemCount; i++)
            {
                inventory[i]->display();
            }
        }
        }

        MedicalItem* findMedicalItem(const string& name)
        {
            for (int i = 0; i < itemCount; i++)
            {
            if (inventory[i]->getName() == name)
            {
                return inventory[i];
            }
            }
            return nullptr;
        }

        void updateMedicalItemName(const string& currentName, const string& newName)
        {
            MedicalItem* item = findMedicalItem(currentName);
            try
            {
				if (item == nullptr)
            	{
            	    throw item;
            	}
        	}
        	catch(...)
        	{
        		cout << "Item Not Found In Inventory." << endl;
			}
            item->setName(newName);
        }

        void removeMedicalItem(const string& name)
        {
            int index = -1;
            for (int i = 0; i < itemCount; i++)
            {
            if (inventory[i]->getName() == name)
            {
                index = i;
                break;
            }
        }
        if (index != -1)
        {
            delete inventory[index];
            for (int i = index; i < itemCount - 1; i++)
            {
                inventory[i] = inventory[i + 1];
            }
            itemCount--;
            cout << "Item Removed From Inventory." << endl;
        }
        else
        {
            cout << "Item Not Found In Inventory." << endl;
        }
        }
        void restockFromSupplier(const string& itemName, int quantityToAdd)
		{
		    int itemIndex = -1;
		    for (int i = 0; i < itemCount; i++)
		    {
		        if (inventory[i]->getName() == itemName)
		        {
		            itemIndex = i;
		            break;
		        }
		    }
		
		    if (itemIndex != -1)
		    {
		        // Item found, update the quantity
		        inventory[itemIndex]->setQuantity(inventory[itemIndex]->getQuantity() + quantityToAdd);
		        cout << "Restocked " << itemName << ": " << quantityToAdd << " units added." << endl;
		    }
		    else
		    {
		        // Item not found, add it to the inventory
		        if (itemCount < 100)
		        {
		            MedicalItem* newItem = new MedicalItem(itemName, 0.0, "", 0, 0, quantityToAdd);
		            inventory[itemCount++] = newItem;
		            cout << "Added " << itemName << " to the inventory: " << quantityToAdd << " units added." << endl;
		        }
		        else
		        {
		            cout << "Inventory is full. Cannot add more items." << endl;
		        }
		    }
		}

};

class Menu
{
    public:
        virtual void displayMenu() {};
        virtual void handleChoice(int choice, MedicalStore& store) {};
        virtual int getExitChoice() {};
};

class AdminMenu : public Menu
{
    public:
        void displayMenu() override
        {
            cout << "\n--- Admin Menu ---" << endl;
            cout << "1. Add Medical Item" << endl;
            cout << "2. Display Medical Items" << endl;
            cout << "3. Update Medical Item Name" << endl;
            cout << "4. Remove Medical Item" << endl;
            cout << "5. Restock from Supplier" << endl;
            cout << "6. Exit" << endl;
            cout << "Enter your choice: ";
        }
        
        int getExitChoice() override
        {
        	return 6;
		}

        void handleChoice(int choice, MedicalStore& store) override
        {
            string itemName, currentName, newName;

            switch (choice)
            {
            case 1:
            {
                // Add Medical Item
                // Implement the logic to add a medical item to the store

                string name, manufacturer;
                float wholesalePrice;
                time_t manufacturerDate, expiryDate;
                int quantity;

                cout << "Enter the details of the medical item:" << endl;
                cout << "Name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Wholesale Price: ";
                cin >> wholesalePrice;
                cout << "Manufacturer: ";
                cin.ignore();
                getline(cin, manufacturer);
                cout << "Manufacturer Date (YYYY-MM-DD): ";
                cin >> manufacturerDate;
                cout << "Expiry Date (YYYY-MM-DD): ";
                cin >> expiryDate;
                cout << "Quantity: ";
                cin >> quantity;

                try
                {
                    MedicalItem item(name, wholesalePrice, manufacturer, manufacturerDate, expiryDate, quantity);
                    store.addMedicalItem(item);
                    cout << "Medical item added successfully!" << endl;
                }
                catch (const exception& e)
                {
                    cerr << "Failed to add medical item: " << e.what() << endl;
                }
                break;
            }
            case 2:
            {
                // Display Medical Items
                // Implement the logic to display all medical items in the store

                store.displayMedicalItems();
                break;
            }
            case 3:
            {
                // Update Medical Item Name
                // Implement the logic to update the name of a medical item in the store

                 cout << "Enter the current name of the medical item: ";
                cin.ignore();
                getline(cin, currentName);
                cout << "Enter the new name of the medical item: ";
                getline(cin, newName);

                try
                {
                    store.updateMedicalItemName(currentName, newName);
                    cout << "Medical item name updated successfully!" << endl;
                }
                catch (const exception& e)
                {
                    cerr << "Failed to update medical item name: " << e.what() << endl;
                }
                break;
            }
            case 4:
            {
                // Remove Medical Item
                // Implement the logic to remove a medical item from the store
                
                cout << "Enter the name of the medical item to remove: ";
                cin.ignore();
                getline(cin, itemName);

                try
                {
                    store.removeMedicalItem(itemName);
                }
                catch (const exception& e)
                {
                    cerr << "Failed to remove medical item: " << e.what() << endl;
                }
                break;
            }
            
            case 5:
            {
                // Restock from Supplier
                // Implement the logic to restock medical items from the supplier

                string itemName;
                int quantity;
                cout << "Enter the name of the medical item to restock: ";
                cin.ignore();
                getline(cin, itemName);
                cout << "Enter the quantity to restock: ";
                cin >> quantity;

                try
                {
                    store.restockFromSupplier(itemName, quantity);
                    cout << "Medical item restocked successfully!" << endl;
                }
                catch (const exception& e)
                {
                    cerr << "Failed to restock medical item: " << e.what() << endl;
                }
                break;
            }
            
            case 6:
            {
                break;
            }
            default:
            {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
            }
        }
};

class CustomerMenu : public Menu
{
    public:
        void displayMenu() override
        {
            cout << "\n--- Customer Menu ---" << endl;
            cout << "1. Search Medicine" << endl;
            cout << "2. Buy Medicine" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
        }
        
        int getExitChoice() override
        {
           	return 3;
		}

        void handleChoice(int choice, MedicalStore& store) override
        {

            switch (choice)
            {
            case 1:
            {
                // Search Medicine
                // Implement the logic to search for medicine

                string itemName;
                cout << "Enter the name of the medicine to search: ";
                cin.ignore();
                getline(cin, itemName);

                MedicalItem* item = store.findMedicalItem(itemName);
                if (item != nullptr)
                {
                    cout << "Medicine found!" << endl;
                    item->display();
                }
                else
                {
                    cout << "Medicine not found." << endl;
                }
                break;
            }
            case 2:
            {
                // Buy Medicine
                // Implement the logic to allow the customer to buy medicine
                
                string itemName;
                int quantity;
                cout << "Enter the name of the medicine to buy: ";
                cin.ignore();
                getline(cin, itemName);
                cout << "Enter the quantity to buy: ";
                cin >> quantity;

                MedicalItem* item = store.findMedicalItem(itemName);
                if (item != nullptr)
                {
                    if (item->getQuantity() >= quantity)
                    {
                        item->setQuantity(item->getQuantity() - quantity);

                        time_t purchaseDate = time(nullptr);
                        Bill bill("John Doe", purchaseDate, item, quantity);
                        bill.generateBill();
                    }
                    else
                    {
                        cout << "Insufficient quantity available." << endl;
                    }
                }
                else
                {
                    cout << "Medicine not found." << endl;
                }
                break;
            }
            case 3:
            {
            	
                break;
            }
            default:
            {
                cout << "Invalid choice. Please try again." << endl;
            }
            }
        }
};

class MedicalStoreRunner
{
    private:
        MedicalStore store;
        Menu* currentMenu = new Menu();

    public:
        MedicalStoreRunner() : currentMenu(nullptr) {}

        void run()
        {
            try
            {
                int choice;
                bool exit = false;

                while (!exit)
                {
                    cout << "--- Medical Store Management System ---" << endl;
                    cout << "1. Admin Login" << endl;
                    cout << "2. Customer" << endl;
                    cout << "3. Exit" << endl;
                    cout << "Enter your choice: ";
                    cin >> choice;

                    switch (choice)
                    {
                    case 1:
                    {
                        if (adminLogin())
                        {
                            currentMenu = new AdminMenu();
                            runMenu();
                        }
                        break;
                    }
                    case 2:
                    {
                        currentMenu = new CustomerMenu();
                        runMenu();
                        break;
                    }
                    case 3:
                    {
                        exit = true;
                        break;
                    }
                    default:
                    {
                        cout << "Invalid choice. Please try again." << endl;
                        break;
                    }
                    }
                }
            }
            catch (const exception& e)
            {
                cerr << "Exception: " << e.what() << endl;
            }
        }

    private:
        void runMenu()
        {
        int choice;

        while (true)
        {
            currentMenu->displayMenu();
            cin >> choice;

            if (choice == currentMenu->getExitChoice())
            {
                delete currentMenu;
                currentMenu = nullptr;
                break;
            }

            currentMenu->handleChoice(choice, store);
        }
        }

        bool adminLogin()
        {
            string username, password;
            cout << "Admin Login" << endl;
            cout << "Username: ";
            cin >> username;
            cout << "Password: ";
            cin >> password;

            ifstream file("admin.txt");
            string fileUsername, filePassword;
            file >> fileUsername >> filePassword;

            if (username == fileUsername && password == filePassword)
            {
                cout << "Login successful!" << endl;
                return true;
            }
            else
            {
                cout << "Login failed!" << endl;
                return false;
            }
        }
};

int main()
{
    MedicalStoreRunner runner;
    runner.run();

	MedicalStore MI;
	MI.~MedicalStore();
    return 0;
}