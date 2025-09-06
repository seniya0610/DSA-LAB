#include <iostream>

using namespace std;

int main() {
    int totalDays, readingsPerDay;
    cout << "Enter number of days to monitor: ";
    cin >> totalDays;
    cout << "Enter number of temperature readings per day: ";
    cin >> readingsPerDay;

    // Allocate memory for temperature readings
    float** temperatureData = new float*[totalDays];
    for (int dayIndex = 0; dayIndex < totalDays; dayIndex++) {
        temperatureData[dayIndex] = new float[readingsPerDay];
        cout << "Enter " << readingsPerDay << " temperature readings for day " << dayIndex + 1 << ": ";
        for(int readingIndex = 0; readingIndex < readingsPerDay; readingIndex++) {
            cin >> temperatureData[dayIndex][readingIndex];
        }
    }

    // Calculate daily averages
    float* dailyAverages = new float[totalDays];
    for (int dayIndex = 0; dayIndex < totalDays; dayIndex++) {
        float dailySum = 0;
        for (int readingIndex = 0; readingIndex < readingsPerDay; readingIndex++) {
            dailySum += temperatureData[dayIndex][readingIndex];
        }
        
        dailyAverages[dayIndex] = dailySum / readingsPerDay;
        cout << "Average temperature for day " << dayIndex + 1 << ": " << dailyAverages[dayIndex] << "°C" << endl;
    }

    // Find hottest and coldest days
    int hottestDayIndex = 0, coldestDayIndex = 0;
    for (int dayIndex = 1; dayIndex < totalDays; dayIndex++) {
        if(dailyAverages[dayIndex] > dailyAverages[hottestDayIndex]) {
            hottestDayIndex = dayIndex;
        }
        if(dailyAverages[dayIndex] < dailyAverages[coldestDayIndex]) {
            coldestDayIndex = dayIndex;
        }
    }

    cout << "\nTemperature Analysis Results:" << endl;
    cout << "Hottest day: Day " << hottestDayIndex + 1 
         << " with average temperature: " << dailyAverages[hottestDayIndex] << "°C" << endl;
    cout << "Coldest day: Day " << coldestDayIndex + 1 
         << " with average temperature: " << dailyAverages[coldestDayIndex] << "°C" << endl;

    // Clean up memory
    for (int dayIndex = 0; dayIndex < totalDays; dayIndex++) {
        delete[] temperatureData[dayIndex];
    }
    
    delete[] temperatureData;
    delete[] dailyAverages;

    return 0;
}
