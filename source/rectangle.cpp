#define _USE_MATH_DEFINES
#include "rectangle.hpp"
#include <math.h>

Rectangle::Rectangle() {
	Vec2 vec; //empty Vec2 - dot at origin
	max_ = vec;
	min_ = vec;
    colour_ = Color();
};

Rectangle::Rectangle(Vec2 const& vec1, Vec2 const& vec2) {
	max_ = vec1;
	min_ = vec2;
    colour_ = Color();
};

Rectangle::Rectangle(Vec2 const& vec1, Vec2 const& vec2, Color const& col) {
	max_ = vec1;
	min_ = vec2;
	colour_ = col;
};

Vec2 Rectangle::getMax() const{
	return max_;
};

Vec2 Rectangle::getMin() const{
	return min_;
};

void Rectangle::setMax(Vec2 const& vec) {
    max_ = vec;
};

void Rectangle::setMin(Vec2 const& vec) {
    min_ = vec;
};

float Rectangle::circumference() const {
    float height = max_.y_ - min_.y_;
	float width = max_.x_ - min_.x_;
	return 2 * (height + width);
};

void Rectangle::setColor(Color const& col) {
	colour_ = col;
};

void Rectangle::draw(Window const& window){
    
	window.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, colour_.r_, colour_.g_, colour_.b_);
    window.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, colour_.r_, colour_.g_, colour_.b_);
    window.draw_line(max_.x_, max_.y_, max_.x_, min_.y_, colour_.r_, colour_.g_, colour_.b_);
    window.draw_line(max_.x_, min_.y_, min_.x_, min_.y_, colour_.r_, colour_.g_, colour_.b_);
    
};


void Rectangle::draw(Window const& window, Color const& color) {
    
	window.draw_line(min_.x_, min_.y_, min_.x_, max_.y_, color.r_, color.g_, color.b_);
    window.draw_line(min_.x_, max_.y_, max_.x_, max_.y_, color.r_, color.g_, color.b_);
    window.draw_line(max_.x_, max_.y_, max_.x_, min_.y_, color.r_, color.g_, color.b_);
    window.draw_line(max_.x_, min_.y_, min_.x_, min_.y_, color.r_, color.g_, color.b_);
    
};

bool Rectangle::is_inside(Vec2 const& vec) {
    if (vec.x_ < min_.x_ || vec.x_ > max_.x_ || vec.y_ < min_.y_ || vec.y_ > max_.y_) {
        return false;
    }
    else {
        return true;
    }
};