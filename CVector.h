//
// Created by Asher S. on 6/7/23.
//

#ifndef CVECTOR_CVECTOR_H
#define CVECTOR_CVECTOR_H


#include <iostream>
#include <ctime>
#include <vector>
#include <cstdlib>
#include <cmath>

class CVector {
public:
    float x;
    float y;

    CVector(float x1, float y1);


    //operator overloading
    CVector operator+ (CVector param) const;
    void operator+= (CVector param);
    CVector operator- (CVector param) const;
    void operator-= (CVector param);
    CVector operator* (CVector param) const;
    void operator*= (CVector param);
    CVector operator/ (CVector param) const;
    void operator/= (CVector param);
    CVector operator% (CVector param) const;
    void operator%= (CVector param);
    bool operator== (CVector param) const;

    //methods
    void set(float x, float y);
    void set(CVector v1);
    static CVector duplicate(CVector v1);
    float mag() const;
    float magSq() const;
    float dot(CVector v1) const;
    float dist(CVector v1) const;
    void normalize(float value);
    void limit(float limit);
    void setMag(float mag);
    float heading() const;
    void setHeading(float angle);
    void rotate(float angle);
    static std::vector<float> array(CVector v1);
    static CVector random2D(float minX, float maxX, float minY, float maxY);
    static CVector fromAngle(float angle, float length);
    static CVector fromAngle(float angle);
    static CVector fromAngles(float theta, float phi);
    void lerp(CVector v, float amt);
};



#endif //CVECTOR_CVECTOR_H
