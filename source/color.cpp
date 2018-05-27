#include "color.hpp"

Color::Color() {
	r_ = 0.0;
	g_ = 0.0;
	b_ = 0.0;
};

Color::Color(float x) {

	if (x > 1.0 || x < 0.0) {
		// exception is caught, no values get assigned.
	}
    else {
	    r_ = x;
	    g_ = x;
	    b_ = x;
    }
};

Color::Color(float ri, float gi, float bi) {

	if (ri > 1.0 || gi > 1.0 || bi > 1.0 || ri < 0.0 || gi < 1.0 || bi < 0.0) {
		// exception is caught, no values get assigned
	}
    else {
    	r_ = ri;
	    g_ = gi;
	    b_ = bi;
    }
};