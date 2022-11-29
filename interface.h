#pragma once
#include "Libs.h"
#include "Colors.h"
#include "vidgets.h"

void MenuDataProcessing();
void Animation();
void ShowPicture();
void ShowSettings();
void ShowInfo(Planet*);
void SetInfo(Planet*);
void ShowInfoMas();
bool TimeShow = false;


void ShowInterface() {
    Animation();
    ButtonSpeedUp.show();
    ButtonSpeedDown.show();
    ButtonPause.show();
    ButtonSettings.show();
    ButtonMenu.show();
    if (SettingsShow) { ShowSettings(); }

    ButtonPress();
}


void ShowSettings() {
    ButtonSetLabel.show();
    ButtonSetBack.show();

    p1Speed.text = String("mercury speed = ") + to_String(GetSpeed(p1) / K, accuracy) + String(" m/s");
    p2Speed.text = String("venera speed =  ") + to_String(GetSpeed(p2) / K, accuracy) + String(" m/s");
    p3Speed.text = String("earth speed =   ") + to_String(GetSpeed(p3) / K, accuracy) + String(" m/s");
    p4Speed.text = String("mars speed =    ") + to_String(GetSpeed(p4) / K, accuracy) + String(" m/s");
    p5Speed.text = String("jupiter speed = ") + to_String(GetSpeed(p5) / K, accuracy) + String(" m/s");
    p6Speed.text = String("saturn speed =  ") + to_String(GetSpeed(p6) / K, accuracy) + String(" m/s");
    p7Speed.text = String("uran speed =    ") + to_String(GetSpeed(p7) / K, accuracy) + String(" m/s");
    p8Speed.text = String("neptune speed = ") + to_String(GetSpeed(p8) / K, accuracy) + String(" m/s");
    moonSpeed.text = String("moon speed =    ") + to_String(GetSpeed(moon) / K, accuracy) + String(" m/s");
    titanSpeed.text = String("titan speed =   ") + to_String(GetSpeed(titan) / K, accuracy) + String(" m/s");
    if (k1init) k1Speed.text = (ButtonEx5.down ? String("to Mars speed =   ") : String("aster speed =   ")) + to_String(GetSpeed(k1) / K, accuracy) + String(" m/s");
    if (TimeShow) {
        if (!arrival) FlightTime.text = String("Flight Time = ") + to_String((t - start_time) / 86400, accuracy) + String("days");
        FlightTime.show();
    }

    p1Speed.show();
    p2Speed.show();
    p3Speed.show();
    p4Speed.show();
    p5Speed.show();
    p6Speed.show();
    p7Speed.show();
    p8Speed.show();
    moonSpeed.show();
    titanSpeed.show();
    if (k1init) k1Speed.show();

    if (ButtonSetBack.press()) { 
        SettingsShow = !SettingsShow; }
}


void ShowMenu() {

    ShowPicture();

    if (!ButtonStart.press()) {
        ButtonEx1.down = false;
        ButtonEx2.down = false;
        ButtonEx3.down = false;
        ButtonEx4.down = false;
        ButtonEx5.down = false;
    }

    ButtonExample1.show();
    ButtonExample2.show();
    ButtonExample3.show();
    ButtonExample4.show();
    ButtonExample5.show();

    ButtonEx1.show();
    ButtonEx2.show();
    ButtonEx3.show();
    ButtonEx4.show();
    ButtonEx5.show();

    ButtonStart.show();

    if (ButtonEx1.pressstatus) {
        MassText.show();
        MassEdit.show();
        SpeedText.show();
        SpeedEdit.show();
        AngleText.show();
        AngleEdit.show();
        RText.show();
        REdit.show();
        XPosText.show();
        XPosEdit.show();
        YPosText.show();
        YPosEdit.show();
        ButtonEx1.down = true;
    }
    else { ButtonEx1.down = false; }

    ButtonEx1.press();

    if (ButtonEx2.press()) { ButtonEx2.down = true; }

    if (ButtonEx3.press()) { ButtonEx3.down = true; }

    if (ButtonEx4.press()) { ButtonEx4.down = true; }

    if (ButtonEx5.press()) { ButtonEx5.down = true; }


    if (ButtonEx1.pressstatus) { ButtonEx1.color = red * 0.5; ButtonEx1.down = true; }
    else { ButtonEx1.color = gray; }

    if (ButtonEx2.pressstatus) { ButtonEx2.color = red * 0.5; ButtonEx2.down = true;}
    else { ButtonEx2.color = gray; }

    if (ButtonEx3.pressstatus) { ButtonEx3.color = red * 0.5;ButtonEx3.down = true; }
    else { ButtonEx3.color = gray; }

    if (ButtonEx4.pressstatus) { ButtonEx4.color = red * 0.5;ButtonEx4.down = true; }
    else { ButtonEx4.color = gray; }

    if (ButtonEx5.pressstatus) { ButtonEx5.color = red * 0.5; ButtonEx5.down = true;}
    else { ButtonEx5.color = gray; }




    if (MassEdit.press) { MassEdit.color = gray / 1.5; ButtonEx1.pressstatus = true; }
    else { MassEdit.color = gray; }

    if (SpeedEdit.press) { SpeedEdit.color = gray / 1.5; ButtonEx1.pressstatus = true; }
    else { SpeedEdit.color = gray; }

    if (XPosEdit.press) { XPosEdit.color = gray / 1.5; ButtonEx1.pressstatus = true; }
    else { XPosEdit.color = gray; }

    if (YPosEdit.press) { YPosEdit.color = gray / 1.5; ButtonEx1.pressstatus = true; }
    else { YPosEdit.color = gray; }

    if (AngleEdit.press) { AngleEdit.color = gray / 1.5; ButtonEx1.pressstatus = true; }
    else { AngleEdit.color = gray; }

    if (REdit.press) { REdit.color = gray / 1.5; ButtonEx1.pressstatus = true; }
    else { REdit.color = gray; }


    if (ButtonStart.press()) {
        MenuDataProcessing();
    }
}


