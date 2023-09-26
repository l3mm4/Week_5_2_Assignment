/*
 * Author: Sean J
 * Date: 26SEP2023
 * Assignment: 5-2 Working With Files
 * Class: CS-210
 */

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <iomanip> // for std::setprecision()
#include <cmath>

void FahrenheitToCelsius(std::vector<double>& fahrenheitList, std::vector<double>& celsiusList)
{
	for (int i = 0; i < fahrenheitList.size(); i++)
	{
		double celsius = (fahrenheitList.at(i) - 32) * 5 / 9;
		celsiusList.push_back(std::round(celsius * 100) / 100.0); // round to two decimal places
	}
}

int main()
{
	// Open the input file
	std::ifstream inputFile("FahrenheitTemperature.txt");

	// Check if the file was opened successfully
	if (!inputFile.is_open())
	{
		std::cerr << "Could not open file FahrenheitTemperature.txt" << std::endl;
		return 1;
	}

	// Declare vectors to store the city names and temperatures
	std::vector<std::string> cityList;
	std::vector<double> fahrenheitList;

	// Read data from the input file
	std::string cityName;
	double temperature;
	while (inputFile >> cityName >> temperature)
	{
		cityList.push_back(cityName);
		fahrenheitList.push_back(temperature);
	}

	// Close the input file
	inputFile.close();

	// Convert fahrenheit temperatures to Celsius
	std::vector<double> celsiusList;
	FahrenheitToCelsius(fahrenheitList, celsiusList);

	// Open the output file
	std::ofstream outputFile("CelsiusTemperature.txt");

	// Check if the file was opened successfully
	if (!outputFile.is_open())
	{
		std::cerr << "Could not open file CelsiusTemperatures.txt." << std::endl;
		return 1;
	}

	// Write data to the output file
	for (int i = 0; i < cityList.size(); i++)
	{
		outputFile << cityList.at(i) << " " << celsiusList.at(i) << "\n";
	}

	// Close the output file
	outputFile.close();

	return 0;
}