#define _USE_MATH_DEFINES
#include "circle.hpp"
#include <math.h>

Circle::Circle() {
    //circle with no parameters: dot at origin
	radius_ = 0;
	center_ = Vec2(0, 0);
    //colour_ = Color();
};

Circle::Circle(float rad) {
	radius_ = rad;
	center_ = Vec2(0, 0);
    //colour_ = Color();
};

Circle::Circle(float rad, Color const& col) {
	radius_ = rad;
	center_ = Vec2(0, 0);
    colour_ = col;
};

Circle::Circle(float rad, Color const& col, Vec2 const& center) {
	radius_ = rad;
	center_ = center;
    colour_ = col;
};

float Circle::getRadius() const{
	return radius_;
};

Vec2 Circle::getCenter() const {
	return center_;
};

void Circle::setRadius(float rad) {
    radius_ = rad;
};

void Circle::setCenter(Vec2 const& cen) {
    center_ = cen;
};

float Circle::circumference() const{
	return (2 * M_PI *radius_);
};

Color Circle::getColor() const {
	return colour_;
};

void Circle::setColor(Color const& col) {
	colour_ = col;
};

void Circle::draw(Window const& window) {
    //bounding box (4 line segments)
	Vec2 bottomleft;
	bottomleft.x_ = center_.x_ - radius_;
	bottomleft.y_ = center_.y_ - radius_;
    
    window.draw_line(bottomleft.x_, bottomleft.y_, bottomleft.x_, bottomleft.y_+2*radius_, colour_.r_, colour_.g_, colour_.b_);
    window.draw_line(bottomleft.x_, bottomleft.y_+2*radius_, bottomleft.x_+2*radius_, bottomleft.y_+2*radius_, colour_.r_, colour_.g_, colour_.b_);
    window.draw_line(bottomleft.x_+2*radius_, bottomleft.y_+2*radius_, bottomleft.x_+2*radius_, bottomleft.y_, colour_.r_, colour_.g_, colour_.b_);
    window.draw_line(bottomleft.x_+2*radius_, bottomleft.y_, bottomleft.x_, bottomleft.y_, colour_.r_, colour_.g_, colour_.b_);
    
};

void Circle::draw(Window const& window, Color const& color) {
	//bounding box (4 line segments)
	Vec2 bottomleft;
	bottomleft.x_ = center_.x_ - radius_;
	bottomleft.y_ = center_.y_ - radius_;
    
    window.draw_line(bottomleft.x_, bottomleft.y_, bottomleft.x_, bottomleft.y_+2*radius_, color.r_, color.g_, color.b_);
    window.draw_line(bottomleft.x_, bottomleft.y_+2*radius_, bottomleft.x_+2*radius_, bottomleft.y_+2*radius_, color.r_, color.g_, color.b_);
    window.draw_line(bottomleft.x_+2*radius_, bottomleft.y_+2*radius_, bottomleft.x_+2*radius_, bottomleft.y_, color.r_, color.g_, color.b_);
    window.draw_line(bottomleft.x_+2*radius_, bottomleft.y_, bottomleft.x_, bottomleft.y_, color.r_, color.g_, color.b_);
   
};

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
};