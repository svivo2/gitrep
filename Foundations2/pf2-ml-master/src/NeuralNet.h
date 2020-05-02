#ifndef NEURALNET_H
#define NEURALNET_H

#include <vector>
#include "layerlinear.h"
#include "rand.h"
#include "supervised.h"
#include "vec.h"

class NeuralNet : public SupervisedLearner
{
    public:
        NeuralNet();
        ~NeuralNet();
        const char* name();

        //Adds a layer to the end of the vector. _inputs must equal _outputs from previous layer.
        Layer& addLayer(Layer* l);

        //Initializes the weights for each layer
        void initWeights(Rand* rng);

        void refineWeights(const Matrix& features, const Matrix& labels);

        void setLearningRate(double _alpha);
        void setMomentum(double _mu);
        void setBatchSize(size_t _batch_size);

        const Vec& predict(const Vec& in);
        void backprop(const Vec& targets);
        void update_gradient(const Vec& x);
        void train(const Matrix& features, const Matrix& labels);

        void snapshot();

    private:
        std::vector<Layer*> layers;
        std::vector<Matrix*> gradients;
        size_t numLayers;
        double alpha;
        double mu;
        size_t batch_size;
};

#endif
