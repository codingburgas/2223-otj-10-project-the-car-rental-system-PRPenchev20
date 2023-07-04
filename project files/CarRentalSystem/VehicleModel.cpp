// VehicleModel.cpp - Implementation file for the VehicleModel class
#include <iostream>
#include <cstring>
#include "VehicleModel.h"

// Constructor
VehicleModel::VehicleModel(int id, int year, const std::string& manufacturer, const std::string& model, const std::string& fuel)
{
    this->id = id;
    this->year = year;
    this->manufacturer = manufacturer;
    this->model = model;
    this->fuel = fuel;
}


// Destructor
VehicleModel::~VehicleModel() 
{
    // Destructor implementation goes here if needed
}

// Getter methods

int VehicleModel::getId() const
{
    return id;
}

int VehicleModel::getYear() const
{
    return year;
}

std::string VehicleModel::getManufacturer() const
{
    return manufacturer;
}

std::string VehicleModel::getModel() const 
{
    return model;
}

std::string VehicleModel::getFuel() const
{
    return fuel;
}

// Setter methods

void VehicleModel::setId(int id)
{
    this->id = id;
}

void VehicleModel::setYear(int year) 
{
    this->year = year;
}

void VehicleModel::setManufacturer(const std::string& manufacturer)
{
    this->manufacturer = manufacturer;
}

void VehicleModel::setModel(const std::string& model) 
{
    this->model = model;
}

void VehicleModel::setFuel(const std::string& fuel)
{
    this->fuel = fuel;
}

// Other methods
void VehicleModel::displayInfo() const 
{
    std::cout << "|    ID: " << id << std::endl;
    std::cout << "|    Manufacturer: " << manufacturer << std::endl;
    std::cout << "|    Model: " << model << std::endl;
    std::cout << "|    Fuel: " << fuel << std::endl;
    std::cout << "|    Year: " << year << std::endl;
}
