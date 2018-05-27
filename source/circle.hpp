#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Circle{

public:
	Circle();
	Circle(float rad);
    Circle(float rad, Color const& color);
	Circle(float rad, Color const& color, Vec2 const& center);

	//getter
	float getRadius() const;
	Vec2 getCenter() const;
    Color getColor() const;

	//setter
    void setRadius(float rad);
    void setCenter(Vec2 const& cen);
    void setColor(Color const& col);

    //methods
    float circumference() const;
	void draw(Window const& window);
	void draw(Window const& window, Color const& color);
    bool is_inside(Vec2 const& vec);

private:
	float radius_;
	Vec2 center_;
    Color colour_;
};

#endif