//
// Created by Kaiyu Xie on 2020/2/8.
//

#include "../../include/layers/l1loss_layer.h"

L1LossLayer::L1LossLayer(const std::string &name) : Layer(name) {
    reduction_ = "mean";
}

L1LossLayer::L1LossLayer(const std::string &name, std::string reduction) : Layer(name) {
    CAFFEBEAN_ASSERT(reduction == "none" || reduction == "mean" || reduction == "sum",
                     "reduction should be one of: none, mean, sum");
    reduction_ = reduction;
}

L1LossLayer::~L1LossLayer() {}

void L1LossLayer::init_layer() {}

Bean *L1LossLayer::forward(std::vector<Bean *> bottom) {
    std::cout << name_ << " forward" << std::endl;
    CAFFEBEAN_ASSERT(bottom.size() == 2,
                     "There should be 2 input.");
    CAFFEBEAN_ASSERT(bottom[0]->shape_ == bottom[1]->shape_,
                     "The 2 input shape of l1losslayer should be equal.");
    CAFFEBEAN_ASSERT(bottom[0]->shape_.size() >= 2,
                     "The input shape of l1losslayer should be (N,*).");
}

Bean *L1LossLayer::backward(std::vector<Bean *> top) {
    std::cout << name_ << " backward" << std::endl;
}

std::string L1LossLayer::get_reduction() {
    return reduction_;
}


