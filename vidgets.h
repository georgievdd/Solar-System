#pragma once
#include "Libs.h"
#include "Colors.h"
//#include "user.h"

void ButtonPress();

char buffer[99999];
int num_quads;
float textsize = 0.0027;
float buttonpressx, buttonpressy;
float ButLevel = -1.85;
float kbutton = 1 / 0.588542;
float mivl = 0.003;
int sletterlen;

const char* to_print(double x);

void print(float x, float y, const char* text, Color color) {
    glPushMatrix();
    glTranslatef(x, y, ButLevel + 0.00001);
    glScalef(textsize, -textsize, 1);
    num_quads = stb_easy_font_print(0, 0, text, NULL, buffer, sizeof(buffer));
    SetColor(color);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(2, GL_FLOAT, 16, buffer);
    glDrawArrays(GL_QUADS, 0, num_quads * 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glPopMatrix();
}

class Button {
public:
    double x1, y1, x2, y2, z;
    Color color;
    const char* text;
    bool down = false;
    bool pressstatus = false;
    int count = 0;


    Button() {}

    Button(float x1, float y1, float x2, float y2, float z, Color color, const char* text) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->color = color;
        this->text = text;
        this->z = z;
    }

    void show() {
        glBegin(GL_TRIANGLE_FAN);
        SetColor(color);
        glVertex3f(x1 + mivl, y1 + mivl, z);
        glVertex3f(x1 + mivl, y2 - mivl, z);
        glVertex3f(x2 - mivl, y2 - mivl, z);
        glVertex3f(x2 - mivl, y1 + mivl, z);
        glEnd();
        print((30 * x1 + x2) / 31, (y1 + y2) / 2, text, white);
    }

    void init(float x1, float y1, float x2, float y2, float z, Color color, const char* text) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->color = color;
        this->text = text;
        this->z = z;
    }

    bool press() {
        buttonpressx = CursorPosX / (float)WIDTH * 2 * kbutton;
        buttonpressy = CursorPosY / (float)HEIGHT * 2;
        bool rezult = (buttonpressx >= x1) && (buttonpressx <= x2) && (buttonpressy >= y1) && (buttonpressy <= y2) && KLICK;
        if (rezult) { pressstatus = true; count++; }
        if (!((buttonpressx >= x1) && (buttonpressx <= x2) && (buttonpressy >= y1) && (buttonpressy <= y2)) && KLICK) {
            pressstatus = false;
            count = 0;
        }
        return rezult;
    }
};


class EditText : public Button {
public:
    String text;
    bool press = false;

    EditText() {}

    EditText(float x1, float y1, float x2, float y2, float z, Color color, String text) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->color = color;
        this->text = text;
        this->z = z;
    }

    void show() {
        glBegin(GL_TRIANGLE_FAN);
        SetColor(color);
        glVertex3f(x1 + mivl, y1 + mivl, z);
        glVertex3f(x1 + mivl, y2 - mivl, z);
        glVertex3f(x2 - mivl, y2 - mivl, z);
        glVertex3f(x2 - mivl, y1 + mivl, z);
        glEnd();
        print((30 * x1 + x2) / 31, (y1 + y2) / 2, text.getstr(), white);

        buttonpressx = KlickPosX / (float)WIDTH * 2 * kbutton;
        buttonpressy = KlickPosY / (float)HEIGHT * 2 - 0.048;
        if ((buttonpressx >= x1 + mivl) && (buttonpressx <= x2 - mivl) && (buttonpressy >= y1 + mivl) && (buttonpressy <= y2 - mivl)) {
            press = true;
        }
        else {
            press = false;
        }
    }

    void init(float x1, float y1, float x2, float y2, float z, Color color, String text) {
        this->x1 = x1;
        this->x2 = x2;
        this->y1 = y1;
        this->y2 = y2;
        this->color = color;
        this->text = text;
        this->z = z;
    }

    long double get_value() {
        return text.to();
    }
};

#include "Res.h"
Button ButtonSetLabel(0.90, -1, 1 / kx, 1, ButLevel - 0.00001, gray.changea(0.4), "");
Button ButtonSetBack(0.90, 0.85, 1.05, 1, ButLevel + 0.0000001, red * 0.25, "Back");

Button ButtonExample1(-1.5, 0.60, -0.15, 0.67, ButLevel, buttoncolor, TextEx1.getstr());
Button ButtonExample2(-1.5, 0.40, -0.15, 0.47, ButLevel, buttoncolor, TextEx2.getstr());
Button ButtonExample3(-1.5, 0.20, -0.15, 0.27, ButLevel, buttoncolor, TextEx3.getstr());
Button ButtonExample4(-1.5, 0.00, -0.15, 0.07, ButLevel, buttoncolor, TextEx4.getstr());
Button ButtonExample5(-1.5, -0.20, -0.15, -0.13, ButLevel, buttoncolor, TextEx5.getstr());

Button ButtonEx1(-0.10, 0.60, -0.03, 0.67, ButLevel, gray, "");
Button ButtonEx2(-0.10, 0.40, -0.03, 0.47, ButLevel, gray, "");
Button ButtonEx3(-0.10, 0.20, -0.03, 0.27, ButLevel, gray, "");
Button ButtonEx4(-0.10, 0.00, -0.03, 0.07, ButLevel, gray, "");
Button ButtonEx5(-0.10, -0.20, -0.03, -0.13, ButLevel, gray, "");
Button ButtonStart(-1, -0.55, -0.6, -0.40, ButLevel, red * Color(0.5, 0.4, 0.3), "          START");

