#include "VehicleController.h"
#include <string>

// Constructor
VehicleController::VehicleController(const std::string& filename):service(filename) 
{
}

// Run the vehicle management application
void VehicleController::run() 
{
    int choice;

    do 
    {
        // Display menu options
        system("cls");
        std::cout << "|-------------------------------------|" << std::endl;
        std::cout << "|    Vehicle Management Application   |" << std::endl;
        std::cout << "|-------------------------------------|" << std::endl;
        std::cout << "|    1. Add a new vehicle             |" << std::endl;
        std::cout << "|    2. View all vehicles             |" << std::endl;
        std::cout << "|    3. Update a vehicle              |" << std::endl;
        std::cout << "|    4. Delete a vehicle              |" << std::endl;
        std::cout << "|    5. Delete all vehicles recorded  |" << std::endl;
        std::cout << "|    0. Exit                          |" << std::endl;
        std::cout << "|-------------------------------------|" << std::endl;
        std::cout << "|    Enter your choice: ";

        std::cin >> choice;

        // Handle user's choice

        switch (choice) 
        {
        case 1: 
        {
            int year;
            std::string manufacturer, model, fuel;

            system("cls");

            std::cout << "|-------------------------\n";
            std::cout << "|   Enter manufacturer: ";
            std::cin.ignore();
            std::getline(std::cin, manufacturer);

            std::cout << "|   Enter model: ";
            std::getline(std::cin, model);

            std::cout << "|   Enter fuel: ";
            std::getline(std::cin, fuel);

            std::cout << "|   Enter year: ";
            std::cin >> year;

            service.createVehicle(0, year, manufacturer, model, fuel);

            std::cout << "Vehicle added successfully." << std::endl;

            break;
        }
        case 2: 
        {
            std::vector<VehicleModel> vehicles = service.getAllVehicles();
            system("cls");
            std::cout << "|-------------------------------------|\n";
            if (vehicles.empty()) 
            {
                std::cout << "|\n|    No vehicles found!" << std::endl;
            }
            else 
            {
                std::cout << "|             Vehicle List:           |\n";
                std::cout << "|-------------------------------------|\n";

                for (const auto& vehicle : vehicles) 
                {
                    vehicle.displayInfo();

                    std::cout << "|-------------------------------------|\n";
                }
            }
            std::cout << "|    ";
            system("pause");
            break;
        }
        case 3: 
        {
            int id, newYear;
            std::string oldManufacturer, oldModel, oldFuel, newManufacturer, newModel, newFuel;

            std::cout << "|-------------------------\n";
            std::cout << "|  Enter the details of the vehicle to update:" << std::endl;

            
            std::cout << "|  Enter vehicle's id: ";
            std::cin >> id;


            std::cout << "|  Enter new manufacturer: ";
            std::cin.ignore();
            std::getline(std::cin, newManufacturer);

            std::cout << "|  Enter new model: ";
            std::getline(std::cin, newModel);

            std::cout << "|  Enter new fuel: ";
            std::getline(std::cin, newFuel);

            std::cout << "|  Enter new year: ";
            std::cin >> newYear;

            service.updateVehicle(id, newYear, newManufacturer, newModel, newFuel);
            
            system("pause");
            break;
        }
        case 4: 
        {
            int id, year;
            std::string manufacturer, model, fuel;

            std::cout << "|-------------------------\n";
            std::cout << "|  Enter the id of the vehicle to delete:" << std::endl;
            std::cin >> id;


            std::cout << "\n|  Now enter the vehicle's parameters!\n";

            std::cout << "|  Enter manufacturer: ";
            std::cin.ignore();
            std::getline(std::cin, manufacturer);

            std::cout << "|  Enter model: ";
            std::getline(std::cin, model);

            std::cout << "|  Enter fuel: ";
            std::getline(std::cin, fuel);

            std::cout << "|  Enter year: ";
            std::cin >> year;

            service.deleteVehicle(id, year, manufacturer, model, fuel);

            break;
        }
        case 5:
        {
            service.deleteAllVehicles();

            system("pause");
            break;
        }
        case 0:
            std::cout << "Exiting the application. Goodbye!" << std::endl;

            break;
        default:

            std::cout << "Invalid choice. Please try again." << std::endl;
        }

        std::cout << std::endl;

    } 
    while (choice != 0);
}