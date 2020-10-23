#include"jpeg.h"

void saveJPEG(int x0,int y0){
    double _y[8][8],_cb[8][8],_cr[8][8];
    double __y[8][8],__cb[8][8],__cr[8][8];
    int y[8][8],cb[8][8],cr[8][8];
    int i,j;
    for(i = 0;i < 8;i++){
        for(j = 0;j < 8;j++){
            _y[i][j] = 0.299 * getRed(x0+i,y0+j) + 0.5870 * getGreen(x0+i,y0+j) + 0.114 * getBlue(x0+i,y0+j);
            _cb[i][j] = -0.1687 * getRed(x0+i,y0+j) - 0.33113 * getGreen(x0+i,y0+j) + 0.5 * getBlue(x0+i,y0+j);
            _cr[i][j] = 0.5 * getRed(x0+i,y0+j) - 0.41887 * getGreen(x0+i,y0+j) - 0.0813 * getBlue(x0+i,y0+j);
        }
    }
    dct(__y,_y);
    dct(__cb,_cb);
    dct(__cr,_cr);
    quantization(__y,0,y);
    quantization(__cb,1,cb);
    quantization(__cr,1,cr);
}

double alpha(double x){
    if(fabs(x) < 1e-6){
        return 1.0/sqrt(8);
    }
    else return 0.5;
}
void dct(double res[][8],double src[][8]){
    int i,j,p,q;
    for(i = 0;i < 8;i++){
        for(j = 0;j < 8;j++){
            res[i][j] = 0;
            for(p = 0;p < 8;p++){
                for(q = 0;q < 8;q++){
                    res[i][j] += src[p][q] * cos((2*p+1)/16*i*PI) * cos((2*q+1)/16*j*PI);
                }
            }
            res[i][j] *= alpha(i);
            res[i][j] *= alpha(j);
        }
    }
}
double round(double x){
    double sign = 1;
    if(x < 0) sign = -1; 
    return sign * (int)(fabs(x) + 0.5);
}
void quantization(double a[][8],int flag,int dest[][8]){
    const char LQT[][8] = {
        16,  11,  10,  16,  24,  40,  51,  61,
        12,  12,  14,  19,  26,  58,  60,  55,
        14,  13,  16,  24,  40,  57,  69,  56,
        14,  17,  22,  29,  51,  87,  80,  62,
        18,  22,  37,  56,  68, 109, 103,  77,
        24,  35,  55,  64,  81, 104, 113,  92,
        49,  64,  78,  87, 103, 121, 120, 101,
        72,  92,  95,  98, 112, 100, 103,  99
        };
    const char CQT[][8] = 
    {
        17,  18,  24,  47,  99,  99,  99,  99,
        18,  21,  26,  66,  99,  99,  99,  99,
        24,  26,  56,  99,  99,  99,  99,  99,
        47,  66,  99,  99,  99,  99,  99,  99,
        99,  99,  99,  99,  99,  99,  99,  99,
        99,  99,  99,  99,  99,  99,  99,  99,
        99,  99,  99,  99,  99,  99,  99,  99,
        99,  99,  99,  99,  99,  99,  99,  99
    };
    int i,j;
    for(i = 0;i < 8;i++){
        for(j = 0;j < 8;j++){
            if(flag == 0){
                dest[i][j] = round(a[i][j] / LQT[i][j]);
            }else{
                dest[i][j] = round(a[i][j] / CQT[i][j]);
            }
        }
    }
}