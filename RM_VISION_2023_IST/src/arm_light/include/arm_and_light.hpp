#ifndef _ARM_AND_LIGHT_HPP_
#define _ARM_AND_LIGHT_HPP_

#include <opencv2/opencv.hpp>
#define SMALL false
#define BIG true
#define RED false
#define BULE true

namespace rm_vision
{
    struct stand_light
    {
        const double min_ratio = 0.04;//最小宽高比
        const double max_ratio = 0.7;//最大宽高比
        const double max_angle = 12;//最大的灯条角度
    };
    
    struct stand_armor
    {
        const double min_light_ratio = 20;
        const double min_small_center_distance = 2.0;
        const double max_small_center_distance = 2.85;
        const double min_large_center_distance = 4.0;
        const double max_large_center_distance = 4.3;
        const double max_angle = 10;
    };
    
    struct Light:public cv::RotatedRect
    {
        Light()=default;
        explicit Light(cv::RotatedRect box): cv::RotatedRect(box)
        {
            cv::Point2f p[4];
            box.points(p);
            std::sort(p, p + 4, [](const cv::Point2f & a, const cv::Point2f & b) { return a.y < b.y; });
            top = (p[0] + p[1]) / 2;
            bottom = (p[2] + p[3]) / 2;

            length = cv::norm(top - bottom);
            width = cv::norm(p[0] - p[1]);

            tilt_angle = std::atan2(std::abs(top.x - bottom.x), std::abs(top.y - bottom.y));
            tilt_angle = tilt_angle / CV_PI * 180;
        }
        int color;
        double width;
        double length;
        cv::Point2f top,bottom;
        double tilt_angle;
    };

    struct Armor
    {
        Armor() = default;
        Armor(const Light & l1, const Light & l2)//传入两个灯条，合成一个装甲板
        {
            if (l1.center.x < l2.center.x) {
            left_light = l1, right_light = l2;
            } else {
            left_light = l2, right_light = l1;
            }//按x坐标的大小来判断是左装甲板还是右装甲板
            this->center = (left_light.center + right_light.center) / 2;

        }

        Light left_light, right_light;//左右灯条
        cv::Point2f center;//装甲板中心坐标

        cv::Mat number_img;//装甲板部分图片
        char number;//装甲板数字分类出来的结果
        // std::string number;
        float similarity;//相似度
        float confidence;//dnn分类完后的可信度
        std::string classfication_result;//分类结果（用来打印到图片上可视化结果）
        double distance_to_center;
        bool armor_type;//装甲板大小
    };
}

#endif