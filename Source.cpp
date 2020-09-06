#include <iostream>
using namespace std;

class Car {
private:
	int enginePower;
	float tireSize;
	string bodyType;
	string  carColor;
	int seatsNumber;
public:
	void ShowInfo() const {
	
		cout << "Type of the body: " << bodyType << endl;
		cout << "Power of the engine: " << enginePower <<" horsepower" << endl;
		cout << "Size of the tire: " << tireSize <<" centimeters" << endl;		
		cout << "Color of the car: " << carColor << endl;
		cout << "Numberof seats: " << seatsNumber << endl;	
	}

	void SetEnginePower(int enginePower)  {
		 this->enginePower=enginePower;
	}

	void SetTireSize(double tireSize)  {
		this->tireSize= tireSize;
	}

	void SetBodyType(string bodyType)  {
		 this->bodyType= bodyType;
	}

	void SetCarColor(string carColor)  {
		 this->carColor= carColor;
	}

	void SetSeatsNumber(int seatsNumber)  {
		 this->seatsNumber= seatsNumber;
	}
};

class AutoTechnology {

protected:
	Car* car;
public:
	
	void CareateNewCar() {
		car = new Car();
	}
	Car* GetCar() const {
		return car;
	}

	virtual void BuildDody() = 0;
	virtual void InstallEngine() = 0;
	virtual void InstallWheels() = 0;
	virtual void Paint() = 0;
	virtual void PreparSalon() = 0;

};

class MiniAutoTechnology : public AutoTechnology 
{
	void BuildDody() {
		car->SetBodyType("Mini");
	}
	void InstallEngine() {
		car->SetEnginePower(110);
	}
	void InstallWheels() {
		car->SetTireSize(20);
	}
	void Paint() {
		car->SetCarColor("Red");
	}
	void PreparSalon() {
		car->SetSeatsNumber(2);
	}
};

class SportsCarTechnology : public AutoTechnology
{
	void BuildDody() {
		car->SetBodyType("Sport car");
	}
	void InstallEngine() {
		car->SetEnginePower(800);
	}
	void InstallWheels() {
		car->SetTireSize(34.5);
	}
	void Paint() {
		car->SetCarColor("Yellow");
	}
	void PreparSalon() {
		car->SetSeatsNumber(4);
	}
};

class SUVTechnology : public AutoTechnology
{
	void BuildDody() {
		car->SetBodyType("SUV");
	}
	void InstallEngine() {
		car->SetEnginePower(220);
	}
	void InstallWheels() {
		car->SetTireSize(24);
	}
	void Paint() {
		car->SetCarColor("Black");
	}
	void PreparSalon() {
		car->SetSeatsNumber(5);
	}
};

class Conveyor {
private:
	AutoTechnology* technology;
public:
	void SetTechnology(AutoTechnology* a) {
		technology = a;
	}

	Car* GetCar() const {
		return technology->GetCar();
	}

	void Build() {
		technology->CareateNewCar();
		technology->BuildDody();
		technology->InstallEngine();
		technology->InstallWheels();
		technology->Paint();
		technology->PreparSalon();
	}
};

int main() {

	Conveyor conveyor;
	conveyor.SetTechnology(new MiniAutoTechnology());

	conveyor.Build();

	Car* car = conveyor.GetCar();

	car->ShowInfo();


	system("pause");
	return 0;
}