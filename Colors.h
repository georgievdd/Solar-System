#pragma once
#include "Libs.h"
class Color {
public:
	float r = 0;
	float g = 0;
	float b = 0;
	float a = 1;

	Color() {}

	Color(float r, float g, float b, float a) {
		this->r = r;
		this->g = g;
		this->b = b;
		this->a = a;
	}

	Color(float r, float g, float b) {
		this->r = r;
		this->g = g;
		this->b = b;
	}

	Color correction() {
		return Color(pow(r, 1 / 2.2), pow(g, 1 / 2.2), pow(b, 1 / 2.2), pow(a, 1 / 2.2));
	}

	Color changea(float a) {
		return Color(r, g, b, a);
	}

	Color operator * (float c) {
		return Color(r * c, g * c, b * c, 1);
	}

	Color operator / (float c) {
		return Color(r / c, g / c, b / c, 1);
	}

	bool operator ==(Color color) {
		return this->r == color.r && this->g == color.g && this->b == color.b;
	}

	void operator = (Color color) {
		r = color.r;
		g = color.g;
		b = color.b;
		a = color.a;
	}

	Color operator * (Color color) {
		return Color(r * color.r, g * color.g, b * color.b, 1);
	}

	Color operator + (Color color) {
		return Color(r + color.r, g + color.g, b + color.b, 1);
	}

};

Color black(0, 0, 0);
Color red(1, 0, 0);
Color green(0, 1, 0);
Color blue(0, 0, 1);
Color yellow(1, 1, 0);
Color gray(0.51, 0.54, 0.59);
Color cube_color(0.78, 0, 0.4, 0.3);
Color white(1, 1, 1);
Color sp(0.26, 0.71, 0.52);
Color buttoncolor(0.27, 0.29, 0.08);
Color defaultcolor(0.25, 0.63, 0.38);
Color star_color = yellow;
Color p1_color(0.74, 0.53, 0.32);
Color p2_color(0.85, 0.41, 0.14);
Color p3_color(0.4, 1, 0.6);
Color p4_color(1, 0.35, 0.25);
Color p5_color(0.91, 0.64, 0.46);
Color p6_color(0.73, 0.49, 0.34);
Color p7_color(0.1, 0.56, 0.54);
Color p8_color(0.15, 0.81, 0.78);
Color moon_color = white;
Color titan_color = white;
Color k1_color(1, 0.38, 0);
Color blue_vers(0.18, 0.18, 0.27);


void SetColor(Color color) {
	glColor4f(color.r, color.g, color.b, color.a);
}

void SetBackgroundColor(Color color) {
	glClearColor(color.r, color.g, color.b, 1);
}

Color colrand() {
	srand(time(NULL));
	float r = (float)(10 + rand() % 91) / 100;
	float g = (float)(10 + rand() % 91) / 100;
	float b = (float)(10 + rand() % 91) / 100;
	return Color(r, g, b);
}