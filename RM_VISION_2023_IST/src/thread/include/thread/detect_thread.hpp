#ifndef _DETECT_THREAD_HPP_
#define _DETECT_THREAD_HPP_

#include "img_deal.hpp"
#include "basicthread.hpp"
#include "entitythread.hpp"
#include "basical_thread.hpp"

#include "conf_read.hpp"


#include <opencv2/opencv.hpp>

namespace rm_thread
{
    DECL_WORKTHTREAD(detect_thread)
    private:
        rm_vision::img_processor armdetecter;
    public:
    detect_thread()=default;
    detect_thread(const rm_conf_read::conf_read &conf);

    DECL_WORKTHTREAD_END()
}

#endif 