void ButtonPress() {
    if (ButtonSpeedUp.press() || TimeSleep < 0.005) {
        ButtonSpeedUp.color = red;
        TimeSleep >= 0.005 ? TimeSleep /= 1.1 : 0;
    } 
    else { ButtonSpeedUp.color = gray; }

    if (ButtonSpeedDown.press()) {
        ButtonSpeedDown.color = red;
        TimeSleep *= 1.1;
    }
    else { ButtonSpeedDown.color = gray; }

    if (ButtonMenu.press()) {
        ButtonMenu.color = red;
        MenuShow = true;
    }
    else { ButtonMenu.color = gray; }

    if (ButtonSettings.press()) {
        ButtonSettings.color = red;
        SettingsShow = true;
    }
    else { ButtonSettings.color = gray; }

    if (Stop) { ButtonPause.color = red; }
    else { ButtonPause.color = gray; }

}

/// отладить ///
void MenuDataProcessing() {
    INIT();
    MenuShow = false;
    /// 1 not
    if (ButtonEx1.down) {
        k1init = true;
        X = XPosEdit.text.to();
        Y = YPosEdit.text.to();
        A = AngleEdit.text.to() * M_PI / 180;
        V = SpeedEdit.text.to();
        R = REdit.text.to();
        M = MassEdit.text.to();
    }
    if (ButtonEx2.down) {
        k1init = true;
        X = 176736022888.57204 * 1;
        Y = 69947994972.87504 * 2 * 0.8;
        A = 226.9 * M_PI / 180;
        V = 23090;
        R = 1738000;
        M = 4.076 / 2;
    }
    if (ButtonEx3.down) {
        k1init = true;
        X = -1 * 100000000000 * 3;
        Y = -0.5 * 100000000000 / 5 * 3;
        A = 70 * M_PI / 180;
        V = 35000;
        R = 1738000;
        M = 5.976;
    }
    if (ButtonEx4.down) {
        k1init = true;
        X = 176736022888.57204 * 1;
        Y = 69947994972.87504 * 2 * 0.8;
        A = 226.9 * M_PI / 180;
        V = 23088.8;
        R = 1738000;
        M = 1.076 / 2;
    }
    if (ButtonEx5.down) {
        dt = 50000;
        M = 0.0000000000000000003;
        V = 58900.000023;
        A = 2.86 / 180 * M_PI;
        R = 100;
    }

    if (k1init) {
        k1->init(vec(X * K, Y * K, 0), vec(V * cos(A) * K, V * sin(A) * K, 0), M * K, R * K, white, true, false, "aster.jpg", k1KTexture, 11);
    }

    p1->tracksize = 2000 * 10000 / dt;
    p2->tracksize = 2500 * 10000 / dt;
    p3->tracksize = 3000 * 10000 / dt;
    p4->tracksize = 4500 * 10000 / dt;
    for (int i = 5; i < 12; i++) {
        PlanetMas[i]->tracksize = 20000;
    }

}


