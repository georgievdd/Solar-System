long double K = 0.000001;
float G = 6.67408;
float t = 0;
float dt = 10000;
////
double CursorPosX, CursorPosY, KlickCtrlPosX, KlickCtrlPosY, KlickShiftPosX, KlickShiftPosY, KlickPosX, KlickPosY;
int WIDTH = 1920; //1920
int HEIGHT = 1080; //1080
bool CtrlPress = false, ShiftPress = false, KLICK;
float kx = (float)HEIGHT / WIDTH;
////
bool TextureInit = true; ///
void INIT();
bool Stop = false;
bool END = false;
int beginning = 0; 
bool MenuShow = false;     ///
bool NoBegin = true;     ///
bool SettingsShow = false;
bool BackgroundShow = true;
float TimeSleep = 0.005;
double MinDistance = 0;

int accuracy = 4;
////

long double X, Y, V, R, M, A;
bool k1init = false;

//for ex5
bool DeparturePermit = false;
bool Depature = false;
bool arrival = false;
bool changedt = true;
double earthmin = 9999999999;
void IsEarthInVertPos();
void PointSearch();
void launch();
void ArrivalCheck();
float start_time;
////
int i, Va, a;
////
#include "Libs.h"
#include "figures.h"
#include "Colors.h"
#include "Planet.h"
///// размеры 1000000 * 1000000;
int const numberofstars = 3000;
float bgAlpha = 0;
vec background[numberofstars];
void ShowBackground();
vec F(Planet*, Planet*);
bool collision(Planet*, Planet*);
void CollisionCheck();
long double Distance(Planet*, Planet*);
long double DistancePos(vec, Planet*);
/////
double GM_K = 10000000000000 * K * K; //10000000000000 * K * K
////
double GetSpeed(Planet*);

/// начальные параметры
double radiusmas[11] = { 696340000 * K, 2439700 * K, 6051800 * K, 6371000 * K, 3390000 * K, 71490000 * K, 60270000 * K, 25560000 * K, 24760000 * K, 1738000 * K, 2175000 * K };
//double radiusmas[11] = { 6963, 2439, 1051, 1371, 3390, 41490, 4027, 2556, 2476, 1738, 2175 };

vec posmas[11] = { vec(0, 0, 0), vec(58000000000 * K, 0, 0), vec(107500000000 * K, 0, 0), vec(147100000000 * K, 0, 0), vec(206700000000 * K, 0, 0), vec(740700000000 * K, 0, 0), 
vec(1350000000000 * K, 0, 0), vec(2730000000000 * K, 0, 0), vec(4450000000000 * K, 0, 0), vec((147100000000 + 406000000)* K, 0, 0), vec((1350000000000 + 1221870000)* K, 0, 0) };

vec speedmas[11] = { vec(0, 0, 0), vec(0, 47870 * K, 0), vec(0, 35020 * K, 0), vec(0, 29670 * K, 0), vec(0, 24130 * K, 0), vec(0, 13070 * K, 0), vec(0, 9690 * K, 0),
vec(0, 6810 * K, 0), vec(0, 5430 * K, 0), vec(0, (29670 + 968.5) * K, 0), vec(0, (9690 + 5570) * K, 0) };

double massmas[11] = { 1989000 * K, 0.32868 * K, 4.81068 * K, 5.9742 * K, 0.63345 * K, 1876.64328 * K, 561.80376 * K, 86.0544 * K, 101.592 * K, 0.0735 * K, 0.135 * K };

Color colormas[11] = { star_color, p1_color, p2_color, p3_color, p4_color, p5_color, p6_color, p7_color, p8_color, moon_color, titan_color };

Planet* k1 = new Planet;
Planet* star = new Planet;
Planet* p1 = new Planet;
Planet* p2 = new Planet;
Planet* p3 = new Planet;
Planet* p4 = new Planet;
Planet* p5 = new Planet;
Planet* p6 = new Planet;
Planet* p7 = new Planet;
Planet* p8 = new Planet;

Planet* moon = new Planet;
Planet* titan = new Planet;

Planet* PlanetMas[] = { star, p1, p2, p3, p4, p5, p6, p7, p8, moon, titan, k1 };


#include "user.h"
#include "interface.h"

