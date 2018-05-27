#include "vec2.hpp"

	Vec2::Vec2() : //constructor with default values
		x_{ 0 },
		y_{ 0 } {}

	Vec2::Vec2(float x, float y) : //constructor with assigned values
		x_{ x },
		y_{ y } {}

	Vec2& Vec2::operator+=(Vec2 const& v) {
		this->x_ += v.x_; //the membervariable x_ gets increased by v.x, with this being the vec2 which the operator gets used on
		this->y_ += v.y_;
		return *this;
	};

	Vec2& Vec2::operator-=(Vec2 const& v) {
		this->x_ -= v.x_;
		this->y_ -= v.y_;
		return *this;
	};

	Vec2& Vec2::operator *=(float s) {
		this->x_ *= s;
		this->y_ *= s;
		return *this;
	};

	Vec2& Vec2::operator /=(float s) {

		if (s == 0.0) {
            //exception, as division by zero isn't defined
            this->x_ = 99999.99;
            this->y_ = 99999.99;
			return *this;
		}
		else {
			this->x_ /= s;
			this->y_ /= s;
			return *this;
		}
	};

	Vec2 operator +(Vec2 const& a, Vec2 const& b) {
		Vec2 temp(a.x_ + b.x_, a.y_ + b.y_);
		return temp;
	};

	Vec2 operator -(Vec2 const& a, Vec2 const& b) {
		Vec2 temp(a.x_ - b.x_, a.y_ - b.y_);
		return temp;
	};

	Vec2 operator *(Vec2 const& v, float s) {
		Vec2 temp(v.x_ * s, v.y_*s);
		return temp;
	};

	Vec2 operator /(Vec2 const& v, float s) {
		if (s == 0) {
            //exception, as division by zero isn't defined
            Vec2 exc(99999.99,99999.99);
			return exc;
		}
		else {
			Vec2 temp(v.x_ / s, v.y_ / s);
			return temp;
		}
	};

	Vec2 operator *(float s, Vec2 const& v){
		Vec2 temp(s * v.x_ , s * v.y_);
		return temp;
	};
