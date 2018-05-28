#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <math.h>
#include <iostream>

Circle::Circle() {
    //circle with no parameters: dot at origin
	radius_ = 0;
	center_ = Vec2(0, 0);
    //colour_ = Color();
}

Circle::Circle(float rad) {
	radius_ = rad;
	center_ = Vec2(0, 0);
    //colour_ = Color();
}

Circle::Circle(float rad, Color const& col) {
	radius_ = rad;
	center_ = Vec2(0, 0);
    colour_ = col;
}

Circle::Circle(float rad, Color const& col, Vec2 const& center) {
	radius_ = rad;
	center_ = center;
    colour_ = col;
}

//Task 3.3
Circle::Circle(float rad, Color const& col, Vec2 const& center, std::string const& name) {
	radius_ = rad;
	center_ = center;
    colour_ = col;
    name_ = name;
}

float Circle::getRadius() const{
	return radius_;
}

Vec2 Circle::getCenter() const {
	return center_;
}

void Circle::setRadius(float rad) {
    radius_ = rad;
}

void Circle::setCenter(Vec2 const& cen) {
    center_ = cen;
}

float Circle::circumference() const{
	return (2 * M_PI *radius_);
}

Color Circle::getColor() const {
	return colour_;
}

void Circle::setColor(Color const& col) {
	colour_ = col;
}
//Task 3.3
std::string Circle::getName() const {
    return name_;
}

void Circle::setName(std::string const& nam) {
    name_ = nam;
}

void Circle::print() const {
    std::cout << "name: " << name_ <<"\n";
    std::cout << "- position: X:" << center_.x_ << " Y:" << center_.y_ << "\n";
    std::cout << "- radius:" << radius_ << "\n";
    std::cout << "- colour: R:" << colour_.r_ << " G:" << colour_.g_ << " B:" << colour_.b_ << "\n";
}

bool Circle::is_inside(Vec2 const& vec) {
    //bounding box
	Vec2 bottomleft;
	bottomleft.x_ = center_.x_ - radius_;
	bottomleft.y_ = center_.y_ - radius_;

    if (vec.x_ < bottomleft.x_ || vec.x_ > bottomleft.x_+2*radius_ || vec.y_ < bottomleft.y_ || vec.y_ > bottomleft.y_+2*radius_) {
        return false;
    }
    else {
        return true;
    }
}

//Task 3.4
std::ostream& operator<<(std::ostream& os, Circle const& c_1) {
    c_1.print();
    return os;
}

bool operator<(Circle const& c_1, Circle const& c_2) {
    return c_1.getRadius()< c_2.getRadius();
}

bool operator>(Circle const& c_1, Circle const& c_2) {
    return c_1.getRadius()> c_2.getRadius();
}

bool operator==(Circle const& c1, Circle const& c2) {
    return (c1.getRadius() == c2.getRadius());
}