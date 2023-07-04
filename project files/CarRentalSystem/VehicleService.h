#pragma once

#include "VehicleModel.h"
#include "VehicleRepository.h"

// Service class for managing vehicle data
class VehicleService 
{
    private:
        VehicleRepository repository; // Repository object for data operations

    public:

        // Constructor
        VehicleService(const std::string& filename);

        // Create a new vehicle record
        void createVehicle(int id, int year, const std::string& make, const std::string& model, const std::string& fuel);

        // Read all vehicle records
        std::vector<VehicleModel> getAllVehicles();

        // Update an existing vehicle record
        void updateVehicle(int id, int newYear, const std::string& newMake, const std::string& newModel, const std::string& newFuel);

        // Delete a vehicle record
        void deleteVehicle(int id, int year, const std::string& make, const std::string& model, const std::string& fuel);

        //Delete all vehicles recorded
        void deleteAllVehicles();
};