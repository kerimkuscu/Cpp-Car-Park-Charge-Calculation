#include <iostream>
#include <stdio.h>
#include <math.h>
#include <string>
#include <stdlib.h>
#include <windows.h>
#include <conio.h>
#include <time.h>
#include <unistd.h>
#include "carpark.h"
using namespace std;
	
	float CarPark::CalculatePrice(int entH,int entM, int exH, int exM, int vType){
		
			if(entH > 24 || entH < 0 ){
				cout << "Please enter enterance hour in correct form"<<"\n"<<"Restarting in 5 seconds";
				CarPark::Restart();
				return -1;
			}else if(entM > 60 || entM < 0){
				cout << "Please enter enterance minute in correct form"<<"\n"<<"Restarting in 5 seconds";
				CarPark::Restart();	
				return -1 ;
			}else if(exH > 24 || exH < 0 ){
				cout << "Please enter exit hour in correct form"<<"\n"<<"Restarting in 5 seconds";
				CarPark::Restart();
				return -1;
			}else if(exM > 60 || exM < 0){
				cout << "Please enter exit minute in correct form"<<"\n"<<"Restarting in 5 seconds";
				CarPark::Restart();
				return -1;	
			}
			else if(exH < entH){
				cout << "Please enter a valid time period"<<"\n"<<"Restarting in 5 seconds";
				CarPark::Restart();
				return -1;
			}
			int hDiff = exH-entH;
			int minDiff = exM - entM;
			int extra = 1;
			if(minDiff < 0){
				minDiff = minDiff * -1;
				
			}
			if(minDiff > 30){
				extra = 1.5;
			}
			switch(vType){
				case 1: return CarPark::_suvPrice * hDiff * extra; break;
				case 2: return CarPark::_truckPrice * hDiff * extra; break;
				case 3: return CarPark::_sedanPrice * hDiff * extra; break;
				case 4: return CarPark::_normalCarPrice * hDiff *extra; break;
				default:
				 cout << "Please enter vehicale type in correct form"<<"\n"<<"Restarting in 5 seconds";
				CarPark::Restart();
				return -1;
				break;
			}
		
	} 
	void CarPark::Initiate(){
		int vehicaleType;
		cout << "Please enter your car type"<<"\nFor SUV 1\nFor Truck 2\nFor Sedan 3\nFor Normal Car 4" << "\n";
		cin >>vehicaleType;
		cout << "Please enter enterance hour" <<"\n";
		int entHour;
		cin >> entHour;
		int entMin;
		cout <<"Please enter enterance minute" <<"\n";
		cin >> entMin;
		int exitHour;
		cout << "Please enter exit hour" <<"\n";
		cin >> exitHour;
		int exitMinute;
		cout <<"Please enter exit minute" <<"\n";
		cin >> exitMinute;
		float price = CarPark::CalculatePrice(entHour,entMin,exitHour,exitMin,vehicaleType);
		cout << "It costs "<< price << "$" <<"\nRestarting in 5..";
		CarPark::Restart();
	}
	void CarPark::Restart(){
		sleep(5);
		system("cls");
		CarPark::Initiate();
	}
