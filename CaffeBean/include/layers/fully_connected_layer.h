//
// Created by Kaiyu Xie on 2019/12/22.
//

#ifndef CAFFEBEAN_FULLY_CONNECTED_LAYER_H
#define CAFFEBEAN_FULLY_CONNECTED_LAYER_H

#include "../layer.h"

class FullyConnectedLayer : public Layer {
private:
    int in_features_, out_features_;
    bool has_bias_;
    Bean *weight_, *bias_;
public:
    FullyConnectedLayer(const std::string &name, int in_features, int out_features, bool has_bias);

    void init_layer();

    Bean *forward(Bean *bottom);

    Bean *backward(Bean *top);
};

#endif //CAFFEBEAN_FULLY_CONNECTED_LAYER_H