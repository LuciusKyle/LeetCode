
#include <map>
#include <string>
#include <unordered_map>

using std::string;

class UndergroundSystem {
 public:
  UndergroundSystem() {}

  void checkIn(int id, const string stationName, int t) {
    id_station_map_.insert({id, {stationName, t}});
  }

  void checkOut(int id, const string stationName, int t) {
    auto check_in_iter = id_station_map_.find(id);
    auto &count_avg_pair = start_end_count_avg_map_[check_in_iter->second.first][stationName];
    const int time_diff = t - check_in_iter->second.second;
    id_station_map_.erase(check_in_iter);
    ++count_avg_pair.first;
    count_avg_pair.second = double(time_diff) / count_avg_pair.first + count_avg_pair.second * (double(count_avg_pair.first - 1) / count_avg_pair.first);
  }

  double getAverageTime(const string startStation, const string endStation) {
    return start_end_count_avg_map_.at(startStation).at(endStation).second;
  }

 private:
  std::unordered_map<string, std::unordered_map<string, std::pair<int, double>>> start_end_count_avg_map_;
  std::unordered_map<int, std::pair<string, int>> id_station_map_;
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */
