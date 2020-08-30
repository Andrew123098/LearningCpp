/* The following code defines a class called WeatherForcast and a struct called ForecastDay.
 * Write the method to find the maximum high temperature stored in the ForecastDay array. 
 * The method should print the day and the temperature. If more than one day had the maximum 
 * high temperature, print the first day found with that temperature.
 */

#include <iostream>

struct ForecastDay{
    std::string day;
    int highTemp;
    int lowTemp;
};

class WeatherForecaster{
    public:
        WeatherForecaster();
        ~WeatherForecaster();
        void addDayToData(ForecastDay);
        void printDaysInData(); // Prints the unique dates in the data
        void maxHighTemp();
    private:
        int arrayLength;
        int index;
        ForecastDay yearData[984]; // Data for each day
};
WeatherForecaster::WeatherForecaster()
{
    //ctor
    arrayLength = 100;
    index = 0;
}
void WeatherForecaster::addDayToData(ForecastDay fd){
    yearData[index] = fd;
    index++;
}
void WeatherForecaster::maxHighTemp(){
    int temp;
    int max;
    int index;
    for(int i= 0 ; i < 984 ; i++){
        temp = yearData[i];
        if(temp > max){
            max = temp;
            index = i;
        }
    }
    std::cout << "Max high temp: " << max << " on day number " << index;
}
