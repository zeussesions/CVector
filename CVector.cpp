#include "CVector.h"
#include <cmath>
#include <cstdlib>
#include <vector>

CVector::CVector(float x1, float y1) {
    this->x = x1;
    this->y = y1;
}


//operator overloading

CVector CVector::operator+(CVector param) const {
    CVector temp(this->x + param.x, this->y + param.y);
    return temp;
}

void CVector::operator+=(CVector param) {
    this->x += param.x;
    this->y += param.y;
}

CVector CVector::operator-(CVector param) const {
    CVector temp(this->x - param.x, this->y - param.y);
    return temp;
}

void CVector::operator-=(CVector param) {
    this->x -= param.x;
    this->y -= param.y;
}

CVector CVector::operator*(CVector param) const {
    CVector temp(this->x * param.x, this->y * param.y);
    return temp;
}

void CVector::operator*=(CVector param) {
    this->x *= param.x;
    this->y *= param.y;
}

CVector CVector::operator/(CVector param) const {
    CVector temp(this->x / param.x, this->y / param.y);
    return temp;
}

void CVector::operator/=(CVector param) {
    this->x /= param.x;
    this->y /= param.y;
}

CVector CVector::operator%(CVector param) const {
    return {fmod(this->x, param.x), fmod(this->y, param.y)};
}

void CVector::operator%=(CVector param) {
    this->x = fmod(this->x, param.x);
    this->y = fmod(this->y, param.y);
}

bool CVector::operator==(CVector param) const {
    if (this->x == param.x && this->y == param.y) {
        return true;
    } else {
        return false;
    }
}



//methods

void CVector::set(float x1, float y1) {
    this->x = x1;
    this->y = y1;
}

CVector CVector::duplicate(CVector v1) { return v1; }

float CVector::mag() const { return sqrt((this->x * this->x) + (this->y * this->y)); }

float CVector::magSq() const { return (this->x * this->x) + (this->y * this->y); }

float CVector::dot(CVector v1) const { return this->x * v1.x + this->y * v1.y; }

float CVector::dist(CVector v1) const {
    return sqrt((v1.x - this->x) * (v1.x - this->x)) +
           ((v1.y - this->y) * (v1.y - this->y));
}

void CVector::normalize(float value = 1) {
    this->x *= (value / this->mag());
    this->y *= (value / this->mag());
}

void CVector::limit(float limit) {
    if (this->mag() > limit) {
        this->normalize(limit);
    }
}

void CVector::setMag(float mag) { this->normalize(mag); }

float Convert(float radian) {
    float pi = 3.14159;
    return (radian * (180 / pi));
}

float CVector::heading() const {
    float pi = 3.14159;
    float h = atan2(this->x, this->y);
    return h * (180 / pi);
}

void CVector::setHeading(float angle) {
    float m = this->mag();
    this->x = m * cos(angle);
    this->y = m * sin(angle);
}

void CVector::rotate(float angle) {
    float heading = this->heading() + angle;
    this->x = cos(heading) * this->mag();
    this->y = sin(heading) * this->mag();
}

std::vector<float> CVector::array(CVector v1) {
    std::vector<float> returnVector{};
    returnVector.push_back(v1.x);
    returnVector.push_back(v1.y);
    return returnVector;
}

CVector CVector::random2D(float minX, float maxX, float minY, float maxY) {
    std::srand(time(0));
    float x;
    float y;
    x = std::rand();
    y = std::rand();
    return CVector(x, y);
}

CVector CVector::fromAngle(float angle) { return CVector(cos(angle), sin(angle)); }

CVector CVector::fromAngle(float angle, float length) {
    CVector temp(length * cos(angle), length * sin(angle));
    return temp;
}

CVector CVector::fromAngles(float theta, float phi) {
    float length = 1;
    float sinPhi = sin(phi);
    float cosTheta = cos(theta);
    float sinTheta = sin(theta);

    CVector n(length * sinTheta * sinPhi, -length * cosTheta);
    return n;
}

void CVector::lerp(CVector v, float amt) {
    this->x += (v.x - this->x) * amt;
    this->y += (v.y - this->y) * amt;
}
