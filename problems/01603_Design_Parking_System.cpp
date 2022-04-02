// Runtime: 87 ms, faster than 37.44% of C++ online submissions for Design Parking System.
// Memory Usage: 33.1 MB, less than 73.16% of C++ online submissions for Design Parking System.
class ParkingSystem {
private:
    int m_big;
    int m_medium;
    int m_small;
public:
    ParkingSystem(int big, int medium, int small) {
        m_big = big;
        m_medium = medium;
        m_small = small;
    }
    
    bool addCar(int carType) {
        switch(carType) {
            case 1: 
                if (m_big > 0) {
                    m_big--;
                    return true;
                } else {
                    return false;
                }
            case 2:
                if (m_medium > 0) {
                    m_medium--;
                    return true;
                } else {
                    return false;
                }
            case 3:
                if (m_small > 0) {
                    m_small--;
                    return true;
                } else {
                    return false;
                }
            default: return false;
        }
    }
};

/**
 * Your ParkingSystem object will be instantiated and called as such:
 * ParkingSystem* obj = new ParkingSystem(big, medium, small);
 * bool param_1 = obj->addCar(carType);
 */