Button   MassText(0.1, 0.55, 0.1, 0.60, ButLevel, black.changea(0), "Mass: ");
Button  SpeedText(0.1, 0.50, 0.1, 0.55, ButLevel, black.changea(0), "Speed: ");
Button  AngleText(0.1, 0.45, 0.1, 0.50, ButLevel, black.changea(0), "Angle: ");
Button      RText(0.1, 0.40, 0.1, 0.45, ButLevel, black.changea(0), "Radius: ");
Button   XPosText(0.1, 0.35, 0.1, 0.40, ButLevel, black.changea(0), "Pos X: ");
Button   YPosText(0.1, 0.30, 0.1, 0.35, ButLevel, black.changea(0), "Pos Y: ");

EditText   MassEdit(0.20, 0.55, 0.60, 0.60, ButLevel, gray, masstext);
EditText  SpeedEdit(0.20, 0.50, 0.60, 0.55, ButLevel, gray, speedtext);
EditText  AngleEdit(0.20, 0.45, 0.60, 0.50, ButLevel, gray, angletext);
EditText      REdit(0.20, 0.40, 0.60, 0.45, ButLevel, gray, rtext);
EditText   XPosEdit(0.20, 0.35, 0.60, 0.40, ButLevel, gray, xtext);
EditText   YPosEdit(0.20, 0.30, 0.60, 0.35, ButLevel, gray, ytext);

Button ButtonSpeedUp(-1.5 * 1, 0.85, -1 * 1.3, 1, ButLevel, gray, "SpeedUp");
Button ButtonSpeedDown(-1 * 1.3, 0.85, -1 * 1.1, 1, ButLevel, gray, "SpeedDown");
Button ButtonPause(-1 * 1.1, 0.85, -1 * 0.9, 1, ButLevel, gray, "Pause");
Button ButtonSettings(1 * 1.55, 0.82, 1 * 1.7, 1, ButLevel, blue_vers, "Par");
Button ButtonMenu(1 * 1.4, 0.82, 1 * 1.55, 1, ButLevel, blue_vers, "Menu");

EditText p1Speed(1, 0.7, 1.1, 0.8, ButLevel, black.changea(0), "");
EditText p2Speed(1, 0.6, 1.1, 0.7, ButLevel, black.changea(0), "");
EditText p3Speed(1, 0.5, 1.1, 0.6, ButLevel, black.changea(0), "");
EditText p4Speed(1, 0.4, 1.1, 0.5, ButLevel, black.changea(0), "");
EditText p5Speed(1, 0.3, 1.1, 0.4, ButLevel, black.changea(0), "");
EditText p6Speed(1, 0.2, 1.1, 0.3, ButLevel, black.changea(0), "");
EditText p7Speed(1, 0.1, 1.1, 0.2, ButLevel, black.changea(0), "");
EditText p8Speed(1, 0.0, 1.1, 0.1, ButLevel, black.changea(0), "");
EditText moonSpeed(1, -0.1, 1.1, 0.0, ButLevel, black.changea(0), "");
EditText titanSpeed(1, -0.2, 1.1, -0.1, ButLevel, black.changea(0), "");
EditText k1Speed(1, -0.4, 1.1, -0.3, ButLevel, black.changea(0), "");
EditText FlightTime(1, -0.5, 1.1, -0.4, ButLevel, black.changea(0), "");

Button InfoLabel(-1 / kx, -1, -0.9, 1, ButLevel - 0.000001, gray.changea(0.3), "");
Button InfoBack(-1 / kx, 0.85, -1.5, 1, ButLevel, red * 0.25, "        Back");
EditText InfoName(-1.65, 0.60, -1, 0.72, ButLevel, gray.changea(0.04), "");
EditText InfoMass(-1.65, 0.50, -1, 0.57, ButLevel, gray.changea(0.04), "");
EditText InfoSpeed(-1.65, 0.40, -1, 0.47, ButLevel, gray.changea(0.04), "");
EditText InfoPosX(-1.65, 0.30, -1, 0.37, ButLevel, gray.changea(0.04), "");
EditText InfoPosY(-1.65, 0.20, -1, 0.27, ButLevel, gray.changea(0.04), "");
EditText InfoRadius(-1.65, 0.10, -1, 0.17, ButLevel, gray.changea(0.04), "");
EditText Info[NumberOfString];


void Key_Callback(GLFWwindow* window, int key, int scancode, int action, int mods) {
    if (action == GLFW_PRESS) {
        if (key == GLFW_KEY_BACKSPACE) {
            if (MassEdit.press) { MassEdit.text -= 1; }
            if (SpeedEdit.press) { SpeedEdit.text -= 1; }
            if (AngleEdit.press) { AngleEdit.text -= 1; }
            if (XPosEdit.press) { XPosEdit.text -= 1; }
            if (YPosEdit.press) { YPosEdit.text -= 1; }
            if (REdit.press) { REdit.text -= 1; }
        }
        else {
            if (MassEdit.press) { MassEdit.text += key; }
            if (SpeedEdit.press) { SpeedEdit.text += key; }
            if (AngleEdit.press) { AngleEdit.text += key; }
            if (XPosEdit.press) { XPosEdit.text += key; }
            if (YPosEdit.press) { YPosEdit.text += key; }
            if (REdit.press) { REdit.text += key; }
        }
    }
}