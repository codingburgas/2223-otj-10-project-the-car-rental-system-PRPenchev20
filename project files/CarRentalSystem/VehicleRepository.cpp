#pragma once

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "VehicleRepository.h"
#include "VehicleModel.h"

// Constructor
VehicleRepository::VehicleRepository(const std::string& filename) 
{
    this->filename = filename;
}

// Create a new vehicle record
void VehicleRepository::addVehicle(VehicleModel& vehicle) 
{
    std::ofstream file(filename, std::ios::app);
    std::fstream counterFile("IdCounter.txt", std::ios::in | std::ios::out);
    int number;
    

    if (counterFile.is_open())
    {
        bool isEmpty = (counterFile.peek() == std::ifstream::traits_type::eof());

        if (isEmpty)
        {
            counterFile << "0";
            std::cout << "Zero has been written to the file." << std::endl;
        }
        std::string line;

        // Read the number from the file
        if (std::getline(counterFile, line))
        {
            std::istringstream iss(line);
            if (iss >> number) 
            {
                // Increment the number by 1
                int newNumber = number + 1;

                // Move the file pointer to the beginning of the file
                counterFile.seekg(0);

                // Write the new number to the file, overwriting the existing number
                counterFile << newNumber;

            }
        }
        else
        {
            std::cout << "Failed to open file." << std::endl;
        }

        counterFile.close();

    }

    

    if (file.is_open()) 
    {
        vehicle.setId(number);
        file << number << "," << vehicle.getManufacturer() << "," << vehicle.getModel() << "," << vehicle.getFuel() << "," << vehicle.getYear() << std::endl;
        file.close();

        std::cout << "|\n|\n|    Vehicle record created successfully." << std::endl;
    }
    else 
    {
        std::cout << "|    Failed to open file for writing." << std::endl;
    }
}

// Read all vehicle records from the file
std::vector<VehicleModel> VehicleRepository::getVehicles() 
{
    std::vector<VehicleModel> vehicles;
    std::ifstream file(filename);

    if (file.is_open()) 
    {
        std::string line;

        while (std::getline(file, line)) 
        {
            std::stringstream lineString(line);
            
            
            std::string token;

            int id = 0;
            std::getline(lineString, token, ',');
            std::stringstream(token) >> id;

            std::getline(lineString, token, ',');
            std::string manufacturer = token;

            std::getline(lineString, token, ',');
            std::string model = token;


            std::getline(lineString, token, ',');
            std::string fuel = token;
            
            
            int yearInt = 0;

            std::getline(lineString, token);
            std::stringstream(token) >> yearInt;

            VehicleModel vehicle(id, yearInt, manufacturer, model, fuel);
            vehicles.push_back(vehicle);
        }
        file.close();
    }
    else
    {
        std::cout << "Failed to open file for reading." << std::endl;
    }
    return vehicles;
}



// Update an existing vehicle record
void VehicleRepository::updateVehicle(const VehicleModel& newVehicle)
{
    std::ifstream fileIn(filename);

    if (fileIn.is_open()) 
    {
        std::ofstream fileOut("temp.txt", std::ios::app);

        if (fileOut.is_open()) 
        {
            std::string line;

            while (std::getline(fileIn, line)) 
            {
                std::stringstream lineString(line);
                std::string token;


                std::getline(lineString, token, ',');
                int id = 0;
                std::stringstream(token) >> id;

                std::getline(lineString, token, ',');
                std::string manufacturer = token;

                std::getline(lineString, token, ',');
                std::string model = token;

                std::getline(lineString, token, ',');
                std::string fuel = token;

                std::getline(lineString, token);
                int yearInt = 0;
                std::stringstream(token) >> yearInt;

                VehicleModel currentVehicle(id, yearInt, manufacturer, model, fuel);

                if (currentVehicle.getId() == newVehicle.getId())
                {
                    fileOut << newVehicle.getId() <<  "," << newVehicle.getManufacturer() << "," << newVehicle.getModel() << "," << newVehicle.getFuel() << "," << newVehicle.getYear() << std::endl;

                    std::cout << "|\n|";
                    std::cout << "    Vehicle record updated successfully." << std::endl;
                }
                else 
                {
                    fileOut << line << std::endl;
                }
            }
            fileIn.close();
            fileOut.close();
            std::remove(filename.c_str());
            std::rename("temp.txt", filename.c_str());
        }
        else 
        {
            std::cout << "Failed to open temporary file for writing." << std::endl;
        }
    }
    else 
    {
        std::cout << "Failed to open file for reading." << std::endl;
    }
}

void VehicleRepository::removeAllVehicles()
{
    system("cls");
    std::ifstream fileIn("Vehicles.txt");

    if (fileIn.is_open())
    {
        std::ofstream fileOut("temp.txt", std::ios::app);

        if (fileOut.is_open())
        {
            std::string line;
            bool anyVehicleDeleted = false; // Flag to check if any vehicle is deleted

            while (std::getline(fileIn, line))
            {
                anyVehicleDeleted = true; // Set the flag to true

                std::cout << "|------------------------------------------------------------" << std::endl;
                std::cout << "|   Vehicle record deleted: " << line << std::endl;
            }

            fileIn.close();
            fileOut.close();
            std::remove(filename.c_str());
            std::rename("temp.txt", filename.c_str());

            if (anyVehicleDeleted)
            {
                std::cout << "|------------------------------------------------------------" << std::endl;
                std::cout << "|\n|\n|    All vehicle records deleted successfully!" << std::endl;
            }
            else
            {

                std::cout << "|-------------------------------------|\n";
                std::cout << "|\n|\n|    No vehicle records found!" << std::endl;
            }
        }
        else
        {
            std::cout << "Failed to open temporary file for writing." << std::endl;
        }
    }
    else
    {
        std::cout << "Failed to open file for reading." << std::endl;
    }
}

// Delete a vehicle record
void VehicleRepository::removeVehicle(const VehicleModel& vehicle) 
{
    std::ifstream fileIn(filename);

    if (fileIn.is_open()) 
    {
        std::ofstream fileOut("temp.txt", std::ios::app);

        if (fileOut.is_open()) 
        {
            std::string line;

            while (std::getline(fileIn, line)) 
            {
                std::stringstream lineString(line);
                std::string token;

                
                int id = 0;
                std::getline(lineString, token, ',');
                std::stringstream(token) >> id;

                std::getline(lineString, token, ',');
                std::string manufacturer = token;

                std::getline(lineString, token, ',');
                std::string model = token;

                std::getline(lineString, token, ',');
                std::string fuel = token;

                int yearInt = 0;
                std::getline(lineString, token);
                std::stringstream(token) >> yearInt;

                VehicleModel currentVehicle(id, yearInt, manufacturer, model, fuel);

                if (currentVehicle.getId() != vehicle.getId())
                {
                    fileOut << line << std::endl;
                }
                else 
                {
                    std::cout << "|\n|    Vehicle record deleted successfully." << std::endl;
                }
            }
            fileIn.close();
            fileOut.close();
            std::remove(filename.c_str());
            std::rename("temp.txt", filename.c_str());
        }
        else 
        {
            std::cout << "Failed to open temporary file for writing." << std::endl;
        }
    }
    else 
    {
        std::cout << "Failed to open file for reading." << std::endl;
    }
}