 #include "detect_thread.hpp"
#include "image_get_thread.hpp"
#include <opencv2/opencv.hpp>

using namespace rm_capture;
using namespace rm_conf_read;
using namespace rm_vision;
using namespace rm_thread;

#define DEBUG_IMSHOW_WIDTH 720.0

void debug_imshow(const std::string name, const cv::Mat &img)
{
  cv::Mat show;
  if (img.cols > DEBUG_IMSHOW_WIDTH)
    cv::resize(img, show,
               cv::Size(DEBUG_IMSHOW_WIDTH, img.rows * (1.0 * DEBUG_IMSHOW_WIDTH / img.cols)));
  else
    show = img;
  cv::imshow(name, show);
}

int main(int ,char **)
{
    conf_read conf;
    conf.read("\\home\\shunxiaochuan\\RM_VISION_2023_IST\\RM_VISION_2023_IST\\configuration_file\\setting.toml");
    std::cout<<"read configuration_file"<<std::endl;
    rm_thread::img_get_thread capture{conf};
    capture.up();
    std::cout<<"open camera"<<std::endl;
    rm_thread::detect_thread detect{conf};
    detect.up();
    std::cout<<"open detect"<<std::endl;
  while (true)
  {
    // 可视化检测结果
    auto ori_img = entitythread<cv::Mat>::get("capture_image");
    auto detections = entitythread<std::vector<Armor>>::get("detect_result", true);
    cv::Mat img;  // 避免引用源图像
    ori_img.copyTo(img);
    const cv::Scalar colors[3] = {{255, 0, 0}, {0, 0, 255}, {0, 255, 0}};
    for (const auto &b : detections)
    {
      bool break_flag = false;
      if ((b.left_light.top.x != b.left_light.top.x || b.left_light.top.y != b.left_light.top.y)&&
          (b.left_light.bottom.x != b.left_light.bottom.x || b.left_light.bottom.y != b.left_light.bottom.y)&&
          (b.right_light.top.x != b.right_light.top.x || b.right_light.top.y != b.right_light.top.y)&&
          (b.right_light.bottom.x != b.right_light.bottom.x || b.right_light.bottom.y != b.right_light.bottom.y)
      )  // NaN
      {
        break_flag = true;
        break;
      }
      if (break_flag) break;
      cv::line(img, b.left_light.top, b.left_light.bottom, colors[2], 2);
      cv::line(img, b.left_light.bottom, b.right_light.bottom, colors[2], 2);
      cv::line(img, b.right_light.bottom, b.right_light.top, 2);
      cv::line(img, b.right_light.top,b.left_light.top, colors[2], 2);
      cv::putText(img, std::to_string(b.number), b.left_light.top, cv::FONT_HERSHEY_SIMPLEX, 1,
                  colors[b.left_light.color], 3);
    }
    debug_imshow("SHOW", img);
    if (entitythread<cv::Mat>::exist("debug_img_1"))
      debug_imshow("debug_img_1", entitythread<cv::Mat>::get("debug_img_1", true));
    if (entitythread<cv::Mat>::exist("debug_img_2"))
      debug_imshow("debug_img_2", entitythread<cv::Mat>::get("debug_img_2", true));
    cv::waitKey(5);
  }

    return 0;
}
