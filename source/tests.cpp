#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include "vec2.hpp"
#include "mat2.hpp"
#include "rectangle.hpp"
#include "circle.hpp"
#include "color.hpp"

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}


//Since our tests will check the validity of Vec2's, we need some Vec2's which we can compare things to
//these will be re-initialized in every test to ensure the tests work in sequence
Vec2 d; //d for default
Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
Vec2 a2(1.1, 0.5);
Vec2 a3(0.0, 0.0);

// Test for default constructor
TEST_CASE("constructor Vec2()", "[d]") {
	REQUIRE(d.x_ == 0);
	REQUIRE(d.y_ == 0);
}

// Test for constructor with assigned values 
TEST_CASE("constructor Vec2(x,y)", "[Vec2(x,y)]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);
	REQUIRE(a1.x_ == Approx(12.88).epsilon(0.01));
	REQUIRE(a1.y_ == Approx(24.44).epsilon(0.01));
}

// Test for += operator
TEST_CASE("Vec2 operator+=", "[operator+=]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a1.operator+=(a2);
	REQUIRE(a1.x_ == Approx(13.98).epsilon(0.01));
	REQUIRE(a1.y_ == Approx(24.94).epsilon(0.01));

	//Edge cases (a3 = (0,0))
	a1.operator+=(a3);
	REQUIRE(a1.x_ == Approx(13.98).epsilon(0.01));
	a3.operator+=(a1);
	REQUIRE(a3.y_ == Approx(24.94).epsilon(0.01));
	
}

// Test for -= operator
TEST_CASE("Vec2 operator -=", "[operator-=]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a1.operator-=(a2);
	REQUIRE(a1.x_ == Approx(11.78).epsilon(0.01));
	REQUIRE(a1.y_ == Approx(23.94).epsilon(0.01));

	//Edge cases (a3 = (0,0))
	a1.operator-=(a3);
	REQUIRE(a1.x_ == Approx(12.88).epsilon(0.01));
	a3.operator-=(a1);
	REQUIRE(a3.y_ == Approx(-24.44).epsilon(0.01));
}

// Test for *= operator
TEST_CASE("Vec2 operator *=", "[operator*=]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a1.operator*=(1.6);
	REQUIRE(a1.x_ == Approx(20.608).epsilon(0.001));
	REQUIRE(a1.y_ == Approx(165.664).epsilon(0.001));

	//Edge case
	a1.operator*=(0.0);
	REQUIRE(a1.x_ == Approx(0).epsilon(0.001));
	
}

// Test for /= operator
TEST_CASE("Vec2 operator /=", "[operator/=]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a1.operator/=(1.6);
	REQUIRE(a1.x_ == Approx(8.05).epsilon(0.01));
	REQUIRE(a1.y_ == Approx(15.275).epsilon(0.001));

	//Edge case
	a1.operator/=(0.0);
	REQUIRE(a1.x_ == Approx(99999.99).epsilon(0.001)); //the /= operator checks for division by zero, and returns 99999.99 as pseudo-infinity. Better would probably be an actual exception output

}

//Task 2.4

// Test for + operator
TEST_CASE("+ operator", "[operator+]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a3 = operator+(a1, a2);
	REQUIRE(a3.x_ == Approx(13.98).epsilon(0.01));
	REQUIRE(a3.y_ == Approx(24.94).epsilon(0.01));
}

// Test for - operator
TEST_CASE("- operator", "[operator-]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a3 = operator-(a1, a2);
	REQUIRE(a3.x_ == Approx(11.78).epsilon(0.01));
	REQUIRE(a3.y_ == Approx(23.94).epsilon(0.01));

}

