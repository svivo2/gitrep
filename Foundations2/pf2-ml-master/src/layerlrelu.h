#ifndef LAYERLRELU_H
#define LAYERLRELU_H

#include "layer.h"
#include "matrix.h"
#include "vec.h"


class LayerLReLU : public Layer
{
    public:
        LayerLReLU(size_t _numUnits);
        ~LayerLReLU();

        void activate(const Vec& x);
        void backprop(Vec& prevBlame);
        void update_gradient(const Vec& x, Matrix& gradient);

    private:
};

#endif
