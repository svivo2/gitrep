#include <algorithm>
#include <cmath>
#include "layerlinear.h"
#include "matrix.h"
#include "NeuralNet.h"
#include "vec.h"

NeuralNet::NeuralNet()
{
    numLayers = 0;
    alpha = 1.0;
    mu = 0.0;
    batch_size = 1;
}

NeuralNet::~NeuralNet()
{
    for(size_t i = 0; i < numLayers; i++)
    {
        delete layers[i];
        delete gradients[i];
    }
}

const char* NeuralNet::name()
{
    return "NeuralNet";
}

Layer& NeuralNet::addLayer(Layer* l)
{
    if(numLayers != 0 && layers[numLayers-1]->getNumOutputs() != l->getNumInputs())
        throw Ex("New layer's number of inputs should equal prev layer's number of outputs");

    layers.push_back(l);
    gradients.push_back(new Matrix(l->getNumOutputs(), l->getNumInputs()));
    gradients.back()->fill(0.0);
    numLayers++;
    return *layers[numLayers-1];
}

void NeuralNet::initWeights(Rand* rng)
{
    for(size_t l = 0; l < numLayers; l++)
        for(size_t i = 0; i < layers[l]->weights->rows(); i++)
            for(size_t j = 0; j < layers[l]->weights->cols(); j++)
                (*layers[l]->weights)[i][j] = std::max(0.03, 1.0/(layers[l]->weights->cols())) * rng->normal();
}

void NeuralNet::refineWeights(const Matrix& features, const Matrix& labels)
{
    //Zero out the gradients for this new batch
    for(size_t i = 0; i < numLayers; i++)
        *gradients[i] *= mu;

    //Run each example through the net and add to the gradient
    for(size_t i = 0; i < features.rows(); i++)
    {
        predict(features[i]);
        backprop(labels[i]);
        update_gradient(features[i]);
    }

    //Add the gradients into the weights
    for(size_t l = 0; l < numLayers; l++)
        *layers[l]->weights += *gradients[l] * alpha;
}

void NeuralNet::setLearningRate(double _alpha)
{
    alpha = _alpha;
}

void NeuralNet::setMomentum(double _mu)
{
    mu = _mu;
}

void NeuralNet::setBatchSize(size_t _batch_size)
{
    batch_size = _batch_size;
}

const Vec& NeuralNet::predict(const Vec& in)
{
	layers[0]->activate(in);
	for(size_t i = 1; i < numLayers; i++)
		layers[i]->activate(*layers[i-1]->activation);

    return *layers[numLayers-1]->activation;
}

void NeuralNet::backprop(const Vec& targets)
{
    layers[numLayers-1]->blame->copy(targets - *layers[numLayers-1]->activation);

    for(int i = numLayers-2; i >= 0; i--)
        layers[i+1]->backprop(*layers[i]->blame);
}

void NeuralNet::update_gradient(const Vec& x)
{
    Vec input;
    input.copy(x);

    for(size_t i = 0; i < numLayers; i++)
    {
        layers[i]->update_gradient(input, *gradients[i]);
        input.copy(*layers[i]->activation);
    }
}

void NeuralNet::train(const Matrix& features, const Matrix& labels)
{
    Matrix f_batch(batch_size, features.cols());
    Matrix l_batch(batch_size, labels.cols());

    for(size_t i = 0; i < ceil(features.rows() / batch_size); i++)
    {
        size_t batchStart = i * batch_size;
        size_t batchEnd = i * batch_size + batch_size;
        if(batchEnd > features.rows())
            batchEnd = features.rows();

        f_batch.copyBlock(0, 0, features, batchStart, 0, batchEnd - batchStart, features.cols());
        l_batch.copyBlock(0, 0, labels, batchStart, 0, batchEnd - batchStart, labels.cols());
        refineWeights(f_batch, l_batch);
    }
}

void NeuralNet::snapshot()
{
    for(size_t i = 0; i < numLayers; i++)
    {
        std::cout << "============ LAYER " << i << " ===========\n";
        std::cout << "WEIGHTS:\n\n";
        layers[i]->weights->print(std::cout);
        std::cout << "\n\n";
        std::cout << "ACTIVATION:\n\n";
        layers[i]->activation->print(std::cout);
        std::cout << "\n\n";
        //std::cout << "GRADIENTS:\n\n";
        //gradients[i]->print(std::cout);
        //std::cout << "\n\n";
    }
}
