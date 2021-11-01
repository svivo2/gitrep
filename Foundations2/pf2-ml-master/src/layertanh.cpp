#include <cmath>
#include "layertanh.h"
#include "vec.h"

LayerTanh::LayerTanh(size_t _numUnits) : Layer(_numUnits, _numUnits)
{

}

LayerTanh::~LayerTanh()
{

}

void LayerTanh::activate(const Vec& x)
{
    for(size_t i = 0; i < numInputs; i++)
        (*activation)[i] = tanh(x[i]);
}

void LayerTanh::backprop(Vec& prevBlame)
{
    for(size_t i = 0; i < numInputs; i++)
        prevBlame[i] = (*blame)[i] * (1.0 - (*activation)[i] * (*activation)[i]);
}

void LayerTanh::update_gradient(const Vec& x, Matrix& gradient)
{
    //This is an activation layer, so this function should do nothing
}
