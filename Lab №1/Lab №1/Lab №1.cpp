#include "pch.h"
#include <iostream>
#include <string>  
#include <vector>  
using namespace std;

class Parquet {
private:
	float length, width;
public:
	Parquet(float length, float width)
	{
		this->length = length;
		this->width = width;
	}
	float getArea()
	{
		return this->length * this->width;
	}
	~Parquet()
	{
	}
};

class Window {
private:
	float width, height;
public:
	Window(float width, float height)
	{
		this->width = width;
		this->height = height;
	}
	float getArea() 
	{
		return this->width * this->height;
	}
	~Window()
	{
	}
};

class Room {
private:
	float length, width, height;
	string color;
	float litersOfPaintPerSquareMeter;
	Parquet *parquet;
	vector<Window*> *windows;
public: 
	Room(float length, float width, float height, string color, float litersOfPaintPerSquareMeter, Parquet &parquet, vector<Window*> windows)
	{
		this->length = length;
		this->width = width;
		this->height = height;
		this->color = color;
		this->litersOfPaintPerSquareMeter = litersOfPaintPerSquareMeter;
		this->parquet = &parquet;
		this->windows = &windows;
	}
	float getVolume()
	{
		return (this->length * this->width * this->height);
	}
	float getAreaOfParquet()
	{
		return this->parquet->getArea();
	}
	float GetAreaOfWindows()
	{
		float sum = 0;
		for (int i = 0; i < this->windows->size(); i++)
			sum += this->windows->at(i)->getArea();
		return sum;
	}
	float getVolumeOfPaint()
	{
		return ((this->height * (this->length * 4)) * this->litersOfPaintPerSquareMeter);
	}
	string getColor()
	{
		return this->color;
	}
	~Room()
	{
		delete parquet;
		delete windows;
	}
};

int main()
{
	Window *w1 = new Window(1.0, 2.0);
	Window *w2 = new Window(3.0, 2.0);
	Window *w3 = new Window(1.0, 2.0);
	vector<Window*> *windows = new vector<Window*>;
	windows->push_back(w1);
	windows->push_back(w2);
	windows->push_back(w3);
	Parquet *p1 = new Parquet(3.0, 2.0);
	Room *r1 = new Room(10.0f, 5.0f, 3.0f, "Red", 1.2f, *p1, *windows);
	cout << r1->getAreaOfParquet() << " " << r1->getColor() << " " << r1->getVolume();
	delete r1;
	// Остальные удаления происходят в деструкторе комнаты 
}
