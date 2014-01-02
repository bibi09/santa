#include "CameraProcessing.h"
#include "../tools/Logger.h"

using namespace std ;

CameraProcessing* CameraProcessing::Singleton = 0 ;


CameraProcessing::CameraProcessing() {
    m_continue = true ;
}

CameraProcessing::~CameraProcessing() throw() {}


CameraProcessing* CameraProcessing::getInstance() {
    if (Singleton == 0)
        Singleton = new CameraProcessing() ;
    return Singleton ;
}


void CameraProcessing::task() {
    #ifdef DEBUG
    Logger::print("Run CameraProcessing thread") ;
    #endif

    m_capture = VideoCapture(0) ;

    if (!m_capture.isOpened()) {
        Logger::print("Cannot open camera...") ;
        return ;
    }

    m_cf = CamFrame() ;
    // Blue color
    Scalar min = Scalar(87, 100, 120) ;                 // H L S
    Scalar max = Scalar(125, 250, 255) ;                // H L S
    m_cf.setMask(min, max) ;

    // Loop to get frames
    while (m_continue) {
        waitKey(40) ;
        getFrame() ;
    }

    m_capture.release() ;
}

void CameraProcessing::getFrame() {
    Mat frame ;
    m_capture >> frame ;
    flip(frame, frame, 1) ;
    m_cf.setFrame(frame) ;
    m_cf.mask() ;
}

/** @brief  Effective stop task. */
void CameraProcessing::effectiveStop() {
    m_continue = false ;
}