const char* to_print(double x) {
    string* sletter = new string;
    *sletter = to_string(x);
    sletter->erase(sletter->find('.'));
    sletterlen = sletter->length();
    char* cletter = new char[sletterlen];
    for (i = 0; i < sletterlen; i++) {
        cletter[i] = (*sletter)[i];
    }
    delete sletter;
    return cletter;
}

int TexturingThreshold = 1000;
void Animation() {
    //aiming at an object
    
    if (star->iscursoron()) {
        star->radius = radiusmas[0] * 10 * Pos.z / Pos0.z;
        if (TextureInit) star->texturing = true;
    }
    else {
        star->radius = radiusmas[0];
        star->texturing = false;
        if (DistancePos(Pos, star) < star->radius * TexturingThreshold) { if (TextureInit) star->texturing = true; }
    }

    if (p1->iscursoron()) {
        p1->radius = radiusmas[1] * 3000 * Pos.z / Pos0.z;
        if (TextureInit) p1->texturing = true;
    }
    else {
        p1->radius = radiusmas[1];
        p1->texturing = false;
        if (DistancePos(Pos, p1) < p1->radius * TexturingThreshold) { if (TextureInit) p1->texturing = true; }
    }

    if (p2->iscursoron()) {
        p2->radius = radiusmas[2] * 1300 * Pos.z / Pos0.z;
        if (TextureInit) p2->texturing = true;
    }
    else {
        p2->radius = radiusmas[2];
        p2->texturing = false;
        if (DistancePos(Pos, p2) < p2->radius * TexturingThreshold) { if (TextureInit) p2->texturing = true; }
    }

    if (p3->iscursoron()) {
        p3->radius = radiusmas[3] * 1300 * Pos.z / Pos0.z;
        if (TextureInit) p3->texturing = true;
    }
    else {
        p3->radius = radiusmas[3];
        p3->texturing = false;
        if (DistancePos(Pos, p3) < p3->radius * TexturingThreshold) { if (TextureInit) p3->texturing = true; }
    }

    if (p4->iscursoron()) {
        p4->radius = radiusmas[4] * 2000 * Pos.z / Pos0.z;
        if (TextureInit) p4->texturing = true;
    }
    else {
        p4->radius = radiusmas[4];
        p4->texturing = false;
        if (DistancePos(Pos, p4) < p4->radius * TexturingThreshold) { if (TextureInit) p4->texturing = true; }
    }

    if (p5->iscursoron()) {
        p5->radius = radiusmas[5] * 165 * Pos.z / Pos0.z;
        if (TextureInit) p5->texturing = true;
    }
    else {
        p5->radius = radiusmas[5];
        p5->texturing = false;
        if (DistancePos(Pos, p5) < p5->radius * TexturingThreshold) { if (TextureInit) p5->texturing = true; }

    }

    if (p6->iscursoron()) {
        p6->radius = radiusmas[6] * 200 * Pos.z / Pos0.z;
        if (TextureInit) p6->texturing = true;
    }
    else {
        p6->radius = radiusmas[6];
        p6->texturing = false;
        if (DistancePos(Pos, p6) < p6->radius * TexturingThreshold) { if (TextureInit) p6->texturing = true; }
    }

    if (p7->iscursoron()) {
        p7->radius = radiusmas[7] * 400 * Pos.z / Pos0.z;
        if (TextureInit) p7->texturing = true;
    }
    else {
        p7->radius = radiusmas[7];
        p7->texturing = false;
        if (DistancePos(Pos, p7) < p7->radius * TexturingThreshold) { if (TextureInit) p7->texturing = true; }
    }

    if (p8->iscursoron()) {
        p8->radius = radiusmas[8] * 400 * Pos.z / Pos0.z;
        if (TextureInit) p8->texturing = true;
    }
    else {
        p8->radius = radiusmas[8];
        p8->texturing = false;
        if (DistancePos(Pos, p8) < p8->radius * TexturingThreshold) { if (TextureInit) p8->texturing = true; }
    }

    if (moon->iscursoron()) {
        moon->radius = radiusmas[9] * 4000 * Pos.z / Pos0.z;
        if (TextureInit) moon->texturing = true;
    }
    else {
        moon->radius = radiusmas[9];
        moon->texturing = false;
        if (DistancePos(Pos, moon) < moon->radius * TexturingThreshold) { if (TextureInit) moon->texturing = true; }
    }

    if (titan->iscursoron()) {
        titan->radius = radiusmas[10] * 4000 * Pos.z / Pos0.z;
        if (TextureInit) titan->texturing = true;
    }
    else {
        titan->radius = radiusmas[10];
        titan->texturing = false;
        if (DistancePos(Pos, titan) < titan->radius * TexturingThreshold) { if (TextureInit) titan->texturing = true; }
    }

    if (k1init) {
        if (k1->iscursoron()) {
            k1->radius = R * K * 4000 * Pos.z / Pos0.z;
            if (TextureInit) k1->texturing = true;
        }
        else {
            k1->radius = R * K;
            k1->texturing = false;
            if (DistancePos(Pos, k1) < k1->radius * TexturingThreshold) { if (TextureInit) k1->texturing = true; }
        }
    }


    if (star->getinfostatus) { ShowInfo(star); }
    if (p1->getinfostatus) { ShowInfo(p1); }
    if (p2->getinfostatus) { ShowInfo(p2); }
    if (p3->getinfostatus) { ShowInfo(p3); }
    if (p4->getinfostatus) { ShowInfo(p4); }
    if (p5->getinfostatus) { ShowInfo(p5); }
    if (p6->getinfostatus) { ShowInfo(p6); }
    if (p7->getinfostatus) { ShowInfo(p7); }
    if (p8->getinfostatus) { ShowInfo(p8); }
    if (moon->getinfostatus) { ShowInfo(moon); }
    if (titan->getinfostatus) { ShowInfo(titan); }
    if (k1->getinfostatus) { ShowInfo(k1); }
}

