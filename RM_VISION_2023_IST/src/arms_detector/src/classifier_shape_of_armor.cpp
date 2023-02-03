#include "classifier_shape_of_armor.hpp"

namespace rm_vision
{
    number_classifier::number_classifier(const std::string &model_path,const std::string &label_path,const double &thr): threshold(thr)
    {
        net = cv::dnn::readNetFromONNX(model_path);
        std::ifstream labels(label_path,std::ifstream::in);
        std::string label;
        while (std::getline(labels, label)) {
        this->shapes.push_back(label);}

    }

    void number_classifier::do_class(std::vector<Armor> arms)
    {
for (auto & armor : arms) {
    cv::Mat image = armor.number_img.clone();

    // Normalize
    image = image / 255.0;

    // Create blob from image
    cv::Mat blob;
    cv::dnn::blobFromImage(image, blob, 1., cv::Size(28, 20));

    // Set the input blob for the neural network
    net.setInput(blob);
    // Forward pass the image blob through the model
    cv::Mat outputs = net.forward();//进行神经网络的预测

    // Do softmax
    float max_prob = *std::max_element(outputs.begin<float>(), outputs.end<float>());
    cv::Mat softmax_prob;
    cv::exp(outputs - max_prob, softmax_prob);
    float sum = static_cast<float>(cv::sum(softmax_prob)[0]);
    softmax_prob /= sum;

    double confidence;
    cv::Point class_id_point;
    minMaxLoc(softmax_prob.reshape(1, 1), nullptr, &confidence, nullptr, &class_id_point);
    int label_id = class_id_point.x;

    armor.confidence = confidence;
    armor.number = *shapes[label_id].c_str();

    std::stringstream result_ss;
    result_ss << armor.number << ":_" << std::fixed << std::setprecision(1)
              << armor.confidence * 100.0 << "%";
    armor.classfication_result = result_ss.str();
  }

  arms.erase(
    std::remove_if(
      arms.begin(), arms.end(),
      [this](const Armor & armor) {
        if (armor.confidence < threshold || armor.number == 'N') {
          return true;
        }

        bool mismatch = false;
        if (armor.armor_type == BIG) {
          mismatch = armor.number == 'O' || armor.number == '2' || armor.number == '3' ||
                     armor.number == '4' || armor.number == '5';
        } else if (armor.armor_type == SMALL) {
          mismatch = armor.number == '1' || armor.number == 'B' || armor.number == 'G';
        }
        return mismatch;
      }),
    arms.end());
    }
} // namespace rm_vision


