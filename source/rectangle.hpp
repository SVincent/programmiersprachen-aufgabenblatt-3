#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "vec2.hpp"
#include "color.hpp"
#include "window.hpp"

class Rectangle {

public:
	Rectangle();
	Rectangle(Vec2 const& vec1, Vec2 const& vec2);
    Rectangle(Vec2 const& vec1, Vec2 const& vec2, Color const& col);

	// getter
	Vec2 getMax() const;
	Vec2 getMin() const;
    Color getColor() const;

	// setter
    void setMax(Vec2 const& vecmax);
    void setMin(Vec2 const& vecmin);
    void setColor(Color const& col);

    // methods
    float circumference() const;
    void draw(Window const& window);
	void draw(Window const& window, Color const& color);
    bool is_inside(Vec2 const& vec);

private:
	Vec2 max_;
	Vec2 min_;
    Color colour_;
};

#endif