void ShowSystem() {
    star->show();
    p1->show();
    p2->show();
    p3->show();
    p4->show();
    p5->show();
    p6->show();
    p7->show();
    p8->show();
    moon->show();
    titan->show();
    if (k1init) { k1->show(); }
}


void INIT() {

    Pos = Pos0;
    Xalpha = 0;
    Yalpha = 0;
    Zalpha = 0;

    dt = 10000;
    Stop = false;
    END = false;
    k1init = false;
    TimeSleep = 0.00499999;
    MinDistance = 0;
    changedt = true;

    DeparturePermit = false;
    Depature = false;
    arrival = false;
    earthmin = 9999999999;

    TimeShow = false;

    star->init(posmas[0], speedmas[0], massmas[0], radiusmas[0], colormas[0], false, false, "sun.jpg", KPlanetTexture, 0);
    p1->init(posmas[1], speedmas[1], massmas[1], radiusmas[1], colormas[1], true, false, "mercury.jpg", KPlanetTexture, 1);
    p2->init(posmas[2], speedmas[2], massmas[2], radiusmas[2], colormas[2], true, false, "venera.jpg", KPlanetTexture, 2);
    p3->init(posmas[3], speedmas[3], massmas[3], radiusmas[3], colormas[3], true, false, "earth.jpg", KPlanetTexture, 3);
    p4->init(posmas[4], speedmas[4], massmas[4], radiusmas[4], colormas[4], true, false, "mars.jpg", KPlanetTexture, 4);
    p5->init(posmas[5], speedmas[5], massmas[5], radiusmas[5], colormas[5], true, false, "jupiter.jpg", KPlanetTexture, 5);
    p6->init(posmas[6], speedmas[6], massmas[6], radiusmas[6], colormas[6], true, false, "saturn.jpg", KPlanetTexture, 6);
    p7->init(posmas[7], speedmas[7], massmas[7], radiusmas[7], colormas[7], true, false, "uran.jpg", KPlanetTexture, 7);
    p8->init(posmas[8], speedmas[8], massmas[8], radiusmas[8], colormas[8], true, false, "neptune.jpg", KPlanetTexture, 8);
    moon->init(posmas[9], speedmas[9], massmas[9], radiusmas[9], colormas[9], true, false, "moon.jpg", KPlanetTexture, 9);
    titan->init(posmas[10], speedmas[10], massmas[10], radiusmas[10], colormas[10], true, false, "moon.jpg", KPlanetTexture, 10);
    k1->inittexture("aster3.jpg", k1KTexture);

    srand(time(NULL));
    for (i = 0; i < numberofstars; i++) {
        float x = (float)(rand() % 3500) / 1000 / kx - 2 / kx;
        float y = (float)(rand() % 3500) / 1000 / kx - 2 / kx;
        background[i].x = x;
        background[i].y = y;
    }

    for (int i = 0; i < NumberOfString; i++) {
        Info[i].init(-1.68, -0.73 + 0.06 * i, -1, -0.66 + 0.06 * i, ButLevel, gray.changea(0), "");
    }

    InitPlanetInfo();
}

void InitLoad() {

    if (SplashScreenTexture != 1) LoadTexture("SplashScreenTexture.jpg", SplashScreenTexture);
    ShowPicture();
    
    if (beginning > 0) {
        LoadTexture(star->name, star->texture);
        LoadTexture(p1->name, p1->texture);
        LoadTexture(p2->name, p2->texture);
        LoadTexture(p3->name, p3->texture);
        LoadTexture(p4->name, p4->texture);
        LoadTexture(p5->name, p5->texture);
        LoadTexture(p6->name, p6->texture);
        LoadTexture(p7->name, p7->texture);
        LoadTexture(p8->name, p8->texture);
        LoadTexture(moon->name, moon->texture);
        LoadTexture(titan->name, titan->texture);
        LoadTexture(k1->name, k1->texture);
    }
}


