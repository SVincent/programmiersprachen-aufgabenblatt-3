#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include <string>


class Circle{

public:
	Circle();
	Circle(float rad);
    Circle(float rad, Color const& color);
	Circle(float rad, Color const& color, Vec2 const& center);
	Circle(float rad, Color const& color, Vec2 const& center, std::string const& name);


	//getter
	float getRadius() const;
	Vec2 getCenter() const;
    Color getColor() const;
	std::string getName() const;

	//setter
    void setRadius(float rad);
    void setCenter(Vec2 const& cen);
    void setColor(Color const& col);
	void setName(std::string const& nam);

    //methods
    float circumference() const;
    bool is_inside(Vec2 const& vec);
	void print() const;

	//if I put the operator within the class, the operator implicitly receives one additional parameter? 
	//do operators need to be defined in global scope?
	//std::ostream& operator<<(std::ostream& os, Circle const& c_1);


private:
	float radius_;
	Vec2 center_;
    Color colour_;
	std::string name_;
};

//Tasks 3.3

	//operators
    std::ostream& operator<<(std::ostream& os, Circle const& c_1);

	//these are needed to fix error message? did we need to add these operators in the previous worksheet?
	bool operator<(Circle const& c1, Circle const& c2);
	bool operator>(Circle const& c1, Circle const& c2);
	bool operator==(Circle const& c1, Circle const& c2);




#endif