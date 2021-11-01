#include "layer.h"
#include "matrix.h"
#include "vec.h"

Layer::Layer(size_t _numInputs, size_t _numOutputs)
{
    if(_numInputs < 1 || _numOutputs < 1)
        throw Ex("Each layer must have at least 1 input and 1 output");

    numInputs = _numInputs;
    numOutputs = _numOutputs;
	weights = new Matrix(numOutputs, numInputs);
	weights->fill(0.0);
	biases = new Vec(numOutputs);
	biases->fill(0.0);
	activation = new Vec(numOutputs);
	activation->fill(0.0);
    blame = new Vec(numOutputs);
    blame->fill(0.0);
}

Layer::~Layer()
{
	delete weights;
	delete biases;
	delete activation;
    delete blame;
}

size_t Layer::getNumInputs()
{
    return numInputs;
}

size_t Layer::getNumOutputs()
{
    return numOutputs;
}
