#include<iostream>
#include<map>
#include<string>
#include<unordered_map>
#include<vector>

using namespace std;

struct CityRecord{
    string Name;
    uint64_t Population;
    double Latitude, Longitude;
};

namespace std{
template<>
struct hash<CityRecord>{
    size_t operator()(const CityRecord& key){
        return hash<string>()(key.Name);
    }
};
}


int main(){
    
    unordered_map<string, CityRecord> cityMap;
    cityMap["Melbourne"] = {"Melbourne", 5000000, 2.4, 9.4};
    cityMap["Lol-town"] = {"Lol-town", 5000000, 2.4, 9.4};
    cityMap["Berlin"] = {"Berlin", 5000555000, 2.4, 9.4};
    cityMap["Paris"] = {"Paris", 5000000, 2.4, 9.4};
    cityMap["London"] = {"London", 5000000, 2.4, 9.4}; 

    CityRecord& berlinData = cityMap["Berlin"];
    berlinData.Population;
} 