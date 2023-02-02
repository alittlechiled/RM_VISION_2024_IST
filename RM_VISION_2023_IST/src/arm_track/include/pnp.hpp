#ifndef _PNP_HPP_
#define _PNP_HPP_

#include <opencv2/opencv.hpp>

#include "arm_and_light.hpp"

#include <vector>
#include <array>
#include <utility>

namespace rm_vision
{
    struct armor_size
    {
        const double kSmallArmorWidth = 135;
        const double kSmallArmorHeight = 55;
        const double kBigArmorWidth = 225;
        const double kBigArmorHeight = 55;
    };

    class pnp_solver
    {
        public:
            pnp_solver() = default;
            pnp_solver(const std::array<double, 9> & camera_matrix,
                       const std::vector<double> & distortion_coefficients);
            std::pair<bool,cv::Point3f> solve_pnp(const Armor & armor);
            double dis_to_cen(const cv::Point2f & image_point);
            void arms_distance_count(std::vector<Armor> &armors);
        private:
            armor_size ARMOR_SIZE;
            cv::Mat camera_matrix_;
            cv::Mat dist_coeffs_;
            std::vector<cv::Point3f> small_armor_points_;
            std::vector<cv::Point3f> big_armor_points_;
    };
}

#endif