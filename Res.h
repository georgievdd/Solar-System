#pragma once
#include "Libs.h"

String TextEx1 = "example 1 - you can enter your initial parameters for the asteroid";
String TextEx2 = "example 2 - proposed a variant with a change in the trajectory of the moon";
String TextEx3 = "example 3 - simple layout";
String TextEx4 = "example 4 - a variant with a collision of the moon with an asteroid is proposed";
String TextEx5 = "example 5 - simulation of sending a satellite from earth to mars";

String masstext("0.038");
String speedtext("10090");
String angletext("30.9");
String rtext("1738000");
String xtext("176736022888.57204");
String ytext("-111916791956.600064");

String PlanetName[] = { "Sun", "Mercury", "Venera", "Earth", "Mars", "Jupiter", "Saturn", "Uran", "Neptune", "Moon", "Titan"};

int const NumberOfString = 12;
String PlanetInfo[12][NumberOfString];

/*
PlanetInfo[1][0] = "";
	PlanetInfo[1][1] = "";
	PlanetInfo[1][2] = "";
	PlanetInfo[1][3] = "";
	PlanetInfo[1][4] = "";
	PlanetInfo[1][5] = "";
	PlanetInfo[1][6] = "";
	PlanetInfo[1][7] = "";
	PlanetInfo[1][8] = "";
	PlanetInfo[1][9] = "";
	PlanetInfo[1][10] = "";
	PlanetInfo[1][11] = "";
*/

