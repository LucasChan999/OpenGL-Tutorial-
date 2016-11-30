//liang barskey.cpp
//使用liang barskey算法进行矩形窗口的线段剪裁
//陈兴雷
//2016.11.30
#include <glut.h>

int LBLineClipTest(float p,float q,float &umax,float &umin) 
{
	float r = 0;
	if (p < 0.0) {
		r = q / p;
		if (r > umin) return 0;
		else if (r > umax) umax = r;
	}
	else if (p > 0.0) {
		r = q / p;
		if (r < umax) return 0;
		else if (r < umin) umin = r;
	}
	else if (q < 0.0) return 0;//处理 p = 0 的情况
	return 1;
}

void LBLineClip(float xwl,float xwr,float ywb,float ywt,float x1, float y1,float x2,float y2) {
	float umax, umin, deltax, deltay;
	deltax = x2 - x1;
	deltay = y2 - y1;
	if (LBLineClipTest(-deltax, x1 - xwl, umax, umin)) {
		if (LBLineClipTest(deltax, xwr - x1 , umax, umin)) {
			if(LBLineClipTest(-deltay, y1 - ywb, umax, umin)) {
				if (LBLineClipTest(deltay, ywt - y1, umax, umin)) {
					x1 = int(x1 + umax*deltax + 0.5);
					y1 = int(y1 + umax*deltay + 0.5);
					x2 = int(x1 + umin*deltax + 0.5);
					y2 = int(y1 + umin*deltay + 0.5);
				}
				Bresenhamline(x1,y1,x2,y2);
			}
		}
	}


}






