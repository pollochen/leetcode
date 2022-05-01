// Runtime: 273 ms, faster than 21.33% of C++ online submissions for Design Underground System.
// Memory Usage: 59.4 MB, less than 34.65% of C++ online submissions for Design Underground System.
class UndergroundSystem {
    map<int, pair<string, int>> m_map_checkin; // id -> {start station, start time}
    map<pair<string, string>, int> m_map_time; // {start station, start time} -> total time
    map<pair<string, string>, int> m_map_count; // {start station, start time} -> count
public:
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        m_map_checkin[id] = {stationName, t};
    }
    
    void checkOut(int id, string stationName, int t) {
        pair<string, int> info = m_map_checkin[id];
        m_map_time[{info.first, stationName}] += t - info.second; // increase totol time
        m_map_count[{info.first, stationName}]++; // increase count
    }
    
    double getAverageTime(string startStation, string endStation) {
        pair<string, string> p = {startStation, endStation};
        return (double)m_map_time[p] / m_map_count[p];
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */