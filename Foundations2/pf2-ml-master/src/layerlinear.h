#ifndef LAYERLINEAR_H
#define LAYERLINEAR_H

#include "layer.h"
#include "matrix.h"
#include "vec.h"

class LayerLinear : public Layer
{
    public:
        LayerLinear(size_t _numInputs, size_t _numOutputs);
        ~LayerLinear();
        void activate(const Vec& x);
        void backprop(Vec& prevBlame);
        void update_gradient(const Vec& x, Matrix& gradient);
        void ordinary_least_squares(const Matrix& x, const Matrix& y);

    private:

};

#endif
