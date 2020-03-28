    #define Phoenix_No_WPI // remove WPI dependencies
	#include "ctre/Phoenix.h"
	#include "ctre/phoenix/platform/Platform.h"
	#include "ctre/phoenix/unmanaged/Unmanaged.h"
	#include <string>
	#include <iostream>
	#include <fstream>
	#include <chrono>
	#include <thread>
	/*#include <SDL2/SDL.h>*/
	#include <unistd.h>
	#include <chrono>
	#include <sys/socket.h>
	#include <netinet/in.h>
	#include <netdb.h>
	#include <stdlib.h>
	#include <stdio.h>
	#include <string.h>
	#include <time.h>
	#include <ctime>
	#include <iomanip>
	#include <sstream>
	

	
	using namespace ctre::phoenix;
	using namespace ctre::phoenix::platform;
	using namespace ctre::phoenix::motorcontrol;
	using namespace ctre::phoenix::motorcontrol::can;
	using namespace std;
	
	/* make some talons for drive train */
	//TalonSRX theTalon1(1);
	//TalonSRX theTalon2(2);
	//TalonSRX theTalon3(3);
	//TalonSRX theTalon4(4);
	//TalonSRX theTalon5(5);
	//TalonSRX theTalon6(6);
	//TalonSRX theTalon7(7);
	//TalonSRX theTalon8(8);
	
	
	void thread1() 
	{ 
		TalonSRX theTalon1(1);
		
		std::ostringstream oss;
				
		string myPayload = "";
		
		while (true) {
			
			//Talon 1
			myPayload = "";
			
			oss.str("");
			auto now = std::chrono::system_clock::now();
			auto time = std::chrono::system_clock::to_time_t(now);
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) -
				std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
		
			oss << std::put_time(std::localtime(&time), "%Y-%m-%d") << "T" << std::put_time(std::localtime(&time), "%H:%M:%S.");
			oss << ms.count();
			auto str = oss.str();
			string myTimeStamp = str;
			
			myPayload = myPayload + "payload::";
			myPayload = myPayload + "537_Motor1*";
			myPayload = myPayload + "{";
			myPayload = myPayload + "\"TimeStamp\": ";
			myPayload = myPayload + "\"" + myTimeStamp + "\"";
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"Temperature\": ";
			myPayload = myPayload + std::to_string(theTalon1.GetTemperature());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"OutputCurrent\": ";
			myPayload = myPayload + std::to_string(theTalon1.GetOutputCurrent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputPercent\": ";
			myPayload = myPayload + std::to_string(theTalon1.GetMotorOutputPercent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon1.GetMotorOutputVoltage());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorPosition\": ";
			myPayload = myPayload + std::to_string(theTalon1.GetSelectedSensorPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon1.GetSelectedSensorVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryArbFeedFwd\": ";
			myPayload = myPayload + std::to_string(theTalon1.GetActiveTrajectoryArbFeedFwd());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"GetActiveTrajectoryPosition\": ";
			myPayload = myPayload + std::to_string(theTalon1.GetActiveTrajectoryPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon1.GetActiveTrajectoryVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"BusVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon1.GetBusVoltage());
			myPayload = myPayload + "}";
			
			myPayload = myPayload + "payload End::";
			
			std::cout << myPayload;
		}//while end
	}//thread1
	
	
	void thread2() 
	{ 
		
		TalonSRX theTalon2(2);
		
		std::ostringstream oss;

		string myPayload = "";
		
		while (true) {
			//Talon 2
			myPayload = "";
			
			oss.str("");
			auto now = std::chrono::system_clock::now();
			auto time = std::chrono::system_clock::to_time_t(now);
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) -
				std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
		
			oss << std::put_time(std::localtime(&time), "%Y-%m-%d") << "T" << std::put_time(std::localtime(&time), "%H:%M:%S.");
			oss << ms.count();
			auto str = oss.str();
			string myTimeStamp = str;
			
			myPayload = myPayload + "payload::";
			myPayload = myPayload + "537_Motor2*";
			myPayload = myPayload + "{";
			myPayload = myPayload + "\"TimeStamp\": ";
			myPayload = myPayload + "\"" + myTimeStamp + "\"";
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"Temperature\": ";
			myPayload = myPayload + std::to_string(theTalon2.GetTemperature());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"OutputCurrent\": ";
			myPayload = myPayload + std::to_string(theTalon2.GetOutputCurrent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputPercent\": ";
			myPayload = myPayload + std::to_string(theTalon2.GetMotorOutputPercent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon2.GetMotorOutputVoltage());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorPosition\": ";
			myPayload = myPayload + std::to_string(theTalon2.GetSelectedSensorPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon2.GetSelectedSensorVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryArbFeedFwd\": ";
			myPayload = myPayload + std::to_string(theTalon2.GetActiveTrajectoryArbFeedFwd());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"GetActiveTrajectoryPosition\": ";
			myPayload = myPayload + std::to_string(theTalon2.GetActiveTrajectoryPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon2.GetActiveTrajectoryVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"BusVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon2.GetBusVoltage());
			myPayload = myPayload + "}";
			
			myPayload = myPayload + "payload End::";
			
			std::cout << myPayload;
		}//while end
	}//thread2
	
	void thread3() 
	{ 

		TalonSRX theTalon3(3);
		
		std::ostringstream oss;
	
		string myPayload = "";
		
		while (true) {
			//Talon 3
			myPayload = "";
			
			oss.str("");
			auto now = std::chrono::system_clock::now();
			auto time = std::chrono::system_clock::to_time_t(now);
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) -
				std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
		
			oss << std::put_time(std::localtime(&time), "%Y-%m-%d") << "T" << std::put_time(std::localtime(&time), "%H:%M:%S.");
			oss << ms.count();
			auto str = oss.str();
			string myTimeStamp = str;
			
			myPayload = myPayload + "payload::";
			myPayload = myPayload + "537_Motor3*";
			myPayload = myPayload + "{";
			myPayload = myPayload + "\"TimeStamp\": ";
			myPayload = myPayload + "\"" + myTimeStamp + "\"";
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"Temperature\": ";
			myPayload = myPayload + std::to_string(theTalon3.GetTemperature());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"OutputCurrent\": ";
			myPayload = myPayload + std::to_string(theTalon3.GetOutputCurrent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputPercent\": ";
			myPayload = myPayload + std::to_string(theTalon3.GetMotorOutputPercent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon3.GetMotorOutputVoltage());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorPosition\": ";
			myPayload = myPayload + std::to_string(theTalon3.GetSelectedSensorPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon3.GetSelectedSensorVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryArbFeedFwd\": ";
			myPayload = myPayload + std::to_string(theTalon3.GetActiveTrajectoryArbFeedFwd());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"GetActiveTrajectoryPosition\": ";
			myPayload = myPayload + std::to_string(theTalon3.GetActiveTrajectoryPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon3.GetActiveTrajectoryVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"BusVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon3.GetBusVoltage());
			myPayload = myPayload + "}";
			
			myPayload = myPayload + "payload End::";
			
			std::cout << myPayload;
		}//while end
	}//thread3
	
	
	void thread4() 
	{ 
		
		TalonSRX theTalon4(4);
		
		std::ostringstream oss;

		string myPayload = "";
		
		while (true) {
			//Talon 4
			myPayload = "";
			
			oss.str("");
			auto now = std::chrono::system_clock::now();
			auto time = std::chrono::system_clock::to_time_t(now);
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) -
				std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
		
			oss << std::put_time(std::localtime(&time), "%Y-%m-%d") << "T" << std::put_time(std::localtime(&time), "%H:%M:%S.");
			oss << ms.count();
			auto str = oss.str();
			string myTimeStamp = str;
			
			myPayload = myPayload + "payload::";
			myPayload = myPayload + "537_Motor4*";
			myPayload = myPayload + "{";
			myPayload = myPayload + "\"TimeStamp\": ";
			myPayload = myPayload + "\"" + myTimeStamp + "\"";
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"Temperature\": ";
			myPayload = myPayload + std::to_string(theTalon4.GetTemperature());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"OutputCurrent\": ";
			myPayload = myPayload + std::to_string(theTalon4.GetOutputCurrent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputPercent\": ";
			myPayload = myPayload + std::to_string(theTalon4.GetMotorOutputPercent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon4.GetMotorOutputVoltage());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorPosition\": ";
			myPayload = myPayload + std::to_string(theTalon4.GetSelectedSensorPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon4.GetSelectedSensorVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryArbFeedFwd\": ";
			myPayload = myPayload + std::to_string(theTalon4.GetActiveTrajectoryArbFeedFwd());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"GetActiveTrajectoryPosition\": ";
			myPayload = myPayload + std::to_string(theTalon4.GetActiveTrajectoryPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon4.GetActiveTrajectoryVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"BusVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon4.GetBusVoltage());
			myPayload = myPayload + "}";
			
			myPayload = myPayload + "payload End::";
			
			std::cout << myPayload;
		}//while end
	}//thread4
	
	
	void thread5() 
	{ 

		TalonSRX theTalon5(5);
		
		std::ostringstream oss;
		
		string myPayload = "";
		
		while (true) {
			//Talon 5
			myPayload = "";
			
			oss.str("");
			auto now = std::chrono::system_clock::now();
			auto time = std::chrono::system_clock::to_time_t(now);
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) -
				std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
		
			oss << std::put_time(std::localtime(&time), "%Y-%m-%d") << "T" << std::put_time(std::localtime(&time), "%H:%M:%S.");
			oss << ms.count();
			auto str = oss.str();
			string myTimeStamp = str;
			
			myPayload = myPayload + "payload::";
			myPayload = myPayload + "537_Motor5*";
			myPayload = myPayload + "{";
			myPayload = myPayload + "\"TimeStamp\": ";
			myPayload = myPayload + "\"" + myTimeStamp + "\"";
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"Temperature\": ";
			myPayload = myPayload + std::to_string(theTalon5.GetTemperature());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"OutputCurrent\": ";
			myPayload = myPayload + std::to_string(theTalon5.GetOutputCurrent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputPercent\": ";
			myPayload = myPayload + std::to_string(theTalon5.GetMotorOutputPercent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon5.GetMotorOutputVoltage());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorPosition\": ";
			myPayload = myPayload + std::to_string(theTalon5.GetSelectedSensorPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon5.GetSelectedSensorVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryArbFeedFwd\": ";
			myPayload = myPayload + std::to_string(theTalon5.GetActiveTrajectoryArbFeedFwd());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"GetActiveTrajectoryPosition\": ";
			myPayload = myPayload + std::to_string(theTalon5.GetActiveTrajectoryPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon5.GetActiveTrajectoryVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"BusVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon5.GetBusVoltage());
			myPayload = myPayload + "}";
			
			myPayload = myPayload + "payload End::";
			
			std::cout << myPayload;
		}//while end
	}//thread5
	
	
	
	void thread6() 
	{ 
		
		TalonSRX theTalon6(6);
		
		std::ostringstream oss;
			
		string myPayload = "";
		
		while (true) {
			//Talon 6
			myPayload = "";
			oss.str("");
			auto now = std::chrono::system_clock::now();
			auto time = std::chrono::system_clock::to_time_t(now);
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) -
				std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
		
			oss << std::put_time(std::localtime(&time), "%Y-%m-%d") << "T" << std::put_time(std::localtime(&time), "%H:%M:%S.");
			oss << ms.count();
			auto str = oss.str();
			string myTimeStamp = str;
			
			myPayload = myPayload + "payload::";
			myPayload = myPayload + "537_Motor6*";
			myPayload = myPayload + "{";
			myPayload = myPayload + "\"TimeStamp\": ";
			myPayload = myPayload + "\"" + myTimeStamp + "\"";
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"Temperature\": ";
			myPayload = myPayload + std::to_string(theTalon6.GetTemperature());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"OutputCurrent\": ";
			myPayload = myPayload + std::to_string(theTalon6.GetOutputCurrent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputPercent\": ";
			myPayload = myPayload + std::to_string(theTalon6.GetMotorOutputPercent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon6.GetMotorOutputVoltage());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorPosition\": ";
			myPayload = myPayload + std::to_string(theTalon6.GetSelectedSensorPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon6.GetSelectedSensorVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryArbFeedFwd\": ";
			myPayload = myPayload + std::to_string(theTalon6.GetActiveTrajectoryArbFeedFwd());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"GetActiveTrajectoryPosition\": ";
			myPayload = myPayload + std::to_string(theTalon6.GetActiveTrajectoryPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon6.GetActiveTrajectoryVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"BusVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon6.GetBusVoltage());
			myPayload = myPayload + "}";
			
			myPayload = myPayload + "payload End::";
			
			std::cout << myPayload;
		}//while end
	}//thread6
	
	
	void thread7() 
	{ 
		
		TalonSRX theTalon7(7);
		
		std::ostringstream oss;

		string myPayload = "";
		
		while (true) {
			//Talon 7
			myPayload = "";
			oss.str("");
			auto now = std::chrono::system_clock::now();
			auto time = std::chrono::system_clock::to_time_t(now);
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) -
				std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
		
			oss << std::put_time(std::localtime(&time), "%Y-%m-%d") << "T" << std::put_time(std::localtime(&time), "%H:%M:%S.");
			oss << ms.count();
			auto str = oss.str();
			string myTimeStamp = str;
			
			myPayload = myPayload + "payload::";
			myPayload = myPayload + "537_Motor7*";
			myPayload = myPayload + "{";
			myPayload = myPayload + "\"TimeStamp\": ";
			myPayload = myPayload + "\"" + myTimeStamp + "\"";
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"Temperature\": ";
			myPayload = myPayload + std::to_string(theTalon7.GetTemperature());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"OutputCurrent\": ";
			myPayload = myPayload + std::to_string(theTalon7.GetOutputCurrent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputPercent\": ";
			myPayload = myPayload + std::to_string(theTalon7.GetMotorOutputPercent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon7.GetMotorOutputVoltage());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorPosition\": ";
			myPayload = myPayload + std::to_string(theTalon7.GetSelectedSensorPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon7.GetSelectedSensorVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryArbFeedFwd\": ";
			myPayload = myPayload + std::to_string(theTalon7.GetActiveTrajectoryArbFeedFwd());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"GetActiveTrajectoryPosition\": ";
			myPayload = myPayload + std::to_string(theTalon7.GetActiveTrajectoryPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon7.GetActiveTrajectoryVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"BusVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon7.GetBusVoltage());
			myPayload = myPayload + "}";
			
			myPayload = myPayload + "payload End::";
			
			std::cout << myPayload;
		}//while end
	}//thread7
	
	
	
	void thread8() 
	{ 
		
		TalonSRX theTalon8(8);
		
		std::ostringstream oss;

		string myPayload = "";
		
		while (true) {
			//Talon 8
			myPayload = "";
			
			oss.str("");
			auto now = std::chrono::system_clock::now();
			auto time = std::chrono::system_clock::to_time_t(now);
			auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(now.time_since_epoch()) -
				std::chrono::duration_cast<std::chrono::seconds>(now.time_since_epoch());
		
			oss << std::put_time(std::localtime(&time), "%Y-%m-%d") << "T" << std::put_time(std::localtime(&time), "%H:%M:%S.");
			oss << ms.count();
			auto str = oss.str();
			string myTimeStamp = str;
			
			myPayload = myPayload + "payload::";
			myPayload = myPayload + "537_Motor8*";
			myPayload = myPayload + "{";
			myPayload = myPayload + "\"TimeStamp\": ";
			myPayload = myPayload + "\"" + myTimeStamp + "\"";
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"Temperature\": ";
			myPayload = myPayload + std::to_string(theTalon8.GetTemperature());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"OutputCurrent\": ";
			myPayload = myPayload + std::to_string(theTalon8.GetOutputCurrent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputPercent\": ";
			myPayload = myPayload + std::to_string(theTalon8.GetMotorOutputPercent());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"MotorOutputVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon8.GetMotorOutputVoltage());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorPosition\": ";
			myPayload = myPayload + std::to_string(theTalon8.GetSelectedSensorPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"SensorVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon8.GetSelectedSensorVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryArbFeedFwd\": ";
			myPayload = myPayload + std::to_string(theTalon8.GetActiveTrajectoryArbFeedFwd());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"GetActiveTrajectoryPosition\": ";
			myPayload = myPayload + std::to_string(theTalon8.GetActiveTrajectoryPosition());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"ActiveTrajectoryVelocity\": ";
			myPayload = myPayload + std::to_string(theTalon8.GetActiveTrajectoryVelocity());
			myPayload = myPayload + ",";
			myPayload = myPayload + "\"BusVoltage\": ";
			myPayload = myPayload + std::to_string(theTalon8.GetBusVoltage());
			myPayload = myPayload + "}";
			
			myPayload = myPayload + "payload End::";
			
			std::cout << myPayload;
		}//while end
	}//thread8
	
	
	
	int main(int argc, char** argv) {
		
		for (int i = 0; i < argc; i++)
		{
			
			string myArg = argv[i];
			
			if (myArg == "1"){
				thread th1(thread1);
				th1.detach();
			}
			
			if (myArg == "2"){
				thread th2(thread2);
				th2.detach();
			}

			if (myArg == "3"){
				thread th3(thread3);
				th3.detach();
			}
			
			if (myArg == "4"){
				thread th4(thread4);
				th4.detach();
			}
			
			if (myArg == "5"){
				thread th5(thread5);
				th5.detach();
			}
			
			if (myArg == "6"){
				thread th6(thread6);
				th6.detach();
			}
			
			if (myArg == "7"){
				thread th7(thread7);
				th7.detach();
			}
			
			if (myArg == "8"){
				thread th8(thread8);
				th8.detach();
			}

		}//for end


		
		while (true) 
		{
		}
	
	}