void InitPlanetInfo() {

	PlanetInfo[0][0] = "  The sun is the source of light, heat, and life";
	PlanetInfo[0][1] = "in the solar system, but it is also the closest";
	PlanetInfo[0][2] = "star to us. We see stars as luminous dots even";
	PlanetInfo[0][3] = "through the strongest telescopes. The Sun is the";
	PlanetInfo[0][4] = "only star in which we observe a disk and various";
	PlanetInfo[0][5] = "phenomena on itand can study them. Studying the";
	PlanetInfo[0][6] = "Sun helps us better understand the nature of the";
	PlanetInfo[0][7] = "stars, even though many of them are very";
	PlanetInfo[0][8] = "different from the Sun. The mass of the Sun is";
	PlanetInfo[0][9] = "333,000 times the mass of the Earth and 750 times";
	PlanetInfo[0][10] = "the mass ofall the planets combined.In diameter,";
	PlanetInfo[0][11] = "it is 109 times larger than the Earth.";

	PlanetInfo[1][0] = "  Mars is smaller than Earth and Venus. It has";
	PlanetInfo[1][1] = "an atmosphere composed mainly of carbon dioxide.";
	PlanetInfo[1][2] = "On its surface there are volcanoes, the largest";
	PlanetInfo[1][3] = "of which, Olympus, exceeds the size of all";
	PlanetInfo[1][4] = "terrestrial volcanoes, reaching a height of";
	PlanetInfo[1][5] = "21.2 km.";
	PlanetInfo[1][6] = "";
	PlanetInfo[1][7] = "";
	PlanetInfo[1][8] = "";
	PlanetInfo[1][9] = "";
	PlanetInfo[1][10] = "";
	PlanetInfo[1][11] = "";

	PlanetInfo[2][0] = "  Venus is the hottest planet in our system,";
	PlanetInfo[2][1] = "with surface temperatures exceeding 400 degrees";
	PlanetInfo[2][2] = "Celsius. The most likely reason for such a high";
	PlanetInfo[2][3] = "temperature is the greenhouse effect due to the";
	PlanetInfo[2][4] = "dense atmosphere rich in carbon dioxide. Venus";
	PlanetInfo[2][5] = "has a thick silicate shell around an iron core";
	PlanetInfo[2][6] = "and an atmosphere. Because of this, Venus is";
	PlanetInfo[2][7] = "often called the 'sister' of the Earth. However,";
	PlanetInfo[2][8] = "the amount of water on Venus is much less than";
	PlanetInfo[2][9] = "Earth's, and its atmosphere is 90 times denser.";
	PlanetInfo[2][10] = "Venus has no satellites.";
	PlanetInfo[2][11] = "";

	PlanetInfo[3][0] = "  The Earth is the largest and densest of the";
	PlanetInfo[3][1] = "terrestrial planets. The question of whether";
	PlanetInfo[3][2] = "life exists anywhere other than Earth remains";
	PlanetInfo[3][3] = "open. Among the terrestrial planets, the Earth";
	PlanetInfo[3][4] = "is unique (primarily due to the hydrosphere).";
	PlanetInfo[3][5] = "Earth's atmosphere is fundamentally different";
	PlanetInfo[3][6] = "from the atmospheres of other planets - it";
	PlanetInfo[3][7] = "contains free oxygen. The Earth has one natural";
	PlanetInfo[3][8] = "satellite, the Moon. The only major satellite";
	PlanetInfo[3][9] = "of the terrestrial planets of the solar system.";
	PlanetInfo[3][10] = "";
	PlanetInfo[3][11] = "";

	PlanetInfo[4][0] = "  Mars is smaller than Earth and Venus. It has";
	PlanetInfo[4][1] = "an atmosphere composed mainly of carbon dioxide.";
	PlanetInfo[4][2] = "On its surface there are volcanoes, the largest";
	PlanetInfo[4][3] = "of which, Olympus, exceeds the size of all";
	PlanetInfo[4][4] = "terrestrial volcanoes, reaching a height of 21.2";
	PlanetInfo[4][5] = "km.";
	PlanetInfo[4][6] = "";
	PlanetInfo[4][7] = "";
	PlanetInfo[4][8] = "";
	PlanetInfo[4][9] = "";
	PlanetInfo[4][10] = "";
	PlanetInfo[4][11] = "";

	PlanetInfo[5][0] = "  Jupiter has a mass of 318 times that of the";
	PlanetInfo[5][1] = "earth, and 2.5 times more massive than all the";
	PlanetInfo[5][2] = "other planetscombined. It consists mainly of";
	PlanetInfo[5][3] = "hydrogen and helium. Jupiter has 67 moons.";
	PlanetInfo[5][4] = "";
	PlanetInfo[5][5] = "";
	PlanetInfo[5][6] = "";
	PlanetInfo[5][7] = "";
	PlanetInfo[5][8] = "";
	PlanetInfo[5][9] = "";
	PlanetInfo[5][10] = "";
	PlanetInfo[5][11] = "";

	PlanetInfo[6][0] = "  Saturn - known for its extensive ring system.";
	PlanetInfo[6][1] = "It is the least dense planet in the solar system";
	PlanetInfo[6][2] = "(its average density is less than that of water).";
	PlanetInfo[6][3] = "Saturn has 62 moons.";
	PlanetInfo[6][4] = "";
	PlanetInfo[6][5] = "";
	PlanetInfo[6][6] = "";
	PlanetInfo[6][7] = "";
	PlanetInfo[6][8] = "";
	PlanetInfo[6][9] = "";
	PlanetInfo[6][10] = "";
	PlanetInfo[6][11] = "";

	PlanetInfo[7][0] = "  Uranus, the seventh planet from the Sun, is";
	PlanetInfo[7][1] = "thelightest of the giant planets. What makes it ";
	PlanetInfo[7][2] = "unique among other planets is that it rotates";
	PlanetInfo[7][3] = "'lying on its side': the inclination of its axis";
	PlanetInfo[7][4] = "of rotation to the plane of the ecliptic is";
	PlanetInfo[7][5] = "approximately 98 degrees. Uranus has 27 moons.";
	PlanetInfo[7][6] = "";
	PlanetInfo[7][7] = "";
	PlanetInfo[7][8] = "";
	PlanetInfo[7][9] = "";
	PlanetInfo[7][10] = "";
	PlanetInfo[7][11] = "";

	PlanetInfo[8][0] = "  Neptune is the last planet in the solar system.";
	PlanetInfo[8][1] = "Although slightly smaller than Uranus, it is more";
	PlanetInfo[8][2] = "massive and therefore denser. Neptune has 14";
	PlanetInfo[8][3] = "known moons.";
	PlanetInfo[8][4] = "";
	PlanetInfo[8][5] = "";
	PlanetInfo[8][6] = "";
	PlanetInfo[8][7] = "";
	PlanetInfo[8][8] = "";
	PlanetInfo[8][9] = "";
	PlanetInfo[8][10] = "";
	PlanetInfo[8][11] = "";

	PlanetInfo[9][0] = "  The Moon is the only natural satellite of the";
	PlanetInfo[9][1] = "Eart. The planet's closest satellite to the Sun,";
	PlanetInfo[9][2] = "since the planets closest to the Sun (Mercury";
	PlanetInfo[9][3] = "and Venus) do not have them. The second brightest";
	PlanetInfo[9][4] = "an object in the Earth's sky after the Sun and";
	PlanetInfo[9][5] = "the fifth largest natural satellite of the planet";
	PlanetInfo[9][6] = "in the solar system. The average distance between";
	PlanetInfo[9][7] = "the centers of the Earth and the Moon is 384,467";
	PlanetInfo[9][8] = "km (0.00257 AU, ~30 Earth diameters).";
	PlanetInfo[9][9] = "";
	PlanetInfo[9][10] = "";
	PlanetInfo[9][11] = "";

	PlanetInfo[10][0] = "Titan (ancient Greek Τιτάν) is the largest satellite";
	PlanetInfo[10][1] = "of Saturn, the second largest satellite of the solar";
	PlanetInfo[10][2] = "system (after Jupiter's satellite Ganymede), the";
	PlanetInfo[10][3] = "only body in the solar system, except for the Earth,";
	PlanetInfo[10][4] = "for which the stable existence of liquid on the";
	PlanetInfo[10][5] = "surface has been proven, and the only satellite of";
	PlanetInfo[10][6] = "the planet with dense atmosphere. Titan was the first";
	PlanetInfo[10][7] = "known moon of Saturn, discovered in 1655 by the Dutch";
	PlanetInfo[10][8] = "astronomer Christian Huygens.";
	PlanetInfo[10][9] = "";
	PlanetInfo[10][10] = "";
	PlanetInfo[10][11] = "";


}