// Test for * operator
TEST_CASE("* operator", "[operator*]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  //Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	// Operator *(Vec2, float)
	a3 = operator*(a1, 2.5);
	REQUIRE(a3.x_ == Approx(32.2).epsilon(0.01));
	REQUIRE(a3.y_ == Approx(61.1).epsilon(0.01));

	// Operator *(float, Vec2)
	a3 = operator*(2.5, a1);
	REQUIRE(a3.x_ == Approx(32.2).epsilon(0.01));
	REQUIRE(a3.y_ == Approx(61.1).epsilon(0.01));

	a3 = operator* (0.0, a1);
	REQUIRE(a3.x_ == Approx(0).epsilon(0.01));
	REQUIRE(a3.y_ == Approx(0).epsilon(0.01));
}

// Test for / operator
TEST_CASE("/ operator", "[operator/]") {
  Vec2 a1(12.88, 24.44); //a1 for assigned no. 1, etc.
  Vec2 a2(1.1, 0.5);
  Vec2 a3(0.0, 0.0);

	a3 = operator/(a1, 1.3);
	REQUIRE(a3.x_ == Approx(9.9076923).epsilon(0.0000001));
	REQUIRE(a3.y_ == Approx(18.8).epsilon(0.001));

	a3 = operator/(a2, -5.5);
	REQUIRE(a3.x_ == Approx(-0.2).epsilon(0.001));
	REQUIRE(a3.y_ == Approx(-0.090909).epsilon(0.000001));

	a3 = operator/(a1, 0); //exception, as division by zero is not defined
	REQUIRE(a3.x_ == Approx(99999.99).epsilon(0.001));
	REQUIRE(a3.y_ == Approx(99999.99).epsilon(0.001));
}

// Task 2.5 tests
Mat2 defmat;

// test for Mat2 default constructor
TEST_CASE("default constructor Mat2", "[defmat]") {
	REQUIRE(defmat.n[0][0] == 1);
	REQUIRE(defmat.n[0][1] == 0);
	REQUIRE(defmat.n[1][0] == 0);
	REQUIRE(defmat.n[1][1] == 1);
}

// test for Mat2 user constructor
TEST_CASE("user constructor Mat2", "[testmat]") {
	Mat2 testmat(1, 2, 3, 4);

	REQUIRE(testmat.n[0][0] == 1);
	REQUIRE(testmat.n[0][1] == 2);
	REQUIRE(testmat.n[1][0] == 3);
	REQUIRE(testmat.n[1][1] == 4);
}


// test for *= operator
TEST_CASE("operator*= Mat2", "[operator*=]") {
	Mat2 testmat(1, 2, 3, 4);
	Mat2 testmat2(5, 6, 7, 8);

	testmat*=(testmat2);

	REQUIRE(testmat.n[0][0] == 19);
	REQUIRE(testmat.n[0][1] == 22);
	REQUIRE(testmat.n[1][0] == 43);
	REQUIRE(testmat.n[1][1] == 50);
}

// test for * operator
TEST_CASE("operator* Mat2", "[operator*]") {
	Mat2 testmat(1, 2, 3, 4);
	Mat2 testmat2(5, 6, 7, 8);
	Mat2 matRes;

	matRes = operator*(testmat, testmat2);

	REQUIRE(matRes.n[0][0] == 19);
	REQUIRE(matRes.n[0][1] == 22);
	REQUIRE(matRes.n[1][0] == 43);
	REQUIRE(matRes.n[1][1] == 50);
}

// Task 2.6

// test for determinant calculation
TEST_CASE("Mat2::det() test" "[Mat2::det]") {
	Mat2 testmat(1, 2, 3, 4);
	Mat2 testmat2(5, 6, 7, 9);

	REQUIRE (testmat.det()== -2);
	REQUIRE(testmat2.det() == 3);
}

