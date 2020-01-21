#ifndef ORIENTATIONMAP_H
#define ORIENTATIONMAP_H

#include <QObject>
#include <QTime>
#include <QImage>

#include "OrientationMap_global.h"

// ArrayFire
#include "arrayfire.h"
#include "af/macros.h"

//OpenCV
#include "opencv2/opencv.hpp"

#include "helper.h"

typedef struct gaussian_blur_settings {
    int blockSize;  // velkost bloku pre vyhladenie smerovej mapy (cez bloky)
    float sigma;   // sigma pre vyhladenie smerovej mapy
} GAUSSIAN_BLUR_SETTINGS;

typedef struct omap_params {
    int blockSize;
    GAUSSIAN_BLUR_SETTINGS gaussBlurBasic;
    GAUSSIAN_BLUR_SETTINGS gaussBlurAdvanced;
} OMAP_PARAMS;

class ORIENTATIONMAP_EXPORT OrientationMap : public QObject
{
    Q_OBJECT

public:
    explicit OrientationMap(QObject *parent = nullptr);
    void setParams(const std::string path, int blockSize = 13, int gaussBlockBasic = 1, float gaussSigmaBasic = 1.0, int gaussBlockAdv = 121, float gaussSigmaAdv = 10.0);
    void setParams(const cv::Mat &imgInput, OMAP_PARAMS omap);
    void setParams(const std::string path, OMAP_PARAMS omap);
    void computeBasicMapCPU();
    void computeBasicMapGPU();
    void computeAdvancedMapCPU();
    void computeAdvancedMapGPU();
    void drawBasicMap(std::string path);
    void drawBasicMap(const cv::Mat &imgOriginal);

    //getNset
    cv::Mat getOMap_advanced() const;
    cv::Mat getOMap_basic() const;
    cv::Mat getImgOMap_basic() const;
    float getDuration() const;
    af::array getOMapAF_basic() const;
    af::array getOMapAF_advanced() const;


private:
    QTime timer;

    cv::Mat imgInput; // obrazok odtlacku
    af::array imgInputAF;

    OMAP_PARAMS omap;

    cv::Mat oMap_basic; // BASIC smerova mapa (vyhladena, jeden smer pre cely blok)
    af::array oMapAF_basic;
    cv::Mat oMap_advanced; // ADVANCED smerova mapa (vyhladena, kazdy pixel ma svoj smer)
    af::array oMapAF_advanced;

    cv::Mat imgOMap_basic; // obrazok BASIC smerovej mapy (ADVANCED mapa sa neda zobrazit, lebo kazdy pixel ma iny smer)

    float duration;

};



#endif // ORIENTATIONMAP_H
