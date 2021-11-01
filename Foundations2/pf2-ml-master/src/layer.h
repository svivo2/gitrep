#ifndef LAYER_H
#define LAYER_H

#include "matrix.h"
#include "vec.h"


class Layer
{
    friend class NeuralNet;

    protected:
        size_t numInputs;
        size_t numOutputs;
        Matrix *weights;
        Vec *biases;
        Vec *activation;
        Vec *blame;

    public:
        Layer(size_t _numInputs, size_t _numOutputs);

        virtual ~Layer();

        virtual void activate(const Vec& x) = 0;
        virtual void backprop(Vec& prevBlame) = 0;
        virtual void update_gradient(const Vec& x, Matrix& gradient) = 0;

        size_t getNumInputs();
        size_t getNumOutputs();

};

#endif
