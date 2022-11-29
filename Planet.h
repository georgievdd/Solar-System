#pragma once
#include "Libs.h"
#include "Colors.h"
#include "figures.h"

vec SunPosConst(10000, 10000, 10000);
float highlight = 0.8;

class Planet {
public:
    double mass;
    vec speed;
    vec pos;
    bool borders = false;
    double radius;
    Color color;
    bool Track = true;
    int tracksize = 10000;
    Color** colorarray;
    vec* track;
    int lasttrackpoint = 0;
    bool getinfostatus = false;
    short index;

    bool texturing = false;
    unsigned int texture;
    float KTexture;
    String name;

    Planet() {
        mass = 0;
        pos = vec(0, 0, 0);
        pos = vec(0, 0, 0);
        radius = 1;
        color = defaultcolor;
    }

    Planet(vec pos, vec speed, double mass, double radius, Color color) {
        this->pos = pos;
        this->color = color;
        this->speed = speed;
        this->mass = mass;
        this->radius = radius;
    }
    
    Planet(vec pos, vec speed, double mass, double radius, bool texturing, String name, float KTexture) {
        this->pos = pos;
        this->texturing = texturing;
        this->name = name;
        this->speed = speed;
        this->mass = mass;
        this->radius = radius;
        this->KTexture = KTexture;
    }
    
    Planet(vec pos, vec speed, double mass, double radius, Color color, bool Track) {
        this->pos = pos;
        this->color = color;
        this->speed = speed;
        this->mass = mass;
        this->radius = radius;
        this->Track = Track;
    }

    Planet(vec pos, vec speed, double mass, double radius, Color color, bool Track, bool texturing, String name, float KTexture) {
        this->pos = pos;
        this->color = color;
        this->speed = speed;
        this->mass = mass;
        this->radius = radius;
        this->Track = Track;
        this->texturing = texturing;
        this->name = name;
        this->KTexture = KTexture;
    }

    void show() {
        if (texturing) { DrawTexSphere(pos, radius, texture, KTexture); }
        else { DrawSphere(pos, radius, colorarray, borders); }



        if (Track) {
            SetColor(color);
            for (i = 0; i < lasttrackpoint - 1; i++) {
                glLineWidth(1.5);
                glBegin(GL_LINES);
                    glVertex3f(track[i].x, track[i].y, track[i].z);
                    glVertex3f(track[i + 1].x, track[i + 1].y, track[i + 1].z);
                glEnd();
            }
            if (lasttrackpoint < tracksize && (track[lasttrackpoint - 1] - pos).length() > radius) {
                track[lasttrackpoint++] = pos;
            }
        }
    }

    void inittexture(String name, float KTexture) {
        this->name = name;
        this->KTexture = KTexture;
    }

    void init(vec pos, vec speed, double mass, double radius, Color color, bool Track, bool texturing, String name, float KTexture, short index) {

        track = new vec[tracksize];

        this->pos = pos;
        this->color = color;
        this->speed = speed;
        this->mass = mass;
        this->radius = radius;
        this->Track = Track;
        this->lasttrackpoint = 0;
        this->texturing = texturing;
        this->name = name;
        this->KTexture = KTexture;
        this->index = index;

        colorarray = new Color * [181];
        for (i = 0; i < 181; i++) {
            colorarray[i] = new Color[360];
        }
        for (Va = -90; Va <= 90; Va += ystep) {
            P_r = radius * cos((long double)Va / 180 * M_PI);
            for (a = 0; a < 360; a += xstep) {
                points[Va + 90][a].x = P_r * sin((long double)a / 180 * M_PI);
                points[Va + 90][a].y = P_r * cos((long double)a / 180 * M_PI);
                points[Va + 90][a].z = radius * sin((long double)Va / 180 * M_PI);
            }
        }

        for (Va = 0; Va <= 180 - ystep; Va += ystep) {
            for (a = 0; a < 360; a += xstep) {
                //lost
                if (a >= 360 - xstep) {

                    Pnull = vec(points[Va][a].x, points[Va][a].y, points[Va][a].z);
                    P2 = vec(points[Va + ystep][a].x, points[Va + ystep][a].y, points[Va + ystep][a].z);
                    P1 = vec(points[Va][0].x, points[Va][0].y, points[Va][0].z);
                    v1 = P1 - Pnull;
                    v2 = P2 - Pnull;
                    N = v1.VECT(v2);
                    Lv = SunPosConst - ((v1 + v2) / 2);
                    angle = acos(N.cos_a(Lv));
                    colorarray[Va][a] = (white * (angle / M_PI / highlight) * color); //// color * (angle / M_PI) + white * (angle / M_PI / highlight)
                }
                //other 
                else {

                    Pnull = vec(points[Va][a].x, points[Va][a].y, points[Va][a].z);
                    P2 = vec(points[Va + ystep][a].x, points[Va + ystep][a].y, points[Va + ystep][a].z);
                    P1 = vec(points[Va][a + xstep].x, points[Va][a + xstep].y, points[Va][a + xstep].z);
                    v1 = P1 - Pnull;
                    v2 = P2 - Pnull;
                    N = v1.VECT(v2);
                    Lv = SunPosConst - ((v1 + v2) / 2);
                    angle = acos(N.cos_a(Lv));
                    colorarray[Va][a] = (white * (angle / M_PI / highlight) * color);
                }
            }
        }
    }


    bool iscursoron();


    long double getspeed() {
        return speed.length();
    }

    long double getmass() {
        return mass;
    }

    long double getradius() {
        return radius;
    }

    vec getpos() {
        return pos;
    }
};