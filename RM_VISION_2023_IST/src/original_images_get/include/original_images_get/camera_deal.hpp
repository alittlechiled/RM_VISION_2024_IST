#ifndef _CAMERA_DEAL_HPP_
#define _CAMERA_DEAL_HPP_

#include "dahua_camera.hpp"
#include "daheng_camera.hpp"

#include <iostream>
#include <string>

namespace camera_processor
{
    using namespace rm_capture;
    typedef struct camera_para
    {
        double gain_value;
        double white_balance_value[3];// b g r
        double exposure_time_value;
    }camera_para;

    class camera_deal:public DahuaCamera, public DahengCamera
    {
        public:
            camera_deal()=default;
            camera_deal(camera_para camera_para_init,std::string camera_choose):camera_setting(camera_para_init),camera_choose(camera_choose)
            {
                this->para_setting();
                printf("Camera is built and setted!");
            }
            cv::Mat picture_get(void);
        private:
            void para_setting(void);
            std::string camera_choose;
            camera_para camera_setting;
    };

}



#endif