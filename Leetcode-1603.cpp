/*
 * Problem 1603: Design Parking System
 * Language: C++
 */
class ParkingSystem {
private:
    int big, medium, small;
    int countBig, countMedium, countSmall;
public:
    ParkingSystem(int big, int medium, int small) {
        this->big = big;
        this->medium = medium;
        this->small = small;
        countBig = 0;
        countSmall = 0;
        countMedium = 0;
    }
    
    bool addCar(int carType) {
        if(carType == 1){
            if(countBig == big) return false;
            countBig++;
        }else if(carType == 2){
            if(countMedium == medium) return false;
            countMedium++;
        }else{
            if(countSmall == small) return false;
            countSmall++;
        }
        return true;
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */