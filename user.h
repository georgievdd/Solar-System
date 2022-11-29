#pragma once
#include "Libs.h"
#include "Colors.h"
#include "figures.h"
#include "vidgets.h"


bool MODE = true;
vec Pos0 = { 0, 0, -(posmas[4].x) / kx};
vec Pos = Pos0;

bool ActionKlickNow = false;

float ANGLE;
float Xalpha = 0, dXalpha = 100, DXalpha = 0, dXalphaSign = 1;
float Zalpha = 0, dZalpha = 0.3;
float Yalpha = 0, dYalpha = 100, DYalpha = 0;
//float Yalpha = 0;
double Alpha, speed, speed_coefficient = 300, Upcoefficient = 5000, Downcoefficient = 5000;
long double CursorMapCoordX();
long double CursorMapCoordY();
void Translate(Planet* p);


void SurfaceDown() {
    Pos.z += Downcoefficient;
}

void SurfaceUp() {
    Pos.z -= Upcoefficient;
}

void MoveCamera() {
    Alpha = -Zalpha / 180 * M_PI;
    if (GetKeyState(VK_LEFT) < 0) { Zalpha -= dZalpha; }
    if (GetKeyState(VK_RIGHT) < 0) { Zalpha += dZalpha; }
    if (GetKeyState(VK_UP) < 0) { dXalpha = 1;  Xalpha -= dXalpha * dXalphaSign; dXalpha = 100; }
    if (GetKeyState(VK_DOWN) < 0) { dXalpha = 1;  Xalpha += dXalpha * dXalphaSign; dXalpha = 100; }
    if (GetKeyState('0') < 0 && GetKeyState(VK_SHIFT) < 0) { Pos = Pos0; Zalpha = 0; Xalpha = 0; Yalpha = 0; }
    
    if (GetKeyState(VK_F1) < 0) {Upcoefficient = 20; Downcoefficient = 20; }
    if (GetKeyState(VK_F2) < 0) { Upcoefficient = 100; Downcoefficient = 100; }
    if (GetKeyState(VK_F3) < 0) {Upcoefficient = 5000; Downcoefficient = 5000; }
    if (GetKeyState(VK_F4) < 0) { Upcoefficient = 50000; Downcoefficient = 50000; }
    if (GetKeyState(VK_F5) < 0) { Upcoefficient = 500000; Downcoefficient = 500000; }
    if (GetKeyState(VK_LBUTTON) < 0) {
        if (GetKeyState(VK_SHIFT) < 0) {
            Pos.x = (-CursorMapCoordX() - KlickShiftPosX);
            Pos.y = (-CursorMapCoordY() - KlickShiftPosY);
        }
        if (GetKeyState(VK_CONTROL) < 0) {
            CtrlPress = true;
            DYalpha = (KlickCtrlPosX - CursorPosX) / (float)WIDTH * dXalpha;
            DXalpha = (KlickCtrlPosY - CursorPosY) / (float)HEIGHT * dYalpha;
        }
    }
    //MOVE
    
    if (MODE) { glRotatef(-Zalpha, 0, 0, 1); }
    if (!MODE) { glRotatef((Yalpha + DYalpha), 0, 1, 0); glRotatef(-(Xalpha + DXalpha), 1, 0, 0); }
    glTranslatef(-Pos.x, -Pos.y, Pos.z);
    if (MODE) { glRotatef(-(Yalpha + DYalpha), 0, 1, 0); glRotatef((Xalpha + DXalpha), 1, 0, 0); }
    if (!MODE) { glRotatef(-Zalpha, 0, 0, 1); }

    if (GetKeyState('1') < 0) { Translate(p1); }
    if (GetKeyState('2') < 0) { Translate(p2); }
    if (GetKeyState('3') < 0) { Translate(p3); }
    if (GetKeyState('4') < 0) { Translate(p4); }
    if (GetKeyState('5') < 0) { Translate(p5); }
    if (GetKeyState('6') < 0) { Translate(p6); }
    if (GetKeyState('7') < 0) { Translate(p7); }
    if (GetKeyState('8') < 0) { Translate(p8); }
    if (GetKeyState('9') < 0) { Translate(moon); }
    if (GetKeyState('0') < 0 && GetKeyState(VK_SHIFT) >= 0) { Translate(titan); }
    if (GetKeyState(VK_SPACE) < 0 && k1init) { Translate(k1); }
}


void Mouse_Callback(GLFWwindow* window, int button, int action, int mods) {
    
    ActionKlickNow = false;

    if (action == GLFW_PRESS) {
        ActionKlickNow = true;
        KLICK = true;
        KlickPosX = CursorPosX;
        KlickPosY = CursorPosY;

        switch (button) {
        case GLFW_MOUSE_BUTTON_LEFT:
            if (GetKeyState(VK_SHIFT) < 0) {
                ShiftPress = true;
                KlickShiftPosX = (-CursorMapCoordX() - Pos.x);
                KlickShiftPosY = (-CursorMapCoordY() - Pos.y);
            }
            if (GetKeyState(VK_CONTROL) < 0) {
                CtrlPress = true;
                KlickCtrlPosX = CursorPosX;
                KlickCtrlPosY = CursorPosY;
            }
            if (GetKeyState(VK_F6) < 0) {
                BackgroundShow = !BackgroundShow;
            }
            if (ButtonPause.press()) {
                Stop = !Stop;
            }
            break;
        case GLFW_MOUSE_BUTTON_RIGHT:
            Stop = !Stop;
            break;
        }

    }

    if (action == GLFW_RELEASE) {

        KLICK = false;

        if (CtrlPress) {
            CtrlPress = false;
            Xalpha += DXalpha; DXalpha = 0;
            Yalpha += DYalpha; DYalpha = 0;
        }
    }
}


void Scroll_Callback(GLFWwindow* window, double x, double y) {
    if (y > 0) {
        Pos.z += Downcoefficient;
    }
    if (y < 0) {
        Pos.z -= Upcoefficient;
    }
}


void Cursor_Pos_Callback(GLFWwindow* window, double x, double y) {
    CursorPosX = x - (float)WIDTH / 2;
    CursorPosY = (float)HEIGHT / 2 - y;
}


long double CursorMapCoordX() {
    return CursorPosX / (float)WIDTH / kx * (-1) * Pos.z;
}


long double CursorMapCoordY() {
    return CursorPosY / (float)HEIGHT / kx * (-1) * Pos.z;
}


void CreateNewWindow(GLFWwindow* window) {
    glfwGetWindowSize(window, &WIDTH, &HEIGHT);
    kx = (float)HEIGHT / WIDTH;
    glViewport(0, 0, WIDTH, HEIGHT);
    glLoadIdentity();
    glFrustum(-0.1, 0.1, -0.1, 0.1, 0.2, 100000000);
    glScalef(kx, 1, 1);
}


void Translate(Planet* p) {
    glTranslatef(-1 * p->pos.x, -1 * p->pos.y, 0);
    if (TextureInit) p->texturing = true;
}