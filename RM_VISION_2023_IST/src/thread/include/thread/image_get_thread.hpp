#ifndef _IMAGE_GET_THREAD_HPP_
#define _IMAGE_GET_THREAD_HPP_

#include "basicthread.hpp"
#include "entitythread.hpp"
#include "basical_thread.hpp"

#include "conf_read.hpp"
#include "img_get.hpp"

#include <opencv2/opencv.hpp>

namespace rm_thread
{
    DECL_WORKTHTREAD(img_get_thread)
    private:
      camera_processor::img_get img_getter;
    public:
    img_get_thread()=default;
    img_get_thread(const rm_conf_read::conf_read &conf);
    DECL_WORKTHTREAD_END()
}


#endif 