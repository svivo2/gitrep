#ifndef LAYERTANH_H
#define LAYERTANH_H

#include "layer.h"
#include "matrix.h"
#include "vec.h"

class LayerTanh : public Layer
{
    public:
        LayerTanh(size_t _numUnits);
        ~LayerTanh();

        void activate(const Vec& x);
        void backprop(Vec& prevBlame);
        void update_gradient(const Vec& x, Matrix& gradient);

    private:
};

#endif
