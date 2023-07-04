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
        std::cout << "---------------------------" << std::endl;
        std::cout << "Vehicle Management Application" << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << "1. Add a new vehicle" << std::endl;
        std::cout << "2. View all vehicles" << std::endl;
        std::cout << "3. Update a vehicle" << std::endl;
        std::cout << "4. Delete a vehicle" << std::endl;
        std::cout << "5. Delete all vehicles recorded" << std::endl;
        std::cout << "0. Exit" << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << "Enter your choice: ";

        std::cin >> choice;

        // Handle user's choice

        switch (choice) 
        {
        case 1: 
        {
            int year;
            std::string make, model, fuel;

            std::cout << "Enter year: ";
            std::cin >> year;

            std::cout << "Enter make: ";
            std::cin.ignore();
            std::getline(std::cin, make);

            std::cout << "Enter model: ";
            std::getline(std::cin, model);

            std::cout << "Enter fuel: ";
            std::getline(std::cin, fuel);

            service.createVehicle(year, make, model, fuel);

            std::cout << "Vehicle added successfully." << std::endl;

            break;
        }
        case 2: 
        {
            std::vector<VehicleModel> vehicles = service.getAllVehicles();

            if (vehicles.empty()) 
            {
                std::cout << "No vehicles found." << std::endl;
            }
            else 
            {
                std::cout << "Vehicle List:" << std::endl;

                for (const auto& vehicle : vehicles) 
                {
                    vehicle.displayInfo();

                    std::cout << std::endl;
                }
            }
            system("pause");
            break;
        }
        case 3: 
        {
            int oldYear, newYear;
            std::string oldMake, oldModel, oldFuel,newMake, newModel, newFuel;

            std::cout << "Enter the details of the vehicle to update:" << std::endl;

            std::cout << "Enter old year: ";
            std::cin >> oldYear;

            std::cout << "Enter old make: ";
            std::cin.ignore();
            std::getline(std::cin, oldMake);

            std::cout << "Enter old model: ";
            std::getline(std::cin, oldModel);

            std::cout << "Enter old fuel: ";
            std::getline(std::cin, oldFuel);


            std::cout << "Enter new year: ";
            std::cin >> newYear;

            std::cout << "Enter new make: ";
            std::cin.ignore();
            std::getline(std::cin, newMake);

            std::cout << "Enter new model: ";
            std::getline(std::cin, newModel);

            std::cout << "Enter new fuel: ";
            std::getline(std::cin, newFuel);

            service.updateVehicle(oldYear, oldMake, oldModel, oldFuel, newYear, newMake, newModel, newFuel);
            
            system("pause");
            break;
        }
        case 4: 
        {
            int year;
            std::string make, model, fuel;

            std::cout << "Enter the details of the vehicle to delete:" << std::endl;

            std::cout << "Enter year: ";
            std::cin >> year;

            std::cout << "Enter make: ";
            std::cin.ignore();
            std::getline(std::cin, make);

            std::cout << "Enter model: ";
            std::getline(std::cin, model);

            std::cout << "Enter fuel: ";
            std::getline(std::cin, fuel);

            service.deleteVehicle(year, make, model, fuel);

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