int main() {

    GLFWwindow* window;
    if (!glfwInit()) {
        return -1;
    }
    window = glfwCreateWindow(WIDTH, HEIGHT, "", NULL, NULL);
    if (!window) {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    ///буфер глубины
    glEnable(GL_DEPTH_TEST);
    SetBackgroundColor(black);

    INIT();

    while (!glfwWindowShouldClose(window)) {
        CreateNewWindow(window);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        srand(time(NULL));
        glPushMatrix();

        if (TextureInit) {
            if (beginning < 2) {
                InitLoad();
                beginning++;
            }
            else if (beginning == 2) {
                MenuShow = true;
                NoBegin = false;
                beginning++;
            }
        }

        if (MenuShow || NoBegin) {
            if (MenuShow) { ShowMenu(); }
        }
        else {
            Sleep(TimeSleep);
            if (BackgroundShow) { ShowBackground(); }
            ShowInterface();
            MoveCamera();
            //////////////////////////////////////////////////////////////////////////////////////////////////////////
            if (!Stop && !END) {
                star->speed += (F(star, p1) + F(star, p2) + F(star, p3) + F(star, p4) + F(star, p5) + F(star, p6) + F(star, p7) + F(star, p8)) * G * GM_K * dt;
                p1->speed += (F(p1, star) + F(p1, p2) + F(p1, p3) + F(p1, p4) + F(p1, p5) + F(p1, p6) + F(p1, p7) + F(p1, p8)) * G * GM_K * dt;
                p2->speed += (F(p2, star) + F(p2, p1) + F(p2, p3) + F(p2, p4) + F(p2, p5) + F(p2, p6) + F(p2, p7) + F(p2, p8)) * G * GM_K * dt;
                p3->speed += (F(p3, star) + F(p3, p1) + F(p3, p2) + F(p3, p4) + F(p3, p5) + F(p3, p6) + F(p3, p7) + F(p3, p8) + F(p3, moon)) * G * GM_K * dt;
                p4->speed += (F(p4, star) + F(p4, p1) + F(p4, p2) + F(p4, p3) + F(p4, p5) + F(p4, p6) + F(p4, p7) + F(p4, p8)) * G * GM_K * dt;
                p5->speed += (F(p5, star) + F(p5, p1) + F(p5, p2) + F(p5, p3) + F(p5, p4) + F(p5, p6) + F(p5, p7) + F(p5, p8)) * G * GM_K * dt;
                p6->speed += (F(p6, star) + F(p6, p1) + F(p6, p2) + F(p6, p3) + F(p6, p4) + F(p6, p5) + F(p6, p7) + F(p6, p8) + F(p6, titan)) * G * GM_K * dt;
                p7->speed += (F(p7, star) + F(p7, p1) + F(p7, p2) + F(p7, p3) + F(p7, p4) + F(p7, p5) + F(p7, p6) + F(p7, p8)) * G * GM_K * dt;
                p8->speed += (F(p8, star) + F(p8, p1) + F(p8, p2) + F(p8, p3) + F(p8, p4) + F(p8, p5) + F(p8, p6) + F(p8, p7)) * G * GM_K * dt;
                moon->speed += (F(moon, star) + F(moon, p3)) * G * GM_K * dt;
                titan->speed += (F(titan, star) + F(titan, p6)) * G * GM_K * dt;
                if (k1init && !arrival) {
                    k1->speed += (F(k1, star) + F(k1, p1) + F(k1, p2) + F(k1, p3) + F(k1, p4) + F(k1, p5) + F(k1, p6) + F(k1, p7) + F(k1, p8) + F(k1, moon) + F(k1, titan)) * G * GM_K * dt;
                    p1->speed += (F(p1, k1)) * G * GM_K * dt;
                    p2->speed += (F(p2, k1)) * G * GM_K * dt;
                    p3->speed += (F(p3, k1)) * G * GM_K * dt;
                    p4->speed += (F(p4, k1)) * G * GM_K * dt;
                    p5->speed += (F(p5, k1)) * G * GM_K * dt;
                    p6->speed += (F(p6, k1)) * G * GM_K * dt;
                    p7->speed += (F(p7, k1)) * G * GM_K * dt;
                    p8->speed += (F(p8, k1)) * G * GM_K * dt;
                    moon->speed += (F(moon, k1)) * G * GM_K * dt;
                    titan->speed += (F(titan, k1)) * G * GM_K * dt;
                }

                star->pos += star->speed * dt;
                p1->pos += p1->speed * dt;
                p2->pos += p2->speed * dt;
                p3->pos += p3->speed * dt;
                p4->pos += p4->speed * dt;
                p5->pos += p5->speed * dt;
                p6->pos += p6->speed * dt;
                p7->pos += p7->speed * dt;
                p8->pos += p8->speed * dt;
                moon->pos += moon->speed * dt;
                titan->pos += titan->speed * dt;
                if (k1init && !arrival) { k1->pos += k1->speed * dt; }


                if (changedt && (ButtonEx4.down || ButtonEx2.down) && Distance(moon, k1) < 819277000 * K) { dt /= 40; changedt = false; }
                if (!changedt && (ButtonEx4.down || ButtonEx2.down) && Distance(moon, k1) > 819277000 * K) { dt *= 40; changedt = true; }

                if (k1init) { CollisionCheck(); }
                if (ButtonEx5.down) { IsEarthInVertPos(); }
                if (DeparturePermit && !Depature) { PointSearch(); }
                if (Depature && !arrival) { ArrivalCheck(); }

                t += dt;
            }
            //////////////////////////////////////////////////////////////////////////////////////////////////////////
            ShowSystem();
        }
        glPopMatrix();
        glfwPollEvents();
        glfwSetKeyCallback(window, Key_Callback);
        glfwSetScrollCallback(window, Scroll_Callback);
        glfwSetMouseButtonCallback(window, Mouse_Callback);
        glfwSetCursorPosCallback(window, Cursor_Pos_Callback);
        glfwSwapBuffers(window);
    }
    glfwTerminate();
    return 0;
}


void ShowBackground() {
    SetColor(white);
    glPointSize(1);
    glPushMatrix();
        glRotatef(-bgAlpha, 0, 0, 1);
        for (i = 0; i < numberofstars; i++) {
            glBegin(GL_POINTS);
                glVertex3f(background[i].x, background[i].y, - 3);
            glEnd();
        }
    glPopMatrix();
    bgAlpha += 0.005;
}


vec F(Planet* p1, Planet* p2) {
    return (p2->pos - p1->pos) * p2->mass / pow((p2->pos - p1->pos).length(), 3);
}

long double Distance(Planet* p1, Planet* p2) {
    return (p1->pos - p2->pos).length();
}


long double DistancePos(vec pos, Planet* p) {
    return (pos - p->pos).length();
}


bool collision(Planet* p1, Planet* p2) {
    if (p1->index == 11) return (Distance(p1, p2) - R * K - radiusmas[p2->index] <= MinDistance);
    return (Distance(p1, p2) - radiusmas[p1->index] - radiusmas[p2->index] <= MinDistance);
}


void CollisionCheck() {
    if (    collision(k1, star) ||
            collision(k1, p1) ||
            collision(k1, p2) ||
(ButtonExample5.down ? false :  collision(k1, p3)) ||
            collision(k1, p4) ||
            collision(k1, p5) ||
            collision(k1, p6) ||
            collision(k1, p7) ||
            collision(k1, p8) ||
(ButtonExample5.down ? false : collision(k1, moon)) ||
            collision(k1, titan)) 
    {
        END = true;
    }
}


void IsEarthInVertPos() {
    if (p3->pos.y >= 143136) { DeparturePermit = true; } //только для K = 0.000001;
}


void PointSearch() {
    if (p3->pos.y <= earthmin) { earthmin = p3->pos.y; }
    else { launch(); }
}


void launch() {
    Depature = true;
    k1init = true;
    k1->init(vec(p3->pos.x + p3->radius, p3->pos.y, 0), vec(V * K, 0 * sin(A) * K, 0), M * K, R * K, k1_color, true, false, "aster.jpg", k1KTexture, 11);
    dt /= 20;
    start_time = t;
    TimeShow = true;
}


void ArrivalCheck() {
    if ((int)(Distance(p4, k1)) == 4905) {
        arrival = true;
        dt *= 4;
    }
}


bool Planet::iscursoron() {
    bool rez = abs((this->pos.x - Pos.x) * WIDTH * kx * (-1) / Pos.z - CursorPosX) <= 8 &&
        abs((this->pos.y - Pos.y) * HEIGHT * (-1) / Pos.z - CursorPosY) <= 8;
    if (rez && KLICK) {
        getinfostatus = true;
        for (int i = 0; i < 12; i++) {
            if (i != this->index) {
                PlanetMas[i]->getinfostatus = false;
            }
        }
    }
    return rez;
}


double GetSpeed(Planet* p) { return p->speed.length(); }