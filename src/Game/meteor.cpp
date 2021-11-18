#include <Animus/helper.h>

class Meteor
{
    public:
        Meteor(int pX=10,int pY=10){
            x = pX;
            y= pY;
            speedX = rnd(5);
            speedY = rnd(5);
        }
        int getX() {return x;}
        int getY() {return y;}
        void setX(int pX) {x = pX;}
        void setY(int pY) {y = pY;}
        int getW() {return w;}
        int getH() {return h;}
        int getSpeedX(){return speedX;}
        int getSpeedY(){return speedY;}
        void setSpeedX(){speedX=speedX*(-1);}
        void setSpeedY(){speedY=speedY*(-1);}
    private:
        int x,y,w,h,speedX,speedY;
};