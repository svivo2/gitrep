#include "layerlrelu.h"
#include "vec.h"

LayerLReLU::LayerLReLU(size_t _numUnits) : Layer(_numUnits, _numUnits)
{

}

LayerLReLU::~LayerLReLU()
{

}

void LayerLReLU::activate(const Vec& x)
{
    for(size_t i = 0; i < numInputs; i++)
    {
        if(x[i] >= 0)
            (*activation)[i] = x[i];
        else
            (*activation)[i] = 0.01 * x[i];
    }
}

void LayerLReLU::backprop(Vec& prevBlame)
{
    for(size_t i = 0; i < numInputs; i++)
    {
        //To do: figure out how to deal with this non-differentiable function
    }
}

void LayerLReLU::update_gradient(const Vec& x, Matrix& gradient)
{
    //This is an activation layer, so this function should do nothing
}