unsigned int SplashScreenTexture;
void ShowPicture() {
    SetArray(-1 / kx, -1, ButLevel - 0.0001, 1 / kx, -1, ButLevel - 0.0001, 1 / kx, 1, ButLevel - 0.0001, -1 / kx, 1, ButLevel - 0.0001);
    SetColor(white.changea(0.5));
    DrawTexture(SplashScreenTexture);
    if (beginning < 2) {
        textsize *= 10;
        print(-0.5, -0.3, "Loading...", white);
        textsize /= 10;
    }
}


void ShowInfo(Planet* p) {

    InfoLabel.show();

    SetInfo(p);
    InfoBack.show();
    textsize *= 2; InfoName.show(); textsize /= 2;
    InfoMass.show();
    InfoSpeed.show();
    InfoPosX.show();
    InfoPosY.show();
    InfoRadius.show();
    ShowInfoMas();

    if (InfoBack.press()) {
        p->getinfostatus = false;
    }
}

void SetInfo(Planet* p) {
    if (p != k1) {
        InfoName.text = String("       ") + PlanetName[p->index];
        InfoMass.text = String("Mass: ") + to_String(p->getmass() / K, accuracy) + String(" * 10^24 kg");

        p->index == 0 ? InfoSpeed.text = String("Speed: 0 m/s") :
            InfoSpeed.text = String("Speed: ") + to_String(p->getspeed() / K, accuracy) + String(" m/s");

        vec PlPos = p->getpos();

        p->index == 0 ? InfoPosX.text = String("Pos X: 0 m") :
            InfoPosX.text = String("Pos X: ") + to_String(PlPos.x / K, accuracy) + String(" m");

        p->index == 0 ? InfoPosY.text = String("Pos Y: 0 m") :
            InfoPosY.text = String("Pos Y: ") + to_String(PlPos.y / K, accuracy) + String(" m");

        InfoRadius.text = String("Radius: ") + to_String(radiusmas[p->index] / K, accuracy) + String(" m");

        for (int i = 0; i < NumberOfString; i++) {
            Info[NumberOfString - i - 1].text = PlanetInfo[p->index][i];
        }
    }
    else {
        vec PlPos = p->getpos();
        if (ButtonEx5.down) { InfoName.text = String("       ") + String("to Mars"); }
        else { InfoName.text = String("       ") + String("Asteroid"); }
        InfoMass.text = String("Mass: ") + to_String(M, accuracy) + String(" * 10^24 kg");
        InfoSpeed.text = String("Speed: ") + to_String(p->getspeed() / K, accuracy) + String(" m/s");
        InfoPosX.text = String("Pos X: ") + to_String(PlPos.x / K, accuracy) + String(" m");
        InfoPosY.text = String("Pos Y: ") + to_String(PlPos.y / K, accuracy) + String(" m");
        InfoRadius.text = String("Radius: ") + to_String(R, accuracy) + String(" m");
        for (int i = 0; i < NumberOfString; i++) {
            Info[NumberOfString - i - 1].text = "";
        }
    }
}


void ShowInfoMas() {
    for (int i = 0; i < NumberOfString; i++) {
        Info[i].show();
    }
}
