class ParkingSystem {
public:
    vector<int> cars;
    ParkingSystem(int big, int medium, int small) {
        this->cars = vector<int> {big, medium, small};
    }
    
    bool addCar(int carType) {
        if(this->cars[carType-1] > 0){
            this->cars[carType - 1]--;
            return true;
        }

        return false;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */