#ifndef __CAMERA_PROCESSING_H__
#define __CAMERA_PROCESSING_H__

#include "Thread.h"
#include "../image_processing/CamFrame.h"
#include "../tools/patterns/NoCopy.h"
#include "../tools/Logger.h"

/**
 * @brief   Thread runned to get pictures from the camera and extract position
 *          of a color. It finally set the position of an object in the
 *          pictures.
 * @author  Denis CARLUS
 */
class CameraProcessing : public Thread, private NoCopy {
    private:
        /** @brief Singleton of CameraProcessing. */
        static CameraProcessing* Singleton ;

        /** @brief  Continue the task on a while loop. */
        bool m_continue ;
        /** @brief  Capture of the video stream from the webcam. */
        cv::VideoCapture m_capture ;
        /** Processing on a single frame. */
        CamFrame m_cf ;



                                            /** CONSTRUCTION AND DESTRUCTION **/
        /**
         * @brief Construction of a CameraProcessing handler.
         */
        CameraProcessing() ;

        /** @brief Destruction of the CameraProcessing handler. */
        ~CameraProcessing() throw() ;


    public:
        /**
         * @brief Get the unique instance of Allegro.
         * @return  The unique instance of Allegro.
         */
        static CameraProcessing* getInstance() ;


    protected:
        /** @brief  The task of the thread. */
        virtual void task() ;

        /** @brief  Get a frame from the camera. */
        void getFrame() ;

        /** @brief  Effective stop task. */
        virtual void effectiveStop() ;
} ;

#endif
