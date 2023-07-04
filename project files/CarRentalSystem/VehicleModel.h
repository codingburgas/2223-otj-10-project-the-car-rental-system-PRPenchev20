#pragma once

#include <iostream>
#include <cstring>


// VehicleModel.h - Header file for the VehicleModel class

// Class representing a vehicle
class VehicleModel 
{
    private:
        // Member variables
        int id;
        int year;           // Year of manufacture
        std::string make;   // Make of the vehicle
        std::string model;  // Model of the vehicle
        std::string fuel;   // Fuel of the vehicle

        static int nextId;
    public:
        // Constructor
        VehicleModel(int year, const std::string& make, const std::string& model, const std::string& fuel);

        // Destructor
        ~VehicleModel();

        // Getter methods

        int getId() const;
        int getYear() const;
        std::string getMake() const;
        std::string getModel() const;
        std::string getFuel() const;

        // Setter methods
        int setId(int year);
        void setYear(int year);
        void setMake(const std::string& make);
        void setModel(const std::string& model);
        void setFuel(const std::string& fuel);

        // Other methods
        void displayInfo() const;
};