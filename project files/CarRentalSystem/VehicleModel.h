#pragma once

#include <iostream>
#include <cstring>
#include <fstream>

// VehicleModel.h - Header file for the VehicleModel class

// Class representing a vehicle

class VehicleModel 
{
    public:
        // Constructor
        VehicleModel(int id, int year, const std::string& manufacturer, const std::string& model, const std::string& fuel);

        // Destructor
        ~VehicleModel();

        // Getter methods

        int getId() const;
        int getYear() const;
        std::string getManufacturer() const;
        std::string getModel() const;
        std::string getFuel() const;

        // Setter methods
        void setId(int id);
        void setYear(int year);
        void setManufacturer(const std::string& manufacturer);
        void setModel(const std::string& model);
        void setFuel(const std::string& fuel);

        // Other methods
        void displayInfo() const;

    private:
        // Member variables
        int id;
        int year;                    // Year of manufacture
        std::string manufacturer;   // Make of the vehicle
        std::string model;         // Model of the vehicle
        std::string fuel;         // Fuel of the vehicle
};