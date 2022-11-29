#pragma once
#include "Libs.h"
#include "Colors.h"

int const ystep = 2;
int const xstep = 5;

vec points[181][360];
vec Pnull, P2, P1, v1, v2, N, Lv;
double angle;
float P_r;

void LoadTexture(String name, unsigned int &texture) {
    int w, h, cnt;

    unsigned char* data = stbi_load(name.getstr(), &w, &h, &cnt, 0);

    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, cnt == 4 ? GL_RGBA : GL_RGB, GL_UNSIGNED_BYTE, data);
    glBindTexture(GL_TEXTURE_2D, 0);

    stbi_image_free(data);
}

float TextureCoords[] = { 0, 0,  1, 0,  1, 1,  0, 1 };
float LocArray[12];
void DrawTexture(unsigned int &texture) {
    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texture);
    glEnableClientState(GL_VERTEX_ARRAY);
    glEnableClientState(GL_TEXTURE_COORD_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, LocArray);
    glTexCoordPointer(2, GL_FLOAT, 0, TextureCoords);
    glDrawArrays(GL_TRIANGLE_FAN, 0, 4);
    glDisableClientState(GL_VERTEX_ARRAY);
    glDisable(GL_TEXTURE_2D);

}
void SetTextureCoords(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4) {
    TextureCoords[0] = x1;
    TextureCoords[1] = y1;
    TextureCoords[2] = x2;
    TextureCoords[3] = y2;
    TextureCoords[4] = x3;
    TextureCoords[5] = y3;
    TextureCoords[6] = x4;
    TextureCoords[7] = y4;
}
void SetArray(float x1, float y1, float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4) {
    LocArray[0] = x1;
    LocArray[1] = y1;
    LocArray[2] = z1;

    LocArray[3] = x2;
    LocArray[4] = y2;
    LocArray[5] = z2;

    LocArray[6] = x3;
    LocArray[7] = y3;
    LocArray[8] = z3;

    LocArray[9] = x4;
    LocArray[10] = y4;
    LocArray[11] = z4;
}


void DrawSphere(vec pos, double radius, Color **colorarray, bool borders) {
    bool lighting = true;
    glPushMatrix();
    glTranslatef(pos.x, pos.y, pos.z);

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
                SetColor(colorarray[Va][a]);
                glBegin(GL_TRIANGLE_FAN);
                glVertex3f(points[Va][a].x, points[Va][a].y, points[Va][a].z);
                glVertex3f(points[Va + ystep][a].x, points[Va + ystep][a].y, points[Va + ystep][a].z);
                glVertex3f(points[Va + ystep][0].x, points[Va + ystep][0].y, points[Va + ystep][0].z);
                glVertex3f(points[Va][0].x, points[Va][0].y, points[Va][0].z);
                glEnd();
                if (borders) {
                    SetColor(black.changea(0.2));
                    glPointSize(3);
                    glBegin(GL_LINE_LOOP);
                    glVertex3f(points[Va][a].x, points[Va][a].y, points[Va][a].z);
                    glVertex3f(points[Va + ystep][a].x, points[Va + ystep][a].y, points[Va + ystep][a].z);
                    glVertex3f(points[Va + ystep][0].x, points[Va + ystep][0].y, points[Va + ystep][0].z);
                    glVertex3f(points[Va][0].x, points[Va][0].y, points[Va][0].z);
                    glEnd();
                }
            }
            //other 
            else {
                SetColor(colorarray[Va][a]);
                glBegin(GL_TRIANGLE_FAN);
                glVertex3f(points[Va][a].x, points[Va][a].y, points[Va][a].z);
                glVertex3f(points[Va + ystep][a].x, points[Va + ystep][a].y, points[Va + ystep][a].z);
                glVertex3f(points[Va + ystep][a + xstep].x, points[Va + ystep][a + xstep].y, points[Va + ystep][a + xstep].z);
                glVertex3f(points[Va][a + xstep].x, points[Va][a + xstep].y, points[Va][a + xstep].z);
                glEnd();
                if (borders) {
                    SetColor(black.changea(0.5));
                    glPointSize(3);
                    glBegin(GL_LINE_LOOP);
                    glVertex3f(points[Va][a].x, points[Va][a].y, points[Va][a].z);
                    glVertex3f(points[Va + ystep][a].x, points[Va + ystep][a].y, points[Va + ystep][a].z);
                    glVertex3f(points[Va + ystep][a + xstep].x, points[Va + ystep][a + xstep].y, points[Va + ystep][a + xstep].z);
                    glVertex3f(points[Va][a + xstep].x, points[Va][a + xstep].y, points[Va][a + xstep].z);
                    glEnd();
                }
            }
        }
    }
    glPopMatrix();
}

void DrawTexSphere(vec pos, float R, unsigned int texture, float KTexture) {

    glPushMatrix();
    glTranslatef(pos.x, pos.y, pos.z);
    glRotatef(180, 1, 0, 0);

    for (int Va = -90; Va <= 90; Va += ystep) {
        float r = R * cos((float)Va / 180 * M_PI);
        for (int a = 0; a < 360; a += xstep) {
            points[Va + 90][a].x = r * sin((float)a / 180 * M_PI);
            points[Va + 90][a].y = r * cos((float)a / 180 * M_PI);
            points[Va + 90][a].z = R * sin((float)Va / 180 * M_PI);
        }
    }

    for (int Va = 0; Va <= 180 - ystep; Va += ystep) {
        for (int a = 0; a < 360; a += xstep) {
            SetColor(white);
            //lost
            if (a >= 360 - xstep) {

                SetArray(points[Va][a].x, points[Va][a].y, points[Va][a].z,
                    points[Va + ystep][a].x, points[Va + ystep][a].y, points[Va + ystep][a].z,
                    points[Va + ystep][0].x, points[Va + ystep][0].y, points[Va + ystep][0].z,
                    points[Va][0].x, points[Va][0].y, points[Va][0].z);

                SetTextureCoords((float)a / 181 * KTexture,
                    (float)Va / 360 / KTexture,
                    (float)a / 181 * KTexture,
                    (float)(Va + ystep) / 360 / KTexture,
                    1,
                    (float)(Va + ystep) / 360 / KTexture,
                    1,
                    (float)Va / 360 / KTexture);

                DrawTexture(texture);
            }
            //other 
            else {

                SetArray(points[Va][a].x, points[Va][a].y, points[Va][a].z,
                    points[Va + ystep][a].x, points[Va + ystep][a].y, points[Va + ystep][a].z,
                    points[Va + ystep][a + xstep].x, points[Va + ystep][a + xstep].y, points[Va + ystep][a + xstep].z,
                    points[Va][a + xstep].x, points[Va][a + xstep].y, points[Va][a + xstep].z);

                SetTextureCoords((float)a / 181 * KTexture,
                    (float)Va / 360 / KTexture,
                    (float)a / 181 * KTexture,
                    (float)(Va + ystep) / 360 / KTexture,
                    (float)(a + xstep) / 181 * KTexture,
                    (float)(Va + ystep) / 360 / KTexture,
                    (float)(a + xstep) / 181 * KTexture,
                    (float)Va / 360 / KTexture);

                DrawTexture(texture);
            }
        }
    }
    glPopMatrix();

    TextureCoords[0] = 0;
    TextureCoords[1] = 0;
    TextureCoords[2] = 1;
    TextureCoords[3] = 0;
    TextureCoords[4] = 1;
    TextureCoords[5] = 1;
    TextureCoords[6] = 0;
    TextureCoords[7] = 1;
}

float KPlanetTexture = 10.5 / 20.5, k1KTexture = 10 / 20.5;