// test for matrix * vector multiplikation
TEST_CASE("mat2*vec2 test" "[operator*]") {
	Mat2 testmat(1, 2, 3, 4);
	Mat2 testmat2(5, 6, 7, 8);
	Vec2 vec(2,1.4);
	Vec2 vecEmpty;

	Vec2 vecRes;
	vecRes = operator*(testmat, vec);

	REQUIRE(vecRes.x_== Approx(4.8).epsilon(0.01));
	REQUIRE(vecRes.y_ == Approx(11.6).epsilon(0.01));

	vecRes = operator*(vec, testmat2);
	REQUIRE(vecRes.x_ == Approx(49.9).epsilon(0.01));
	REQUIRE(vecRes.y_ == Approx(57.6).epsilon(0.01));

	vecRes = operator*(vecEmpty, testmat2);
	REQUIRE(vecRes.x_ == 0);
	REQUIRE(vecRes.y_ == 0);
}

// test for matrix inversion
TEST_CASE("inverse matrix test" "[inverse(Mat2 m)]") {
	Mat2 testmat(1, 2, 3, 4);
	Mat2 testmat2(5, 6, 7, 8);
	Mat2 matRes;

	matRes = inverse(testmat);
	REQUIRE(matRes.n[0][0] == -2);
	REQUIRE(matRes.n[0][1] == 1);
	REQUIRE(matRes.n[1][0] == 1.5);
	REQUIRE(matRes.n[1][1] == -0.5);

	matRes = inverse(testmat2);
	REQUIRE(matRes.n[0][0] == -4);
	REQUIRE(matRes.n[0][1] == 3);
	REQUIRE(matRes.n[1][0] == 3.5);
	REQUIRE(matRes.n[1][1] == -2.5);
}

// test for transposed matrices
TEST_CASE("transposed matrix test" "[transpose(Mat2 m)]") {
	Mat2 testmat(1, 2, 3, 4);
	Mat2 testmat2(5, 6, 7, 8);
	Mat2 matRes;

	matRes = transpose(testmat);
	REQUIRE(matRes.n[0][0] == 1);
	REQUIRE(matRes.n[0][1] == 3);
	REQUIRE(matRes.n[1][0] == 2);
	REQUIRE(matRes.n[1][1] == 4);

	matRes = transpose(testmat2);
	REQUIRE(matRes.n[0][0] == 5);
	REQUIRE(matRes.n[0][1] == 7);
	REQUIRE(matRes.n[1][0] == 6);
	REQUIRE(matRes.n[1][1] == 8);
}

// test for matrix rotation
TEST_CASE("rotation matrix test" "[make_rotation_mat2(float phi)]") {
	Mat2 matRes;

	//~90°
	matRes = make_rotation_mat2(1.570796);
	REQUIRE(matRes.n[0][0] == Approx(0).epsilon(0.01));
	REQUIRE(matRes.n[0][1] == Approx(-1).epsilon(0.01));
	REQUIRE(matRes.n[1][0] == Approx(1).epsilon(0.01));
	REQUIRE(matRes.n[1][1] == Approx(0).epsilon(0.01));

	// ~123°
	matRes = make_rotation_mat2(2.146755);
	REQUIRE(matRes.n[0][0] == Approx(-0.5446).epsilon(0.0001));
	REQUIRE(matRes.n[0][1] == Approx(-0.8386).epsilon(0.0001));
	REQUIRE(matRes.n[1][0] == Approx(0.8386).epsilon(0.0001));
	REQUIRE(matRes.n[1][1] == Approx(-0.5446).epsilon(0.0001));
}

// Task 2.8
TEST_CASE("Rectangle, circle" "[Rectangle, circle]") {
	
	Circle circle1;
	Circle circle2(12.34);

	REQUIRE(circle1.getRadius() == Approx(0.0).epsilon(0.01));
	REQUIRE(circle2.getRadius() == Approx(12.34).epsilon(0.01));
	
	Vec2 vec1(2.3, 4.5);
	Vec2 vec2(0.0, 1.1);
	class::Rectangle rect(vec1,vec2);

	REQUIRE(rect.getMax().x_ == Approx(2.3).epsilon(0.01));
	REQUIRE(rect.getMin().y_ == Approx(1.1).epsilon(0.01));	
  REQUIRE(rect.circumference() == Approx(11.4).epsilon(0.01));
}